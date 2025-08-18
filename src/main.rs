use raylib::prelude::*;

fn raylib_test() {
    let (mut rl, thread) = raylib::init().size(640, 480).title("Hello, World").build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::WHITE);
        d.draw_text("Hello, world!", 12, 12, 20, Color::BLACK);
    }
}

use mun_runtime::Runtime;

fn main() -> Result<(), Error> {
    let lib_path = "./mun_test_project";
    let builder = Runtime::builder(lib_path);
    let mut runtime = unsafe { builder.finish() }.expect("Failed to spawn Runtime");
    loop {
        runtime.invoke("main", ());
        unsafe { runtime.update() };
    }
    Ok(())
}
