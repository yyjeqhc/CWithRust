#include <iostream>
#include <windows.h>

typedef int (*AddFunction)(int, int);  // 定义函数指针类型
typedef void (*HelloWorldFunction)();  // 定义函数指针类型

int main() {
    // 加载 DLL
    HMODULE hModule = LoadLibrary("add.dll");
    if (hModule == NULL) {
        std::cerr << "Failed to load DLL!" << std::endl;
        return 1;
    }

    // 获取函数地址
    AddFunction add = (AddFunction)GetProcAddress(hModule, "add");
    HelloWorldFunction hello_world = (HelloWorldFunction)GetProcAddress(hModule, "hello_world");

    // 检查函数地址是否有效
    if (add == NULL || hello_world == NULL) {
        std::cerr << "Failed to get function address!" << std::endl;
        FreeLibrary(hModule);
        return 1;
    }
    // 调用 add 函数
    int result = add(10, 20);
    std::cout << "Result of add: " << result << std::endl;

    // 调用 hello_world 函数
    hello_world();

    // 卸载 DLL
    FreeLibrary(hModule);
    return 0;
}
