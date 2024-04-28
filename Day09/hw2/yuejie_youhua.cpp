#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v(10, 0);
    std::cout << v[9] << std::endl;

    return 0;
}