#pragma once

#include "bd/core/core.h"
#include "bd/platform/linux/rendering/renderer.h"

namespace bd::linux_x11 {
    inline SharedPtr<Core> Build() {
        SharedPtr<Core> core = std::make_shared<Core>();
        core->CreateModule<RaylibRenderer>();
        core->Init();
        return core;
    }
}