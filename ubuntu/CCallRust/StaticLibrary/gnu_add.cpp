#include <iostream>
// 声明 add 函数的类型
extern "C" int add(int a, int b);
extern "C" void hello_world();
int main() {
    // 调用 Rust 中的 add 函数
    int result = add(10, 20);
    std::cout << "Result of add(10, 20): " << result << std::endl;
    hello_world();
    return 0;
}

