/*
This C++ program defines three classes: 'LocalPhone', 'natphone', and 'intphone'.
The 'LocalPhone' class represents a local phone number and contains a private attribute 'Phone' to store the phone number.
It has a constructor to initialize the 'Phone' attribute and functions to set and display the phone number.

The 'natphone' class is derived from the 'LocalPhone' class and represents a national phone number.
It adds an additional private attribute 'citycode' to store the city code.
The 'natphone' class has a constructor that initializes both 'citycode' and the 'Phone' attribute inherited from the base class.
It also includes functions to set and display the city code.

The 'intphone' class is derived from the 'natphone' class and represents an international phone number.
It adds an additional private attribute 'countrycode' to store the country code.
The 'intphone' class has a constructor that initializes both 'countrycode' and the 'citycode' attribute inherited from the base class.
It also includes functions to set and display the country code.

In the 'main' function, the program demonstrates the usage of these classes by creating objects of each class.
It creates a 'LocalPhone' object 'lp' with phone number "1234567", a 'natphone' object 'np' with city code 999 and phone number "1234567",
and an 'intphone' object 'ip' with country code 42, city code 999, and phone number "1234567".

The program then displays the local phone number using 'showphone', the city code using 'showcity', the country code using 'showcountry',
and the final result, which shows the country code followed by the city code and the phone number, using 'showcountrycode'.
*/

#include <iostream>
using namespace std;
class LocalPhone{
private:
    string Phone;
public:
    LocalPhone(string n){
        Phone=n;
    }
    void setphone(string n){
        Phone=n;
    }
    void showphone(){
        cout<<this->Phone;
    }
};
class natphone:public LocalPhone{
private:
    int citycode;
public:
 natphone(int c,string n):LocalPhone(n){
        citycode=c;
    }
    void setcitycode(int c){
        citycode=c;
    }
    void showcitycode(){
        cout<<this->citycode;
        showphone();
    }
    void showcity(){
        cout<<this->citycode;
    }
};
class intphone:public natphone{
private:
    int countrycode;
public:
 intphone(int country,int c,string n):natphone(c,n){
        countrycode=country;
    }
    void setcountrycode(int c){
        countrycode=c;
    }
    void showcountrycode(){
        cout<<this->countrycode;
        showcitycode();
    }
    void showcountry(){
        cout<<this->countrycode;
    }
};
int main(){
    LocalPhone lp("1234567");
    natphone np(999,"1234567");
    intphone ip(42,999,"1234567");
    cout<<"Local Phone Number : ";
    lp.showphone();endl(cout);
    cout<<"City Code : ";
    np.showcity();endl(cout);
    cout<<"International Code : ";
    ip.showcountry();endl(cout);
    cout<<"Final result : ";
    ip.showcountrycode();

return 0;

}
