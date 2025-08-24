using System.Collections;
using System.Data;
using Raylib_cs;

namespace Vetche2D.Engine
{
    public class World
    {
        List<Entity> _entities = new List<Entity>();

        public Entity SpawnEntity()
        {
            var entity = new Entity();
            _entities.Add(entity);
            return entity;
        }

        public void Update(float delta)
        {
            foreach (Entity entity in _entities)
            {
                entity.Position += entity.Velocity * delta;
            }
        }


        public void Draw()
        {
            foreach (Entity entity in _entities)
            {
                Raylib.DrawRectangle(
                    (int)System.Math.Round(entity.Position.X - entity.Extents.X),
                    (int)System.Math.Round(entity.Position.Y - entity.Extents.Y),
                    (int)System.Math.Round(entity.Extents.X*2),
                    (int)System.Math.Round(entity.Extents.Y*2),
                    entity.Color
                );
            }
        }
    }
}