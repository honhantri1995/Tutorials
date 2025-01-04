#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <math.h>
#include <stdarg.h>
#include <iostream>

#include "DebugHook.h"

/////////////////////////////////
// Init static class members
const char* Trace::m_traceFile = "";
int Trace::m_depth = 0;
const char* Trace::m_nest = "| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | ";
/////////////////////////////////

Trace::Trace(const char* funcName, const char* argsFmt, ...)
{
    char fmt[256] = {0};
    sprintf(fmt, "%s%s", funcName, argsFmt);

    va_list arglist;
    va_start(arglist, argsFmt);
    doFunctionTrace(m_depth, m_depth * 2, fmt, arglist);
    va_end(arglist);

    ++m_depth;
}

Trace::~Trace()
{
    --m_depth;
}

void Trace::setTraceLogFile(const char* traceFile)
{
    m_traceFile = traceFile;
}

const char* Trace::getTimeStampString()
{
    char buffer[30] = {0};

    // Get current time
    struct timeval tv;
    gettimeofday(&tv, NULL);

    // Get millisecond part
    int millisec = lrint(tv.tv_usec/1000.0);    // Round to nearest millisec

    // If out of milisec, go for the next second
    if (millisec >= 1000)
    {
        millisec -=1000;
        tv.tv_sec++;
    }

    // Convert to local time
    struct tm* tm = localtime(&tv.tv_sec);

    // Convert time in number to time in readable string
    size_t len = strftime(buffer, sizeof(buffer), "[%Y:%m:%d %H:%M:%S", tm);

    // Add milisecond part to the string
    snprintf(buffer + len, sizeof(buffer) - len, ".%03d]", millisec);

    const char* pBuffer = buffer;               // Prevent warning "-Wreturn-local-addr"
    return pBuffer;
}

void Trace::doFunctionTrace(int depth, int align, const char* fmt, va_list args)
{
    // Open trace log file
    FILE* pFile = fopen(m_traceFile, "a+");
    if (pFile == NULL)
    {
        return;
    }

    // Write to trace log
    /* Format example:
        [2022:09:13 13:27:28.354] > (0) int main()
        [2022:09:13 13:27:28.356] | > (1) void Vehicle::car(int)(6)
        [2022:09:13 13:27:28.358] | > (1) void Vehicle::roadster()
        [2022:09:13 13:27:28.360] | | > (2) void Vehicle::truck(int, double)(2, 10.000000)
        ...
    */
    unsigned int len = fprintf(pFile, "%s %*.*s> (%d) ",
                               getTimeStampString(),
                               2 * depth,
                               2 * depth,
                               m_nest,
                               depth);
    len += vfprintf(pFile, fmt, args);
    len += fwrite("\n", 1, 1, pFile);

    // Close trace log file
    fflush(pFile);
    fclose(pFile);
}