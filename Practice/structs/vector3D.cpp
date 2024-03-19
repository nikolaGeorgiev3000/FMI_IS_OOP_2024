#include <iostream>
#include <cmath>

struct Vector3D {
    double x, y, z; // 3D vector with three coordinates

    double getVectorLength() const {
        return sqrt(this->x * this->x +
                    this->y * this->y +
                    this->z * this->z);
    }

    Vector3D plus(const Vector3D v) const {
        // A 3D vector is defined through its three coordinates
        Vector3D resultVector = {};

        resultVector.x = this->x + v.x;
        resultVector.y = this->y + v.y;
        resultVector.z = this->z + v.z;

        return resultVector;
    }

    void printCoordinates() const {
        std::cout << "("
                  << this->x << ", "
                  << this->y << ", "
                  << this->z << ")"
                  << std::endl;
    }
};

double getScalarProduct(const Vector3D v1, const Vector3D v2) {
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

bool arePerpendicular(const Vector3D v1, const Vector3D v2) {
    return getScalarProduct(v1, v2) == 0;
}

int main() {
    const Vector3D v1 = {1, 2, 3};
    const Vector3D v2 = {4, 5, 6};

    std::cout << "The coord. of v1 are: ";
    v1.printCoordinates();

    std::cout << "The coord. of v2 are: ";
    v2.printCoordinates();

    std::cout << "Are v1 & v2 perp: " << std::boolalpha << arePerpendicular(v1, v2) << std::endl;


    std::cout << "The length of v2 is: " << v2.getVectorLength() << std::endl;

    std::cout << "v1 scalarPr v2: " << getScalarProduct(v1, v2) << std::endl;



    std::cout << "v1 + v2: ";
    v1.plus(v2).printCoordinates(); // {(v1.plus(v2)).printCoordinates()} -> leftToRight

    return 0;
}
