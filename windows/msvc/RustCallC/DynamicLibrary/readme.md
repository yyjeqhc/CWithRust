### 编译add.cpp为动态库，这个很容易了。还是在cl.exe那个prompt

```shell
cl /LD add.cpp

D:\Git\CWithRust\windows\msvc\RustCallC\DynamicLibrary>cl /LD add.cpp
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

add.cpp
Microsoft (R) Incremental Linker Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:add.dll
/dll
/implib:add.lib
add.obj
  正在创建库 add.lib 和对象 add.exp

D:\Git\CWithRust\windows\msvc\RustCallC\DynamicLibrary>
```

#### 然后就是创建一个hello项目进行调用

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\DynamicLibrary>cargo new rcall
    Creating binary (application) `rcall` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

修改下cargo.toml，依赖libc这个crate
修改下main.rs
还需要把add.dll和add.lib移入cargo.toml同级目录
```

#### 这种方式依赖很大啊，两个文件都需要同时在，才能编译，但是运行的时候只需要能找到dll就好了。

