#include <iostream>
#include "../Week_05/DynMemEx.h"

void DynMemEx::freeData()
{
    delete[] label;
}
DynMemEx::DynMemEx() : label(nullptr) {}

DynMemEx::DynMemEx(const char *src)
{
    // Dynamically allocate memory
    int srcLen = strlen(src);
    label = new char[srcLen + 1];
    strncpy(label, src, srcLen);
    label[srcLen] = '\0';
}

const char *DynMemEx::getLabel() const
{
    return label; // this->label
}

DynMemEx::~DynMemEx()
{
    freeData(); // delete[] label
}

int main()
{
    DynMemEx ex1("LabelExample");
    std::cout << "Our label example is: " << ex1.getLabel();

    return 0;
}