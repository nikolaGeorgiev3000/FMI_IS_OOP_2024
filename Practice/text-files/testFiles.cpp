#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;

void writeToTxtFile(std::ofstream& ofs) {
    ofs.open("test1.txt");

    if (!ofs.is_open()) {
        return;
    }

    ofs << "Testing files writing\n";
    ofs << "Once again...";
    ofs << "Once again......";

    ofs.close();
}

void readFromTxtFile(std::ifstream& ifs, char* buffer) {

    ifs.open("test1.txt");

    // Open validation
    if(!ifs.is_open()) {
        return;
    }

    while (ifs.getline(buffer, BUFFER_SIZE))
    {
        std::cout << buffer << "\n"; // Manually add '\n' in order to account for new lines
    }

    ifs.close();
}

int main() {
    std::ofstream ofs;
    writeToTxtFile(ofs);

    std::ifstream ifs;

    char buffer[BUFFER_SIZE];

    readFromTxtFile(ifs, buffer);

    return 0;
}
