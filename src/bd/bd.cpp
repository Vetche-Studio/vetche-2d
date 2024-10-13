
#include <iostream>
#include <raylib.h>

#include "bd/bd.h"
#include "bd/core/core.h"
#include "bd/core/modules.h"
#include "bd/def/types.h"
#include "bd/memory/smartptr.h"

void bd::Println(const char *str) {
    std::cout << "BrainDust: " << str << '\n';
}

struct RaylibRenderer : bd::modules::IRenderer {
    inline virtual void Init(bd::Core& core) override {

    }

    virtual void Draw() override {
        InitWindow(800, 450, "raylib [core] example - basic window");

        while (!WindowShouldClose())
        {
            BeginDrawing();
                ClearBackground(RAYWHITE);
                DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            EndDrawing();
        }

        CloseWindow();
    }

};

void bd::RunMain() {
    Core core;
    core.CreateModule<RaylibRenderer>();

    SharedPtr<modules::IRenderer> renderer;
    core.GivePtr(renderer);
    renderer->Draw();
}