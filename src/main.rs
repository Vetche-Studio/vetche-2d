use raylib::prelude::*;

fn raylib_test() {
    let (mut rl, thread) = raylib::init().size(640, 480).title("Hello, World").build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(Color::WHITE);
        d.draw_text("Hello, world!", 12, 12, 20, Color::BLACK);
    }
}

use vetche_api::vetche_api;
use pyo3::prelude::*;
use pyo3::types::PyList;

fn pyo3_test(path: &'static str) -> Result<(), Box<dyn std::error::Error>> {
    pyo3::append_to_inittab!(vetche_api);
    pyo3::prepare_freethreaded_python();
    Python::with_gil(|py| {
        let sys_path: Bound<PyList> = py.import("sys")?.getattr("path")?.extract()?;
        sys_path.insert(0, &path)?;
        println!("Import path is: {:?}", sys_path);
        let module = PyModule::import(py, "init")?;
        let _ = module.getattr("start")?.call0()?;
        Ok(())
    })
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    pyo3_test("./python_script_test/")
}
