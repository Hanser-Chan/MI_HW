#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int main()
{

    int (*pf)(int a, int b) = add;

    std::cout << "(*pf)(1, 2) = " << (*pf)(1, 2) << std::endl;

    pf = &add;

    std::cout << "pf(1, 2) = " << pf(1, 2) << std::endl;
}