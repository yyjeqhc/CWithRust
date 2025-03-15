#include <iostream>
#include <dlfcn.h>  // Linux 动态库加载 API

typedef int (*AddFunction)(int, int);     // 定义函数指针类型
typedef void (*HelloWorldFunction)();     // 定义函数指针类型

int main() {
    // 加载共享库（Linux 下是 .so）
    void* handle = dlopen("./libadd.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load shared library: " << dlerror() << std::endl;
        return 1;
    }

    // 获取函数地址
    AddFunction add = (AddFunction)dlsym(handle, "add");
    HelloWorldFunction hello_world = (HelloWorldFunction)dlsym(handle, "hello_world");

    // 检查是否成功加载函数
    const char* error = dlerror();
    if (error != NULL) {
        std::cerr << "Failed to get function address: " << error << std::endl;
        dlclose(handle);
        return 1;
    }

    // 调用 add 函数
    int result = add(10, 20);
    std::cout << "Result of add: " << result << std::endl;

    // 调用 hello_world 函数
    hello_world();

    // 关闭动态库
    dlclose(handle);
    return 0;
}
