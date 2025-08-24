#include <raylib.h>
#include <angelscript.h>

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

using PhysicsUnit = float;

struct Vec2
{
    PhysicsUnit X, Y;

    PhysicsUnit dot()
    {
        return X * X + Y * Y;
    }
};

void angelscript_stuff()
{
    asIScriptEngine* engine = asCreateScriptEngine(ANGELSCRIPT_VERSION);
    asFreeMem(engine); // meh
}

int main() {
    raylib_stuff();
}
