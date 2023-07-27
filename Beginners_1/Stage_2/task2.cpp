/*
  This C++ program takes an input string, counts and categorizes various elements in the string.

  - The 'Counter' function takes a character array 'array' as input and counts the following elements:
    - 'spaces': Counts the number of space characters in the input array.
    - 'uppercase': Counts the number of uppercase letters in the input array.
    - 'lowercase': Counts the number of lowercase letters in the input array.
    - 'vowels': Counts the number of vowels (a, e, i, o, u, both uppercase and lowercase) in the input array.
    - 'consonant': Calculates the number of consonants (total letters - vowels) in the input array.

  - In the 'main' function, the user is prompted to enter an array of characters (string) using 'cin.getline()'.
    The 'Counter' function is then called with this array as an argument to analyze the content of the input string.

  - The 'Counter' function prints the total number of letters (uppercase and lowercase combined), spaces,
    uppercase letters, lowercase letters, vowels, and consonants in the input string.

  Note: The program showcases basic string manipulation using character arrays and various character count calculations.
  The 'Counter' function iterates through the input array and counts the desired elements based on specific conditions.
  The use of 'cin.getline()' allows the program to read spaces and accept input of multiple words in a single line.
*/
#include<iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;
void Counter(char array[]){
 int spaces=0;
 int uppercase=0;
 int lowercase=0;
 int vowels=0;
 int cosonant=0;
 int i=0;
    for(int i=0;i<strlen(array);i++){
		 if(array[i]==32){
		 spaces++;
		 }
        if(array[i]>='A' && array[i]<='Z'){
           uppercase++;
          // cout<<uppercase;
         }
        else if(array[i]>='a' && array[i]<='z'){
           lowercase++;
          //cout<<lowercase;
         }
 if(array[i]=='a'||array[i]=='e'||array[i]=='i'||array[i]=='o'||array[i]=='u'){
           vowels++;
          //cout<<vowels;
         }
       }
 cout<<"Total lettes are :"<<uppercase+lowercase<<endl;
 cout<<"Total spaces are :"<<spaces<<endl;
 cout<<"Upper case letters are :"<<uppercase<<endl;
 cout<<"Lowercase letters are :"<<lowercase<<endl;
 cout<<"Vowels are :"<<vowels<<endl;
 cout<<"Consonants are :"<<(uppercase+lowercase)-vowels<<endl;

}

int main(){
 char array[50];
 cout<<"enter array"<<endl;
 cin.getline(array,50);
    Counter(array);
 system("pause");
 return 0;
}

