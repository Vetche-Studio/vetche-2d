#include "renderer.h"

void bd::PDRenderer::Init(bd::Core& core) {
    core.PushOverlay(this);
}

void bd::PDRenderer::Process(bd::Float32 delta) {
    Draw();
}

void bd::PDRenderer::Draw() {
}