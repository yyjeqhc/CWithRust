extern crate libc;
use libc::c_int;

#[link(name = "add", kind = "dylib")] // 指定库名为 add.dll
unsafe extern {
    fn add(a: c_int, b: c_int) -> c_int;
    fn hello_world();
}

fn main() {
    unsafe {
        let result = add(10, 20);
        println!("The result is: {}", result);
        hello_world();
    }
}