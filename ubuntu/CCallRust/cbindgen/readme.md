## 安装cbindgen

```shell
cargo install cbindgen
就会下载编译进行安装了，没啥问题
```

# 导出函数头符号

```shell
cargo new add --lib
    Creating library `add` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

cd add 必须在cargo.toml同级目录

 cbindgen --output add.h
```

#### 然后就是生成静态库：

```shell
cargo build --release
```

然后就是编译链接了。

```shell
oot@yyjeqhc:~/share/ubuntu/CCallRust/cbindgen/add#  cbindgen --output add.h
root@yyjeqhc:~/share/ubuntu/CCallRust/cbindgen/add# cargo build --release
   Compiling add v0.1.0 (/root/share/ubuntu/CCallRust/cbindgen/add)
    Finished `release` profile [optimized] target(s) in 0.91s
root@yyjeqhc:~/share/ubuntu/CCallRust/cbindgen/add# g++ gnu.cpp -L./target/release -ladd  -o gnu
root@yyjeqhc:~/share/ubuntu/CCallRust/cbindgen/add# ls
add.h  Cargo.lock  Cargo.toml  gnu  gnu.cpp  src  target
root@yyjeqhc:~/share/ubuntu/CCallRust/cbindgen/add# ./gnu
Result of add(10, 20): 30
Hello from Rust!
root@yyjeqhc:~/share/ubu
```

#### 执行OK，复制到其他执行也OK
