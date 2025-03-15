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
D:\Git\CWithRust\windows\gnu\CCallRust\cbindgen>cargo new add --lib
    Creating library `add` package
note: see more `Cargo.toml` keys and their definitions at https://doc.rust-lang.org/cargo/reference/manifest.html

cd add 必须在cargo.toml同级目录

PS D:\Git\CWithRust\windows\gnu\CCallRust\cbindgen\add> cbindgen --output add.h
PS D:\Git\CWithRust\windows\gnu\CCallRust\cbindgen\add> dir


    目录: D:\Git\CWithRust\windows\gnu\CCallRust\cbindgen\add


Mode                 LastWriteTime         Length Name
----                 -------------         ------ ----
d-----         2025/3/15     20:27                src
-a----         2025/3/15     20:44            180 add.h
-a----         2025/3/15     18:36            147 Cargo.lock
-a----         2025/3/15     18:40            105 Cargo.toml
-a----         2025/3/15     18:42            227 gnu.cpp

```

#### 然后就是生成静态库：

```shell
cargo build --release
```

然后就是编译链接了。

```shell
PS D:\Git\CWithRust\windows\gnu\CCallRust\cbindgen\add> g++ gnu.cpp -L./target/release -ladd -lws2_32 -luserenv -lntdll -o gnu.exe
PS D:\Git\CWithRust\windows\gnu\CCallRust\cbindgen\add> .\gnu.exe
Result of add(10, 20): 30
Hello from Rust!
```

#### 执行OK，复制到其他执行也OK
