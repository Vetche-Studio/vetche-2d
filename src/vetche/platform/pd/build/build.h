#pragma once

#include "vetche/core/core.h"
#include "vetche/platform/pd/rendering/renderer.h"
#include "vetche/platform/pd/system/runner.h"

namespace vtc::pd {
    inline SharedPtr<Core> Build() {
        SharedPtr<Core> core = MakeShared<Core>();
        core->SetRunner<PDRunner>();
        core->CreateModule<PDRenderer>();
        core->Init();
        return core;
    }
}