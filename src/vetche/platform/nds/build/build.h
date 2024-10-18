
#include <nds.h>
#include <stdio.h>

#include "vetche/core/core.h"
#include "vetche/layer/layerstack.h"
#include "vetche/core/modules.h"
#include <nds/arm9/input.h>
#include <nds/arm9/console.h>

namespace vtc::nds
{
    volatile int frame = 0;

    void Vblank()
    {
        frame++;
    }

    struct NDSRunner : vtc::modules::IRunner
    {
        inline virtual void Init(Core &core) override
        {
        }

        inline virtual bool IsRunning() override
        {
            return true;
        }

        inline virtual void SetPaused(bool flag) override
        {
        }

        inline virtual vtc::Float32 GetDelta() override
        {
            return 0.0f;
        }
    };

    struct NDSRenderer : vtc::modules::IRenderer, vtc::ILayer
    {
        inline virtual void Init(Core &core) override
        {
            core.PushOverlay(this);
            irqSet(IRQ_VBLANK, Vblank);

            consoleDemoInit();

            iprintf("      Hello DS dev'rs\n");
            iprintf("     \x1b[32mwww.devkitpro.org\n");
            iprintf("   \x1b[32;1mwww.drunkencoders.com\x1b[39m");
        }

        inline virtual void Process(Float32 delta) override
        {
            Draw();
        }

        inline virtual void Draw() override
        {

            while(1) {
            
                swiWaitForVBlank();
                scanKeys();
                int keys = keysDown();
                if (keys & KEY_START) break;

                touchRead(&TouchPos);

                // print at using ansi escape sequence \x1b[line;columnH 
                iprintf("\x1b[16;0HTouch x = %04X, %04X\n", TouchPos.rawx, TouchPos.px);
                iprintf("Touch y = %04X, %04X\n", TouchPos.rawy, TouchPos.py);		
            
            }
        }

        touchPosition TouchPos;
    };

    inline SharedPtr<Core> Build()
    {
        auto core = MakeShared<Core>();
        core->SetRunner<NDSRunner>();
        core->CreateModule<NDSRenderer>();
        core->Init();
        return core;
    }
}