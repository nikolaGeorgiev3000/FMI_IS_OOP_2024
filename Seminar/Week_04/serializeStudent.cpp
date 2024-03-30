#include <iostream>
#include <cstring>
#include <fstream>

#pragma warning(disable : 4996)

struct Student
{
    char *name;
    unsigned age;
    float height;
};

Student createStudent(const char *name, unsigned age, float height)
{
    Student toReturn;
    int length = strlen(name);
    toReturn.name = new char[length + 1];

    strcpy(toReturn.name, name); // Assign name into toReturn.name
    toReturn.age = age;
    toReturn.height = height;

    return toReturn;
}

void freeStudent(const Student &st) // `const` is allowed here!
{
    delete[] st.name;
}

void serializeStudent(std::ofstream &ofs, const Student &st)
{
    int nameLen = strlen(st.name);

    // Write into a binary file
    ofs.write((const char *)&nameLen, sizeof(nameLen)); // GIGA-IMPORTANT: Write the length of the name in the binary file
    ofs.write(st.name, nameLen);
    ofs.write((const char *)&st.age, sizeof(st.age));
    ofs.write((const char *)&st.height, sizeof(st.height));
}

Student deserializeStudent(std::ifstream &ifs)
{
    Student toReturn;

    int nameLen = 0;
    ifs.read((char *)&nameLen, sizeof(nameLen));

    toReturn.name = new char[nameLen + 1];
    ifs.read(toReturn.name, nameLen);
    toReturn.name[nameLen] = '\0';

    ifs.read((char *)&toReturn.age, sizeof(toReturn.age));
    ifs.read((char *)&toReturn.height, sizeof(toReturn.height));

    return toReturn;
}

void printStudent(const Student &st)
{
    std::cout << "Name: " << st.name << "\nAge: " << st.age << "\nHeight: " << st.height << std::endl;
}

int main()
{
    {
        Student studentExample = createStudent("Dragan", 25, 1.78);
        std::ofstream ofs("serStudent.dat", std::ios::binary);
        serializeStudent(ofs, studentExample);
        freeStudent(studentExample); // Free the heap because of createStudent()
    }
    {
        std::ifstream ifs("serStudent.dat", std::ios::binary);
        Student readStudent = deserializeStudent(ifs);
        printStudent(readStudent); // Print the read from the binary file student
        freeStudent(readStudent);
    }
}