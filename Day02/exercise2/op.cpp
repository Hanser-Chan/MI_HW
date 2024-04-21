#include <iostream>
#include <format>

double oper(double a, char ch, double b)
{
    switch (ch)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    default:
        std::cout << "error"
                  << "\n";
        return -1;
        break;
    }
}

int main()
{
    double a{}, b{};
    char ch{};
    std::cout << "请输入表达式：";
    std::cin >> a >> ch >> b;

    std::cout << std::format("结果：{}", oper(a, ch, b));
    return 0;
}