#include <iostream>
#include "../include/Time.h"
#include "../include/Person.h"

int main()
{
    Time t1;            // Default constructor, sets time to 00:00:00
    Time t2(13, 5, 45); // Constructor with parameters, sets time to 13:05:45

    // Example usage
    Time remaining = t2.timeUntilMidnight();
    std::cout << "Time remaining until midnight: ";
    remaining.printTime();

    std::cout << "Is it dinner time? " << (t2.isDinnerTime() ? "Yes" : "No") << std::endl;

    t2.incrementSecond();
    std::cout << "Time after incrementing by 1 second: ";
    t2.printTime();

    Time t3(21, 30, 0);
    Time diff = t2.difference(t3);
    std::cout << "Difference between ";
    t2.printTime();
    std::cout << "and ";
    t3.printTime();
    std::cout << "is ";
    diff.printTime();

    std::cout << "Comparison result: " << (t2 < t3 ? "Earlier" : "Later") << " than ";
    t3.printTime();

    std::cout << std::endl;

    std::cout << "Testing hierarchy:\n";

    Person p1(20);

    p1.print();

    return 0;
}