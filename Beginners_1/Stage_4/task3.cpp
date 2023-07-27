/*
  This C++ program defines a 'Date' class to represent dates in day/month/year format.
  The class has private data members 'day', 'month', and 'year' to store the date components.

  - The default constructor initializes the date to 1/1/1926 and displays a message indicating its call.

  - The 'Print' function displays the date in day/month/year format.

  - The 'Input' function allows the user to input the day, month, and year.

  - The 'SetDay', 'SetMonth', and 'SetYear' functions set the day, month, and year, respectively.

  - The 'GetDay', 'GetMonth', and 'GetYear' functions return the day, month, and year, respectively.


  Note: The program demonstrates the use of a class to represent dates and the member functions to interact with date components.
  It also showcases the constructor and how member functions can be used to set and get the date components.
*/
#include <iostream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date() : day(1), month(1), year(1926) {
        cout << "Default Constructor Called" << endl;
    }

    void Print() {
        cout << day << "/" << month << "/" << year << endl;
    }

    void Input() {
        cout << "Enter day, month, and year: ";
        cin >> day >> month >> year;
    }

    void SetDay(int d) {
        day = d;
    }

    void SetMonth(int m) {
        month = m;
    }

    void SetYear(int y) {
        year = y;
    }

    int GetDay() {
        return day;
    }

    int GetMonth() {
        return month;
    }

    int GetYear() {
        return year;
    }
};

int main() {
    Date date1;
    date1.Print();

    date1.Input();
    date1.Print();

    Date xmasDay;
    xmasDay.Print();

    xmasDay.SetDay(25);
    xmasDay.SetMonth(12);
    xmasDay.SetYear(2020);

    cout << "Updated Christmas Day: ";
    xmasDay.Print();

    return 0;
}
