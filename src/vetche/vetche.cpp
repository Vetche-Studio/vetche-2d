
#include <iostream>


#include "vetche/vetche.h"

#ifdef BUILD_LINUX_X11

#include "vetche/platform/raylib/build/build.h"

void vtc::RunMain() {
    auto core = rl::Build();
    core->Run();
}

#elif BUILD_PLAYDATE

#include "vetche/platform/pd/build/build.h"

void vtc::RunMain() {
    auto core = pd::Build();
    core->Run();
}

#elif BUILD_NDS

#include "vetche/platform/nds/build/build.h"

void vtc::RunMain() {
    auto core = nds::Build();
    core->Run();
}

#else

void vtc::RunMain() {
    // TODO: Add edge-case.
}

#endif