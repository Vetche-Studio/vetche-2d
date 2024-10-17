
#include <iostream>


#include "bd/bd.h"

#ifdef BUILD_LINUX_X11

#include "bd/platform/linux/build/build.h"

void bd::RunMain() {
    auto core = linux_x11::Build();
    core->Run();
}

#else

void bd::RunMain() {
    // TODO: Add edge-case.
}

#endif