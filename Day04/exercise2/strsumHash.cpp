#include <iostream>
#include <unordered_set>
#include <string>

using std::string;

int sumStr(string str)
{
    std::unordered_set<char> set;
    for (auto s : str)
    {
        set.insert(s);
    }
    return set.size();
}

int main()
{
    std::string str{};
    std::cin >> str;

    int sum = sumStr(str);

    std::cout << sum;
}