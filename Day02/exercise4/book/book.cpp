#include <iostream>
#include <string>
#include <format>
#include "book.h"

//
// Created by JJC on 2024/4/21.
//
const std::__1::basic_string<char> &book::getMBookName() const {
    return m_bookName;
}

void book::setMBookName(const std::__1::basic_string<char> &mBookName) {
    m_bookName = mBookName;
}

const std::__1::basic_string<char> &book::getMAuthor() const {
    return m_author;
}

void book::setMAuthor(const std::__1::basic_string<char> &mAuthor) {
    m_author = mAuthor;
}

const std::__1::basic_string<char> &book::getMPrice() const {
    return m_price;
}

void book::setMPrice(const std::__1::basic_string<char> &mPrice) {
    m_price = mPrice;
}

book::book(const std::string &mBookName, const std::string &mAuthor, const std::string &mPrice) : m_bookName(mBookName),
                                                                                                  m_author(mAuthor),
                                                                                                  m_price(mPrice) {}
