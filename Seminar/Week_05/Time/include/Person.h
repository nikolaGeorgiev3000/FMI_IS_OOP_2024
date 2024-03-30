#pragma once

class Person
{
private:
    unsigned _age;

public:
    // Ctors
    Person(unsigned age);
    // Getters
    const unsigned getAge() const;

    // Print
    void print() const;
};