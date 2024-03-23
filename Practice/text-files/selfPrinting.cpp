#include <iostream>
#include <fstream>

void selfPrint(const char* fileName) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) {
        return; // Validate error
    }

    char ch;
    while (ifs.get(ch)) {
        std::cout << ch;
    }

    ifs.close();
}

int main() {
    selfPrint("../FMI_IS_OOP_2024/Practice/text-files/selfPrinting.cpp"); // Important to use relative path: "(../.../fileName)"

    return 0;
}