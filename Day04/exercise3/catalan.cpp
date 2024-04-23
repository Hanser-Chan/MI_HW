#include <iostream>
#include <vector>
#include <string>

//返回第n个卡特兰数
long long catalan(int n) {
    if (n <= 1) return 1;
    std::vector<long long> c(n + 1, 0);
    c[0] = c[1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            c[i] += c[j] * c[i - j - 1];
        }
    }
    return c[n];
}

int main() {
    std::vector<std::pair<int, int>> points;
    std::string line;
    while (std::getline(std::cin, line) && !line.empty()) {
        int x, y;
        sscanf(line.c_str(), "%d %d", &x, &y);
        points.push_back({x, y});
    }
    
    
    int n = points.size() - 1;  
    if (n <= 1) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << catalan(n - 1) << std::endl;
    }
    return 0;
}