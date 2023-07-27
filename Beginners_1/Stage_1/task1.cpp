/*
  - Declare two integer variables 'a' and 'b'.
  - Create two integer pointers 'ptrA' and 'ptrB' and assign them the addresses of 'a' and 'b' respectively.
  - Prompt the user to input two integer values, which are stored in 'a' and 'b'.
  - Display the values of 'a' and 'b' using the pointers 'ptrA' and 'ptrB' respectively.
  - Update the values of 'a' and 'b' by setting the values at the memory addresses pointed to by 'ptrA' and 'ptrB' to 30 and 40 respectively.
  - Display the updated values of 'a' and 'b' using the pointers 'ptrA' and 'ptrB' respectively.
*/
#include <iostream>
using namespace std;
int main(){
	int a,b;
	int *ptrA=&a;
	int *ptrB=&b;
	
	cout<<"Enter first number = ";
	cin>>a;
	
	cout<<"Enter second number = ";
	cin>>b;
	
	cout<<"the values are = "<<*ptrA<<" & "<<*ptrB<<endl;
	
	*ptrA=30;
	*ptrB=40;
	
	cout<<"Updated values of *ptrA and *ptrB are = "<<*ptrA<<" & "<<*ptrB;
	
	return 0;
}
