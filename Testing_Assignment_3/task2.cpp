/*
Description: This C++ code defines a class "String" that represents a dynamic string.
The class provides various string manipulation functionalities, including conversion
to uppercase and lowercase, string concatenation, substring extraction, index search,
comparison, and overloaded operators for concatenation, assignment, comparison, and
indexing.

The "String" class contains a private member variable "text," which is a dynamically
allocated character array to store the string. Public member functions include
constructors (default, parameterized, and copy), a destructor, and methods for string
manipulation. The class also overloads operators for concatenation (+), assignment (=),
comparison (==, !=, <, >), and indexing ([]).

In the main function, the code demonstrates the usage of the "String" class. It creates
two "String" objects "str1" and "str2," performs string concatenation using the + operator,
and stores the result in "str3." The code then prompts the user to enter a string and
displays the entered string using the overloaded insertion (<<) operator.

The "String" class provides a flexible and efficient implementation for string
manipulation and is suitable for applications requiring dynamic string handling. The
main function showcases the functionality of the "String" class through string
concatenation and user input, making it a practical and reusable code snippet for string
processing in C++.
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

class String {
private:
    char* text;

public:
    String(); // Default constructor
    String(const char* str); // Parameterized constructor
    String(const String& other); // Copy constructor
    ~String(); // Destructor

    // Operations
    int length() const;
    String upper() const;
    String lower() const;
    char at(int index) const;
    String substring(int start, int end) const;
    int index(const char* substr) const;
    int compare(const String& other) const;
    void concat(const char* str);
    void concat(const String& other);
    void concat(char ch);
    void concat(int num);
    void concat(float num);
    void prepend(const char* str);
    void prepend(const String& other);
    void prepend(char ch);
    void prepend(int num);
    void prepend(float num);

    // Operators
    String operator+(const String& other) const;
    String operator+(const char* str) const;
    String operator+(char ch) const;
    String operator+(int num) const;
    String operator+(float num) const;
    String& operator=(const String& other);
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;
    char operator[](int index) const;
    char& operator[](int index);
    friend istream& operator>>(istream& is, String& str);
    friend ostream& operator<<(ostream& os, const String& str);
};

// Default constructor
String::String() {
    text = new char[1];
    text[0] = '\0';
}

// Parameterized constructor
String::String(const char* str) {
    int len = strlen(str);
    text = new char[len + 1];
    strcpy(text, str);
}

// Copy constructor
String::String(const String& other) {
    int len = other.length();
    text = new char[len + 1];
    strcpy(text, other.text);
}

// Destructor
String::~String() {
    delete[] text;
}

int String::length() const {
    return strlen(text);
}

String String::upper() const {
    String result(*this);
    for (int i = 0; i < result.length(); i++) {
        result.text[i] = toupper(result.text[i]);
    }
    return result;
}

String String::lower() const {
    String result(*this);
    for (int i = 0; i < result.length(); i++) {
        result.text[i] = tolower(result.text[i]);
    }
    return result;
}

char String::at(int index) const {
    if (index >= 0 && index < length()) {
        return text[index];
    }
    return '\0';
}

String String::substring(int start, int end) const {
    if (start < 0 || start >= length() || end < 0 || end >= length() || start > end) {
        return String();
    }

    int len = end - start + 1;
    char* sub = new char[len + 1];
    strncpy(sub, text + start, len);
    sub[len] = '\0';

    String result(sub);
    delete[] sub;
    return result;
}

int String::index(const char* substr) const {
    char* pos = strstr(text, substr);
    if (pos != nullptr) {
        return pos - text;
    }
    return -1;
}

int String::compare(const String& other) const {
    return strcmp(text, other.text);
}

void String::concat(const char* str) {
    int len1 = length();
    int len2 = strlen(str);
    char* temp = new char[len1 + len2 + 1];
    strcpy(temp, text);
    strcat(temp, str);
    delete[] text;
    text = temp;
}

void String::concat(const String& other) {
    concat(other.text);
}

void String::concat(char ch) {
    int len1 = length();
    char* temp = new char[len1 + 2];
    strcpy(temp, text);
    temp[len1] = ch;
    temp[len1 + 1] = '\0';
    delete[] text;
    text = temp;
}

void String::concat(int num) {
    char buffer[20];
    sprintf(buffer, "%d", num);
    concat(buffer);
}

void String::concat(float num) {
    char buffer[20];
    sprintf(buffer, "%f", num);
    concat(buffer);
}

void String::prepend(const char* str) {
    int len1 = strlen(str);
    int len2 = length();
    char* temp = new char[len1 + len2 + 1];
    strcpy(temp, str);
    strcat(temp, text);
    delete[] text;
    text = temp;
}

void String::prepend(const String& other) {
    prepend(other.text);
}

void String::prepend(char ch) {
    int len1 = 1;
    int len2 = length();
    char* temp = new char[len1 + len2 + 1];
    temp[0] = ch;
    strcpy(temp + 1, text);
    delete[] text;
    text = temp;
}

void String::prepend(int num) {
    char buffer[20];
    sprintf(buffer, "%d", num);
    prepend(buffer);
}

void String::prepend(float num) {
    char buffer[20];
    sprintf(buffer, "%f", num);
    prepend(buffer);
}

String String::operator+(const String& other) const {
    String result(*this);
    result.concat(other);
    return result;
}

String String::operator+(const char* str) const {
    String result(*this);
    result.concat(str);
    return result;
}

String String::operator+(char ch) const {
    String result(*this);
    result.concat(ch);
    return result;
}

String String::operator+(int num) const {
    String result(*this);
    result.concat(num);
    return result;
}

String String::operator+(float num) const {
    String result(*this);
    result.concat(num);
    return result;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] text;
        int len = other.length();
        text = new char[len + 1];
        strcpy(text, other.text);
    }
    return *this;
}

bool String::operator==(const String& other) const {
    return compare(other) == 0;
}

bool String::operator!=(const String& other) const {
    return compare(other) != 0;
}

bool String::operator<(const String& other) const {
    return compare(other) < 0;
}

bool String::operator>(const String& other) const {
    return compare(other) > 0;
}

char String::operator[](int index) const {
    return at(index);
}

char& String::operator[](int index) {
    if (index >= 0 && index < length()) {
        return text[index];
    }
    // Return the first character of the string if the index is out of bounds
    return text[0];
}

istream& operator>>(istream& is, String& str) {
    char buffer[1000];
    is.getline(buffer, sizeof(buffer));
    str = buffer;
    return is;
}

ostream& operator<<(ostream& os, const String& str) {
    os << str.text;
    return os;
}

int main() {
    String str1("Hello");
    String str2("World");
    String str3 = str1 + " " + str2; // Concatenation using + operator
    cout << str3 << endl; // Output: "Hello World"

    String str4;
    cout << "Enter a string: ";
    cin >> str4;
    cout << "You entered: " << str4 << endl;

    return 0;
}
