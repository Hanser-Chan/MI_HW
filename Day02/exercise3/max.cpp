#include <iostream>
#include <algorithm>
#include <format>

int smax(int a, int b, int c)
{
    return std::max({a, b, c});
}

int smax(int a, int b)
{
    return std::max(a, b);
}

int main()
{
    int a{}, b{}, c{};
    std::cout << "请输入3个数: ";
    std::cin >> a >> b >> c;
    std::cout << std::format("3个数中最大值为{}", smax(a, b, c)) << std::endl;
}