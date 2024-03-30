#pragma once

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    // Default constructor
    Time();

    // Constructor with parameters
    Time(int h, int m, int s);

    // Function to return time remaining until midnight
    Time timeUntilMidnight();

    // Function to increment time by 1 second
    void incrementSecond();

    // Function to check if it's dinner time
    bool isDinnerTime() const;

    // Function to calculate difference between two times
    Time difference(const Time &other) const;

    // Function to compare two times
    bool operator<(const Time &other) const;

    // Function to print the time
    void printTime() const;
};