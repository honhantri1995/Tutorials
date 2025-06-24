#pragma once

#ifdef _DEBUGHOOK_EXPORTS
	#define MYEXPORT __declspec( dllexport )
#else
	#define MYEXPORT __declspec( dllimport )
#endif

/*
	Export to DLL
*/
extern"C" void MYEXPORT FindSymbol_enter(void* pa);
extern"C" void MYEXPORT FindSymbol_exit(void* pa);

class ProfileInfo
{
public:
	ProfileInfo()
	{
		m_isFilled = false;
	}

	char	m_funName[256];		// Name of the function
	DWORD   m_threadID;			// Thread executig the function

	LARGE_INTEGER	m_startTime;	// Start time
	LARGE_INTEGER	m_endTime;		// End time

	bool m_isFilled;

	void Display();
};