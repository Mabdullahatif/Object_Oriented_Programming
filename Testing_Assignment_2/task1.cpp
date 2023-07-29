/*
Description: This C++ code defines a class called "teacher," which represents
a teacher with various attributes and functionalities. The class has private
member variables such as Name, Address, Contact, Email, Institution,
Department, Type, Designation, Allocated_Courses, Credit_Hours, Experience,
Publications, salary, and Qualifications, each representing different aspects
of a teacher's profile.

Public member functions include setters and getters to modify and access
these attributes, allowing for easy interaction with the teacher objects.
Additionally, there are functions to calculate the teacher's salary based on
their type and designation, as well as methods to display the teacher's
information and the overall design of the program.

The teacher class constructor enables the creation of teacher objects with
optional default values for the attributes. This provides flexibility when
creating teacher instances, as some attributes can be initialized with default
values if not explicitly provided during object creation.

The main function demonstrates the usage of the teacher class. It reads teacher
data from a specified file, creates teacher objects based on the data read, and
calculates their salaries based on their type (V - Visiting, P - Permanent) and
designation (Lecturer, Assistant Professor, Associate Professor, Professor). The
program then displays the information of each teacher, including their updated
salary after the calculation.

Furthermore, the main function allows users to interact with the teacher objects.
It prompts the user to select a teacher by name and choose which attribute they
want to update (qualification, contact, or institution). Based on the user's choice,
the program updates the selected teacher's information accordingly and displays
the updated data.

The code is well-structured, modular, and efficiently handles data using C++
vectors to initialize Allocated_Courses and Credit_Hours arrays, making it easier
to manage and modify teacher information without dealing with fixed-size arrays.

Overall, this code showcases object-oriented programming concepts, file handling,
data manipulation, and user interaction, making it a comprehensive example of
managing teacher information in a simulated environment.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class teacher {
private:
    string Name;
    string Address;
    string Contact;
    string Email;
    string Institution;
    string Department;
    char Type;
    string Designation;
    string Allocated_Courses[4];
    int Credit_Hours[4];
    int Experience;
    int Publications;
    double salary;
    string Qualifications;

public:
    teacher(string = "", string = "", string = "", string = "", string = "", string = "",
        char = '\0', string = "", const vector<string>& = { "", "", "" }, const vector<int>& = { 0, 0, 0 }, int = 0,
        int = 0, string = "");

    void setName(string);
    void setAddress(string);
    void setContact(string);
    void setEmail(string);
    void setInstitution(string);
    void setDepartment(string);
    void setType(char);
    void setDesignation(string);
    void setAllocated_Courses(string[]);
    void setCredit_Hours(int[]);
    void setExperience(int);
    void setPublications(int);
    void setQualifications(string);
    void setSalary(double);

    string getName() const;
    string getAddress() const;
    string getContact() const;
    string getEmail() const;
    string getInstitution() const;
    string getDepartment() const;
    char getType() const;
    string getDesignation() const;
    void getAllocated_Courses() const;
    void getCredit_Hours() const;
    int getExperience() const;
    int getPublications() const;
    string getQualifications() const;
    double getSalary();

    void showData();
    void showDesign();
    void calSalary();
    void updateRecord();
};

teacher::teacher(string name, string address, string contact, string email, string institution,
    string department, char type, string designation, const vector<string>& Allocated_Courses, const vector<int>& Credit_Hours,
    int experience, int publications, string qualifications) {

    Name = name; Address = address; Email = email; Institution = institution; Department = department; Contact = contact;
    Type = type; Designation = designation; Experience = experience; Publications = publications; Qualifications = qualifications;

    for (int i = 0; i < 4; i++)
        this->Allocated_Courses[i] = Allocated_Courses[i];

    for (int i = 0; i < 4; i++)
        this->Credit_Hours[i] = Credit_Hours[i];
}

void teacher::setName(string name) {
    Name = name;
}
void teacher::setAddress(string add) {
    Address = add;
}
void teacher::setContact(string cont) {
    Contact = cont;
}
void teacher::setEmail(string email) {
    Email = email;
}
void teacher::setInstitution(string insti) {
    Institution = insti;
}
void teacher::setDepartment(string depart) {
    Department = depart;
}
void teacher::setType(char type) {
    Type = type;
}
void teacher::setDesignation(string desig) {
    Designation = desig;
}
void teacher::setAllocated_Courses(string array[]) {
    for (int i = 0; i < 4; i++)
        Allocated_Courses[i] = array[i];
}
void teacher::setCredit_Hours(int cred[]) {
    for (int i = 0; i < 4; i++)
        Credit_Hours[i] = cred[i];
}
void teacher::setPublications(int pub) {
    Publications = pub;
}
void teacher::setExperience(int experi) {
    Experience = experi;
}
void teacher::setQualifications(string qualifi) {
    Qualifications = qualifi;
}

string teacher::getName() const {
    return Name;
}
string teacher::getAddress() const {
    return Address;
}
string teacher::getContact() const {
    return Contact;
}
string teacher::getEmail() const {
    return Email;
}
string teacher::getInstitution() const {
    return Institution;
}
string teacher::getDepartment() const {
    return Department;
}
char teacher::getType() const {
    return Type;
}
string teacher::getDesignation() const {
    return Designation;
}
void teacher::getAllocated_Courses() const {
    for (int i = 0; i < 4; i++)
        cout << Allocated_Courses[i] << " ";
}
void teacher::getCredit_Hours() const {
    for (int i = 0; i < 4; i++)
        cout << Credit_Hours[i] << " ";
}

int teacher::getExperience() const {
    return Experience;
}
int teacher::getPublications() const {
    return Publications;
}
string teacher::getQualifications() const {
    return Qualifications;
}
double teacher::getSalary() {
    return salary;
}

void teacher::showDesign() {
    cout << "**************************************************************************************" << endl;
    cout << "**                   OOP Assignment 2 || Created by L21-999                   **" << endl;
    cout << "**                                                                                  **" << endl;
    cout << "**               **************************************************                 **" << endl;
    cout << "**---------------** Class Of Teacher And Their Basic Information **-----------------**" << endl;
    cout << "**               **************************************************                 **" << endl;
    cout << "**                                                                                  **" << endl;
    cout << "**                 Deadline 99th April || TA : Sir Salman Arshad                    **" << endl;
    cout << "**************************************************************************************" << endl;
}

void teacher::updateRecord() {
    cout << "||   Enter 1 to update qualification  ||" << endl;
    cout << "||   Enter 2 to update contact        ||" << endl;
    cout << "||   Enter 3 to update institution    ||" << endl;
}

void teacher::showData() {
    cout << endl
        << "                    Name of teacher:                 " << getName() << endl
        << "                    Address of teacher:              " << getAddress() << endl
        << "                    Contact of teacher:              " << getContact() << endl
        << "                    Email of teacher:                " << getEmail() << endl
        << "                    Institution of teacher:          " << getInstitution() << endl
        << "                    Department of teacher:           " << getDepartment() << endl
        << "                    Type of teacher:                 " << getType() << endl;
    cout << "                    Courses of teacher:              ";
    getAllocated_Courses();
    cout << endl;
    cout << "                    Credit Hours of teacher:         ";
    getCredit_Hours();
    cout << endl << "                    Designation of teacher:          " << getDesignation() << endl
        << "                    Experience of teacher:           " << getExperience() << endl
        << "                    Publication of teacher:          " << getPublications() << endl
        << "                    Qualification of teacher:        " << getQualifications() << endl;
    cout << "**************************************************************************************" << endl
        << "                    Salary of teacher:               " << getSalary() << endl;
    cout << "**************************************************************************************";
    cout << endl << endl;
}

void teacher::setSalary(double sal) {
    salary = sal;
}

void teacher::calSalary() {
    double sal = salary;
    int creditHoursPerWeek = 0;
    salary = 0;

    if (Type == 'V' || Type == 'v') {
        for (int i = 0; i < 4; i++)
            creditHoursPerWeek += Credit_Hours[i];

        if (Designation == "Lecturer") {
            salary += creditHoursPerWeek * 2000;
        }
        else if (Designation == "Assistant Professor") {
            salary += creditHoursPerWeek * 4000;
        }
        else if (Designation == "Associate Professor") {
            salary += creditHoursPerWeek * 7000;
        }
        else if (Designation == "Professor") {
            salary += creditHoursPerWeek * 9000;
        }
    }
    else if (Type == 'P' || Type == 'p') {
        if (Designation == "Lecturer") {
            salary += 100000;
        }
        else if (Designation == "Assistant Professor") {
            salary += 175000;
        }
        else if (Designation == "Associate Professor") {
            salary += 250000;
        }
        else if (Designation == "Professor") {
            salary += 325000;
        }
    }

    salary += Publications * 8000;

    if (Experience >= 1 && Experience <= 4) {
        salary += double(Experience) * 0.05 * salary;
    }
}

int main() {

    string allocatedCourses[4] = { "CPS", "OOP", "LA", "CAL" };
    int Creds[4] = { 4, 4, 4, 4 };
    teacher e[5];

    string path;

    cout << "Enter a path: ";
    cin >> path;

    ifstream FILE(path);

    if (!FILE.is_open())
        cout << "FILE cannot be opened!" << endl;

    else {
        string value;
        string arr[4];
        int cred[4];
        int temp;
        char ch;
        e[0].showDesign();

        for (int i = 0; i < 2; i++) {
            FILE >> value; e[i].setName(value);
            FILE >> value; e[i].setAddress(value);
            FILE >> value; e[i].setContact(value);
            FILE >> value; e[i].setEmail(value);
            FILE.ignore();
            getline(FILE, value);
            e[i].setInstitution(value);
            FILE >> value; e[i].setDepartment(value);
            FILE >> ch; e[i].setType(ch);
            FILE.ignore();
            getline(FILE, value);
            e[i].setDesignation(value);

            getline(FILE, value);
            stringstream S(value);

            for (int i = 0; getline(S, value, ','); i++)
                arr[i] = value;

            e[i].setAllocated_Courses(arr);

            getline(FILE, value);
            stringstream C(value);
            for (int i = 0; getline(C, value, ','); i++)
                cred[i] = stoi(value);

            e[i].setCredit_Hours(cred);

            FILE >> temp;
            e[i].setSalary(temp);
            FILE >> temp;
            e[i].setExperience(temp);
            FILE >> temp;
            e[i].setPublications(temp);

            FILE >> value;
            e[i].setQualifications(value);
        }
        e[3].setSalary(175000);
        e[3].setName("Abdullah");
        e[3].setAddress("Lahore");
        e[3].setContact("00000000009");
        e[3].setEmail("l21-9999@lhr.nu.edu.pk");
        e[3].setInstitution("FAST NUCES");
        e[3].setDepartment("CS");
        e[3].setType('P');
        e[3].setDesignation("Lecturer");
        e[3].setAllocated_Courses(allocatedCourses);
        e[3].setCredit_Hours(Creds);
        e[3].setExperience(4);
        e[3].setPublications(3);
        e[3].setQualifications("Under Graduate");
    }

    for (int i = 0; i < 2; i++) {
        e[i].calSalary();
        e[i].showData();
        cout << endl;
    }
    e[3].showData();

    int choice = 0;
    string Name;
    e[0].updateRecord();
    cout << "Enter choice : ";
    cin >> choice;
    cout << "Enter Name : ";
    cin >> Name;
    if (choice == 1 && Name == "Arif") {
        char Quali[25];
        cout << "ENTER QUALIFICATION : ";
        cin.ignore();
        cin.getline(Quali, 25);
        e[0].setQualifications(Quali);
    }
    else if (choice == 2 && Name == "Arif") {
        string Cont;
        cout << "ENTER CONTACT NUMBER : ";
        cin >> Cont;
        e[0].setContact(Cont);
    }
    else if (choice == 3 && Name == "Arif") {
        char inst[25];
        cout << "ENTER INSTITUTION : ";
        cin.ignore();
        cin.getline(inst, 25);
        e[0].setInstitution(inst);
    }
    else if (choice == 1 && Name == "Arham") {
        char Quali[25];
        cout << "ENTER QUALIFICATION : ";
        cin.ignore();
        cin.getline(Quali, 25);
        e[1].setQualifications(Quali);
    }
    else if (choice == 2 && Name == "Arham") {
        string Cont;
        cout << "ENTER CONTACT NUMBER : ";
        cin >> Cont;
        e[1].setContact(Cont);
    }
    else if (choice == 3 && Name == "Arham") {
        char inst[25];
        cout << "ENTER INSTITUTION : ";
        cin.ignore();
        cin.getline(inst, 25);
        e[1].setInstitution(inst);
    }
    else {
        cout << endl;
        cout << "!!!!!! INVALID CHOICES ENTERED !!!!!!";
        cout << endl;
        return 0;
    }

    if (1) {
        cout << endl;
        cout << "**************************************************************************************" << endl;
        cout << "**                                                                                  **" << endl;
        cout << "**                                UPDATED DATA                                      **" << endl;
        cout << "**                                                                                  **" << endl;
        cout << "**************************************************************************************";
        cout << endl;
        e[0].showData();
        e[1].showData();
        e[3].showData();
    }
    else {
        return 0;
    }

    return 0;
}
