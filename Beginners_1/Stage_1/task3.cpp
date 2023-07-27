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
/*
  This C++ program allows the user to input the size of an array and then takes input for the array elements.
  It then finds and displays the index of the second largest value in the array.

  - Prompt the user to enter the limit (size) of the array.
  - Create a dynamically allocated integer array 'arr' of size 'limit' to store the elements.
  - Prompt the user to input 'limit' number of integer values, which are stored in the array 'arr'.
  - Initialize variables 'largest' and 'secondmax' to keep track of the index of the largest and second largest values in the array.
  - Iterate through the array elements and find the index of the largest value, storing it in 'largest'.
  - While finding the largest value, also update 'secondmax' to keep track of the index of the second largest value.
  - Display the index of the second largest value found in the array.

  Note: The program uses dynamic memory allocation to create an array with a size specified by the user. By iterating
  through the array, it identifies the index of the second largest value without sorting the array explicitly.
*/
#include <iostream>
using namespace std;
int main(){
	
	int limit;
	cout<<"Enter limit of the array = ";
	cin>>limit;
	
	int *arr=new int [limit];
	cout<<"Enter values upto "<<limit<<endl;
	
	for(int i=0;i<limit;i++){
		cin>>arr[i];
	}
	int largest=0,secondmax=0;
	
	for (int i=0;i<limit;i++){
		if(arr[i]>arr[largest]){
			secondmax=largest;
			largest=i;
		}
	}
	cout<<endl;
	cout<<"Index of the 2nd largest value is = ";
	cout<<secondmax;
	
	return 0;
	
	
}
