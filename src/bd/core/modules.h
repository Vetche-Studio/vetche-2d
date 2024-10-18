#pragma once

#include "bd/def/types.h"

namespace bd {
    struct Core;
}

namespace bd::modules {
    struct IModule {
        IModule() = default;
        ~IModule() = default;
        virtual void Init(Core& core) = 0;
    };

    struct IRunner : IModule {
        virtual bool IsRunning() = 0;
        virtual void SetPaused(bool flag) = 0;
        virtual bd::Float32 GetDelta() = 0;
    };

    struct IRenderer : IModule {
        virtual void Draw() = 0;
    };

    struct IFileSystem : IModule {
        
    };
    
    struct IAudio : IModule {
        
    };
}