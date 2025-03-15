### 编译add.cpp为动态库，这个很容易了。

```shell
g++ -shared -o add.dll add.cpp
```

#### 然后就是创建一个hello项目进行调用

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\DynamicLibrary>cargo new rcall
    Creating binary (application) `rcall` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

修改下cargo.toml，依赖libc这个crate
修改下main.rs
还需要把add.dllcargo.toml同级目录
然后还要设置环境
PS D:\Git\CWithRust\windows\gnu\RustCallC\DynamicLibrary\rcall> $env:RUSTFLAGS = "-L ."
PS D:\Git\CWithRust\windows\gnu\RustCallC\DynamicLibrary\rcall> cargo build --release
   Compiling libc v0.2.171
   Compiling rcall v0.1.0 (D:\Git\CWithRust\windows\gnu\RustCallC\DynamicLibrary\rcall)
    Finished `release` profile [optimized] target(s) in 0.86s
```

#### 还是需要手动指定库的位置，可以尝试其他方式

#### 貌似编译的时候需要把dll库命名为libadd.dll，但是编译以后运行，复制过去，还是要改名为add.dll
