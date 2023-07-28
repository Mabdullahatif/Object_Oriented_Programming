/*
This C++ program takes a person's date of birth in numeric form (e.g., 8-27-1980) and parses it to validate the day, month, and year.

The 'parseDate' function:
1. Parses the input string to extract the day, month, and year components.
2. Checks if the day, month, and year are valid according to the given rules.
3. If any component is invalid, it throws the corresponding exception: invalidDay, invalidMonth, or invalidYear.
4. If the date is valid, it prints the date in a more readable format (e.g., "August 27, 1980").

The 'isLeapYear' function:
1. Determines whether a year is a leap year or not based on the leap year rules.

In the 'main' function:
1. Asks the user to enter a person's date of birth in numeric form.
2. Calls the 'parseDate' function to validate and parse the input date.
3. Catches any exceptions thrown during the parsing process and prints an error message accordingly.

Sample output 1:
------------------
Enter a person's date of birth in numeric form (e.g., 8-27-1980): 12-31-2000
December 31, 2000
------------------

Sample output 2:
------------------
Enter a person's date of birth in numeric form (e.g., 8-27-1980): 2-30-1995
Invalid day!
------------------
*/

#include <iostream>
#include <string>
using namespace std;

class invalidDay {};
class invalidMonth {};
class invalidYear {};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void parseDate(const string& date) {
    int month, day, year;
    char dash1, dash2;

    if (sscanf(date.c_str(), "%d%c%d%c%d", &month, &dash1, &day, &dash2, &year) != 5) {
        throw invalidDay();
    }

    if (month < 1 || month > 12) {
        throw invalidMonth();
    }

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1]) {
        throw invalidDay();
    }

    if (year < 0) {
        throw invalidYear();
    }

    string monthNames[] = { "January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December" };
    cout << monthNames[month - 1] << " " << day << ", " << year << endl;
}

int main() {
    string date;
    cout << "Enter a person's date of birth in numeric form (e.g., 8-27-1980): ";
    cin >> date;

    try {
        parseDate(date);
    }
    catch (const invalidDay&) {
        cout << "Invalid day!" << endl;
    }
    catch (const invalidMonth&) {
        cout << "Invalid month!" << endl;
    }
    catch (const invalidYear&) {
        cout << "Invalid year!" << endl;
    }

    return 0;
}
