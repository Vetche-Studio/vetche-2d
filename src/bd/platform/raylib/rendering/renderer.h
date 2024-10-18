#pragma once

#include <raylib.h>

#include "bd/core/core.h"
#include "bd/layer/layerstack.h"

namespace bd {
    struct RLRenderer : modules::IRenderer, ILayer {
        virtual void Init(bd::Core& core) override;
        virtual void Process(bd::Float32 delta) override;
        virtual void Draw() override;
    };
}