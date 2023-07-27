/*
  This C++ program defines a 'Sample' class with multiple constructors to demonstrate constructor overloading.

  The 'Sample' class has private data members 'x' (an integer) and 'y' (a double).

  The class includes the following constructors:
  1. Default constructor: Initializes 'x' to 0 and 'y' to 0.0.
  2. Constructor with one integer parameter: Initializes 'x' with the provided integer value and 'y' to 0.0.
  3. Constructor with two integer parameters: Initializes 'x' and 'y' with the provided integer values.
  4. Constructor with one integer and one double parameter: Initializes 'x' with the integer value and 'y' with the double value.
  
  In the 'main' function:
  - Four instances of the 'Sample' class ('s1', 's2', 's3', and 's4') are created using different constructors.
  Note: The program showcases constructor overloading, which allows the 'Sample' class to be initialized with different combinations of values for 'x' and 'y'.
*/
#include <iostream>
using namespace std;

class Sample {
private:
    int x;
    double y;

public:
    Sample() : x(0), y(0.0) {}
    Sample(int val) : x(val), y(0.0) {}
    Sample(int val1, int val2) : x(val1), y(val2) {}
    Sample(int val1, double val2) : x(val1), y(val2) {}
};

int main() {
    Sample s1;
    Sample s2(10);
    Sample s3(20, 30);
    Sample s4(40, 3.14);

    return 0;
}
