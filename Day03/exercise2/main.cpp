#include <iostream>
#include <cstdio>
#include <array>
#include <format>

/*
 *定义一个int型的大小为10的一维数组arr，使用print函数按照p式打打印arr、&arr和&arr[0]的值并比较
 *定义一个int型的大小为10的一维数组buf，再定义一个对应类型的指针变量p，比sizeof(buf)和sizeof(p)的区别
 *定义一个int型的二维数组data[3[4]并初始化，再定义一个相应类型的指针变量p，并把&data赋值给指针变量0
 * */

int main() {

    std::array<int,10> arr{};

    std::array<int,10> buf{};
    //std::array<std::array<int,4>,3> data;
    int* p{};

    int data[3][4]{};
//    int* data1 = data[0] ;
//    int* data2 = data[1] ;
//    int* data3 = data[2] ;
//    int* dataP[] = {data1,data2,data3};
//    int** pData_level2 = dataP ;

//  如果需要使用引用符需要以下代码：
    int *dataX[4];
    dataX[0] = &data[0][0];

    printf("%p\n",arr);
    printf("%p\n",&arr);
    printf("%p\n",&arr[0]);

    std::cout << std::format("sizeof(buf):{}\nsizeof()p:{}",sizeof(buf), sizeof(p));
}
