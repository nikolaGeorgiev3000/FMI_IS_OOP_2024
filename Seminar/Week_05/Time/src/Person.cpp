#include <iostream>
#include "../include/Person.h"

Person::Person(unsigned age) : _age(age)
{
}

const unsigned Person::getAge() const
{
    return _age;
}

void Person::print() const
{
    std::cout << "Age: " << _age << std::endl;
}