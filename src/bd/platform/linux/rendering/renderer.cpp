#include "renderer.h"

void bd::RaylibRenderer::Init(bd::Core& core) {
    core.PushOverlay(this);
}

void bd::RaylibRenderer::Process(bd::Float32 delta) {
    Draw();
}

void bd::RaylibRenderer::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}