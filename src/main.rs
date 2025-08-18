use raylib::prelude::*;
use rhai;

mod entity;


fn set_vel_x(x: f32) {

}

fn main() {
    let mut engine = rhai::Engine::new();

    engine.register_fn("set_vel_x",set_vel_x);
    let mut e = entity::Entity::new(100.0, 200.0);

    let (mut rl, thread) = raylib::init().size(640, 480).title("Hello, World").build();

    rl.set_target_fps(60);

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);
        d.clear_background(Color::RAYWHITE);
        e.update(1.0 / 60.0);
        e.draw(&mut d);
    }
}
