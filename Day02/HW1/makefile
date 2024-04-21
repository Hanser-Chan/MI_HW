CXX = g++
TARGET = rectangle
SRC = $(wildcard *.cpp)					#编译所有后缀为.cpp文件
OBJ = $(patsubst %.cpp, %.o, $(SRC))	#将.cpp文件编译成.o

CXXFLAGS = -c -Wall	-std=c++20				#使用-c,-Wall(打印报错信息)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@