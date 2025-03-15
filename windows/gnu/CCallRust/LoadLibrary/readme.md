# 编译add.rs为动态库

```shell
rustc --crate-type=dylib add.rs
PS D:\Git\CWithRust\windows\gnu\CCallRust\LoadLibrary> rustc --crate-type=dylib add.rs
PS D:\Git\CWithRust\windows\gnu\CCallRust\LoadLibrary> dir


    目录: D:\Git\CWithRust\windows\gnu\CCallRust\LoadLibrary


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
-a----         2025/3/15     20:39        6554785 add.dll
-a----         2025/3/15     16:51            190 add.rs
-a----         2025/3/15     16:52           1024 gnu.cpp
-a----         2025/3/15     20:39        2002032 libadd.dll.a
-a----         2025/3/15     20:39           3079 readme.md

```

#### 生成了add.dll，直接编译cpp进行调用即可



#### 编译执行：

```shell
PS D:\Git\CWithRust\windows\gnu\CCallRust\LoadLibrary> g++ .\gnu.cpp -o gnu.exe
PS D:\Git\CWithRust\windows\gnu\CCallRust\LoadLibrary> ./gnu.exe
Result of add: 30
Hello from Rust!
```

##### 可见，以动态库的方式进行调用是非常容易的。

#### 调用很容易，但是操作却麻烦，需要自己定义函数指针，首先就需要自己查看dll导出信息

#### 要查看的话，直接在cl那个prompt使用dumpbin /exports add.dll即可。注意：输出很多，而且只有个函数名称，没有函数头

##### 这种方式，就需要dll和exe在能加载到的地方（这个概念就不详细说明了），最简单的反面例子就是你把dll移开，就会加载失败了。