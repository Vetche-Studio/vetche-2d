use raylib::prelude::*;

pub struct Vec2<T> {
    pub x: T,
    pub y: T,
}

type Vec2f = Vec2<f32>;

pub struct Entity {
    pub position: Vec2f,
    pub velocity: Vec2f
}

impl Entity {
    pub fn new(x: f32, y: f32) -> Self {
        Self {
            position: Vec2f{x: x, y: y},
            velocity: Vec2f{x: 0.0, y: 0.0},
        }
    }

    pub fn update(&mut self, delta: f32) {
        self.position.x += self.velocity.x * delta;
        self.position.y += self.velocity.y * delta;   
    }

    pub fn draw(&self, d: &mut RaylibDrawHandle<'_>) {
        d.draw_rectangle(
            self.position.x as i32, 
            self.position.y as i32, 
            32, 
            32, 
            color::Color::BLUE,
        );
    }
}