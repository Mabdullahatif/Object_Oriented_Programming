/*
This C++ program demonstrates the implementation of a simple dynamic array-like class called 'Vector' using templates.

The 'Vector' class has the following features:
1. Dynamic Resizing: When the number of elements exceeds the capacity, the array is dynamically resized to double its current capacity.
2. Insert Element: It allows inserting elements at the end of the array.
3. Copy Constructor: It has a copy constructor that creates a new vector by copying the elements from another vector.
4. Destructor: It deallocates the dynamically allocated memory for the array when the vector goes out of scope.

In the 'main' function:
1. An 'int' type vector 'iv1' with an initial capacity of 2 is created.
2. Three elements (5, 6, and 1) are inserted into 'iv1'.
3. A new vector 'iv2' is created by using the copy constructor with 'iv1' as the argument.
4. The 'iv2' vector is printed using the overloaded '<<' operator, which prints the elements of the vector.

Sample output:
------------------
5 6 1
------------------
The 'iv2' vector is a copy of 'iv1', and it contains the same elements as 'iv1'.
*/

#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* arrayPtr;
    int capacity;
    int totalElements;

public:
    Vector(int cap) : capacity(cap), totalElements(0) {
        arrayPtr = new T[capacity];
    }

    Vector(const Vector& other) : capacity(other.capacity), totalElements(other.totalElements) {
        arrayPtr = new T[capacity];
        for (int i = 0; i < totalElements; ++i) {
            arrayPtr[i] = other.arrayPtr[i];
        }
    }

    ~Vector() {
        delete[] arrayPtr;
    }

    void insertElement(const T& param) {
        if (totalElements == capacity) {
            capacity *= 2;
            T* newArrayPtr = new T[capacity];
            for (int i = 0; i < totalElements; ++i) {
                newArrayPtr[i] = arrayPtr[i];
            }
            delete[] arrayPtr;
            arrayPtr = newArrayPtr;
        }
        arrayPtr[totalElements++] = param;
    }

    friend ostream& operator<<(ostream& os, const Vector& vec) {
        for (int i = 0; i < vec.totalElements; ++i) {
            os << vec.arrayPtr[i] << " ";
        }
        return os;
    }

    int getTotalElements() const {
        return totalElements;
    }

    int getCapacity() const {
        return capacity;
    }
};

int main() {
    Vector<int> iv1(2);
    iv1.insertElement(5);
    iv1.insertElement(6);
    iv1.insertElement(1);

    Vector<int> iv2(iv1);
    cout << iv2 << endl;

    return 0;
}
