// add.cpp
#include <stdio.h>
#include "add.h"

__declspec(dllexport)  int add(int a, int b) {
    return a + b;
}

__declspec(dllexport)  void hello_world() {
    printf("Hello from C!\n");
}