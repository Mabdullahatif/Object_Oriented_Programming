/*
  This C++ program defines a 'fraction' class that represents fractions and provides various operations on them.
  
  - The 'fraction' class has private data members 'numerator' and 'denominator' to store the fraction components.
  
  - The class has a 'fractionsCount' static data member that keeps track of the number of fraction objects created.
  
  - The class has constructors to create a fraction object and initialize its numerator and denominator.
    It also has setter and getter functions for the numerator and denominator.
  
  - The class overloads the '+' and '*' operators to perform addition and multiplication of fractions, respectively.
    The overloaded '>' operator is provided to compare fractions.
  
  - The 'isProper' function checks if the fraction is a proper fraction.
  
  - The 'getCount' function returns the total number of fraction objects created.
  
  - The 'show' function displays the fraction in reduced form, whether it is proper or not, and the total number of fractions.
  
  In the 'main' function:
  - Two fraction objects ('f1' and 'f2') are created and initialized with different values.
  
  - The overloaded '+' and '*' operators are used to perform addition and multiplication of fractions.
    The 'show' function is called to display the results.
  
  - The overloaded '>' operator is used to compare two fractions, and the comparison result is displayed.
  
  - The values of 'f1' and 'f2' are changed using the setter functions, and the addition and multiplication operations are performed again.
  
  - The overloaded '>' operator is used again to compare the new fractions, and the comparison result is displayed.
  
  Note: The program demonstrates the implementation of a 'fraction' class with various member functions to manipulate and compare fractions.
  It shows how overloaded operators can be used to perform arithmetic and comparison operations on custom data types like fractions.
*/

#include <iostream>
using namespace std;

class fraction {
private:
    static int fractionsCount;
    int numerator;
    int denominator;

public:
    fraction(int n = 1, int d = 1);
    void setNum(int n);
    void setDen(int d);
    int getNum() const;
    int getDen() const;
    fraction operator+(const fraction& f) const;
    fraction operator*(const fraction& f) const;
    bool operator>(const fraction& f) const;
    bool isProper() const;
    static int getCount();
    void show() const;
};

int fraction::fractionsCount = 0;

fraction::fraction(int n, int d) {
    if (d == 0) {
        d = 1; // Ensure denominator is not zero
    }

    this->numerator = n;
    this->denominator = d;
    fractionsCount++;
}

void fraction::setNum(int n) {
    this->numerator = n;
}

void fraction::setDen(int d) {
    if (d != 0) {
        this->denominator = d;
    }
}

int fraction::getNum() const {
    return numerator;
}

int fraction::getDen() const {
    return denominator;
}

fraction fraction::operator+(const fraction& f) const {
    fraction result;
    result.numerator = (numerator * f.denominator) + (f.numerator * denominator);
    result.denominator = denominator * f.denominator;

    int div = 2;
    while (div <= result.numerator && div <= result.denominator) {
        if (result.numerator % div == 0 && result.denominator % div == 0) {
            result.numerator /= div;
            result.denominator /= div;
        } else {
            div++;
        }
    }
    return result;
}

fraction fraction::operator*(const fraction& f) const {
    fraction result;
    result.numerator = numerator * f.numerator;
    result.denominator = denominator * f.denominator;

    int div = 2;
    while (div <= result.numerator && div <= result.denominator) {
        if (result.numerator % div == 0 && result.denominator % div == 0) {
            result.numerator /= div;
            result.denominator /= div;
        } else {
            div++;
        }
    }
    return result;
}

bool fraction::operator>(const fraction& f) const {
    if (denominator == f.denominator) {
        return numerator > f.numerator;
    } else {
        return numerator * f.denominator > f.numerator * denominator;
    }
}

bool fraction::isProper() const {
    return numerator > denominator;
}

int fraction::getCount() {
    return fractionsCount;
}

void fraction::show() const {
    cout << "Reduced Form: " << numerator << "/" << denominator << endl;
    if (isProper()) {
        cout << "The Fraction Is Proper" << endl;
    } else {
        cout << "The Fraction Is Not Proper" << endl;
    }
    cout << "Number of Fractions: " << getCount() << endl;
}

int main() {
    fraction f1(4, 5), f2(6, 7);

    cout << "Hard-coded using constructor: " << endl;
    cout << "Fractions are 4/5 + 6/7" << endl;
    fraction f3 = f1 + f2;
    fraction f4 = f1 * f2;
    cout << "Addition of fractions: ";
    f3.show();
    cout << "Multiplication of fractions: ";
    f4.show();
    cout << endl;

    cout << "> Operator: " << endl;
    cout << "f1: 4/5, f2: 6/7" << endl;
    if (f1 > f2) {
        cout << "Fraction One > Fraction Two !!" << endl;
    } else {
        cout << "Fraction One Not > Fraction Two !!" << endl;
    }

    cout << "Hard-coded using setter function: " << endl;
    f1.setNum(9);
    f1.setDen(4);
    f2.setNum(8);
    f2.setDen(5);
    cout << "Fractions are 9/4 + 8/5" << endl;
    fraction f5 = f1 + f2;
    fraction f6 = f1 * f2;
    cout << "Addition of fractions: ";
    f5.show();
    cout << "Multiplication of fractions: ";
    f6.show();

    cout << "> Operator: " << endl;
    cout << "f5: 9/4, f6: 8/5" << endl;
    if (f5 > f6) {
        cout << "Fraction Five > Fraction Six !!" << endl;
    } else {
        cout << "Fraction Five Not > Fraction Six !!" << endl;
    }

    return 0;
}
