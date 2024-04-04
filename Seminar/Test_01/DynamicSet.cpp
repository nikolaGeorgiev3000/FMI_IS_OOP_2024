#include <iostream>
#include "../Seminar/Test_01/DynamicSet.h"

// Ctors / Dtor
// Call the param. ctor, the values are from our condition
DynamicSet::DynamicSet() : DynamicSet("EmptySet", 0, 255, nullptr, 0) {}

DynamicSet::DynamicSet(const char *name,
                       unsigned a, unsigned b,
                       unsigned *numbers, size_t size)
    : start(a), end(b)
{
    setName(name); // Set the name for our set

    unsigned numbersCount = b - a + 1;                                        // Numbers in the given interval
    unsigned bucketsCount = numbersCount / Constants::ELEMENTS_IN_BUCKET + 1; // An extra bucket to accommodate the remaining numbers
    buckets = new uint8_t[bucketsCount]{};                                    // `{}` to init all elements with zeros

    // TODO: Carefully analyze this step
    for (size_t i = 0; i < size; ++i)
    {
        if (!this->contains(numbers[i]))
        {
            this->invert(numbers[i]);
        }
    }
}

// Helper methods
void DynamicSet::copyFrom(const DynamicSet &other)
{
    start = other.start; // a
    end = other.end;     // b
    setName(other.name); // Name for our set

    bucketsCount = other.bucketsCount;
    buckets = new uint8_t[bucketsCount];

    for (size_t i = 0; i < bucketsCount; ++i)
    {
        buckets[i] = other.buckets[i];
    }
}

void DynamicSet::free()
{
    delete[] buckets;
    buckets = nullptr;
    bucketsCount = 0;
}

// Ctors
DynamicSet::DynamicSet(const DynamicSet &other)
{
    copyFrom(other);
}

DynamicSet &DynamicSet::operator=(const DynamicSet &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

// Dtor
DynamicSet::~DynamicSet()
{
    free();
}

// Getter / Setter
const char *DynamicSet::getName() const
{
    return this->name;
}

void DynamicSet::setName(const char *name)
{
    // Validation
    if (name == nullptr || strlen(name) > Constants::MAX_NAME_LENGTH)
    {
        std::cout << "Please enter a valid name for the set.\n";
        return;
    }

    strcpy(this->name, name);
}