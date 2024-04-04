// A set containing elements in a given interval [a .. b]
// Assume they are all non-negative numbers
// Use the buckets & bits logic taught to us in Seminars

#pragma once
#include <cstdint> // Needed for uint8_t's definition
#include <cstring> // Needed for size_t

// Organize global constants
namespace Constants
{
    constexpr unsigned ELEMENTS_IN_BUCKET = sizeof(uint8_t) * 8; // Calculated at compile time rather than runtime. Same size for all platforms.
    constexpr short MAX_NAME_LENGTH = 31;
}

class DynamicSet
{
public:
    // Ctors, Dtor
    DynamicSet();
    DynamicSet(const char *name, unsigned a, unsigned b, unsigned *numbers, size_t size);
    DynamicSet(const DynamicSet &other);
    DynamicSet &operator=(const DynamicSet &other);
    ~DynamicSet();

    // Getters / Setters
    const char *getName() const;
    unsigned getElementsCount() const;
    void setName(const char *name);

    // Others
    void invert(unsigned num);
    void clearElements();
    void print() const;

    bool isSubsetOf(const DynamicSet &other) const;
    bool contains(unsigned num) const;

    // Union & Intersection of sets
    DynamicSet unionOfSets(const DynamicSet &rhs) const; // Doesn't modify `this` object
    DynamicSet intersectionOfSets(const DynamicSet &rhs) const;

private:
    // Member-data
    char name[Constants::MAX_NAME_LENGTH + 1]{};
    uint8_t *buckets = nullptr; // Elements in our set. `uint8_t` is an 8-bit integer [0 .. 255]
    unsigned bucketsCount = 0;

    unsigned start; // a
    unsigned end;   // b

    // Private methods
    void copyFrom(const DynamicSet &other);
    void free();

    unsigned getBucketIndex(unsigned num) const;
    bool isInInterval(unsigned num) const;
};