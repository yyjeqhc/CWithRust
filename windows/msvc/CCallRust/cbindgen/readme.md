## 安装cbindgen

```shell
PS C:\Users\yyjeqhc\Desktop\test> cargo install cbindgen
    Updating crates.io index
warning: spurious network error (3 tries remaining): [35] SSL connect error (schannel: next InitializeSecurityContext failed: CRYPT_E_REVOCATION_OFFLINE (0x80092013))
warning: spurious network error (2 tries remaining): [35] SSL connect error (schannel: next InitializeSecurityContext failed: CRYPT_E_REVOCATION_OFFLINE (0x80092013))
warning: spurious network error (1 tries remaining): [35] SSL connect error (schannel: next InitializeSecurityContext failed: CRYPT_E_REVOCATION_OFFLINE (0x80092013))
error: failed to download from `https://static.crates.io/crates/cbindgen/0.28.0/download`

Caused by:
  [35] SSL connect error (schannel: next InitializeSecurityContext failed: CRYPT_E_REVOCATION_OFFLINE (0x80092013))
PS C:\Users\yyjeqhc\Desktop\test>
```

#### 很奇怪，浏览器访问网站也是异常

```xml
<Error>
<Code>AccessDenied</Code>
<Message>Access Denied</Message>
<RequestId>XX98ND4K1GM3R1RS</RequestId>
<HostId>IRtWMpwSl3teeQ9UXQiOzTnhnUEswyEWCMZUpKviD3cVJUdcGiQJ+KT7nr1hRPIXaO8NEhAyd6I=</HostId>
</Error>
```

#### 只能直接去crates.io下载源码然后编译安装了。

```shell
git clone https://github.com/mozilla/cbindgen
cd cbindgen
cargo install --path .
PS D:\Git\cbindgen> cbindgen --version
cbindgen 0.28.0
```



# 导出函数头符号

```shell
D:\Git\CWithRust\windows\msvc\CCallRust\cbindgen>cargo new add --lib
    Creating library `add` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

cd add 必须在cargo.toml同级目录

D:\Git\CWithRust\windows\msvc\CCallRust\cbindgen\add>cbindgen --output add.h

D:\Git\CWithRust\windows\msvc\CCallRust\cbindgen\add>dir
 驱动器 D 中的卷是 新加卷
 卷的序列号是 D6E9-7942

 D:\Git\CWithRust\windows\msvc\CCallRust\cbindgen\add 的目录

2025/03/15  18:36    <DIR>          .
2025/03/15  18:32    <DIR>          ..
2025/03/15  18:36               180 add.h
2025/03/15  18:36               147 Cargo.lock
2025/03/15  18:36               105 Cargo.toml
2025/03/15  18:32    <DIR>          src
               3 个文件            432 字节
               3 个目录 40,071,778,304 可用字节

在cargo.toml同级目录生成了add.h头文件

```

#### 然后就是生成静态库：

```shell
cargo build --release
```

然后就是编译链接了。

```shell
cl /EHsc msvc_add.cpp /link ./target/release/add.lib Ws2_32.lib Kernel32.lib Advapi32.lib ntdll.lib

D:\Git\CWithRust\windows\msvc\CCallRust\cbindgen\add>cl /EHsc msvc_add.cpp /link ./target/release/add.lib Ws2_32.lib Kernel32.lib Advapi32.lib ntdll.lib userenv.lib
用于 x64 的 Microsoft (R) C/C++ 优化编译器 19.41.34120 版
版权所有(C) Microsoft Corporation。保留所有权利。

msvc_add.cpp
Microsoft (R) Incremental Linker Version 14.41.34120.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:msvc_add.exe
./target/release/add.lib
Ws2_32.lib
Kernel32.lib
Advapi32.lib
ntdll.lib
userenv.lib
msvc_add.obj
```

#### 执行OK，复制到其他执行也OK
