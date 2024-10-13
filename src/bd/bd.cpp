
#include <iostream>
#include <raylib.h>

#include "bd/bd.h"
#include "bd/core/core.h"
#include "bd/core/modules.h"
#include "bd/def/types.h"
#include "bd/layer/layerstack.h"

void bd::Println(const char *str) {
    std::cout << "BrainDust: " << str << '\n';
}

struct RaylibRenderer : bd::modules::IRenderer, bd::ILayer {
    inline virtual void Init(bd::Core& core) override {
        core.PushOverlay(this);
    }

    virtual void Process(bd::Float32 delta) override {
        Draw();
    }

    virtual void Draw() override {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

};

void bd::RunMain() {
    Core core;
    core.CreateModule<RaylibRenderer>();

    core.Init();
    core.Run();
}