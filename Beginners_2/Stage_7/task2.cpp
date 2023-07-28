/*
This C++ program defines a class called 'Quadratic' that represents quadratic equations
of the form ax² + bx + c. The class has three private data members: 'a', 'b', and 'c',
to store the coefficients of the quadratic equation. The class provides a default constructor
to initialize the coefficients to zero and an overloaded constructor to allow custom initialization
of the coefficients. The copy constructor is also implemented to create a new 'Quadratic' object with
the same coefficient values as an existing object. The destructor is provided but does not perform any
specific actions as there is no dynamic memory allocation.

The class supports various arithmetic operations through overloaded operators, including addition,
subtraction, and multiplication by a constant. Additionally, it provides comparison operators for checking
the equality and inequality of 'Quadratic' objects. A friend function 'operator>>' is used to allow user input
of 'Quadratic' objects, prompting the user to enter the values of 'a', 'b', and 'c'. Another friend function 'operator<<'
is implemented to display the quadratic equation in the standard form (ax² + bx + c).

In the 'main' function, the program demonstrates the use of 'Quadratic' objects by performing arithmetic operations
(addition, multiplication) on them. It also allows user input to set the coefficients of a 'Quadratic' object and displays
the result. The program then compares two 'Quadratic' objects for equality and prints the respective messages based on the comparison result.
*/

#include <iostream>
using namespace std;

class Quadratic {
private:
    int a; // First part of the quadratic equation
    int b; // Second part of the equation
    int c; // Third part of the quadratic equation (ax² + bx + c)

public:
    Quadratic();
    Quadratic(int a, int b, int c); // overloaded constructor
    Quadratic(const Quadratic& other); // copy constructor
    ~Quadratic(); // destructor

    Quadratic operator+(const Quadratic& other) const; // add two quadratic objects
    Quadratic operator-(const Quadratic& other) const; // subtract one quadratic object from another
    Quadratic operator*(int constant) const; // multiply a constant with Quadratic object

    friend istream& operator>>(istream& in, Quadratic& quad); // input a quadratic object
    friend ostream& operator<<(ostream& out, const Quadratic& quad); // output a quadratic object

    bool operator==(const Quadratic& other) const; // equality operator
    bool operator!=(const Quadratic& other) const; // inequality operator

    Quadratic& operator=(const Quadratic& other); // assignment operator
};

Quadratic::Quadratic() : a(0), b(0), c(0) {}

Quadratic::Quadratic(int a, int b, int c) : a(a), b(b), c(c) {}

Quadratic::Quadratic(const Quadratic& other) {
    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
}

Quadratic::~Quadratic() {}

Quadratic Quadratic::operator+(const Quadratic& other) const {
    Quadratic result;
    result.a = this->a + other.a;
    result.b = this->b + other.b;
    result.c = this->c + other.c;
    return result;
}

Quadratic Quadratic::operator-(const Quadratic& other) const {
    Quadratic result;
    result.a = this->a - other.a;
    result.b = this->b - other.b;
    result.c = this->c - other.c;
    return result;
}

Quadratic Quadratic::operator*(int constant) const {
    Quadratic result;
    result.a = this->a * constant;
    result.b = this->b * constant;
    result.c = this->c * constant;
    return result;
}

istream& operator>>(istream& in, Quadratic& quad) {
    cout << "Enter coefficients (a b c): ";
    in >> quad.a >> quad.b >> quad.c;
    return in;
}

ostream& operator<<(ostream& out, const Quadratic& quad) {
    out << quad.a << "x^2 + " << quad.b << "x + " << quad.c;
    return out;
}

bool Quadratic::operator==(const Quadratic& other) const {
    return (this->a == other.a && this->b == other.b && this->c == other.c);
}

bool Quadratic::operator!=(const Quadratic& other) const {
    return !(*this == other);
}

Quadratic& Quadratic::operator=(const Quadratic& other) {
    if (this == &other) {
        return *this;
    }

    this->a = other.a;
    this->b = other.b;
    this->c = other.c;
    return *this;
}


int main() {
    Quadratic q1(1, 2, 3), q2(2, 3, 4), q3, q4;
    q3 = q1 + q2;
    cout << "q1 + q2 = " << q3 << endl;

    q4 = q1 * 2;
    cout << "q1 * 2 = " << q4 << endl;

    cout << "Enter values for a, b, c for q3: ";
    cin >> q3;
    cout << "q3 = " << q3 << endl;

    if (q1 == q2) {
        cout << "q1 and q2 are equal" << endl;
    } else {
        cout << "q1 and q2 are not equal" << endl;
    }

    return 0;
}