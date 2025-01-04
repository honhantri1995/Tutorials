#include "Utility.h"

Utility::Utility()
{
}

Utility::~Utility()
{
}

void Utility::WriteDebugLogToFile(LOG_LEVEL inLogLevel, const char* inLogMsg, const char * inClassFuncName, long inLine)
{
	DebugLog* pDebugLog = DebugLog::GetInstance();
	pDebugLog->WriteDebugLogToFile(inLogLevel, inLogMsg, inClassFuncName, inLine);
}