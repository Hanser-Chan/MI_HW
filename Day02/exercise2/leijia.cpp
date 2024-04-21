#include <iostream>

int main()
{
    int sum{0};
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
        std::cout << sum << "\n";
    }
    return 0;
}