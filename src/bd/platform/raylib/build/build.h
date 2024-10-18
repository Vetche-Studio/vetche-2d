#pragma once

#include "bd/core/core.h"
#include "bd/platform/raylib/rendering/renderer.h"
#include "bd/platform/raylib/system/runner.h"

namespace bd::rl {
    inline SharedPtr<Core> Build() {
        auto core = MakeShared<Core>();
        core->SetRunner<RLRunner>();
        core->CreateModule<RLRenderer>();
        core->Init();
        return core;
    }
}