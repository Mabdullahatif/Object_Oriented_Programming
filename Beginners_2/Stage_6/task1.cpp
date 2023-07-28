/*
  This C++ program defines a class 'BiggerInt' to work with arrays of integers representing large integers.
  The class provides various member functions to perform operations like assignment, appending, comparison, and display.

  The 'BiggerInt' class has the following private data members:
  - 'big_int_': A pointer to an integer to store the dynamic array of integers representing a large integer.
  - 'int_length_': An integer to store the number of elements in the 'big_int_' array.

  The class has the following public member functions:
  - 'BiggerInt()': Default constructor to initialize 'big_int_' to NULL and 'int_length_' to 0.
  - 'BiggerInt(const int* obj, int size)': Constructor to create a 'BiggerInt' object and initialize it with the given array of integers and its size.
  - 'BiggerInt(const BiggerInt& obj)': Copy constructor to create a deep copy of a 'BiggerInt' object.
  - 'void assign(const BiggerInt& obj)': Function to assign the 'big_int_' array from another 'BiggerInt' object.
  - 'void assign(const int* big_int, int size)': Function to assign the 'big_int_' array from a given array of integers and its size.
  - 'void append(const BiggerInt& obj)': Function to append the 'big_int_' array from another 'BiggerInt' object to the current object's 'big_int_'.
  - 'void append(const int* big_int, int size)': Function to append a given array of integers and its size to the current object's 'big_int_'.
  - 'int compareTo(const BiggerInt& obj)': Function to compare the 'int_length_' of the current object and another 'BiggerInt' object.
    Returns 2 if the current object has a smaller 'int_length_', 0 if both have the same 'int_length_', and 1 if the current object has a larger 'int_length_'.
  - 'int compareTo(const int* big_int, int size)': Function to compare the 'int_length_' of the current object and a given array of integers and its size.
    Returns 2 if the current object has a smaller 'int_length_', 0 if both have the same 'int_length_', and 1 if the current object has a larger 'int_length_'.
  - 'void display()': Function to display the elements of the 'big_int_' array in a space-separated format.
    If the 'big_int_' array is empty, it prints "No value assigned."

  The 'BiggerInt' class also has a destructor 'BiggerInt::~BiggerInt()' to deallocate the dynamically allocated 'big_int_' array.

  In the 'main' function:
  - Two integer arrays 'arr' and 'arr2' are defined to hold sample large integers.
  - Two 'BiggerInt' objects 'pro' and 'pro1' are created using different constructors and initialized with the sample arrays.
  - The 'display' function is called to show the elements of 'pro' and 'pro1'.
  - The 'append' function is called to append the 'big_int_' array of 'pro1' to the 'big_int_' array of 'pro'.
  - The 'display' function is called again to show the updated elements of 'pro'.

  Note: The program demonstrates the use of a custom class 'BiggerInt' to work with large integers represented as arrays of integers.
  It showcases various member functions that handle assignment, appending, and comparison of large integers.
*/
#include <iostream>
using namespace std;

class BiggerInt{
private:
	int* big_int_;
	int int_length_;
public:
	BiggerInt(); //task1

	BiggerInt(const int * obj, int size); //task2

	BiggerInt(const BiggerInt &obj); //task3
	
	void assign(const BiggerInt &obj); //task4
	
	void assign(const int * big_int, int size); //task5
	
	void append(const BiggerInt &obj); //task6
	
	void append(const int* big_int, int size); //task7
	
	int compareTo(const BiggerInt &obj); //task8
	 
	int compareTo(const int* big_int, int size); //task9
	
	void display(); //task10
	
	~BiggerInt(); //task11
	
};
    BiggerInt::BiggerInt(){                         //task1
		big_int_ = 0;
		int_length_ =0;
	}

	BiggerInt::BiggerInt(const int * obj, int size){  //task2
		int_length_=size;
		big_int_=new int [int_length_];
		for(int i=0;i<int_length_;i++){
	    	big_int_[i]=obj[i];
		}
		//for(int i=0;i<int_length_;i++){
		//cout<<big_int_[i]<<" ";
		//}
	
	}

	BiggerInt::BiggerInt(const BiggerInt &obj){      //task3
		int_length_=obj.int_length_;
		big_int_=new int[obj.int_length_];
		for(int i=0;i<int_length_;i++){
	    	big_int_[i]=obj.big_int_[i];
		}
		//for(int i=0;i<int_length_;i++){
		//cout<<big_int_[i]<<" ";
		//}
	}
	
	void BiggerInt::assign(const BiggerInt &obj){    //task4
		int_length_=obj.int_length_;
		big_int_=new int[obj.int_length_];
		for(int i=0;i<int_length_;i++){
		    big_int_[i]=obj.big_int_[i];
		}
	}
	
	void BiggerInt::assign(const int * big_int, int size){  //task5
		int_length_=size;
		big_int_=new int[int_length_];
		for(int i=0;i<int_length_;i++){
		    big_int_[i]=big_int[i];
		}
	}

	void BiggerInt::append(const BiggerInt &obj){      //task6
		int new_size=int_length_ +obj.int_length_;
		int*dummy = new int[new_size];
			for(int i=0,k=0;i<new_size;i++){
				if(i<int_length_){
				dummy[i]=big_int_[i];
			    }
			    else{
				dummy[i]=obj.big_int_[k++];
				}
			}
		big_int_=dummy;
		int_length_=new_size;
		// for(int i=0;i<int_length_;i++){
		// cout<<big_int_[i]<<" ";
		// }
	}
	
	void BiggerInt::append(const int* big_int, int size){      //task7
	    int new_size=int_length_ +size;
		int*newarray = new int[new_size];
			for(int i=0,k=0;i<new_size;i++){
				if(i<int_length_){
				    newarray[i]=big_int_[i];
			    }
			    else{
			        newarray[i]=big_int[k++];
		        }
		    }
			big_int_=newarray;
			int_length_=new_size;
			// for(int i=0;i<int_length_;i++){
			// cout<<big_int_[i]<<" ";
			// }
	}
	
	int BiggerInt::compareTo(const BiggerInt &obj){    //task8
		if(obj.int_length_>int_length_){
	    	return 2;
		}
		else if(obj.int_length_==int_length_){
		    return 0;
		}
		else{
		    return 1;
		}
	}
	
	int BiggerInt::compareTo(const int* big_int, int size){ //task9
		if(size>int_length_){
		    return 2;
		}
		else if(size==int_length_){
		    return 0;
		}
		else{
		    return 1;
		}
	}
	
	void BiggerInt::display(){         //task10
		if(int_length_==0){
	    	cout<<"No value assigned"<<endl;
		}
		else{
		    for(int i=0;i<int_length_;i++){
	        	cout<<big_int_[i]<<" ";
		    }
		    cout<<endl;
	    }
	}
	
	BiggerInt::~BiggerInt(){         //task11
	    delete[] big_int_;
	}

int main(){           //task12
	int arr[5]={5,6,7,8,9};
	int arr2[6]={1,2,3,4,5,6};
	BiggerInt pro(arr,5);
	BiggerInt pro1(arr2, 6);
	pro.display();
	pro1.display();
	pro.append(pro1);
	pro.display();

return 0;
}

