#include <iostream>
#include <set>
#include <string>

int strSet(const std::string &str)
{
    int sum{0};

    std::set<char> st;
    for (auto i : str)
    {
        st.insert(i);
    }

    for (auto it : st)
        sum++;

    return sum;
}

int main()
{
    std::string str{};
    std::cin >> str;

    int sum = strSet(str);

    std::cout << sum;
}