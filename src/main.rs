use raylib::prelude::*;
use rhai;
use std::env;
use std::fs;

use crate::entity::Entity;

mod entity;

type EntityUID = usize;

#[derive(Clone)]
struct Engine {
    entities: Vec<entity::Entity>,
}

impl Engine {
    fn new() -> Self {
        Self {
            entities: Vec::new(),
        }
    }

    fn instantiate_entity(&mut self) -> EntityUID {
        self.entities.push(Entity::new(0.0, 0.0).clone());
        return self.entities.len() - 1;
    }

    fn start(&mut self) {
        let (mut rl, thread) = raylib::init().size(640, 480).title("Hello, World").build();

        rl.set_target_fps(60);
        const DELTA: f32 = 1.0 / 60.0;
        while !rl.window_should_close() {
            for entity in &mut self.entities {
                entity.update(DELTA);
            }

            let mut d: RaylibDrawHandle<'_> = rl.begin_drawing(&thread);
            d.clear_background(Color::RAYWHITE);
            for entity in &mut self.entities {
                entity.draw(&mut d);
            }
        }
    }
}

fn main() {
    let mut engine = rhai::Engine::new();
    engine
        .register_type_with_name::<Engine>("vetche")
        .register_fn("start", Engine::start)
        .register_fn("new_entity", Engine::instantiate_entity);
    let mut scope = rhai::Scope::new();
    scope.push("vetche", Engine::new());

    let file_path = "./test_scripts/entity.rhai";

    println!("Reading .rhai script '{file_path}'");

    let script_contents =
        fs::read_to_string(file_path).expect("Should have been able to read the file");

    match engine.run_with_scope(&mut scope, script_contents.as_str()) {
        Ok(_) => println!("===== Success ====="),
        Err(e) => println!("{}", e),
    }
}
