#include <iostream>
#include <cstring>

class Entity
{
private:
    char *label;

    void copyFrom(const Entity &other)
    {
        label = new char[strlen(other.label) + 1];
        strcpy(label, other.label);
    }

    void free()
    {
        delete[] label;
    }

public:
    // Default ctor with MIL
    Entity() : label(nullptr) {} // Kind of problematic with this nullptr...

    // Parameterized ctor
    Entity(const char *l)
    {
        size_t len = strlen(l);
        label = new char[len + 1];
        strncpy(label, l, len);
        label[len] = '\0';
    }

    // Copy ctpr
    Entity(const Entity &other)
    {
        copyFrom(other);
    }

    // Copy-assignment operator
    Entity &operator=(const Entity &other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }
    // Dtor
    ~Entity()
    {
        free();
    }
    // Getter
    const char *getLabel() const
    {
        return this->label;
    }
};

int main()
{
    Entity ent1; // Default ctor

    Entity ent2("Something"); // Param. ctor

    Entity ent3(ent2); // Copy ctor

    Entity ent4 = ent3; // Copy ctor

    ent3 = ent2; // operator=

    // std::cout << ent1.getLabel(); // Leads to segmentation fault

    return 0;
}