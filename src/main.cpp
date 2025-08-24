#include <raylib.h>

void raylib_stuff()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "raylib simple example");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello, raylib!", screenWidth/2 - MeasureText("Hello, raylib!", 20)/2, screenHeight/2 - 20, 20, LIGHTGRAY);
        EndDrawing();
    }
    CloseWindow();
}

int main() {
    raylib_stuff();
}
