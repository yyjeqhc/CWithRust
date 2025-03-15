#### 首先是把add.cpp编译为静态库

```shel
PS D:\Git\CWithRust\windows\gnu\RustCallC\bindgen_2> g++ -c .\add.cpp -o add.o
PS D:\Git\CWithRust\windows\gnu\RustCallC\bindgen_2> ar rcs libadd.a add.o
```

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



```shell
PS D:\Git\CWithRust\windows\gnu\RustCallC\bindgen_2> rustc radd.rs -L . -ladd
PS D:\Git\CWithRust\windows\gnu\RustCallC\bindgen_2> .\radd.exe
2 + 3 = 5
Hello from C!
```





