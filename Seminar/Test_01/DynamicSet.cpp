#include <iostream>
#include "../FMI_IS_OOP_2024/Seminar/Test_01/DynamicSet.h"

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
    // Set default values
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

unsigned DynamicSet::getBucketIndex(unsigned num) const
{
    return num / Constants::ELEMENTS_IN_BUCKET;
}

bool DynamicSet::isInInterval(unsigned num) const
{
    return (num >= start && num <= end);
}

// Invert function. Uses the XOR operation to remove the `num` if it's not in the set, and the opposite
void DynamicSet::invert(unsigned num)
{
    if (!this->isInInterval(num))
        return;

    num -= start; // Normalize the number;

    // Bucket index & bit position
    unsigned bucketIndex = getBucketIndex(num);
    unsigned bitPosition = num % Constants::ELEMENTS_IN_BUCKET;

    // XOR operation on the bucket
    buckets[bucketIndex] ^= (1 << bitPosition);
}

bool DynamicSet::contains(unsigned num) const
{
    if (!this->isInInterval(num))
        return false;

    // Normalize the number;
    num -= start;

    unsigned bucketIndex = getBucketIndex(num);
    unsigned bitPosition = num % Constants::ELEMENTS_IN_BUCKET;

    // Create a mask
    uint8_t mask = 1 << bitPosition;

    // Use the mask to check whether `num` is contained in our set
    return (mask & buckets[bucketIndex]); // Implicit cast into a boolean (!0 -> true; 0 -> false)
}

unsigned DynamicSet::getElementsCount() const
{
    unsigned count = 0;
    for (size_t i = start; i <= end; ++i)
    {
        if (this->contains(i))
        {
            ++count;
        }
    }
    return count;
}

void DynamicSet::clearElements()
{
    for (size_t i = 0; i < bucketsCount; ++i)
    {
        buckets[i] = 0; // First iter. -> 0000 0000, Second iter. -> 0000 0000, ...
    }
}

bool DynamicSet::isSubsetOf(const DynamicSet &other) const
{
    unsigned minStart = std::min(this->start, other.start);
    unsigned maxEnd = std::max(this->end, other.end);

    for (size_t i = minStart; i <= maxEnd; ++i)
    {
        if (this->contains(i) && !other.contains(i))
            return false;
    }

    return true;
}

DynamicSet DynamicSet::unionOfSets(const DynamicSet &rhs) const
{
    if (this->start != rhs.start || this->end != rhs.end)
        return DynamicSet(); // Return the empty set

    // Copy ctor
    DynamicSet result(*this);
    result.setName("Union");

    for (size_t i = 0; i < result.bucketsCount; ++i)
    {
        result.buckets[i] |= rhs.buckets[i]; // Bitwise `|` operation on every bucket.
    }

    return result;
}

DynamicSet DynamicSet::intersectionOfSets(const DynamicSet &rhs) const
{
    if (this->start != rhs.start || this->end != rhs.end)
        return DynamicSet(); // Return the empty set

    // Copy ctor
    DynamicSet result(*this);
    result.setName("Intersection");

    for (size_t i = 0; i < result.bucketsCount; ++i)
    {
        result.buckets[i] &= rhs.buckets[i]; // Bitwise `&` operation on every bucket.
    }

    return result;
}

void DynamicSet::print() const
{
    for (size_t i = this->start; i <= this->end; ++i)
    {
        if (this->contains(i))
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}