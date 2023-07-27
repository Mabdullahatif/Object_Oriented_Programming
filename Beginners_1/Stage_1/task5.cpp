/*
  This C++ program calculates the median of three constant integer values 'a', 'b', and 'c'.
  It uses pointers to compare the values and finds the median by checking the order of the values.

  - Declare three constant integer variables 'a', 'b', and 'c' with initial values.
  - Declare three constant integer pointers 'pa', 'pb', and 'pc' and assign them the addresses of 'a', 'b', and 'c' respectively.
  - Declare an integer variable 'median' to store the calculated median value.
  - Compare the three values using pointers to determine the median:
    - If 'a' is in between 'b' and 'c' or vice versa, set 'median' to 'a'.
    - If 'b' is in between 'a' and 'c' or vice versa, set 'median' to 'b'.
    - Otherwise, set 'median' to 'c'.
  - The program then uses const_cast to modify the constant values of 'a', 'b', or 'c' to -1 through the pointers,
    effectively updating the value that was used as the median.
  - Display the calculated median value.
  - Display the updated values of 'a', 'b', and 'c' to show that one of them is now -1.

  Note: The const_cast is used to modify the constant values, but it is generally not recommended to modify
  constant variables as it can lead to undefined behavior. This code is for illustrative purposes only.
*/
#include <iostream>
using namespace std;

int main() {
    const int a = 5;
    const int b = 12;
    const int c = 10;
    const int *pa = &a;
    const int *pb = &b;
    const int *pc = &c;

    int median = 0;

    if ((*pa <= *pb && *pa >= *pc) || (*pa >= *pb && *pa <= *pc)) {
        median = *pa;
        const_cast<int&>(a) = -1; // Updating median value to -1 through pointers
    } else if ((*pb <= *pa && *pb >= *pc) || (*pb >= *pa && *pb <= *pc)) {
        median = *pb;
        const_cast<int&>(b) = -1; // Updating median value to -1 through pointers
    } else {
        median = *pc;
        const_cast<int&>(c) = -1; // Updating median value to -1 through pointers
    }

    cout << "Median is = " << median << endl;
    cout << "Updated values of a, b, and c are: " << a << ", " << b << ", " << c << endl;

    return 0;
}
