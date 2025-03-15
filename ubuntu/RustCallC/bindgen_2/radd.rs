mod bindings {
    include!("add.rs");
}

fn main() {
    unsafe {
        println!("2 + 3 = {}", bindings::add(2, 3));
        bindings::hello_world();
    }
}
