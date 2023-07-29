/*
Description: This C++ code defines a class "Roman" to represent Roman numerals and their operations.
The class provides functionalities to convert Roman numerals to decimal numbers and vice versa.
It also overloads arithmetic operators (+, -, *, /), comparison operators (>, ==), and
prefix/postfix increment and decrement operators (++ and --).

The "Roman" class contains private member variables "RomanV" (string for Roman numeral) and
"RomanN" (integer for decimal value). It also has public member variables "variable" (string for Roman numeral)
and "number" (integer for decimal value).

The main function demonstrates the usage of the "Roman" class. It prompts the user to enter two Roman numerals
and performs various operations on them, such as addition, subtraction, multiplication, and division. The result
of each operation is displayed in Roman numerals.

Additionally, the code tests the comparison operators (== and >) and the prefix/postfix increment and decrement
operators for Roman numerals.

The "Roman" class provides a convenient way to work with Roman numerals and perform basic arithmetic operations
on them. It's a useful tool for handling Roman numerals in C++ programs.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Roman {
private:
    string RomanV;
    int RomanN;

public:
    Roman();
    Roman(string, int);

    string variable;
    int number = 0;

    friend Roman operator+(const Roman&, const Roman&);
    friend Roman operator-(const Roman&, const Roman&);
    friend Roman operator*(const Roman&, const Roman&);
    friend Roman operator/(const Roman&, const Roman&);
    friend bool operator>(const Roman&, const Roman&);
    friend bool operator==(const Roman&, const Roman&);

    Roman& operator++();       // Prefix increment
    Roman operator++(int);     // Postfix increment
    Roman& operator--();       // Prefix decrement
    Roman operator--(int);     // Postfix decrement

    int ConvertToDnumber(string) const;
    string ConvertToRvariable(int) const;
};

Roman::Roman() {
    RomanV = '\0';
    RomanN = 0;
}

Roman::Roman(string v, int n) {
    RomanV = v;
    RomanN = n;
}

Roman operator+(const Roman& V1, const Roman& V2) {
    Roman V;
    V.number = V1.number + V2.number;
    return V;
}

Roman operator-(const Roman& V1, const Roman& V2) {
    Roman V;
    if (V1.number - V2.number > 1) {
        V.number = V1.number - V2.number;
        return V;
    }
    else {
        cout << " (It is less than 1 so no Roman Variable)";
        return V;
    }
}

Roman operator*(const Roman& V1, const Roman& V2) {
    Roman V;
    V.number = V1.number * V2.number;
    return V;
}

Roman operator/(const Roman& V1, const Roman& V2) {
    Roman V;
    if (V1.number / V2.number > 1) {
        V.number = V1.number / V2.number;
        return V;
    }
    else {
        cout << " (It is less than 1 so no Roman Variable)";
        return V;
    }
}

bool operator>(const Roman& V1, const Roman& V2) {
    if (V1.variable > V2.variable) {
        return true;
    }
    else {
        return false;
    }
}

bool operator==(const Roman& V1, const Roman& V2) {
    if (V1.variable == V2.variable) {
        return true;
    }
    else {
        return false;
    }
}

int Roman::ConvertToDnumber(string str) const {
    Roman decimal;
    for (int i = 0; i < str.length(); i++) {
        switch (str[i]) {
        case 'M':
            decimal.number += 1000;
            break;
        case 'm':
            decimal.number += 1000;
            break;
        case 'D':
            decimal.number = decimal.number + 500;
            break;
        case 'd':
            decimal.number = decimal.number + 500;
            break;
        case 'C':
            decimal.number = decimal.number + 100;
            break;
        case 'c':
            decimal.number = decimal.number + 100;
            break;
        case 'L':
            decimal.number = decimal.number + 50;
            break;
        case 'l':
            decimal.number = decimal.number + 50;
            break;
        case 'X':
            decimal.number = decimal.number + 10;
            break;
        case 'x':
            decimal.number = decimal.number + 10;
            break;
        case 'V':
            decimal.number = decimal.number + 5;
            break;
        case 'v':
            decimal.number = decimal.number + 5;
            break;
        case 'I':
            decimal.number = decimal.number + 1;
            break;
        case 'i':
            decimal.number = decimal.number + 1;
            break;
        default:
            cout << "\n\n\n!!!Invalid Input!!!";
        }
    }
    return decimal.number;
}

string Roman::ConvertToRvariable(int num) const {
    Roman roman;
    while (num > 0) {
        if (num >= 1000) {
            roman.variable = roman.variable + "M";
            num = num - 1000;
        }
        else if (num >= 500) {
            roman.variable = roman.variable + "D";
            num = num - 500;
        }
        else if (num >= 100) {
            roman.variable = roman.variable + "C";
            num = num - 100;
        }
        else if (num >= 50) {
            roman.variable = roman.variable + "L";
            num = num - 50;
        }
        else if (num >= 10) {
            roman.variable = roman.variable + "X";
            num = num - 10;
        }
        else if (num >= 5) {
            roman.variable = roman.variable + "V";
            num = num - 5;
        }
        else if (num >= 1) {
            roman.variable = roman.variable + "I";
            num = num - 1;
        }
        else {
            exit(0);
        }
    }
    roman.number = num;
    return roman.variable;
}

Roman& Roman::operator++() {
    // Prefix increment
    this->number++;
    this->variable = ConvertToRvariable(this->number);
    return *this;
}

Roman Roman::operator++(int) {
    // Postfix increment
    Roman temp = *this;
    this->number++;
    this->variable = ConvertToRvariable(this->number);
    return temp;
}

Roman& Roman::operator--() {
    // Prefix decrement
    if (this->number > 1) {
        this->number--;
        this->variable = ConvertToRvariable(this->number);
    }
    else {
        cout << " (It is less than 1 so no Roman Variable)";
    }
    return *this;
}

Roman Roman::operator--(int) {
    // Postfix decrement
    Roman temp = *this;
    if (this->number > 1) {
        this->number--;
        this->variable = ConvertToRvariable(this->number);
    }
    else {
        cout << " (It is less than 1 so no Roman Variable)";
    }
    return temp;
}

int main() {
    endl(cout);
    string str1, str2;
    Roman obj1, obj2;
    Roman result;

    cout << "Enter The First Roman Variable : ";
    cin >> str1;
    endl(cout);
    cout << "Enter The Second Roman Variable : ";
    cin >> str2;
    endl(cout);

    obj1.variable = str1;
    obj2.variable = str2;

    int num1 = obj1.ConvertToDnumber(str1);
    int num2 = obj2.ConvertToDnumber(str2);

    obj1.number = num1;
    obj2.number = num2;

    int num = num1 + num2;
    cout << "Decimal Value Of Both Roman variables : ";
    cout << num1 << " & " << num2;
    cout << "\n\n";
    result = obj1 + obj2;
    result.variable = result.ConvertToRvariable(num);
    cout << "Decimal Addition Of Both Roman Variables : ";
    cout << result.variable << "\n\n";

    cout << "Decimal Subtraction Of Both Roman Variables : ";
    result = obj1 - obj2;
    num = num1 - num2;
    result.variable = result.ConvertToRvariable(num);
    cout << result.variable << "\n\n";

    num = num1 * num2;
    result.variable = result.ConvertToRvariable(num);
    cout << "Decimal Multiplication Of Both Roman Variables : ";
    cout << result.variable << "\n\n";

    cout << "Decimal Division Of Both Roman Variables : ";
    result = obj1 / obj2;
    num = num1 / num2;
    result.variable = result.ConvertToRvariable(num);
    cout << result.variable << "\n\n";

    if (obj1.variable == obj2.variable) {
        cout << "== Condition Check For Both Roman Variables !! ";
        endl(cout);
        cout << "The Roman Value " << str1 << " == " << str2 << endl;
    }
    else {
        cout << "== Condition Check For Both Roman Variables !! ";
        endl(cout);
        cout << "The Roman Value " << str1 << " != " << str2 << endl;
    }

    endl(cout);
    if (obj1.number > obj2.number) {
        cout << "> Condition Check For Both Roman Variables !! ";
        endl(cout);
        cout << "The Larger Roman Number Is  " << obj1.variable << " : " << obj1.number << " >= " << obj2.number;
    }
    else {
        cout << "> Condition Check For Both Roman Variables !! ";
        endl(cout);
        cout << "The Larger Roman Number Is  " << obj2.variable << " : " << obj2.number << " >= " << obj1.number;
    }

    endl(cout);
    cout << "Testing Prefix Increment" << endl;
    Roman inc_result = ++result;
    cout << "After Prefix Increment: " << inc_result.variable << endl;

    cout << "Testing Postfix Increment" << endl;
    inc_result = result++;
    cout << "After Postfix Increment: " << inc_result.variable << endl;

    cout << "Testing Prefix Decrement" << endl;
    Roman dec_result = --result;
    cout << "After Prefix Decrement: " << dec_result.variable << endl;

    cout << "Testing Postfix Decrement" << endl;
    dec_result = result--;
    cout << "After Postfix Decrement: " << dec_result.variable << endl;

    cout << "\n\n********************************END OF PROGRAM THANK YOU*********************************";
    return 0;
}
