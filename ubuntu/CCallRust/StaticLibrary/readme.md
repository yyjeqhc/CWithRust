## 编译rust为静态库

```shell
rustc --crate-type=staticlib add.rs
root@yyjeqhc:~/share/ubuntu/CCallRust/StaticLibrary# rustc --crate-type=staticlib add.rs
root@yyjeqhc:~/share/ubuntu/CCallRust/StaticLibrary# ls
add.rs  gnu_add.cpp  libadd.a  readme.md
root@yyjeqhc:~/share/ubuntu/CCallRust/StaticLibrary# 
```

### 生成了add.lib，下面编译链接gnu_add.cpp

```shell
root@yyjeqhc:~/share/ubuntu/CCallRust/StaticLibrary# g++ gnu_add.cpp -L. -ladd -o gnu_add
root@yyjeqhc:~/share/ubuntu/CCallRust/StaticLibrary# ls
add.rs  gnu_add  gnu_add.cpp  libadd.a  readme.md
root@yyjeqhc:~/share/ubuntu/CCallRust/StaticLibrary# ./gnu_add
Result of add(10, 20): 30
Hello from Rust!
```

#### 
