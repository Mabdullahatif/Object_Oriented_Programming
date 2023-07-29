/*
Description: This C++ code defines a class "VectorType" that represents a 3D vector.
The class implements various operations on vectors, such as addition, subtraction,
dot product, length calculation, and finding the angle between two vectors.

The class contains private member variables "x," "y," and "z," which represent the
vector's components. Public member functions include constructors, a copy constructor,
destructor, and overloaded operators for assignment, addition, subtraction, dot product,
pre/post-increment, pre/post-decrement, equality, and inequality. The class also
provides functions to calculate the vector's length and the angle between two vectors.

In the main function, the user is prompted to enter the x, y, and z values for two
vectors (c1 and c2). The code then demonstrates various operations on these vectors,
including printing their components, calculating dot product, vector length, and the
angle between them. Additionally, it displays the sum and difference of vectors c1 and
c2, as well as the result of pre/post-increment and pre/post-decrement operations on c1
and c2. Finally, it checks for equality and inequality between the vectors.

The VectorType class provides a convenient and reusable implementation for 3D vector
manipulation, and the main function demonstrates its functionality with user-provided
vector values. The code showcases object-oriented programming, operator overloading,
and mathematical vector operations in C++.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class VectorType {
private:
    double *x;
    double *y;
    double *z;

public:
    VectorType();
    VectorType(double, double, double);
    VectorType(const VectorType&); // Copy constructor
    ~VectorType();

    VectorType& operator=(const VectorType&);

    double operator*(const VectorType&);

    VectorType operator+(const VectorType&);
    VectorType operator-(const VectorType&);

    VectorType& operator++();     // Pre-increment
    VectorType operator++(int);   // Post-increment
    VectorType& operator--();     // Pre-decrement
    VectorType operator--(int);   // Post-decrement

    bool operator==(const VectorType&);
    bool operator!=(const VectorType&);

    friend istream& operator>>(istream&, VectorType&);
    friend ostream& operator<<(ostream&, const VectorType&);

    double length()const;
    double findAngle(const VectorType&);
};

VectorType::VectorType() {
    x = new double;
    y = new double;
    z = new double;
    *x = 0;
    *y = 0;
    *z = 0;
}

VectorType::VectorType(double X, double Y, double Z) {
    x = new double;
    y = new double;
    z = new double;
    *x = X;
    *y = Y;
    *z = Z;
}

VectorType::VectorType(const VectorType& vec) {
    x = new double;
    y = new double;
    z = new double;
    *x = *vec.x;
    *y = *vec.y;
    *z = *vec.z;
}

VectorType::~VectorType() {
    delete x;
    delete y;
    delete z;
}

VectorType& VectorType::operator=(const VectorType& vec) {
    if (this == &vec) return *this;

    *x = *vec.x;
    *y = *vec.y;
    *z = *vec.z;
    return *this;
}

double VectorType::operator*(const VectorType& vec) {
    return (*x * (*vec.x)) + (*y * (*vec.y)) + (*z * (*vec.z));
}

VectorType VectorType::operator+(const VectorType& vec) {
    VectorType result(*x + (*vec.x), *y + (*vec.y), *z + (*vec.z));
    return result;
}

VectorType VectorType::operator-(const VectorType& vec) {
    VectorType result(*x - (*vec.x), *y - (*vec.y), *z - (*vec.z));
    return result;
}

VectorType& VectorType::operator++() {
    ++(*x);
    ++(*y);
    ++(*z);
    return *this;
}

VectorType VectorType::operator++(int) {
    VectorType temp(*this);
    ++(*x);
    ++(*y);
    ++(*z);
    return temp;
}

VectorType& VectorType::operator--() {
    --(*x);
    --(*y);
    --(*z);
    return *this;
}

VectorType VectorType::operator--(int) {
    VectorType temp(*this);
    --(*x);
    --(*y);
    --(*z);
    return temp;
}

bool VectorType::operator==(const VectorType& vec) {
    return (*x == *vec.x) && (*y == *vec.y) && (*z == *vec.z);
}

bool VectorType::operator!=(const VectorType& vec) {
    return (*x != *vec.x) || (*y != *vec.y) || (*z != *vec.z);
}

istream& operator>>(istream& is, VectorType& vec) {
    is >> *vec.x >> *vec.y >> *vec.z;
    return is;
}

ostream& operator<<(ostream& os, const VectorType& vec) {
    os << "(" << *vec.x << "i," << *vec.y << "j," << *vec.z << "k)";
    return os;
}

double VectorType::length()const {
    return sqrt((*x * *x) + (*y * *y) + (*z * *z));
}

double VectorType::findAngle(const VectorType& vec) {
    double dotProduct = *x * (*vec.x) + *y * (*vec.y) + *z * (*vec.z);
    double lengthProduct = length() * vec.length();
    double angleInRadians = acos(dotProduct / lengthProduct);
    return angleInRadians * (180 / 3.14159265358979323846); // Convert radians to degrees
}

int main() {
    VectorType c1, c2;

    cout << "Enter x, y, z values for Vector 1: ";
    cin >> c1;
    cout << "Enter x, y, z values for Vector 2: ";
    cin >> c2;

    cout << "Vector 1: " << c1 << endl;
    cout << "Vector 2: " << c2 << endl;

    cout << "Dot Product: " << (c1 * c2) << endl;
    cout << "Length of Vector 1: " << c1.length() << endl;
    cout << "Length of Vector 2: " << c2.length() << endl;
    cout << "Angle between Vector 1 and Vector 2: " << c1.findAngle(c2) << " degrees" << endl;

    VectorType c3 = c1 + c2;
    cout << "Sum of Vectors: " << c3 << endl;

    VectorType c4 = c1 - c2;
    cout << "Difference of Vectors: " << c4 << endl;

    VectorType c5 = c1++;
    VectorType c6 = ++c2;
    cout << "Post-increment of Vector 1: " << c5 << endl;
    cout << "Pre-increment of Vector 2: " << c6 << endl;

    VectorType c7 = c1--;
    VectorType c8 = --c2;
    cout << "Post-decrement of Vector 1: " << c7 << endl;
    cout << "Pre-decrement of Vector 2: " << c8 << endl;

    cout << "Vector 1 == Vector 2? " << (c1 == c2 ? "Yes" : "No") << endl;
    cout << "Vector 1 != Vector 2? " << (c1 != c2 ? "Yes" : "No") << endl;

    return 0;
}
