#pragma once

#include "vetche/core/core.h"
#include "vetche/platform/raylib/rendering/renderer.h"
#include "vetche/platform/raylib/system/runner.h"

namespace vtc::rl {
    inline SharedPtr<Core> Build() {
        auto core = MakeShared<Core>();
        core->SetRunner<RLRunner>();
        core->CreateModule<RLRenderer>();
        core->Init();
        return core;
    }
}