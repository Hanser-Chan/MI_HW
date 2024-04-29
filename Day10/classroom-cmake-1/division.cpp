#include "division.h"

int division(int a, int b) {
    if (b == 0) {
        std::cout << "被除数不能为0！" << std::endl;
        return 0;
    }
    return a / b;
}