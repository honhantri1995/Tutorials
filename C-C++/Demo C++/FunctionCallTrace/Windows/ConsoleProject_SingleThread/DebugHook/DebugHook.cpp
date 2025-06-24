#include <windows.h>
#include <imagehlp.h>
#include <intrin.h>
#include <strsafe.h>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

#include "DebugHook.h"

// Flag to indicate the result of symbol initialization
static BOOL g_isInit = FALSE;

// Base address of the loaded module
static DWORD64 g_baseAddr = 0;

// Critical section to protect the g_mapProfileInfo
CRITICAL_SECTION g_csProfileInfo;

// Map between the thread id to list of profile info
map<int, vector<ProfileInfo>> g_mapProfileInfo;

// Function prototypes
void InitSymbols(void* pAddress);
void DisplayProfileData();
void FindFunction(void* pa, char* &funcName);

/*
	Dll entry point function
*/
BOOL APIENTRY DllMain(HMODULE module,
					  DWORD callReason,
					  LPVOID reserved)
{
	switch (callReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			// Intitalize the critical section
			::InitializeCriticalSection(&g_csProfileInfo);

			// Loads the symbols of the module
			InitSymbols(module);
			break;
		}
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			// At the end, when the DLL is detached from the process,
			// dump all the profiled data
			DisplayProfileData();

			// Clean-up the symbols
			::SymCleanup(::GetCurrentProcess());
			break;
		}
		break;
	}

	return TRUE;
}

/*
	Load the symbols of the module
*/
void InitSymbols(void* pAddress)
{
	// Query the memory
	char moduleName[MAX_PATH];
	MEMORY_BASIC_INFORMATION mbi;

	// Get the module name where the address is available
	::VirtualQuery((void *)pAddress, &mbi, sizeof(mbi));
	::GetModuleFileNameA((HMODULE)mbi.AllocationBase, moduleName, MAX_PATH);

	// Initialize the symbols
	g_isInit = ::SymInitialize(::GetCurrentProcess(), moduleName, TRUE);

	// Load the module
	g_baseAddr = ::SymLoadModule64(::GetCurrentProcess(),
								   NULL,
								   (PCSTR)moduleName,
								   NULL,
								   (DWORD)mbi.AllocationBase,
								   0);
	// Set the options
	::SymSetOptions(::SymGetOptions() & ~SYMOPT_UNDNAME);
}

/*
	Iterate through the map.
	For each thread, print the profile data strored in the vector
*/
void DisplayProfileData()
{
	cout << endl << "########################## Profile Information ############################" << endl;

	map<int, vector<ProfileInfo>>::iterator it_thread = g_mapProfileInfo.begin();
	for (; it_thread != g_mapProfileInfo.end(); ++it_thread)
	{
		vector<ProfileInfo>& vec_profileInfo = it_thread->second;
		vector<ProfileInfo>::iterator it = vec_profileInfo.begin();
		for (; it != vec_profileInfo.end(); ++it)
		{
			it->Display();
		}
	}
}

