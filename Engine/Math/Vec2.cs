using System;
using Raylib_cs;

namespace Vetche2D.Engine.Math
{
    struct Vec2f
    {
        public float X;
        public float Y;

        public Vec2f()
        {
            Y = 0f;
            X = 0f;
        }

        public Vec2f(float x, float y)
        {
            X = x;
            Y = y;
        }
    }
}