#include <iostream>
#include "animal.h"

int main()
{

    Dog dog(50, "boy", 4);
    Cat cat(20, "girl", 2);

    dog.printInfo();
    dog.bark();
    cat.printInfo();
    cat.meow();
    return 0;
}
