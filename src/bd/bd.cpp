
#include <iostream>
#include <raylib.h>

#include "bd/bd.h"

void bd::Println(const char *str) {
    std::cout << "BrainDust: " << str << '\n';
}
void bd::RunMain()
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
}