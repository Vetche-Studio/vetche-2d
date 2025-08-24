using Raylib_cs;
using Vetche2D.Engine.Math;

namespace Vetche2D.Engine
{
    public class Entity
    {
        public Vec2f Position { get; set; }
        public Vec2f Velocity { get; set; }
        public Vec2f Extents { get; set; }

        public Color Color { get; set; }
    }
}

