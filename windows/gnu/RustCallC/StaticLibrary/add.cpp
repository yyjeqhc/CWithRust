#include<stdio.h>
extern "C" {
    __declspec(dllexport) int add(int a, int b) {
    return a + b;
}
    __declspec(dllexport) void hello_world() {
        printf("hello world!\n");
    }
}
