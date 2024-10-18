#pragma once

#include "bd/core/core.h"
#include "bd/platform/pd/rendering/renderer.h"

namespace bd::pd {
    inline SharedPtr<Core> Build() {
        SharedPtr<Core> core = std::make_shared<Core>();
        core->CreateModule<PDRenderer>();
        core->Init();
        return core;
    }
}