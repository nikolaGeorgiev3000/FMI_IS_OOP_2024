#include <iostream>
#include <cstring>
#include <fstream>
#include "../Student/Student.h"

void Student::copyFrom(const Student &other)
{
    _name = new char[strlen(other._name) + 1];
    strcpy(_name, other._name);

    _fn = other._fn;
    _averageGrade = other._averageGrade;
}

void Student::free()
{
    delete[] this->_name;
}

Student::Student() : _name(nullptr), _fn(0), _averageGrade(0.0f) {}

Student::Student(const char *name, unsigned fn, float averageGrade)
{
    size_t len = strlen(name);
    _name = new char[len + 1];
    strncpy(_name, name, len);
    _name[len] = '\0';

    _fn = fn;
    _averageGrade = averageGrade;
}

Student::Student(const Student &other)
{
    copyFrom(other);
}

Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

Student::~Student()
{
    free();
}

void Student::print() const
{
    std::cout << "\nName: " << _name << "\nFN: " << _fn << "\nAv. grade: " << _averageGrade;
}

void Student::serializeStudent(std::ofstream &ofs) const
{
    int nameLen = strlen(_name);

    // Write into a binary file
    ofs.write((const char *)&nameLen, sizeof(nameLen));
    ofs.write(_name, nameLen);
    ofs.write((const char *)&_fn, sizeof(_fn));
    ofs.write((const char *)&_averageGrade, sizeof(_averageGrade));
}

void Student::deserializeStudent(std::ifstream &ifs)
{
    int nameLen = 0;
    ifs.read((char *)&nameLen, sizeof(nameLen));
    delete[] _name; // Free existing memory before allocating new
    _name = new char[nameLen + 1];
    ifs.read(_name, nameLen);
    _name[nameLen] = '\0';
    ifs.read((char *)&_fn, sizeof(_fn));
    ifs.read((char *)&_averageGrade, sizeof(_averageGrade));
}

int main()
{
    {
        Student studentExample("Dragan", 24145323, 4.64);
        std::ofstream ofs("../Student/serStudent.dat", std::ios::binary);
        studentExample.serializeStudent(ofs);
    }
    {
        std::ifstream ifs("../Student/serStudent.dat", std::ios::binary);
        Student readStudent;
        readStudent.deserializeStudent(ifs);
        readStudent.print(); // Print the read from the binary file student
    }

    return 0;
}
