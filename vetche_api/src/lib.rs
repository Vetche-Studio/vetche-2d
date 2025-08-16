use pyo3::prelude::*;

#[pyclass]
#[derive(Clone)]
pub struct Vec2 {
    #[pyo3(get, set)]
    pub x: i32,
    #[pyo3(get, set)]
    pub y: i32,
}

#[pymethods]
impl Vec2 {
    #[new]
    pub fn new(x: i32, y: i32) -> Self {
        return Self { x, y };
    }
}

#[pyclass(subclass)]
pub struct Object {
    #[pyo3(get)]
    pub name: String,
}

#[pymethods]
impl Object {
    #[new]
    pub fn new(name: String) -> Self {
        return Self { name };
    }

    pub fn print(&self) {
        println!("Hello, this is an object with name '{}'", self.name);
    }
}

#[pyclass(extends=Object)]
pub struct Node {
    #[pyo3(get, set)]
    pub position: Vec2,
}

#[pymethods]
impl Node {
    #[new]
    pub fn new(name: String, position: Vec2) -> (Self, Object) {
        let object = Object { name };
        let node = Self { position: position };

        return (node, object);
    }

    pub fn print<'py>(self_: PyRef<'py, Self>) {
        let position = self_.position.clone();
        let base = self_.into_super();

        println!(
            "Hello, this is an node with name '{}' and position ({},{})",
            base.name, position.x, position.y
        );
    }
}

/// This defines the actual python module to be imported.
#[pymodule]
pub fn vetche_api(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_class::<Vec2>()?;
    m.add_class::<Object>()?;
    m.add_class::<Node>()?;
    Ok(())
}
