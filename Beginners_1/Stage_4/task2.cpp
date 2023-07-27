/*
  This C++ program defines a 'Phone' class to store and display phone numbers.
  The class has private data members 'areaCode', 'exchange', and 'number' to represent the phone number components.

  - The default constructor is provided to initialize the phone number components to 0.

  - The 'Input' function allows the user to input the area code, exchange, and number.

  - The 'Display' function displays the phone number in the format (areaCode) exchange-number.

  Note: The program demonstrates the use of a class to represent phone numbers and the member functions to interact with class data.
  The 'Phone' class encapsulates the phone number details and provides methods to input and display phone numbers.
*/
#include <iostream>
using namespace std;

class Phone {
private:
    int areaCode;
    int exchange;
    int number;

public:
    Phone() : areaCode(0), exchange(0), number(0) {}

    void Input() {
        cout << "Enter your area code, exchange, and number: ";
        cin >> areaCode >> exchange >> number;
    }

    void Display() {
        cout << "My number is (" << areaCode << ") " << exchange << "-" << number << endl;
    }
};

int main() {
    Phone myNumber;
    Phone yourNumber;

    myNumber.Display();

    yourNumber.Input();

    cout << "Your number is ";
    yourNumber.Display();

    return 0;
}
