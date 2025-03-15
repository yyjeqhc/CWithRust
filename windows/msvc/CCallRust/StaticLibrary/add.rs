
#[no_mangle] // 防止 Rust 修改函数名
pub extern "C" fn hello_world() {
    println!("Hello from Rust!");
}

#[no_mangle]
pub extern "C" fn add(a:i32,b:i32) ->i32 {
    a+b
}
