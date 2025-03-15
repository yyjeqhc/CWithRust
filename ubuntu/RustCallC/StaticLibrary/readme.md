#### 首先是把add.cpp编译链接为静态库

```shel
g++ -c add.cpp -o add.o
ar rcs libadd.a add.o
详细：
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary# g++ -c add.cpp -o add.o
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary# ar rcs libadd.a add.o
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary# dir
add.cpp  add.o	libadd.a  rcall  readme.md

root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary# nm libadd.a 

add.o:
0000000000000000 T add
0000000000000018 T hello_world
                 U puts

```

#### 编译链接

```shell
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary# cp libadd.a rcall/
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary# cd rcall/
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# ls
Cargo.lock  Cargo.toml  libadd.a  src

cargo build --release
一切都结束了？没那么简单。
报错很奇怪。
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# cargo clean
     Removed 27 files, 3.4MiB total
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# cargo build --release
   Compiling libc v0.2.171
error: failed to run custom build command for `libc v0.2.171`

Caused by:
  could not execute process `/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/build/libc-7267a19d3e008163/build-script-build` (never executed)

Caused by:
  Invalid argument (os error 22)
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# ls

然后使用cargo build --release --verbose看看详细的
Wl,--strip-debug" "-nodefaultlibs"
  = note: some arguments are omitted. use `--verbose` to show all linker arguments
  = note: /usr/bin/ld: cannot find -ladd: No such file or directory
          collect2: error: ld returned 1 exit status
          

error: could not compile `rcall` (bin "rcall") due to 1 previous error

Caused by:
  process didn't exit successfully: `/root/.rustup/toolchains/stable-x86_64-unknown-linux-gnu/bin/rustc --crate-name rcall --edition=2021 src/main.rs --error-format=json --json=diagnostic-rendered-ansi,artifacts,future-incompat --diagnostic-width=125 --crate-type bin --emit=dep-info,link -C opt-level=3 -C embed-bitcode=no --check-cfg 'cfg(docsrs,test)' --check-cfg 'cfg(feature, values())' -C metadata=384c8705096c722d -C extra-filename=-01deb3b79e587869 --out-dir /root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps -C strip=debuginfo -L dependency=/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps --extern libc=/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps/liblibc-ce68b811bfc09cd1.rlib` (exit status: 1)
说白了，就是需要指定这个库的位置
```

```shell
方法应该挺多的，就不一一尝试了。
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# export RUSTFLAGS="-L ."
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# cargo build --release
   Compiling libc v0.2.171
error: failed to run custom build command for `libc v0.2.171`

Caused by:
  could not execute process `/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/build/libc-0c39fd41dd870f86/build-script-build` (never executed)

Caused by:
  Invalid argument (os error 22)
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# cargo build --release --verbose
   Compiling libc v0.2.171
     Running `/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/build/libc-0c39fd41dd870f86/build-script-build`
     Running `/root/.rustup/toolchains/stable-x86_64-unknown-linux-gnu/bin/rustc --crate-name libc --edition=2021 /root/.cargo/registry/src/index.crates.io-1949cf8c6b5b557f/libc-0.2.171/src/lib.rs --error-format=json --json=diagnostic-rendered-ansi,artifacts,future-incompat --diagnostic-width=125 --crate-type lib --emit=dep-info,metadata,link -C opt-level=3 -C embed-bitcode=no --cfg 'feature="default"' --cfg 'feature="std"' --check-cfg 'cfg(docsrs,test)' --check-cfg 'cfg(feature, values("align", "const-extern-fn", "default", "extra_traits", "rustc-dep-of-std", "rustc-std-workspace-core", "std", "use_std"))' -C metadata=a47cb8329a2bccb5 -C extra-filename=-db9131617ec3f614 --out-dir /root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps -C strip=debuginfo -L dependency=/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps --cap-lints allow -L . --cfg freebsd11 --cfg libc_const_extern_fn --check-cfg 'cfg(emscripten_old_stat_abi)' --check-cfg 'cfg(espidf_time32)' --check-cfg 'cfg(freebsd10)' --check-cfg 'cfg(freebsd11)' --check-cfg 'cfg(freebsd12)' --check-cfg 'cfg(freebsd13)' --check-cfg 'cfg(freebsd14)' --check-cfg 'cfg(freebsd15)' --check-cfg 'cfg(libc_const_extern_fn)' --check-cfg 'cfg(libc_deny_warnings)' --check-cfg 'cfg(libc_thread_local)' --check-cfg 'cfg(libc_ctest)' --check-cfg 'cfg(linux_time_bits64)' --check-cfg 'cfg(target_os,values("switch","aix","ohos","hurd","rtems","visionos","nuttx","cygwin"))' --check-cfg 'cfg(target_env,values("illumos","wasi","aix","ohos"))' --check-cfg 'cfg(target_arch,values("loongarch64","mips32r6","mips64r6","csky"))'`
   Compiling rcall v0.1.0 (/root/share/ubuntu/RustCallC/StaticLibrary/rcall)
     Running `/root/.rustup/toolchains/stable-x86_64-unknown-linux-gnu/bin/rustc --crate-name rcall --edition=2021 src/main.rs --error-format=json --json=diagnostic-rendered-ansi,artifacts,future-incompat --diagnostic-width=125 --crate-type bin --emit=dep-info,link -C opt-level=3 -C embed-bitcode=no --check-cfg 'cfg(docsrs,test)' --check-cfg 'cfg(feature, values())' -C metadata=384c8705096c722d -C extra-filename=-9c8e12affdb386c6 --out-dir /root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps -C strip=debuginfo -L dependency=/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps --extern libc=/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/deps/liblibc-db9131617ec3f614.rlib -L .`
    Finished `release` profile [optimized] target(s) in 1.20s
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# ls
Cargo.lock  Cargo.toml  libadd.a  src  target
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall#
```

#### 不过这里挺奇怪的，设置环境变量以后，第一次还是报错，第二次却成功了。

##### 换了个shell窗口

```shell
cargo clean
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# export RUSTFLAGS="-L ."
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# cargo build --release
   Compiling libc v0.2.171
error: failed to run custom build command for `libc v0.2.171`

Caused by:
  could not execute process `/root/share/ubuntu/RustCallC/StaticLibrary/rcall/target/release/build/libc-0c39fd41dd870f86/build-script-build` (never executed)

Caused by:
  Invalid argument (os error 22)
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# cargo build --release
   Compiling libc v0.2.171
   Compiling rcall v0.1.0 (/root/share/ubuntu/RustCallC/StaticLibrary/rcall)
    Finished `release` profile [optimized] target(s) in 1.21s
root@yyjeqhc:~/share/ubuntu/RustCallC/StaticLibrary/rcall# 
```

#### 竟然还是一样的，需要build两次才成功
