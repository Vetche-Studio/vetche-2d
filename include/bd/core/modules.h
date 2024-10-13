#pragma once

#include "bd/def/types.h"
#include "bd/memory/smartptr.h"

namespace bd {
    struct Core;
}

namespace bd::modules {
    struct IModule {
    // private:
    //     IModule() = default;
    //     friend Core;
    public:
        virtual void Init(Core& core) = 0;
    };

    struct IRenderer : IModule {
        virtual void Draw() = 0;
    };

    struct IFileSystem : IModule {
        
    };
    
    struct IAudio : IModule {
        
    };
}