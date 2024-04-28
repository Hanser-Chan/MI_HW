# Valgrind 检测 C++ 



## 内存泄漏

下面是一个正常的 C++ 程序，没有发生内存泄漏：

```
#include <string>

int main()
{
    auto ptr = new std::string("Hello, World!");
    delete ptr;

    return 0;
}
```



　　使用 Valgrind 分析这段程序：

```
$ valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./main_cpp
==31438== Memcheck, a memory error detector
==31438== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31438== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31438== Command: ./main_cpp
==31438==
==31438==
==31438== HEAP SUMMARY:
==31438==     in use at exit: 72,704 bytes in 1 blocks
==31438==   total heap usage: 2 allocs, 1 frees, 72,736 bytes allocated
==31438==
==31438== 72,704 bytes in 1 blocks are still reachable in loss record 1 of 1
==31438==    at 0x4C2DBF6: malloc (vg_replace_malloc.c:299)
==31438==    by 0x4EC3EFF: ??? (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)
==31438==    by 0x40104E9: call_init.part.0 (dl-init.c:72)
==31438==    by 0x40105FA: call_init (dl-init.c:30)
==31438==    by 0x40105FA: _dl_init (dl-init.c:120)
==31438==    by 0x4000CF9: ??? (in /lib/x86_64-linux-gnu/ld-2.23.so)
==31438==
==31438== LEAK SUMMARY:
==31438==    definitely lost: 0 bytes in 0 blocks
==31438==    indirectly lost: 0 bytes in 0 blocks
==31438==      possibly lost: 0 bytes in 0 blocks
==31438==    still reachable: 72,704 bytes in 1 blocks
==31438==         suppressed: 0 bytes in 0 blocks
==31438==
==31438== For counts of detected and suppressed errors, rerun with: -v
==31438== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```



　　使用 Valgrind 分析 C++ 程序时，有一些问题需要留意。例如，这个程序并没有发生内存泄漏，但是从`HEAP SUMMARY`可以看到，程序分配了 2 次内存，但却只释放了 1 次内存。
　　实际上这是由于 C++ 在分配内存时，为了提高效率，使用了它自己的内存池。当程序终止时，内存池的内存才会被操作系统回收，所以 Valgrind 会将这部分内存报告为 reachable 的，需要注意，reachable 的内存不代表内存泄漏，例如，从上面的输出中可以看到，有 72704 个字节是 reachable 的，但没有报告内存泄漏。



## 检测越界访问

```
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v(10, 0);
    std::cout << v[10] << std::endl;

    return 0;
}
```



　　使用 Valgrind 分析这段程序，Valgrind 会提示越界访问：

```
$ g++ -std=c++11 -g -o main_cpp main.cpp
$ valgrind --tool=memcheck --leak-check=full ./main_cpp
==31523== Memcheck, a memory error detector
==31523== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31523== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31523== Command: ./main_cpp
==31523==
==31523== Invalid read of size 4
==31523==    at 0x400AD7: main (main.cpp:7)
==31523==  Address 0x5ab5ca8 is 0 bytes after a block of size 40 alloc'd
==31523==    at 0x4C2E216: operator new(unsigned long) (vg_replace_malloc.c:334)
==31523==    by 0x4010D3: __gnu_cxx::new_allocator<int>::allocate(unsigned long, void const*) (new_allocator.h:104)
==31523==    by 0x401040: std::allocator_traits<std::allocator<int> >::allocate(std::allocator<int>&, unsigned long) (alloc_traits.h:491)
==31523==    by 0x400F91: std::_Vector_base<int, std::allocator<int> >::_M_allocate(unsigned long) (stl_vector.h:170)
==31523==    by 0x400E7E: std::_Vector_base<int, std::allocator<int> >::_M_create_storage(unsigned long) (stl_vector.h:185)
==31523==    by 0x400D1E: std::_Vector_base<int, std::allocator<int> >::_Vector_base(unsigned long, std::allocator<int> const&) (stl_vector.h:136)
==31523==    by 0x400C11: std::vector<int, std::allocator<int> >::vector(unsigned long, int const&, std::allocator<int> const&) (stl_vector.h:291)
==31523==    by 0x400AB9: main (main.cpp:6)
```



　　`Invalid read of size 4`表示越界读取 4 个字节，这个操作出现在`main.cpp`文件的第 7 行。另外可以看到，`vector`分配了一块 40 字节的内存，程序越界访问紧急着这块内存之后的 4 个字节。

优化：只需将下表设置不超过10

## 检测未初始化的内存

　　另一种经常出现的 Bug，就是程序访问了未初始化的内存。例如：

```
#include <iostream>

int main()
{
    int x;
    if (x == 0)
    {
        std::cout << "X is zero" << std::endl;
    }

    return 0;
}
```



　　使用 Valgrind 检测这个程序：

```
$ g++ -std=c++11 -g -o main_cpp main.cpp
$ valgrind --tool=memcheck --leak-check=full ./main_cpp
==31554== Memcheck, a memory error detector
==31554== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==31554== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==31554== Command: ./main_cpp
==31554==
==31554== Conditional jump or move depends on uninitialised value(s)
==31554==    at 0x400852: main (main.cpp:6)
```



　　输出中提示了`main.cpp`文件的第 6 行访问了未初始化的内存。

优化：初始化：`int x { };`使用大括号即可初始化，置空默认为0