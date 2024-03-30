#include <iostream>
#include "../include/Time.h"

#pragma warning(disable : 4996)

// Default constructor
Time::Time() : hours(0), minutes(0), seconds(0) {}

// Constructor with parameters
Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

// Function to return time remaining until midnight
Time Time::timeUntilMidnight()
{
    Time midnight(23 - hours, 59 - minutes, 59 - seconds);
    return midnight;
}

// Function to increment time by 1 second
void Time::incrementSecond()
{
    seconds++;
    if (seconds >= 60)
    {
        seconds = 0;
        minutes++;
        if (minutes >= 60)
        {
            minutes = 0;
            hours++;
            if (hours >= 24)
            {
                hours = 0;
            }
        }
    }
}

// Function to check if it's dinner time
bool Time::isDinnerTime() const
{
    return (hours == 20 && minutes >= 30) || (hours > 20 && hours < 22);
}

// Function to calculate difference between two times
Time Time::difference(const Time &other) const
{
    int diffHours = other.hours - hours;
    int diffMinutes = other.minutes - minutes;
    int diffSeconds = other.seconds - seconds;

    if (diffSeconds < 0)
    {
        diffSeconds += 60;
        diffMinutes--;
    }
    if (diffMinutes < 0)
    {
        diffMinutes += 60;
        diffHours--;
    }
    if (diffHours < 0)
    {
        diffHours += 24;
    }

    return Time(diffHours, diffMinutes, diffSeconds);
}

// Function to compare two times
bool Time::operator<(const Time &other) const
{
    if (hours != other.hours)
        return hours < other.hours;
    if (minutes != other.minutes)
        return minutes < other.minutes;
    return seconds < other.seconds;
}

// Function to print the time
void Time::printTime() const
{
    std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
}
