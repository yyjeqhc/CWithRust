### 注意：windows下安装的rust默认是msvc的，所以需要再安装gnu版本的。

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>rustup show
Default host: x86_64-pc-windows-msvc
rustup home:  C:\Users\yyjeqhc\.rustup

installed toolchains
--------------------

stable-x86_64-pc-windows-msvc
nightly-x86_64-pc-windows-msvc (default)

installed targets for active toolchain
--------------------------------------

aarch64-pc-windows-msvc
aarch64-unknown-linux-gnu
wasm32-unknown-unknown
x86_64-pc-windows-gnu
x86_64-pc-windows-msvc

active toolchain
----------------

nightly-x86_64-pc-windows-msvc (default)
rustc 1.87.0-nightly (f04bbc60f 2025-02-20)

rustup toolchain install stable-x86_64-pc-windows-gnu 
会进行安装，然后切换即可
D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>rustup default stable-x86_64-pc-windows-gnu
info: using existing install for 'stable-x86_64-pc-windows-gnu'
info: default toolchain set to 'stable-x86_64-pc-windows-gnu'

  stable-x86_64-pc-windows-gnu unchanged - rustc 1.85.0 (4d91de4e4 2025-02-17)
```
## 现在，我的环境都是切换过去到gnu的，rustc切换过去，gcc则是打开普通的控制台使用msys2那一套
