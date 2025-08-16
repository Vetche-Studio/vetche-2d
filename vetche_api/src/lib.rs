use pyo3::prelude::*;

#[pyclass]
pub struct Object {

}

#[pymethods]
impl Object {
    #[new]
    pub fn new() -> Self {
        Self{}
    }

    pub fn print(&self) {
        println!("Hello, this is an object: {:p}", self);
    }
}

/// This defines the actual python module to be imported.
#[pymodule]
pub fn vetche_api(m: &Bound<'_, PyModule>) -> PyResult<()> {
    m.add_class::<Object>()?;
    Ok(())
}