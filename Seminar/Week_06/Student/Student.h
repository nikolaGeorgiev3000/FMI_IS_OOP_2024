#include <fstream>
#pragma once

class Student
{
private:
    char *_name;
    unsigned _fn;
    float _averageGrade;

    void copyFrom(const Student &other);
    void free();

public:
    Student();
    Student(const char *name, unsigned fn, float averageGrade);
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    void print() const;
    void serializeStudent(std::ofstream &ofs) const;
    void deserializeStudent(std::ifstream &ifs);
};