#include <iostream>

// 第三层调用，触发段错误
void triggerFault()
{
    int *ptr = nullptr; // 定义一个空指针
    *ptr = 10;          // 尝试写入空指针，将导致段错误
}

// 第二层调用
void callFault()
{
    triggerFault();
}

// 第一层调用
void startFault()
{
    callFault();
}

int main()
{
    startFault(); // 开始错误触发链
    return 0;
}
