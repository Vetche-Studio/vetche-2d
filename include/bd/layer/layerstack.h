#pragma once

#include <vector>
#include "bd/def/types.h"

namespace bd {
    struct ILayer {
        virtual void Process(Float32 delta) = 0;
    };

    struct LayerStack {
        LayerStack() = default;
        
        /// @brief Insert a layer to the beginning of the stack.
        void InsertLayer(ILayer* layer);

        /// @brief Push a layer to the end of the stack. Good for renderers.
        void PushOverlay(ILayer* layer);
        void Process(Float32 delta);

        std::vector<ILayer*> Layers;
    };
}