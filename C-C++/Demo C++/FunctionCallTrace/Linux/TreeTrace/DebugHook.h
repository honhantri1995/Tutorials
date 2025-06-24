#pragma once

#define TRACE_FILE(traceFile) Trace::setTraceLogFile(traceFile)

// Note: __TRACE_FUNC__ is our user-defined macro and can be any name
#define TRACE_FUNC() Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, "")

#define TRACE_FUNC_1(argFmt, arg1) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1)

#define TRACE_FUNC_2(argFmt, arg1, arg2) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2)

#define TRACE_FUNC_3(argFmt, arg1, arg2, arg3) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3)

#define TRACE_FUNC_4(argFmt, arg1, arg2, arg4) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4)

#define TRACE_FUNC_5(argFmt, arg1, arg2, arg4, arg5) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4, arg5)

#define TRACE_FUNC_6(argFmt, arg1, arg2, arg4, arg5, arg6) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4, arg5, arg6)

#define TRACE_FUNC_7(argFmt, arg1, arg2, arg4, arg5, arg6, arg7) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7)

#define TRACE_FUNC_8(argFmt, arg1, arg2, arg4, arg5, arg6, arg7, arg8) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8)

#define TRACE_FUNC_9(argFmt, arg1, arg2, arg4, arg5, arg6, arg7, arg8, arg9) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9)

#define TRACE_FUNC_10(argFmt, arg1, arg2, arg4, arg5, arg6, arg7, arg8, arg9, arg10) \
    Trace __TRACE_FUNC__ (__PRETTY_FUNCTION__, argFmt, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10)


class Trace
{
public:
    Trace(const char* funcName, const char* argsFmt, ...);
    ~Trace();
    static void setTraceLogFile(const char* traceFile);

private:
    static void doFunctionTrace(int depth, int align, const char* fmt, va_list args);
    static const char* getTimeStampString();

private:
    static const char* m_traceFile;     // Path to trace log file
    static int m_depth;                 // Function call depth (entry function 'main' has depth of 0, others have depth of 1+)
    static const char* m_nest;          // Fixed characters " | | ... " to bring a hierarchical look when printing function names to trace log
};