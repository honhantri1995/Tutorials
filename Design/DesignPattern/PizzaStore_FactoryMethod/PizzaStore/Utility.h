#pragma once
#include "DebugLog.h"

class Utility
{
public:
	Utility();
	~Utility();
	static void WriteDebugLogToFile(LOG_LEVEL inLogLevel, const char* inLogMsg, const char * inClassFuncName, long inLine);
};