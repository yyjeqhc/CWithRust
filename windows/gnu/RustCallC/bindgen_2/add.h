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