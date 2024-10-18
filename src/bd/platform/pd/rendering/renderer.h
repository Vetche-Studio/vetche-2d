#pragma once

#include <raylib.h>

#include "bd/core/core.h"
#include "bd/layer/layerstack.h"

namespace bd {
    struct PDRenderer : modules::IRenderer, ILayer {
        virtual void Init(Core& core) override;
        virtual void Process(Float32 delta) override;
        virtual void Draw() override;
    };
}