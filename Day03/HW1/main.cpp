#include <iostream>
#include <format>

using std::cin,std::cout;

int pMax(const int *p, size_t size){
    int max{p[0]};
    for (size_t i = 1; i < size; ++i) {
        if (p[i] > max){
            max = p[i];
        }
    }
    return max;
}

int main() {

    size_t size;
    cout << "请输入数组大小：";
    cin >> size;

    int *p = new int[size];
    cout << std::format("\n请输入{}个数据:",size);

    for (int i = 0; i < size; ++i) std::cin >> p[i];

    cout << std::format("\n该数组最大值为：{}",pMax(p,size));

    delete[] p;

    return 0;
}
