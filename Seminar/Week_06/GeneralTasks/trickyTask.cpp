#include <iostream>

struct T
{
    T()
    {
        std::cout << "Default constructor\n";
    }
    T(const T &other)
    {
        std::cout << "Copy constructor\n";
    }
    T &operator=(const T &other)
    {
        std::cout << "Operator=\n";
        return *this;
    }
    ~T()
    {
        std::cout << "Destructor\n";
    }
};
int main()
{
    T obj1; // Default ctor
    {
        T obj2;      // Default ctor
        obj2 = obj1; // operator=
    }                // Destructor
    T obj3(obj1);    // Copy ctor

    return 0;
} // Destructor, Destructor
