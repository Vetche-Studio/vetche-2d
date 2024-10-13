#include "bd/core/core.h"
#include "bd/core/modules.h"


void bd::Core::Init() {
    for (auto& mod_shared_ptr : Modules) {
        mod_shared_ptr->Init(*this);
    }
}