#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{

    int (*pf)(int a, int b) = add; // 解引用调用

    std::cout << "(*pf)(1, 2) = " << (*pf)(1, 2) << std::endl;

    pf = &add; // 直接调用

    std::cout << "pf(1, 2) = " << pf(1, 2) << std::endl;

    std::cout << (void *)add << std::endl
              << (void *)*add << std::endl
              << &add << std::endl
              << pf << std::endl
              << *pf << std::endl
              << &pf << std::endl;
}