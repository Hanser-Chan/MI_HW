#include <iostream>
#include "add.h"
#include "sub.h"
#include "mutiple.h"
#include "division.h"

int main(int argc, char *argv[]) {
    int a = 1;
    int b = 2;

    std::cout << "a+b=" << add(a, b) << std::endl;
    std::cout << "a-b=" << sub(a, b) << std::endl;
    std::cout << "a*b=" << mutiple(a, b) << std::endl;
    std::cout << "a/b=" << division(a, b) << std::endl;

    return 0;
}