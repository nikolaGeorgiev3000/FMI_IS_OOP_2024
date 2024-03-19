#include <iostream>
#include <fstream>

unsigned getCharCount(std::ifstream& ifs, char ch)
{
    if(!ifs.is_open())
        return 0;

    unsigned int counter = 0;

    while(!ifs.eof())
    {
        char currentCh = ifs.get();

        if(currentCh == ch)
            counter++;
    }

    return counter;
}

unsigned getLinesCount(const char* path) {
    std::ifstream ifs(path);

    if (!ifs.is_open())
        return 0;

    return getCharCount(ifs, '\n') + 1; // Last line doesn't have a new line character
}

int main()
{
    unsigned int newLinesInFile = getLinesCount("Seminar/Week_02/newLinesCount.cpp");
    std::cout << "New lines: " << newLinesInFile << std::endl;

    return 0;
}