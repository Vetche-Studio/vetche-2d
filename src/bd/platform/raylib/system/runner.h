#pragma once

#include "bd/core/modules.h"
#include "bd/def/types.h"

namespace bd::rl {
    struct RLRunner : bd::modules::IRunner {
        virtual void Init(bd::Core& core) override;
        virtual bool IsRunning() override;
        virtual void SetPaused(bool flag) override;
        virtual bd::Float32 GetDelta() override;
    };

    // InitWindow(800, 450, "raylib [core] example - basic window");
    // while (!WindowShouldClose())
    // {
    //     Process(GetFrameTime());
    // }
    // CloseWindow();
}