#ifndef __USE_GNU
    #define __USE_GNU
#endif
#include <dlfcn.h>

extern "C"
{
    const char* getSymbolName(void *addr) __attribute__((no_instrument_function));
    void __cyg_profile_func_enter(void *this_fn, void *call_site) __attribute__((no_instrument_function));
    void __cyg_profile_func_exit(void *this_fn, void *call_site) __attribute__((no_instrument_function));
}