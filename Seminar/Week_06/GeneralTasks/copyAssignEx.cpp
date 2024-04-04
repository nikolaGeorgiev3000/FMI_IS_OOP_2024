#include <iostream>

class A
{
    int a;

public:
    A()
    {
        std::cout << "Default Constructor of A\n";
    }
    A(const A &other)
    {
        std::cout << "Copy constructor of A\n";
    }
    A &operator=(const A &other)
    {
        std::cout << "Operator= of A\n";
        return *this;
    }
};

class B
{
    int b;

public:
    B()
    {
        std::cout << "Default constructor of B\n";
    }
    B(const B &other)
    {
        std::cout << "Copy constructor of B\n";
    }
    B &operator=(const B &other)
    {
        std::cout << "Operator= of B\n";
        return *this;
    }
};

class C
{
    A a;
    B b;

public:
    C()
    {
        std::cout << "Default Constructor of C\n";
    }
    C(const C &other) : a(other.a), b(other.b)
    {
        std::cout << "Copy constructor of C\n";
    }
    // you have to explicitly call a and b operator=
    //  otherwise nothing will be called
    C &operator=(const C &other)
    {
        a = other.a;
        b = other.b;
        std::cout << "Operator= of C\n";
        return *this;
    }
};

int main()
{

    C c1, c2;
    std::cout << std::endl;
    c2 = c1;

    return 0;
}