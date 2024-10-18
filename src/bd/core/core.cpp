#include "raylib.h"
#include "bd/core/core.h"
#include "bd/core/modules.h"

void bd::Core::Init() {
    for (auto& mod_shared_ptr : Modules) {
        mod_shared_ptr->Init(*this);
    }
}

void bd::Core::Run() {
    // TODO: Abstract the windowing to a module.
    // InitWindow(800, 450, "raylib [core] example - basic window");
    // while (!WindowShouldClose())
    // {
    //     Process(GetFrameTime());
    // }
    // CloseWindow();
}