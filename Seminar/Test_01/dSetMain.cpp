#include <iostream>
#include "../FMI_IS_OOP_2024/Seminar/Test_01/DynamicSet.h"

int main()
{
    DynamicSet d;
    d.invert(1);
    d.invert(0);
    d.invert(255);
    d.invert(256);
    d.invert(17);
    d.print();
    d.invert(0);
    std::cout << std::endl;
    d.print();

    std::cout << std::endl;
    unsigned *nums = new unsigned[3]{10, 12, 14};
    DynamicSet d1("My name", 10, 17, nums, 3);
    d1.print();
    std::cout << d1.getName() << std::endl;

    std::cout << d.isSubsetOf(d1) << std::endl;
    d.invert(10);
    d.invert(12);
    d.invert(14);

    std::cout << d1.isSubsetOf(d) << std::endl;

    nums[0] = 11;
    nums[2] = 16;
    DynamicSet d2("Second", 10, 17, nums, 3);

    d1.print();
    d2.print();

    DynamicSet Union = d1.unionOfSets(d2);
    Union.print();
    DynamicSet Intersec = d1.intersectionOfSets(d2);
    Intersec.print();

    Intersec = Union;
    Intersec.print();

    delete[] nums;
}