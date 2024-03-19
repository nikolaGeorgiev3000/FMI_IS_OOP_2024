#include <iostream>
#include <fstream>

void printFile(const char* path)
{
    std::ifstream ifs(path);

    if(!ifs.is_open())
        return;

    while(!ifs.eof())
    {
        char buff[1024];
        ifs.getline(buff, 1024);
        std::cout << buff << std::endl;
    }
}


int main()
{
    printFile("Seminar/Week_02/selfPrinting.cpp");

    return 0;
}
