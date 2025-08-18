// extends Entity

fn init() {
    set_pos_x(123);
    set_pos_y(123);
}

fn process(delta) {
    set_vel_x(100 * delta)
}