using Raylib_cs;
using Vetche2D.Engine;
using Vetche2D.Engine.Math;

Raylib.InitWindow(800, 480, "Hello World");

var world = new World();

var entity = world.SpawnEntity();
entity.Position = new Vec2f(100, 200);
entity.Velocity = new Vec2f();
entity.Extents = new Vec2f(8, 8);
entity.Color = Color.Black;

while (!Raylib.WindowShouldClose())
{
    world.Update(Raylib.GetFrameTime());

    Raylib.BeginDrawing();
    Raylib.ClearBackground(Color.RayWhite);
    world.Draw();
    Raylib.EndDrawing();
}

Raylib.CloseWindow();