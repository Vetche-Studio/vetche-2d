#include "renderer.h"

void bd::RLRenderer::Init(bd::Core& core) {
    core.PushOverlay(this);
}

void bd::RLRenderer::Process(bd::Float32 delta) {
    Draw();
}

void bd::RLRenderer::Draw() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}