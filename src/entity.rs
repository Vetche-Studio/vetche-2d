use raylib::prelude::*;

pub struct Vec2<T> {
    pub x: T,
    pub y: T,
}

impl<T> Clone for Vec2<T> where T : Clone {
    fn clone(&self) -> Self {
        Self {
            x: self.x.clone(),
            y: self.y.clone(),
        }
    }
}

type Vec2f = Vec2<f32>;

pub struct Entity {
    pub position: Vec2f,
    pub velocity: Vec2f,
}

impl Clone for Entity {
    fn clone(&self) -> Self {
        Self {
            position: self.position.clone(),
            velocity: self.velocity.clone(),
        }
    }
}

impl Entity {
    pub fn new(x: f32, y: f32) -> Self {
        Self {
            position: Vec2f { x: x, y: y },
            velocity: Vec2f { x: 0.0, y: 0.0 },
        }
    }

    pub fn set_velocity_x(&mut self, x: f32) {
        self.velocity.x = x;
    }

    pub fn update(&mut self, delta: f32) {
        self.position.x += self.velocity.x * delta;
        self.position.y += self.velocity.y * delta;
    }

    pub fn draw(&mut self, d: &mut RaylibDrawHandle<'_>) {
        const SIZE: i32 = 32;
        d.draw_rectangle(
            self.position.x as i32 - SIZE / 2,
            self.position.y as i32 - SIZE / 2,
            SIZE,
            SIZE,
            color::Color::BLUE,
        );
    }
}