/*
	Get function name from function address
*/
void FindFunction(void* pa, char* &funcName)
{
	DWORD64 symDisplacement = 0;
	char undName[1024];

	if (g_baseAddr)
	{
		// Allocate the memory for PSYMBOL_INFO
		TCHAR buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
		memset(&buffer, 0, sizeof(buffer));
		PSYMBOL_INFO pSymbolInfo = (PSYMBOL_INFO)buffer;
		pSymbolInfo->SizeOfStruct = sizeof(SYMBOL_INFO);
		pSymbolInfo->MaxNameLen = MAX_SYM_NAME;

		// Get the name of the symbol using the address
		BOOL isSuccess = ::SymFromAddr(::GetCurrentProcess(), (DWORD64)pa, &symDisplacement, pSymbolInfo);

		LPVOID msgBuf;
		LPVOID displayBuf;

		// If symbol is found, get its undecorated name.
		// The name could be a decorated one as the name mangling schemes are deployed.
		if (isSuccess)
		{
			if (::UnDecorateSymbolName(pSymbolInfo->Name, undName,
									   sizeof(undName),
									   UNDNAME_NO_MS_KEYWORDS |
										 UNDNAME_NO_ACCESS_SPECIFIERS |
										 UNDNAME_NO_FUNCTION_RETURNS |
										 UNDNAME_NO_ALLOCATION_MODEL |
										 UNDNAME_NO_ALLOCATION_LANGUAGE |
										 UNDNAME_NO_ARGUMENTS |
										 UNDNAME_NO_SPECIAL_SYMS |
										 UNDNAME_NO_MEMBER_TYPE))

			{
				// Ignore the unnecessary calls emulated from std library
				if (strstr(undName, "std::"))
				{
					// Skip the symbol
				}
				else
				{
					strcpy_s(undName, pSymbolInfo->Name);
					funcName = new char[strlen(undName) + 2];
					strcpy_s(funcName, strlen(undName) + 1, undName);
				}
			}
		}
		else
		{
			DWORD lastError = ::GetLastError();
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
							FORMAT_MESSAGE_FROM_SYSTEM |
							FORMAT_MESSAGE_IGNORE_INSERTS,
						  NULL,
						  lastError,
						  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
						  (LPTSTR)&msgBuf,
						  0,
						  NULL);

			displayBuf = (LPVOID)::LocalAlloc(LMEM_ZEROINIT, (lstrlen((LPCTSTR)msgBuf) + 40) * sizeof(TCHAR));

			StringCchPrintf((LPTSTR)displayBuf,
							::LocalSize(displayBuf) / sizeof(TCHAR),
							TEXT("[ERROR] Failed with error %d: %s"),
							lastError, msgBuf);
		}
	}
}

/*
*/
void FindSymbol_enter(void* pCallee)
{
	char* callee = NULL;
	FindFunction(pCallee, callee);

	if(callee)
	{
		ProfileInfo profileInfo;
		strcpy_s(profileInfo.m_funName, callee);

		LARGE_INTEGER li;
		::QueryPerformanceCounter(&li);
		profileInfo.m_startTime = li;

		DWORD threadId = ::GetCurrentThreadId();
		profileInfo.m_threadID = threadId;

		::EnterCriticalSection(&g_csProfileInfo);

		map<int, vector<ProfileInfo>>::iterator it_thread = g_mapProfileInfo.find(threadId);
		if (it_thread != g_mapProfileInfo.end())
		{
			it_thread->second.push_back(profileInfo);
		}
		else
		{
			vector<ProfileInfo> vec_profileInfo;
			vec_profileInfo.push_back(profileInfo);
			g_mapProfileInfo.insert(make_pair(threadId, vec_profileInfo));
		}

		::LeaveCriticalSection(&g_csProfileInfo);
	}
}

/*
*/
void FindSymbol_exit(void* pCallee)
{
	char *callee = NULL;
	FindFunction(pCallee, callee);

	LARGE_INTEGER li;
	::QueryPerformanceCounter(&li);

	// Find if the callee is there in the vectoar
	if (callee)
	{
		// Check for the thread ID
		DWORD threadId = ::GetCurrentThreadId();

		::EnterCriticalSection(&g_csProfileInfo);
		map<int, vector<ProfileInfo>>::iterator it_thread = g_mapProfileInfo.find(threadId);

		if (it_thread != g_mapProfileInfo.end())
		{
			vector<ProfileInfo>& vecProfileInfo = it_thread->second;
			vector<ProfileInfo>::iterator it = vecProfileInfo.end();
			--it;

			while (1)
			{
				if (strcmp(it->m_funName, callee) == 0 && (!it->m_isFilled))
				{
					it->m_endTime = li;
					it->m_isFilled = true;
					break;
				}
				if (it == vecProfileInfo.begin())
				{
					break;
				}
				--it;
			}
		}

		::LeaveCriticalSection(&g_csProfileInfo);
	}
}

/*
	Display all profile information at the end of the program
*/
void ProfileInfo::Display()
{
	cout << "[" << m_threadID << "] Enter: " << m_funName;

	// Number of ticks
	LARGE_INTEGER elapsedTime;
	elapsedTime.QuadPart = m_endTime.QuadPart - m_startTime.QuadPart;

	// Number of ticks-per-sec
	LARGE_INTEGER freq;
	::QueryPerformanceFrequency(&freq);

	elapsedTime.QuadPart = (elapsedTime.QuadPart) * 1000 * 1000 / freq.QuadPart;

	cout << " (" << elapsedTime.QuadPart << " us)" << endl;
}