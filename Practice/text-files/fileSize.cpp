#include <iostream>
#include <fstream>

int getFileSize(const char* fileName) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) {
        return -1; // Error
    }

    // Save the get-pointer
    int currPos = ifs.tellg();

    // Move the get-pointer to the end of the file
    ifs.seekg(0, std::ios::end);

    // Get file size
    int fileSize = ifs.tellg();

    // Move back the get-pointer to its original position
    ifs.seekg(currPos, std::ios::beg);

    ifs.close();

    return fileSize;
}

int main() {
    // std::cout << "The size of fileSize.cpp is: " << getFileSize("FMI_IS_OOP_2024/Practice/text-files/fileSize.cpp") << " B" << std::endl;
    std::cout << "The size of test1.txt is: " << getFileSize("testFiles") << " B" << std::endl;

    return 0;
}
