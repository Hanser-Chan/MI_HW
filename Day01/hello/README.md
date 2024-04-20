# 使用makefile编译cpp

## 设置三个cpp文件

printHello.cpp

```cpp
#include <iostream>
#include "printHello.h"

void print()
{
    std::cout << "Hello World!" << std::endl;
}
```

printHello.h

```cpp
#ifndef __printHello_h
#define __printHello_h
void print();
#endif
```

Main.cpp

```cpp
#include <iostream>
#include "printHello.h"

int main()
{
    print();
    return 0;
}
```

## 编辑makefile文件

```makefile
CXX = g++
TARGET = hello
SRC = $(wildcard *.cpp)					#编译所有后缀为.cpp文件
OBJ = $(patsubst %.cpp, %.o, $(SRC))	#将.cpp文件编译成.o

CXXFLAGS = -c -Wall						#使用-c,-Wall(打印报错信息)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@
```

## 后续及结果可见文件内容和截图

![out.png](https://img2.imgtp.com/2024/04/20/4bUvnpPB.png)

![make.png](https://img2.imgtp.com/2024/04/20/LkZXrxxO.png)
