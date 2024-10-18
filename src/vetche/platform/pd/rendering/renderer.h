#pragma once

#include <raylib.h>

#include "vetche/core/core.h"
#include "vetche/layer/layerstack.h"

namespace vtc {
    struct PDRenderer : modules::IRenderer, ILayer {
        virtual void Init(Core& core) override;
        virtual void Process(Float32 delta) override;
        virtual void Draw() override;
    };
}