#include <raylib.h>
#include "runner.h"

void vtc::rl::RLRunner::Init(vtc::Core& core) {
    InitWindow(320, 160, "Vetche2d");
}

bool vtc::rl::RLRunner::IsRunning() {
    return !WindowShouldClose();
}

void vtc::rl::RLRunner::SetPaused(bool flag) {
    // TODO
}

vtc::Float32 vtc::rl::RLRunner::GetDelta() {
    return GetFrameTime();
}