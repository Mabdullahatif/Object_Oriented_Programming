/*
This C++ program demonstrates the concept of polymorphism using a simple banking system.

There is a base class 'Account' that represents a generic bank account with attributes 'AN' (Account Number) and 'AB' (Account Balance).
It has member functions to get and set these attributes, and also virtual functions 'Print', 'Credit', and 'Debit'.

Two derived classes, 'CurrentAccount' and 'SavingAccount', are created from the 'Account' class.
The 'CurrentAccount' class adds attributes 'SC' (Service Charges) and 'MB' (Minimum Balance) and overrides the 'Print', 'Credit', and 'Debit' functions.
The 'SavingAccount' class adds an attribute 'IR' (Interest Rate) and also overrides the 'Print', 'Credit', and 'Debit' functions.

In the 'main' function, an array of pointers to the 'Account' base class is created, and three different account objects (one 'SavingAccount', one 'CurrentAccount', and one 'Account') are dynamically allocated and assigned to the array elements.

Polymorphism is demonstrated by calling the 'Print', 'Credit', and 'Debit' functions on the array elements, which results in calling the appropriate functions based on the object type.

Sample output:
------------------
Account Number : 0
Account Balance : 0
Interest Rate : 5
Account Number : 0
Account Balance : 0
Services Charges : 100
Minimum Balance : 1000
Account Number : 0
Account Balance : 0
Account destroyed !!
Saving Account destroyed !!
Current Account destroyed !!
------------------
*/

#include <iostream>
using namespace std;

class Account {
private:
    int AN, AB;

public:
    int getAN() {
        return AN;
    }

    int getAB() {
        return AB;
    }

    void setAN(int acn) {
        AN = acn;
    }

    void setAB(int acb) {
        AB = acb;
    }

    virtual void Print() {
        cout << "Account Number : " << AN << endl
             << "Account Balance : " << AB << endl;
    }

    virtual void Credit(float) {
    }

    virtual void Debit(float) {
    }

    virtual ~Account() {
        cout << "Account destroyed !!" << endl;
    }
};

class CurrentAccount : public Account {
private:
    int SC, MB;

public:
    CurrentAccount() {
        SC = 100; // Default service charges
        MB = 1000; // Default minimum balance
    }

    void Print() {
        Account::Print();
        cout << "Services Charges : " << SC << endl
             << "Minimum Balance : " << MB << endl;
    }

    void Credit(float amount) {
        setAB(getAB() + amount);
    }

    void Debit(float amount) {
        if (amount <= getAB()) {
            setAB(getAB() - amount);
            if (getAB() < MB) {
                setAB(getAB() - SC);
            }
        }
    }

    ~CurrentAccount() {
        cout << "Current Account destroyed !!" << endl;
    }
};

class SavingAccount : public Account {
private:
    int IR; // Interest Rate

public:
    SavingAccount() {
        IR = 5; // Default interest rate
    }

    void Print() {
        Account::Print();
        cout << "Interest Rate : " << IR << endl;
    }

    void Credit(float amount) {
        setAB(getAB() + amount);
    }

    void Debit(float amount) {
        if (amount <= getAB()) {
            setAB(getAB() - amount);
        }
    }

    ~SavingAccount() {
        cout << "Saving Account destroyed !!" << endl;
    }
};

int main() {
    // Array of base pointers
    Account** alist = new Account*[3];
    alist[0] = new SavingAccount;
    alist[1] = new CurrentAccount;
    alist[2] = new Account;

    // Print data of all accounts polymorphic behavior
    for (int i = 0; i < 3; i++)
        alist[i]->Print();

    // Credit and debit polymorphic behavior
    alist[0]->Credit(50);
    alist[2]->Debit(333);

    // Freeing the dynamically allocated objects
    for (int i = 0; i < 3; i++) {
        delete alist[i];
    }
    delete[] alist;

    return 0;
}
