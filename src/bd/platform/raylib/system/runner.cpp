#include <raylib.h>
#include "runner.h"

void bd::rl::RLRunner::Init(bd::Core& core) {
    InitWindow(320, 160, "Vetche2d");
}

bool bd::rl::RLRunner::IsRunning() {
    return !WindowShouldClose();
}

void bd::rl::RLRunner::SetPaused(bool flag) {
    // TODO
}

bd::Float32 bd::rl::RLRunner::GetDelta() {
    return GetFrameTime();
}