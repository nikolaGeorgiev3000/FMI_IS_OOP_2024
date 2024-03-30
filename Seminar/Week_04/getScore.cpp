#include <iostream>
#include <fstream>

#pragma warning(disable : 4996)

struct Word
{
    char data[25];
    short density;
};

Word createWord(const char *data, short density)
{
    Word toReturn;
    strcpy(toReturn.data, data);
    toReturn.density = density;

    return toReturn;
}

int getFileSize(std::ifstream &ifs)
{
    int currentLocation = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    int fileSize = ifs.tellg();
    ifs.seekg(currentLocation, std::ios::beg);

    return fileSize;
}

bool isPrefix(const char *fst, const char *snd)
{
    while (*fst && *snd && *fst == *snd)
    {
        ++fst;
        ++snd;
    }

    return (*fst == '\0');
}

size_t getScore(const char *wordPref, const char *filePath)
{
    std::ifstream ifs(filePath, std::ios::binary);

    if (!ifs.is_open())
        return 0;

    size_t fileSize = getFileSize(ifs);
    size_t recordSize = sizeof(Word);

    size_t recordsCount = fileSize / recordSize;
}
int main()
{
}