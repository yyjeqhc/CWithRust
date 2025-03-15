#### 首先是把add.cpp编译链接为静态库

```shel
g++ -c .\add.cpp -o add.o
ar rcs libadd.a add.o
详细：
PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary> dir


    目录: D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         2025/3/15     20:27                rcall
-a----         2025/3/15     18:51            199 add.cpp
-a----         2025/3/15     19:08            998 readme.md


PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary> g++ -c .\add.cpp -o add.o
PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary> ar rcs libadd.a add.o
PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary> dir


    目录: D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         2025/3/15     20:27                rcall
-a----         2025/3/15     18:51            199 add.cpp
-a----         2025/3/15     20:57           1062 add.o
-a----         2025/3/15     20:58           1218 ladd.a
-a----         2025/3/15     19:08            998 readme.md


PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary> nm libadd.a

add.o:
0000000000000000 b .bss
0000000000000000 d .data
0000000000000000 i .drectve
0000000000000000 p .pdata
0000000000000000 r .rdata
0000000000000000 r .rdata$zzz
0000000000000000 t .text
0000000000000000 r .xdata
0000000000000000 T add
0000000000000014 T hello_world
                 U puts
```

#### 编译链接

```shell
PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary\rcall> $env:RUSTFLAGS = "-L ."
PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary\rcall> cargo build --release 
warning: unused manifest key: build
   Compiling libc v0.2.171
   Compiling rcall v0.1.0 (D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary\rcall)
    Finished `release` profile [optimized] target(s) in 0.64s
PS D:\Git\CWithRust\windows\gnu\RustCallC\StaticLibrary\rcall>

这是在powershell里面的,AI提示还有好几种方法，就不一一尝试了。
```

