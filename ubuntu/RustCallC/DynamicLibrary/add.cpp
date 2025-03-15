#include<stdio.h>
extern "C" {
    int add(int a, int b) {
    return a + b;
}
    void hello_world() {
        printf("hello world!\n");
    }
}
