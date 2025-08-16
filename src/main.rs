use raylib::prelude::*;

fn raylib_test() {
    let (mut rl, thread) = raylib::init().size(640, 480).title("Hello, World").build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::WHITE);
        d.draw_text("Hello, world!", 12, 12, 20, Color::BLACK);
    }
}

use engine::engine;
use pyo3::prelude::*;
use pyo3::types::PyList;

fn pyo3_test() -> Result<(), Box<dyn std::error::Error>> {
    pyo3::append_to_inittab!(engine);
    pyo3::prepare_freethreaded_python();
    let path = "./engine_py/";
    Python::with_gil(|py| {
        let syspath: Bound<PyList> = py.import("sys")?.getattr("path")?.extract()?;
        syspath.insert(0, &path)?;
        println!("Import path is: {:?}", syspath);
        let engine_module = PyModule::import(py, "init")?;
        let _ = engine_module.getattr("start")?.call0()?;
        Ok(())
    })
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    pyo3_test()
}
