## 编译rust为静态库

```shell
rustc --crate-type=staticlib add.rs
D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary>rustc --crate-type=staticlib add.rs

PS D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary>  dir


    目录: D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----         2025/3/15     17:58            192 add.rs
-a----         2025/3/15     17:02            310 gnu_add.cpp
-a----         2025/3/15     20:28       16144380 libadd.a
-a----         2025/3/15     20:28          10168 readme.md
```

### 生成了add.lib，下面编译链接gnu_add.cpp

```shell
PS D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary> rustc --crate-type=staticlib add.rs
PS D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary> g++ gnu_add.cpp -L. -ladd -lws2_32 -luserenv -lntdll -o gnu_add.exe
PS D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary> .\gnu_add.exe
Result of add(10, 20): 30
Hello from Rust!
PS D:\Git\CWithRust\windows\gnu\CCallRust\StaticLibrary>
这些库和msvc编译的时候很像，不加就会出现大堆错误，这些就是编译器平时帮我们自动完成的事情。
```

#### 然后就愉快的生成了gnu_add.exe，可以进行运行了。

#### 因为是静态链接，所以把exe复制到其他目录下也可以正常执行。
