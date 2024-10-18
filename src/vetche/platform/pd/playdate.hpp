
#pragma once
#include <pdcpp/pdnewlib.h>

/**
 * You can use STL containers! Be careful with some stdlib objects which rely
 * on an OS though, those will cause your app to crash on launch.
 */

int update(void *pd)
{
    return 1;
};

void init(PlaydateAPI *pd)
{
    pd->system->setUpdateCallback(update, pd);
};

/**
 * the `eventHandler` function is the entry point for all Playdate applications
 * and Lua extensions. It requires C-style linkage (no name mangling) so we
 * must wrap the entire thing in this `extern "C" {` block
 */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * This is the main event handler. Using the `Init` and `Terminate` events, we
 * allocate and free the `HelloWorld` handler accordingly.
 *
 * You only need this `_WINDLL` block if you want to run this on a simulator on
 * a windows machine, but for the sake of broad compatibility, we'll leave it
 * here.
 */
#ifdef _WINDLL
    __declspec(dllexport)
#endif
    int
    eventHandler(PlaydateAPI *pd, PDSystemEvent event, uint32_t arg)
    {
        /*
         * This is required, otherwise linker errors abound
         */
        eventHandler_pdnewlib(pd, event, arg);

        switch (event)
        {
        case kEventInit:
            init(pd);
            break;
        default:
            break;
        }
        return 0;
    }
#ifdef __cplusplus
}
#endif