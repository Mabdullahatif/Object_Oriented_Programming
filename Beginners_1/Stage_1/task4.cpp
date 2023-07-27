/*
  This C++ program allows the user to input the size of an array and then takes input for the array elements.
  It then adds 3 to each element of the array and displays the updated array.

  - Prompt the user to enter the limit (size) of the array.
  - Check if the entered limit is non-positive (less than or equal to 0), and if so, display an error message and terminate the program.
  - Create a dynamically allocated integer array 'arr' of size 'limit' to store the elements.
  - Prompt the user to input 'limit' number of integer values, which are stored in the array 'arr'.
  - Create an integer pointer 'ptr' and set it to point to the first element of the 'arr' array.
  - Iterate through the array 'arr' using the pointer 'ptr', and for each element, add 3 to its value using the pointer.
  - Display the updated array 'arr' to show the values after adding 3 to each element.

  Note: The program uses dynamic memory allocation to create an array with a size specified by the user. It then manipulates
  the array elements through a pointer 'ptr', adding 3 to each element directly via pointer manipulation.
*/
#include <iostream>
using namespace std;
int main(){
	int limit;
	cout<<"Enter limit of the array = ";
	cin>>limit;
	
	if(limit<=0){
		cout<<"Enter valid and positve limit !!!";
	}
	
	int *arr=new int [limit];
	cout<<"Enter values upto "<<limit<<endl;
	
	for(int i=0;i<limit;i++){
		cin>>arr[i];
	}
	
	int *ptr;
	ptr=arr;
	
	for(int i=0;i<limit;i++){
		*ptr+=3;
		ptr++;
	}
	cout<<endl;
	cout<<"The values after adding 3 are = ";
	
		for(int i=0;i<limit;i++){
		cout<<arr[i];
		cout<<" ";
	}
	
	return 0;
}
