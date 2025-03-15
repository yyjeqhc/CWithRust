#### 首先是把add.cpp编译为静态库，这一步需要分为编译和链接两条指令

```shel
如何生成msvc格式的静态库，可以看微软官方的资料，里面有详细解释
https://learn.microsoft.com/zh-cn/cpp/build/walkthrough-creating-and-using-a-static-library-cpp?view=msvc-170
cl /c add.cpp (编译)
lib add.obj (链接)
也就是编译和链接要分成两步操作
```

过程：

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>cl /c add.cpp
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

add.cpp

D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>lib add.obj
Microsoft (R) Library Manager Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.
然后就生成了add.lib,非常的小巧，只有4kb
```

#### 然后就是安装bindgen了。高版本以后，只能安装bindgen-cli了

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>cargo install bindgen
    Updating crates.io index
error: there is nothing to install in `bindgen v0.71.1`, because it has no binaries
`cargo install` is only for installing programs, and can't be used with libraries.
To use a library crate, add it as a dependency to a Cargo project with `cargo add`.
cargo install bindgen-cli，然后就会下载源码进行编译安装了。

D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>bindgen --version
bindgen 0.71.1

```

#### 然后就是使用它来生成rust的绑定了

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>bindgen add.cpp -o bindings.rs

thread 'main' panicked at C:\Users\yyjeqhc\.cargo\registry\src\index.crates.io-1949cf8c6b5b557f\bindgen-0.71.1\lib.rs:604:27:
Unable to find libclang: "couldn't find any valid shared libraries matching: ['clang.dll', 'libclang.dll'], set the `LIBCLANG_PATH` environment variable to a path where one of these files can be found (invalid: [])"
note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```

#### 哦，还需要安装LLVM

```shell
https://releases.llvm.org/
安装以后，还要配置环境变量并重新打开cli的prompt
```

#### 然后就是使用它来生成rust的绑定了

```shell
D:\Git\CWithRust\windows\msvc\RustCallC\bindgen>bindgen  add.cpp  -o bindings.rs
就运行结束了，一看，多了个27KB的rs文件，也太大了。
原来是因为展开了#include<stdio.h>
```

#### 不过不影响使用，直接使用rustc进行编译链接吧。

```shell
rustc radd.rs -L . -ladd
```

#### ^_^,我以为这种写法只适合linux呢，试一试，能然能用。



#### 还是把add.cpp函数头定义在h，函数写在cpp的好。

就是这样：add.h

```c++
// add.h
#ifndef ADD_H
#define ADD_H

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) int add(int a, int b);
__declspec(dllexport) void hello_world();

#ifdef __cplusplus
}
#endif

#endif // ADD_H
```

add.cpp

```c++
// add.cpp
#include <stdio.h>
#include "add.h"

int add(int a, int b) {
    return a + b;
}

void hello_world() {
    printf("Hello from C!\n");
}
```

#### 再使用bindgen

```shell
bindgen add.h -o add.rs
```

#### 这样，生成的rust绑定就很小了。

#### 还是编译链接生成add.lib

```shell
C:\Users\yyjeqhc\Desktop\test\t>cl /c add.cpp
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

add.cpp

C:\Users\yyjeqhc\Desktop\test\t>lib add.obj
Microsoft (R) Library Manager Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.
C:\Users\yyjeqhc\Desktop\test\t>rustc radd.rs -L . -ladd

C:\Users\yyjeqhc\Desktop\test\t>radd.exe
2 + 3 = 5
Hello from C!

C:\Users\yyjeqhc\Desktop\test\t>
```





