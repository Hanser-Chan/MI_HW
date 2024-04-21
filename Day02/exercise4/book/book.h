//
// Created by JJC on 2024/4/21.
//
#include <iostream>
#include <string>
#ifndef BOOK_BOOK_H
#define BOOK_BOOK_H



class book{

public:
    book(const std::string &mBookName, const std::string &mAuthor, const std::string &mPrice);

    const std::string &getMBookName() const;

    void setMBookName(const std::string &mBookName);

    const std::string &getMAuthor() const;

    void setMAuthor(const std::string &mAuthor);

    const std::string &getMPrice() const;

    void setMPrice(const std::string &mPrice);


private:
    std::string m_bookName;
    std::string m_author;
    std::string m_price;

};


#endif //BOOK_BOOK_H
