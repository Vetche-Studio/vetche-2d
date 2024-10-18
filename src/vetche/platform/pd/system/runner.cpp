#include "runner.h"

void vtc::pd::PDRunner::Init(Core& core) {
}

bool vtc::pd::PDRunner::IsRunning() {
    return true;
}

void vtc::pd::PDRunner::SetPaused(bool flag) {
    // TODO
}

vtc::Float32 vtc::pd::PDRunner::GetDelta() {
    return 1.0f;
}