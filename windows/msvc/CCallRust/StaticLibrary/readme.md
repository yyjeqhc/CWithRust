## 编译rust为静态库

```shell
rustc --crate-type=staticlib add.rs
D:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary>rustc --crate-type=staticlib add.rs

D:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary>dir
 驱动器 D 中的卷是 新加卷
 卷的序列号是 D6E9-7942
 D:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary 的目录

2025/03/15  17:04    <DIR>          .
2025/03/15  17:00    <DIR>          ..
2025/03/15  17:04        13,442,610 add.lib
2025/03/15  16:51               190 add.rs
2025/03/15  17:02               310 msvc_add.cpp
2025/03/15  17:03                 0 readme.md
               4 个文件     13,443,110 字节
               2 个目录 40,224,387,072 可用字节

D:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary>
```

### 生成了add.lib，下面编译链接msvc_add.cpp

```shell
D:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary>cl /c /EHsc msvc_add.cpp /link add.lib
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

msvc_add.cpp
msvc_add.cpp(1): warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
只编译不链接，倒是生成了msvc_add.lib，而没有可执行文件。

D:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary>cl  /EHsc msvc_add.cpp /link add.lib
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

msvc_add.cpp
msvc_add.cpp(1): warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
Microsoft (R) Incremental Linker Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:msvc_add.exe
add.lib
msvc_add.obj
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSAStartup，函数 _ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h4560ca3b0b53e332E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSACleanup，函数 _ZN4core3ops8function6FnOnce40call_once$u7b$$u7b$vtable.shim$u7d$$u7d$17h4560ca3b0b53e332E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_GetUserProfileDirectoryW，函数 _ZN3std3env8home_dir17ha461b0894b29ac8bE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_NtReadFile，函数 _ZN3std2io19default_read_to_end17hb9ee048f4072ce26E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_RtlNtStatusToDosError，函数 _ZN3std2io19default_read_to_end17hb9ee048f4072ce26E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_freeaddrinfo，函数 _ZN3std3net11socket_addr19resolve_socket_addr17h1ed1d756b3ce9fc6E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_closesocket， 函数 _ZN3std3net3tcp9TcpStream15connect_timeout17h4699b0b144a72632E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_shutdown，函数 _ZN3std3net3tcp9TcpStream8shutdown17h04e746fe961b919aE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSAGetLastError，函数 _ZN3std3net3tcp9TcpStream8shutdown17h04e746fe961b919aE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_setsockopt，函数 _ZN3std3net3udp9UdpSocket16set_read_timeout17h4519b30dcadc862cE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_getsockopt，函数 _ZN3std3net3udp9UdpSocket12read_timeout17h49fbe8af5fe91739E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_recv，函数 _ZN3std3net3udp9UdpSocket4peek17h0f02a1ab632159e6E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSARecv，函数 _ZN58_$LT$std..net..tcp..TcpStream$u20$as$u20$std..io..Read$GT$13read_vectored17h62e9a6ed9bd1f4ceE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSASend，函数 _ZN59_$LT$std..net..tcp..TcpStream$u20$as$u20$std..io..Write$GT$14write_vectored17h4ac84d98946066afE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_send，函数 _ZN63_$LT$$RF$std..net..tcp..TcpStream$u20$as$u20$std..io..Write$GT$5write17h922aff7a46160ba8E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_accept，函数 _ZN3std3net3tcp11TcpListener6accept17h7025bb823d4d4cefE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_ioctlsocket， 函数 _ZN3std3net3udp9UdpSocket15set_nonblocking17h31f5d18171419efbE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_getpeername， 函数 _ZN3std3net3udp9UdpSocket9peer_addr17h173feefed1524730E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSADuplicateSocketW，函数 _ZN3std2os7windows2io6socket14BorrowedSocket18try_clone_to_owned17hf8718d2e9479a0a5E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_WSASocketW，函数 _ZN3std2os7windows2io6socket14BorrowedSocket18try_clone_to_owned17hf8718d2e9479a0a5E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_getaddrinfo， 函数 _ZN3std3sys3pal6common14small_c_string24run_with_cstr_allocating17hccd29e0a460b28faE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_NtOpenFile，函数 _ZN3std3sys3pal7windows2fs14remove_dir_all20open_link_no_reparse17h087427ec732a5185E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_NtWriteFile， 函数 _ZN3std3sys3pal7windows6handle6Handle17synchronous_write17hb600c9b2cba92bf0E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_connect，函数 _ZN3std3sys3pal7windows3net6Socket7connect17h4a7bd1713ae48a3cE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_select，函数 _ZN3std3sys3pal7windows3net6Socket15connect_timeout17hde08b0cdfcc139fcE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_recvfrom，函数 _ZN3std3sys3pal7windows3net6Socket20recv_from_with_flags17h848944c56872e01bE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_bind，函数 _ZN3std10sys_common3net11TcpListener4bind17h34bd4ed4b11ac4fcE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_listen，函数 _ZN3std10sys_common3net11TcpListener4bind17h34bd4ed4b11ac4fcE 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_getsockname， 函数 _ZN3std10sys_common3net11TcpListener11socket_addr17ha1e85c233a5b2704E 中引用了该符号
add.lib(std-99a5467416e27682.std.791127b64b61979d-cgu.0.rcgu.o) : error LNK2019: 无法解析的外部符号 __imp_sendto，函数 _ZN3std10sys_common3net9UdpSocket7send_to17h3f87b4e3d7d09d8cE 中引用了该符号
msvc_add.exe : fatal error LNK1120: 30 个无法解析的外部命令

想链接的话去掉/c就麻烦了，一大堆错误
```

#### 不知道注意到没有，生成的lib和动态库相比，体积显著增加，竟然有13M，该不会整个标准库都在其中吧，所以链接的时候缺少一些系统库。

#### 省略解决过程，直接给出解决方案：

```shell
cl /EHsc msvc_add.cpp /link add.lib Ws2_32.lib Kernel32.lib Advapi32.lib ntdll.lib userenv.lib

:\Git\CWithRust\windows\msvc\CCallRust\StaticLibrary>cl /EHsc msvc_add.cpp /link add.lib Ws2_32.lib Kernel32.lib Advapi32.lib ntdll.lib userenv.lib
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

msvc_add.cpp
msvc_add.cpp(1): warning C4819: 该文件包含不能在当前代码页(936)中表示的字符。请将该文件保存为 Unicode 格式以防止数据丢失
Microsoft (R) Incremental Linker Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:msvc_add.exe
add.lib
Ws2_32.lib
Kernel32.lib
Advapi32.lib
ntdll.lib
userenv.lib
msvc_add.obj
```

#### 然后就愉快的生成了msvc_add.exe，可以进行运行了。

#### 因为是静态链接，所以把exe复制到其他目录下也可以正常执行。
