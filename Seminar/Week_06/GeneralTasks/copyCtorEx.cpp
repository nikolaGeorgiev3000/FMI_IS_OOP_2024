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
    ~A()
    {
        std::cout << "Dtor of A\n";
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
    ~B()
    {
        std::cout << "Dtor of B\n";
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
    { // извикват се копиращи конструктори на A, B
        std::cout << "Copy constructor of C\n";
    }
    ~C()
    {
        std::cout << "Dtor of C\n";
    }
};

int main()
{
    C c1;
    std::cout << std::endl;
    C c2(c1);

    return 0;
} // Dtor of C, B, A, for the object c2, and then Dtor of C, B, A for object c1