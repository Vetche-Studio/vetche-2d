#include <raylib.h>
#include "runner.h"

void vtc::pd::PDRunner::Init(vtc::Core& core) {
}

bool vtc::pd::PDRunner::IsRunning() {
    return !WindowShouldClose();
}

void vtc::pd::PDRunner::SetPaused(bool flag) {
    // TODO
}

vtc::Float32 vtc::pd::PDRunner::GetDelta() {
    return GetFrameTime();
}