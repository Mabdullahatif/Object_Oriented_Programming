/*
This C++ program defines several classes related to employees, including 'Employee', 'Employee2', 'manager', 'scientist', and 'laborer'.

The 'Employee' class has two protected attributes 'name' and 'number' and two member functions 'getdata' and 'putdata'.
'getdata' is used to display the employee's name and number, while 'putdata' is used to set the 'name' and 'number' attributes.

The 'Employee2' class is derived from 'Employee' and has two additional protected attributes 'compensation' and 'time'.
It also has two member functions, 'input' to set the compensation and time, and 'show' to display these attributes.

The 'manager', 'scientist', and 'laborer' classes are all derived from 'Employee2' and represent different types of employees.
Each of these classes has a 'input' function to set the attributes inherited from the base class as well as their own attributes.
They also have an 'output' function to display all the attributes including name, number, compensation, and time for the respective employee type.

In the 'main' function, the program creates objects of 'manager', 'scientist', and 'laborer' classes, and uses the 'input' function to set their attributes.
Then it calls the 'output' function for each employee type to display their information.
*/

#include<iostream>
using namespace std;
class Employee{
protected:
string name;
string number;
public:
void getdata(){
    cout<<name<<" "<<number;
}
void putdata(string name,string num){
    this->name=name;
    this->number=num;
}
};
class Employee2:public Employee{
protected:
    double compensation;
    string time;
public:
    void input(double compens,string time){
        this->compensation=compens;
        this->time=time;
    }
    void show(){
        cout<<compensation<<" "<<time;
    }
};
class manager:public Employee2{
public:
    void input(string name,string num,double compens,string time){
        this->name=name;
        this->number=num;
        this->compensation=compens;
        this->time=time;
    }
    void output(){
        cout<<name;endl(cout);
        cout<<number;endl(cout);
        cout<<compensation;endl(cout);
        cout<<time;endl(cout);
    }

};
class scientist:public Employee2{
public:
    void input(string name,string num,double compens,string time){
        this->name=name;
        this->number=num;
        this->compensation=compens;
        this->time=time;
    }
    void output(){
        cout<<name;endl(cout);
        cout<<number;endl(cout);
        cout<<compensation;endl(cout);
        cout<<time;endl(cout);
    }

};
class laborer:public Employee2{
public:
    void input(string name,string num,double compens,string time){
        this->name=name;
        this->number=num;
        this->compensation=compens;
        this->time=time;
    }
    void output(){
        cout<<name;endl(cout);
        cout<<number;endl(cout);
        cout<<compensation;endl(cout);
        cout<<time;endl(cout);
    }

};
int main(){
    manager m1;
    m1.input("Abdullah","03362504929",10,"29-04-2022");
    m1.output();endl(cout);
    scientist s1;
    s1.input("Abdullah","03362504929",10,"29-04-2022");
    s1.output();endl(cout);
    laborer l1;
    l1.input("Abdullah","03362504929",10,"29-04-2022");
    l1.output();
return 0;
}
