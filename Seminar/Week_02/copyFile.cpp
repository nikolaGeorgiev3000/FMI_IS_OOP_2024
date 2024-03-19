#include <iostream>
#include <fstream>

bool copyTo(const char* pathSource, const char* destinationSource)
{
    std::ifstream sourceStream(pathSource);

    if(!sourceStream.is_open())
        return false;

    std::ofstream destinationStream(destinationSource);

    if(!destinationStream.is_open())
        return false;

    while (!sourceStream.eof())
    {
        char buff[1024];
        sourceStream.getline(buff, 1024);
        destinationStream << buff << std::endl;
    }

    // Close the files
    sourceStream.close();
    destinationStream.close();

    return true; // Everything's okay
}

int main()
{
    std::cout << "Valid operation: " << copyTo("Seminar/Week_02/copyFile.cpp", "destFile.txt");

    return 0;
}