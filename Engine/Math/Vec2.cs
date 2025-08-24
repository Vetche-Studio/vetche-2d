using System;
using Raylib_cs;

namespace Vetche2D.Engine.Math
{
    public struct Vec2f
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

        public static Vec2f operator +(Vec2f left, Vec2f right)
        {
            var result = new Vec2f();
            result.X = left.X + right.X;
            result.Y = left.Y + right.Y;
            return result;
        }

        public static Vec2f operator -(Vec2f left, Vec2f right)
        {
            var result = new Vec2f();
            result.X = left.X - right.X;
            result.Y = left.Y - right.Y;
            return result;
        }

        public static Vec2f operator /(Vec2f left, float right)
        {
            var result = new Vec2f();
            result.X = left.X / right;
            result.Y = left.Y / right;
            return result;

        }
        
        public static Vec2f operator *(Vec2f left, float right)
        {
            var result = new Vec2f();
            result.X = left.X * right;
            result.Y = left.Y * right;
            return result;
        }
    }
}