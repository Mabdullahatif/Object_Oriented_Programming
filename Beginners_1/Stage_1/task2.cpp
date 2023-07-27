/*
  This C++ program demonstrates the use of dynamic memory allocation and pointer operations to evaluate
  the square, cube, and half of a user-provided number.

  - Declare an integer pointer 'ptr' to hold a memory address for an integer value.
  - Dynamically allocate memory for an integer using the 'new' operator, and store the address in 'ptr'.
  - Prompt the user to enter a number, which is stored in the memory location pointed to by 'ptr'.
  - Display the square of the entered number by multiplying the value at 'ptr' with itself.
  - Display the cube of the entered number by multiplying the value at 'ptr' with itself twice.
  - Display half of the entered number by dividing the value at 'ptr' by 2.
  - Deallocate the memory previously allocated for the integer using the 'delete' operator to avoid memory leaks.

  Note: Dynamic memory allocation using 'new' allows for creating variables at runtime and is useful when the
  size of memory needed is not known at compile time. However, it is crucial to deallocate the memory using 'delete'
  to avoid memory leaks and free up memory for reuse.
*/
#include <iostream>
using namespace std;
int main(){
	int *ptr;
	ptr = new int;
	
	cout<<"Enter a number for the evaluation = ";
	cin>>*ptr;
	
	cout<<"Square of a number is = ";
	cout<<(*ptr)*(*ptr)<<endl;
	
	cout<<"Cube of a number is = ";
	cout<<(*ptr)*(*ptr)*(*ptr)<<endl;
	
	cout<<"Half of a number is = ";
	cout<<(*ptr)/2<<endl;
	
	delete ptr;
	
	return 0;
}
