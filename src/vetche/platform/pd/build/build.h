#pragma once

#include "vetche/core/core.h"
#include "vetche/platform/pd/rendering/renderer.h"

namespace vtc::pd {
    inline SharedPtr<Core> Build() {
        SharedPtr<Core> core = std::make_shared<Core>();
        core->CreateModule<PDRenderer>();
        core->Init();
        return core;
    }
}