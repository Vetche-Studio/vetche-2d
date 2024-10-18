
#include <nds.h>

#include "bd/core/core.h"
#include "bd/layer/layerstack.h"
#include "bd/core/modules.h"

namespace bd::nintendo_ds {
    struct NDSRenderer : bd::modules::IRenderer, bd::ILayer {
        virtual void Init(Core& core) override {
            core.PushOverlay(this);
        }
        
        virtual void Process(Float32 delta) override {
            
        }

        virtual void Draw() override {

        }
    };
    
    inline SharedPtr<Core> Build() {
        auto core = MakeShared<Core>();
        core->CreateModule<NDSRenderer>();
        core->Init();
        return core;
    }
}