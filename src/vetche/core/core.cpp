#include <cassert>
#include "vetche/core/core.h"
#include "vetche/core/modules.h"

void vtc::Core::Init() {
    assert(Runner != nullptr);
    for (auto& mod_shared_ptr : Modules) {
        mod_shared_ptr->Init(*this);
    }
}

void vtc::Core::Run() {
    while(Runner->IsRunning()) {
        Process();
    }
}

void vtc::Core::Process() {
    LayerStack::Process(Runner->GetDelta());
}