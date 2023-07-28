/*
This C++ program demonstrates the use of abstract classes and inheritance to create different types of bank accounts.

The 'Account' class is defined as an abstract class with two pure virtual functions: 'Debit' and 'Credit'.
The class also has two member variables: 'accountNumber' to store the account number and 'accountBalance' to store the current balance.

Two derived classes 'CurrentAccount' and 'SavingAccount' inherit from the 'Account' class and provide their implementations of the 'Debit' and 'Credit' functions.
Additionally, a new class 'BasicAccount' is created that also inherits from the 'Account' class and implements its own version of 'Debit' and 'Credit'.

In the 'main' function, we create an array of pointers to 'Account' class objects to hold different types of accounts.
We create instances of 'CurrentAccount', 'SavingAccount', and 'BasicAccount' using dynamic memory allocation.
We then print the account details using the 'Print' function for each account type and finally, free the dynamically allocated memory.

Sample output:
------------------
Account Number: 456
Account Balance: 2000
Minimum Balance: 500
Service Charges: 50
Account Number: 789
Account Balance: 3000
Interest Rate: 5
Account Number: 123
Account Balance: 1000
------------------
Here, we see the details for each account, including the minimum balance and service charges for the current account and the interest rate for the saving account.
The basic account has no additional features, and its details only include the account number and balance.
*/

#include <iostream>
using namespace std;

class Account {
protected: // Change access specifier to protected
    int accountNumber;
    float accountBalance;

public:
    Account(int num, float balance) : accountNumber(num), accountBalance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    float getAccountBalance() const {
        return accountBalance;
    }

    virtual void Debit(float amount) = 0;
    virtual void Credit(float amount) = 0;

    virtual void Print() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Balance: " << accountBalance << endl;
    }

    virtual ~Account() {}
};

class CurrentAccount : public Account {
private:
    float serviceCharges;
    float minBalance;

public:
    CurrentAccount(int num, float balance, float charges, float minBal)
        : Account(num, balance), serviceCharges(charges), minBalance(minBal) {}

    void Debit(float amount) override {
        if (amount <= getAccountBalance()) {
            accountBalance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void Credit(float amount) override {
        accountBalance += amount;
        if (accountBalance < minBalance) {
            accountBalance -= serviceCharges;
        }
    }

    void Print() override {
        Account::Print();
        cout << "Minimum Balance: " << minBalance << endl;
        cout << "Service Charges: " << serviceCharges << endl;
    }
};

class SavingAccount : public Account {
private:
    float interestRate;

public:
    SavingAccount(int num, float balance, float rate)
        : Account(num, balance), interestRate(rate) {}

    void Debit(float amount) override {
        if (amount <= getAccountBalance()) {
            accountBalance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void Credit(float amount) override {
        accountBalance += amount;
    }

    void Print() override {
        Account::Print();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class BasicAccount : public Account {
public:
    BasicAccount(int num, float balance)
        : Account(num, balance) {}

    void Debit(float amount) override {
        if (amount <= getAccountBalance()) {
            accountBalance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void Credit(float amount) override {
        accountBalance += amount;
    }
};

int main() {
    Account* accounts[4];
    accounts[0] = new CurrentAccount(456, 2000, 50, 500);
    accounts[1] = new SavingAccount(789, 3000, 5);
    accounts[2] = new BasicAccount(123, 1000);

    for (int i = 0; i < 3; ++i) {
        accounts[i]->Print();
        delete accounts[i];
    }

    return 0;
}
