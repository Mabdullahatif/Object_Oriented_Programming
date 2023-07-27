/*
  This C++ program defines a 'Student' class to store and display student data.
  The class has private data members 'name', 'eng' (English marks), 'math' (Math marks), 'science' (Science marks), and 'total' (total marks).
  It includes member functions:

  1. 'TakeData': To input student details such as name, marks in English, Math, and Science, and calculate the total marks.

  2. 'ShowData': To display the student's name, marks in English, Math, Science, and the total marks.

  The 'main' function creates two instances of the 'Student' class ('s1' and 's2').
  It then calls the 'TakeData' function for both instances to input student data and calculates the total marks.
  After that, it calls the 'ShowData' function for both instances to display the student details, including the total marks.

  Note: The program showcases the use of a class to represent student data, member functions to interact with class data,
  and the concept of encapsulation to keep data private.
*/
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    float eng, math, science;
    float total;

public:
    void TakeData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks in English: ";
        cin >> eng;
        cout << "Enter marks in Math: ";
        cin >> math;
        cout << "Enter marks in Science: ";
        cin >> science;
        total = cTotal();
    }

    void ShowData() {
        cout << "Name: " << name << endl;
        cout << "English: " << eng << endl;
        cout << "Math: " << math << endl;
        cout << "Science: " << science << endl;
        cout << "Total: " << total << endl;
    }

    float cTotal() {
        return eng + math + science;
    }
};

int main() {
    Student s1, s2;
    s1.TakeData();
    s2.TakeData();
    cout << "\nStudent 1 Data:\n";
    s1.ShowData();
    cout << "\nStudent 2 Data:\n";
    s2.ShowData();

    return 0;
}
