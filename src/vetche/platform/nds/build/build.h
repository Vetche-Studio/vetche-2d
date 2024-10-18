
#include <nds.h>

#include "vetche/core/core.h"
#include "vetche/layer/layerstack.h"
#include "vetche/core/modules.h"

namespace vtc::nintendo_ds {
    struct NDSRenderer : vtc::modules::IRenderer, vtc::ILayer {
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