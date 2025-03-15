# 编译add.rs为动态库

```shell
root@yyjeqhc:~/share/ubuntu/CCallRust/LoadLibrary# ls
add.rs  gnu.cpp  readme.md
root@yyjeqhc:~/share/ubuntu/CCallRust/LoadLibrary# rustc --crate-type=dylib add.rs
root@yyjeqhc:~/share/ubuntu/CCallRust/LoadLibrary# ls
add.rs  gnu.cpp  libadd.so  readme.md

```

#### 生成了add.so，直接编译cpp进行调用即可

#### 编译执行：

```shell
root@yyjeqhc:~/share/ubuntu/CCallRust/LoadLibrary# g++ gnu.cpp -L./ -ladd -o main -Wl,-rpath=./
root@yyjeqhc:~/share/ubuntu/CCallRust/LoadLibrary# ./main
Result of add: 30
Hello from Rust!
```

##### 可见，以动态库的方式进行调用是非常容易的。
