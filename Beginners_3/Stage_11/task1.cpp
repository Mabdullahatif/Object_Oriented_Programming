/*
This C++ program demonstrates the use of a function template to compare two values for equality.

The function template 'isEqualTo' is defined, which takes two parameters of the same data type 'T'.
It compares the values of 'a' and 'b' using the '==' operator and returns true if they are equal, otherwise false.

In the 'main' function, we have variables of different data types: 'num1' and 'num2' of type int, 'f1' and 'f2' of type float, and 'ch1' and 'ch2' of type char.

The 'isEqualTo' function is called with each pair of variables, and the result is printed to the console.

Sample output:
------------------
Is num1 equal to num2? 0
Is f1 equal to f2? 1
Is ch1 equal to ch2? 0
------------------
Here, num1 is not equal to num2, f1 is equal to f2, and ch1 is not equal to ch2.
*/

#include <iostream>
using namespace std;

template <typename T>
bool isEqualTo(T a, T b) {
    return a == b;
}

int main() {
    int num1 = 5, num2 = 10;
    float f1 = 3.14, f2 = 3.14;
    char ch1 = 'A', ch2 = 'B';

    cout << "Is num1 equal to num2? " << isEqualTo(num1, num2) << endl;
    cout << "Is f1 equal to f2? " << isEqualTo(f1, f2) << endl;
    cout << "Is ch1 equal to ch2? " << isEqualTo(ch1, ch2) << endl;

    return 0;
}
