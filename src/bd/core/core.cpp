#include <cassert>
#include "bd/core/core.h"
#include "bd/core/modules.h"

void bd::Core::Init() {
    assert(Runner != nullptr);
    for (auto& mod_shared_ptr : Modules) {
        mod_shared_ptr->Init(*this);
    }
}

void bd::Core::Run() {
    while(Runner->IsRunning()) {
        Process();
    }
}

void bd::Core::Process() {
    LayerStack::Process(Runner->GetDelta());
}