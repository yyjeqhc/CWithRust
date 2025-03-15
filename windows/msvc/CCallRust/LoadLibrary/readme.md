# 编译add.rs为动态库

```shell
rustc --crate-type=dylib add.rs
PS D:\Git\CWithRust\windows\msvc\CCallRust\LoadLibrary> ls


    目录: D:\Git\CWithRust\windows\msvc\CCallRust\LoadLibrary


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----         2025/3/15     16:53         874496 add.dll
-a----         2025/3/15     16:53         516593 add.dll.exp
-a----         2025/3/15     16:53         850430 add.dll.lib
-a----         2025/3/15     16:53        3837952 add.pdb
-a----         2025/3/15     16:51            190 add.rs
-a----         2025/3/15     16:52           1024 msvc_loadlibrary.cpp
-a----         2025/3/15     16:52              0 readme.md

```

#### 生成了add.dll，直接编译cpp进行调用即可

#### 需要注意的是，要使用msvc的专属prompt打开

![image-20250315165708864](readme/image-20250315165708864.png)

#### 编译执行：

```shell
cl msvc_loadlibrary.cpp
msvc_loadlibrary.exe
下为详细记录：
D:\Git\CWithRust\windows\msvc\CCallRust\LoadLibrary>cl msvc_loadlibrary.cpp
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

msvc_loadlibrary.cpp
C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\include\ostream(298): warning C4530:  使用了 C++ 异常处理程序，但未启用展开语义。请指定 /EHsc
C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\include\ostream(298): note: 模板实例化上下文(最早的实例化上下文)为
msvc_loadlibrary.cpp(11): note: 查看对正在编译的 类 模板 实例化“std::basic_ostream<char,std::char_traits<char>>”的引用
C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\include\ostream(283): note: 在编译 类 模板 成员函数“std::basic_ostream<char,std::char_traits<char>> &std::basic_ostream<char,std::char_traits<char>>::operator <<(int)”时
msvc_loadlibrary.cpp(27): note: 请参阅 "main" 中对 "std::basic_ostream<char,std::char_traits<char>>::operator <<" 的第一个引用
Microsoft (R) Incremental Linker Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:msvc_loadlibrary.exe
msvc_loadlibrary.obj

D:\Git\CWithRust\windows\msvc\CCallRust\LoadLibrary>msvc_loadlibrary.exe
Result of add: 30
Hello from Rust!

D:\Git\CWithRust\windows\msvc\CCallRust\LoadLibrary>
```

##### 可见，以动态库的方式进行调用是非常容易的。

#### 调用很容易，但是操作却麻烦，需要自己定义函数指针，首先就需要自己查看dll导出信息

#### 要查看的话，直接在cl那个prompt使用dumpbin /exports add.dll即可。注意：输出很多，而且只有个函数名称，没有函数头

##### 这种方式，就需要dll和exe在能加载到的地方（这个概念就不详细说明了），最简单的反面例子就是你把dll移开，就会加载失败了。