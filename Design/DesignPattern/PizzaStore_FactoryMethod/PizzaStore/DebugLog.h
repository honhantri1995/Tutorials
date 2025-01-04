#pragma once
#include <Windows.h>

#define MAX_LOG		1024

typedef enum {
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR
} LOG_LEVEL;

class DebugLog
{
public:
	static DebugLog* GetInstance();
	void ReleaseInstance();
	void WriteDebugLogToFile(LOG_LEVEL inLogLevel, const char* inLogMsg, const char* inClassFuncName, long inLine);

private:
	DebugLog();
	~DebugLog();
	void SetLogFilePath();
	bool OpenLogFile();

	static DebugLog* m_DebugLog;
	char m_LogFilePath[MAX_PATH];
	HANDLE m_LogFileHandler;
};
