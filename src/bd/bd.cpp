
#include <iostream>


#include "bd/bd.h"

#ifdef BUILD_LINUX_X11

#include "bd/platform/raylib/build/build.h"

void bd::RunMain() {
    auto core = rl::Build();
    core->Run();
}

#elif BUILD_NDS

#include "bd/platform/nds/build/build.h"

void bd::RunMain() {
    auto core = nintendo_ds::Build();
    core->Run();
}


#else

void bd::RunMain() {
    // TODO: Add edge-case.
}

#endif