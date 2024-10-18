#include "renderer.h"

void vtc::PDRenderer::Init(vtc::Core& core) {
    core.PushOverlay(this);
}

void vtc::PDRenderer::Process(vtc::Float32 delta) {
    Draw();
}

void vtc::PDRenderer::Draw() {
}