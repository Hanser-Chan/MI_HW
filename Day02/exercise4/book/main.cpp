#include <iostream>
#include <format>
#include "book.h"

void printBook(book book){

    std::cout << std::format("该书的信息如下：书名:{}; 作者:{}; 价格:{} \n",
                             book.getMBookName(),book.getMAuthor(),book.getMPrice());
}



int main() {
    book book1("abc","CJJ","$80");
    printBook(book1);
}
