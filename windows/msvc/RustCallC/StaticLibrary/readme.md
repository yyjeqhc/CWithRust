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
D:\Git\CWithRust\windows\msvc\RustCallC\StaticLibrary>cl /c add.cpp
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

add.cpp

D:\Git\CWithRust\windows\msvc\RustCallC\StaticLibrary>lib add.obj
Microsoft (R) Library Manager Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.


然后就生成了add.lib,非常的小巧，只有4kb，还是把它移入cargo.toml同级目录
然后cargo build --release 直接生成exe，运行即可。
```

