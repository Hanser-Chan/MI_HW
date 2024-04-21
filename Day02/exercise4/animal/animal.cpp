#include "animal.h"
#include <iostream>
//
// Created by JJC on 2024/4/21.
//
int animal::getWeight() const
{
    return weight;
}

void animal::setWeight(int weight)
{
    animal::weight = weight;
}

const std::__1::basic_string<char> &animal::getSex() const
{
    return sex;
}

void animal::setSex(const std::__1::basic_string<char> &sex)
{
    animal::sex = sex;
}

int animal::getAge() const
{
    return age;
}

void animal::setAge(int age)
{
    animal::age = age;
}

animal::animal(int weight, const std::string &sex, int age) : weight(weight), sex(sex), age(age) {}

void bark()
{
    std::cout << "\nWoof! Woof!" << std::endl;
}

void meow()
{
    std::cout << "\nMeow~ Meow~" << std::endl;
}

Dog::Dog(int weight, const std::string &sex, int age) : animal(weight, sex, age) {}

Cat::Cat(int weight, const std::string &sex, int age) : animal(weight, sex, age) {}
