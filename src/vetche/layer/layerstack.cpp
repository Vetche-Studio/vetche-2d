#include "vetche/layer/layerstack.h"

void vtc::LayerStack::InsertLayer(ILayer* layer) {
    Layers.insert(Layers.begin(), layer);
}

void vtc::LayerStack::PushOverlay(ILayer* layer) {
    Layers.push_back(layer);
}

void vtc::LayerStack::Process(Float32 delta) {
    for (auto* layer : Layers) {
        layer->Process(delta);
    }
}