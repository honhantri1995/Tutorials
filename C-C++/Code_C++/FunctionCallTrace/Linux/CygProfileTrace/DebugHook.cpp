#include <cstdio>
#include "DebugHook.h"

/*
    Get function name based on its address
*/
const char* getSymbolName(void *addr)
{
    void *hdl;
    Dl_info dlInfo = {0};

    hdl = dlopen(NULL, 0);
    dladdr(addr, &dlInfo);

    if ((dlInfo.dli_saddr != NULL) && (dlInfo.dli_fname != NULL) && (dlInfo.dli_sname != NULL)) {
        char name[1024] = {0};
        char* p_name = name;
        snprintf(name, sizeof(name), "[%s] %s", dlInfo.dli_fname, dlInfo.dli_sname);
        return p_name;
    }
    else {
        return "<unknown-symbol>";
    }
}

/*
    This function is called after entering every other function in the program
*/
void __cyg_profile_func_enter(void *this_fn, void *call_site)
{
    printf("Enter: %s\n", getSymbolName(this_fn));
}

/*
    This function is called before exiting every other function in the program
*/
void __cyg_profile_func_exit(void *this_fn, void *call_site)
{
    printf("Exit: %s\n", getSymbolName(this_fn));
}
