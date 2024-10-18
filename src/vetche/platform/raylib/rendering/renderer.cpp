#include "renderer.h"

void vtc::RLRenderer::Init(vtc::Core& core) {
    core.PushOverlay(this);
}

void vtc::RLRenderer::Process(vtc::Float32 delta) {
    Draw();
}

void vtc::RLRenderer::Draw() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
}