#include "DebugLog.h"
#include <string>
#include <ctime>

DebugLog* DebugLog::m_DebugLog = nullptr;

DebugLog::DebugLog()
	: m_LogFilePath{0},
	  m_LogFileHandler(nullptr)
{
	SetLogFilePath();
	OpenLogFile();
}

DebugLog::~DebugLog()
{
	if (::CloseHandle(m_LogFileHandler) == 0) {
		printf("[ERROR] Failed to close debug log file.\n");
	}
}

DebugLog* DebugLog::GetInstance()
{
	if (m_DebugLog == nullptr) {
		m_DebugLog = new DebugLog();
	}
	return m_DebugLog;
}

void DebugLog::ReleaseInstance()
{
	if (m_DebugLog != nullptr) {
		delete m_DebugLog;
		m_DebugLog = nullptr;
	}
}

/**
 * Set path of log file
 */
void DebugLog::SetLogFilePath()
{
	// Get EXE's full path
	char exeFullPath[MAX_PATH] = {0};
	::GetModuleFileNameA(NULL, exeFullPath, sizeof(exeFullPath));

	// Get EXE's directory path
	char* end = strrchr(exeFullPath, '\\');
	char exeDirPath[MAX_PATH] = {0};
	strncpy_s(exeDirPath, exeFullPath, end-exeFullPath+1);

	// Set log file's full path
	_snprintf_s(m_LogFilePath, sizeof(m_LogFilePath), "%s\\Log.txt", exeDirPath);
}

/**
 * Create file if have not existed. Else, open it.
 */
bool DebugLog::OpenLogFile()
{
	// If the log file already exists, open it.
	m_LogFileHandler = ::CreateFileA(m_LogFilePath, GENERIC_READ | GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, FILE_FLAG_WRITE_THROUGH, NULL);
	// If the log file doesn't exist, create and then open it.
	if (ERROR_FILE_NOT_FOUND == ::GetLastError()) {
		m_LogFileHandler = ::CreateFileA(m_LogFilePath, GENERIC_READ | GENERIC_WRITE,
			0, NULL, CREATE_ALWAYS, FILE_FLAG_WRITE_THROUGH, NULL);
	}

	if (m_LogFileHandler == INVALID_HANDLE_VALUE) {
		printf("[ERROR] Failed to create or open log file.\n");
		return false;
	}

	return true;
}

/**
 * Format the debug log message with extra information (time, level, line, etc.) and write it to file
 */
void DebugLog::WriteDebugLogToFile(LOG_LEVEL inLogLevel, const char* inLogMsg, const char* inClassFuncName, long inLine)
{
	char logLevel[20] = {0};
	switch (inLogLevel)
	{
	case LOG_INFO:
		strcpy_s(logLevel, "INFO");
		break;
	case LOG_WARNING:
		strcpy_s(logLevel, "WARNING");
		break;
	case LOG_ERROR:
		strcpy_s(logLevel, "ERROR");
		break;
	default:
		strcpy_s(logLevel, "UNDEFINED");
		break;
	}

	// Get current date/time based on current system
	time_t rawTime = time(0);
	tm curTime = {0};
	localtime_s(&curTime, &rawTime);

	// Windows uses a CR/LF combination to signify the end of line,
	// So need to use "\r\n" for breaking line to show up correctly in, eg, Notepad.
	char log[MAX_LOG] = {0};
	_snprintf_s(log, sizeof(log), "On [%d/%d/%d] at [%d:%d:%d], [%s] at [%s:%d]\r\n%s\r\n\r\n",
									curTime.tm_year + 1900, curTime.tm_mon + 1, curTime.tm_mday,
									curTime.tm_hour, curTime.tm_min, curTime.tm_sec,
									logLevel, inClassFuncName, inLine, inLogMsg);

	// Set the file pointer to the end of the file
	// Note: Without it, the file pointer is set to the beginning of the file, by default
	DWORD moved = ::SetFilePointer(m_LogFileHandler, 0, NULL, FILE_END);
	if (moved == INVALID_SET_FILE_POINTER) {
		printf("[ERROR] Failed to set file pointer to end of the file.\n");
		return;
	}

	DWORD bytesWritten = 0;
	if (!::WriteFile(m_LogFileHandler, log, strlen(log), &bytesWritten, NULL)) {
		printf("[ERROR] Failed to write debug log to file.\n");
		return;
	}
}