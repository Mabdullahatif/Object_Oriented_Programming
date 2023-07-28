/*
This C++ program defines a class called 'BiggerInt' that represents a dynamic array of integers.
The class has private data members 'big_int_' and 'int_length_' to store the array and its size,
respectively. The class provides a default constructor to initialize the array as nullptr and size to zero,
an overloaded constructor to allow the creation of an array with specified values, and a copy constructor
to create a new 'BiggerInt' object with the same data as an existing object. The destructor is implemented to
release the dynamically allocated memory when the object is destroyed.

The class supports various operations, including assignment, pre-increment, post-increment, pre-decrement,
and post-decrement using overloaded operators. It also provides getter and setter functions for the array and its size,
as well as an overloaded '[]' operator for element access.

In the 'main' function, the program demonstrates the use of the 'BiggerInt' class by creating two 'BiggerInt'
objects, 'e1' and 'e2', and initializing them with different arrays. It then performs pre-increment and post-increment
operations on the arrays using the overloaded operators and displays the results. Similarly, it demonstrates pre-decrement
and post-decrement operations and their corresponding results. The program finally prints the modified arrays after
the increment and decrement operations.
*/

#include <iostream>
using namespace std;

class BiggerInt {
private:
    int* big_int_;
    int int_length_;

public:
    BiggerInt();
    BiggerInt(const int* obj, int size);
    BiggerInt(const BiggerInt& obj);
    BiggerInt operator=(const BiggerInt& c);
    ~BiggerInt();

    void display();
    void setbig_int_(int*);
    void setint_length_(int);
    int* getbig_int_();
    int getint_length_();
    int& operator[](int);

    BiggerInt operator++(); // pre-increment
    BiggerInt operator++(int); // post-increment
    BiggerInt operator--(); // pre-decrement
    BiggerInt operator--(int); // post-decrement
};

BiggerInt::BiggerInt() {
    big_int_ = nullptr;
    int_length_ = 0;
}

BiggerInt::BiggerInt(const int* obj, int size) {
    int_length_ = size;
    big_int_ = new int[int_length_];
    for (int i = 0; i < int_length_; i++) {
        big_int_[i] = obj[i];
    }
}

BiggerInt::BiggerInt(const BiggerInt& obj) {
    int_length_ = obj.int_length_;
    big_int_ = new int[obj.int_length_];
    for (int i = 0; i < int_length_; i++) {
        big_int_[i] = obj.big_int_[i];
    }
}

BiggerInt BiggerInt::operator=(const BiggerInt& c) {
    if (this == &c) {
        return *this;
    }

    if (big_int_ != nullptr) {
        delete[] big_int_;
    }

    int_length_ = c.int_length_;
    big_int_ = new int[int_length_];
    for (int i = 0; i < int_length_; i++) {
        big_int_[i] = c.big_int_[i];
    }

    return *this;
}

BiggerInt::~BiggerInt() {
    delete[] big_int_;
}

void BiggerInt::display() {
    if (int_length_ == 0) {
        cout << "No value assigned";
    } else {
        for (int i = 0; i < int_length_; i++) {
            cout << big_int_[i];
        }
        cout << endl;
    }
}

void BiggerInt::setbig_int_(int* big) {
    big_int_ = big;
}

void BiggerInt::setint_length_(int len) {
    int_length_ = len;
}

int* BiggerInt::getbig_int_() {
    return big_int_;
}

int BiggerInt::getint_length_() {
    return int_length_;
}

int& BiggerInt::operator[](int index) {
    if (index >= int_length_) {
        cout << "Array index out of bounds, exiting";
        exit(0);
    }
    return big_int_[index];
}

BiggerInt BiggerInt::operator++() {
    for (int i = 0; i < int_length_; i++) {
        ++big_int_[i];
    }
    return *this;
}

BiggerInt BiggerInt::operator++(int) {
    BiggerInt copy = *this;
    for (int i = 0; i < int_length_; i++) {
        big_int_[i]++;
    }
    return copy;
}

BiggerInt BiggerInt::operator--() {
    for (int i = 0; i < int_length_; i++) {
        --big_int_[i];
    }
    return *this;
}

BiggerInt BiggerInt::operator--(int) {
    BiggerInt copy = *this;
    for (int i = 0; i < int_length_; i++) {
        big_int_[i]--;
    }
    return copy;
}
int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[4] = {6, 7, 8, 9};

    BiggerInt e1(arr1, 5);
    BiggerInt e2(arr2, 4);

    cout << "Array 1: ";
    e1.display();

    cout << "Array 2: ";
    e2.display();

    cout << "Using pre-increment on Array 1: ";
    (++e1).display();

    cout << "Using post-increment on Array 2: ";
    (e2++).display();

    cout << "After post-increment, Array 2: ";
    e2.display();

    cout << "Using pre-decrement on Array 1: ";
    (--e1).display();

    cout << "Using post-decrement on Array 2: ";
    (e2--).display();

    cout << "After post-decrement, Array 2: ";
    e2.display();

    return 0;
}