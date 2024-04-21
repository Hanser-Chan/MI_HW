//
// Created by JJC on 2024/4/21.
//
#include <iostream>
#include <string>
#include <format>
#ifndef ANIMAL_ANIMAL_H
#define ANIMAL_ANIMAL_H

class animal
{

public:
    animal(int weight, const std::string &sex, int age);

    int getWeight() const;

    void setWeight(int weight);

    const std::string &getSex() const;

    void setSex(const std::string &sex);

    int getAge() const;

    void setAge(int age);

    void printInfo()
    {
        std::cout << std::format("这个小动物重量:{},性别:{},年龄:{}", getWeight(), getSex(), getAge());
    }

private:
    int weight;
    std::string sex;
    int age;
};

// 狗类继承自动物类
class Dog : public animal
{
public:
    Dog(int weight, const std::string &sex, int age);

private:
    void bark() const;
};

// 猫类继承自动物类
class Cat : public animal
{
public:
    Cat(int weight, const std::string &sex, int age);

private:
    void meow() const;
};

#endif // ANIMAL_ANIMAL_H
