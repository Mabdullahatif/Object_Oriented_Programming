/*
  This C++ program demonstrates encryption using a Caesar cipher with a user-provided encryption key.

  - The function 'isValidEncryptionKey' takes a single character 'key' and checks if it is a valid encryption key.
    The function returns 'true' if the key is an alphabet (a-z or A-Z) and 'false' otherwise.

  - The function 'Encrypt' takes a character array 'arr', an integer 'size', and a character 'key' as inputs.
    It encrypts the characters in the 'arr' array using the Caesar cipher technique, shifting each character by the value of the 'key'.
    If the 'key' is a valid alphabet (a-z or A-Z), the characters in the array are modified in place.

  - In the 'main' function:
    - The user is prompted to enter the size of the character array ('arr') dynamically.
    - The 'arr' array is dynamically allocated based on the user-provided size.
    - The user is prompted to input the elements of the 'arr' array.
    - The 'actualSize' variable is used to store the actual number of characters entered by excluding the null terminator.
    - The user is prompted to input the encryption key ('key').
    - A new character array 'resizedArr' is dynamically allocated with a size of 'actualSize + 1' to hold the modified string.
    - The original 'arr' array is copied into 'resizedArr' character by character, and a null terminator is added.
    - The 'Encrypt' function is called with 'resizedArr', 'actualSize', and 'key' to encrypt the array.
    - The original 'arr' and encrypted 'resizedArr' are displayed.

  - The program deallocates the dynamic memory allocated for 'arr' and 'resizedArr' using 'delete[]' to avoid memory leaks.

  Note: The program showcases dynamic memory allocation for character arrays, input handling for encryption key, and the implementation of a simple Caesar cipher for encryption.
*/
#include <iostream>
using namespace std;

bool isValidEncryptionKey(char key) {
    return ((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z'));
}

void Encrypt(char* arr, int size, char key) {
    if (!isValidEncryptionKey(key)) {
        cout << "Invalid encryption key! Please enter a valid alphabet (a-z or A-Z)." << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = (arr[i] + key - 'a') % 26 + 'a';
    }
}

int main() {
    int size;
    cout << "Enter Size of array: ";
    cin >> size;

    // Dynamically allocate char array
    char* arr = new char[size];

    cout << "Enter the array elements: ";
    cin.ignore(); // Ignore the newline character left in the input buffer
    cin.getline(arr, size);

    // Get the actual number of characters entered
    int actualSize = cin.gcount() - 1; // Excluding the null terminator

    cout << "Enter the encryption key: ";
    char key;
    cin >> key;

    // Resize the original array to the number of characters entered
    char* resizedArr = new char[actualSize + 1]; // +1 for null terminator
    for (int i = 0; i < actualSize; i++) {
        resizedArr[i] = arr[i];
    }
    resizedArr[actualSize] = '\0'; // Add null terminator

    Encrypt(resizedArr, actualSize, key);

    cout << "Original array: " << arr << endl;
    cout << "Encrypted array: " << resizedArr << endl;

    // Deallocate dynamic memory
    delete[] arr;
    delete[] resizedArr;

    return 0;
}
