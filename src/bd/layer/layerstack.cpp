#include "bd/layer/layerstack.h"

void bd::LayerStack::InsertLayer(ILayer* layer) {
    Layers.insert(Layers.begin(), layer);
}

void bd::LayerStack::PushOverlay(ILayer* layer) {
    Layers.push_back(layer);
}

void bd::LayerStack::Process(Float32 delta) {
    for (auto* layer : Layers) {
        layer->Process(delta);
    }
}