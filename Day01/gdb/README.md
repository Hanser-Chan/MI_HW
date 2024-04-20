# gdb

## 编写一个有bug的cpp

```cpp
#include <iostream>

// 第三层调用，触发段错误
void triggerFault()
{
    int *ptr = nullptr; // 定义一个空指针
    *ptr = 10;          // 尝试写入空指针，将导致段错误
}

// 第二层调用
void callFault()
{
    triggerFault();
}

// 第一层调用
void startFault()
{
    callFault();
}

int main()
{
    startFault(); // 开始错误触发链
    return 0;
}

```



## 使用g++

```shell
$g++ -g main.cpp -o ptr
```

这里可以看到生成的编译文件，但是出现了一个很严重的问题

## 🤔无法找到core

![dSYM.png](https://img2.imgtp.com/2024/04/20/47bFmSv7.png)
图中可见生成了编译文件和**macOS提供的*.dSYM***文件，但是并未找到相关core文件，这个也是我和同学们发现的一个非常奇怪的问题，他们也找不到core文件，他们的Ubantu只能生成前两个文件。

## 找到了.yml文件

但是打开mac提供的**.dSYM**文件(显示包内容)，可以找到一个**ptr.yml**文件，文件中显示如下

```yaml
---
triple:          'x86_64-apple-darwin'
binary-path:     ptr
relocations:
  - { offsetInCU: 0x26, offset: 0x26, size: 0x8, addend: 0x0, symName: __Z12triggerFaultv, symObjAddr: 0x0, symBinAddr: 0x100000F40, symSize: 0x20 }
  - { offsetInCU: 0x2E05, offset: 0x2E05, size: 0x8, addend: 0x0, symName: __Z12triggerFaultv, symObjAddr: 0x0, symBinAddr: 0x100000F40, symSize: 0x20 }
  - { offsetInCU: 0x2E2D, offset: 0x2E2D, size: 0x8, addend: 0x0, symName: __Z9callFaultv, symObjAddr: 0x20, symBinAddr: 0x100000F60, symSize: 0x10 }
  - { offsetInCU: 0x2E46, offset: 0x2E46, size: 0x8, addend: 0x0, symName: __Z10startFaultv, symObjAddr: 0x30, symBinAddr: 0x100000F70, symSize: 0x10 }
  - { offsetInCU: 0x2E5F, offset: 0x2E5F, size: 0x8, addend: 0x0, symName: _main, symObjAddr: 0x40, symBinAddr: 0x100000F80, symSize: 0x1C }
...
```

猜测这就是这个代码的内存使用信息，已将这串信息添加到bt.txt中。

