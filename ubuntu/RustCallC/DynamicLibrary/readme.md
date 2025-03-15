### 编译add.cpp为动态库，这个很容易了。

```shell
g++ -fPIC -shared -o libadd.so add.cpp
```

#### 然后就是创建一个hello项目进行调用

```shell
cargo new rcall
    Creating binary (application) `rcall` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

修改下cargo.toml，依赖libc这个crate
修改下main.rs
还需要把libadd.so 复制到cargo.toml同级目录
然后还要设置环境
ls
Cargo.lock  Cargo.toml  libadd.so  src
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall# export RUSTFLAGS="-L ."
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall# cargo build --release
   Compiling libc v0.2.171
error: failed to run custom build command for `libc v0.2.171`

Caused by:
  could not execute process `/root/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release/build/libc-0c39fd41dd870f86/build-script-build` (never executed)

Caused by:
  Invalid argument (os error 22)
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall# cargo build --release
   Compiling libc v0.2.171
   Compiling rcall v0.1.0 (/root/share/ubuntu/RustCallC/DynamicLibrary/rcall)
    Finished `release` profile [optimized] target(s) in 1.20s
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall# 
```

#### 很奇怪，和静态库是一样的。

#### 运行要稍微麻烦些

```shell
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# ./rcall
./rcall: error while loading shared libraries: libadd.so: cannot open shared object file: No such file or directory
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# ls
build  deps  examples  incremental  libadd.so  rcall  rcall.d
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# ./rcall
./rcall: error while loading shared libraries: libadd.so: cannot open shared object file: No such file or directory
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# 

还是需要设置一个环境变量
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# export LD_LIBRARY_PATH=./:$LD_LIBRARY_PATH
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# ls
build  deps  examples  incremental  libadd.so  rcall  rcall.d
root@yyjeqhc:~/share/ubuntu/RustCallC/DynamicLibrary/rcall/target/release# ./rcall
The result is: 30
hello world!

```

