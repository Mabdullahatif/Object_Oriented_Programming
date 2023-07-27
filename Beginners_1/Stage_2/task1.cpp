/*
  This C++ program demonstrates the dynamic input, compression, and output of an integer array.

  - The function 'InputArray' takes a reference to an integer 'size' and dynamically allocates memory for an integer array.
    It prompts the user to input the size and elements of the array and returns a pointer to the dynamically created array.

  - The function 'OutputArray' takes a constant integer pointer 'myarray' and a constant integer reference 'size'.
    It displays the elements of the array pointed to by 'myarray' using pointer arithmetic.

  - The function 'CompressArray' takes an integer pointer 'originalArr' and a reference to an integer 'size'.
    It creates a new dynamically allocated integer array 'compressedArr' to store the compressed version of the original array.
    The function compresses the original array by removing duplicate consecutive elements.
    It then updates the 'size' parameter with the new compressed size, deallocates the memory of the original array, and returns the compressed array.

  - In the 'main' function, the user is prompted to input the length of the array.
    It calls the 'InputArray' function to dynamically create the array and fill it with user-provided values.
    It then displays the original array using the 'OutputArray' function.

  - The 'CompressArray' function is called to obtain the compressed version of the original array.
    The compressed array is then displayed using the 'OutputArray' function.

  - Finally, memory allocated for the compressed array is deallocated using 'delete[]' to prevent memory leaks.

  Note: The program showcases dynamic memory allocation and manipulation of arrays using pointers.
  Remember to free up the memory allocated using 'new' with 'delete[]' to prevent memory leaks.
*/
#include <iostream>
using namespace std;

// Function to input an array dynamically
int* InputArray(int& size) {
    cout << "Enter size of the array: ";
    cin >> size;

    int* array = new int[size];

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    return array;
}

// Function to output an array
void OutputArray(const int* myarray, const int& size) {
    for (int i = 0; i < size; i++) {
        cout << *(myarray + i) << " ";
    }
}

// Function to compress an array
int* CompressArray(int* originalArr, int& size) {
    int* compressedArr = new int[size];
    int compressedSize = 0;

    compressedArr[compressedSize++] = originalArr[0];
    for (int i = 1; i < size; i++) {
        if (originalArr[i] != originalArr[i - 1]) {
            compressedArr[compressedSize++] = originalArr[i];
        }
    }

    // Update the size parameter with the compressed size
    size = compressedSize;

    // Delete the original array to prevent memory leaks
    delete[] originalArr;

    return compressedArr;
}

int main() {
    int length;
    cout << "Enter length of the array: ";
    cin >> length;

    int* array = InputArray(length);

    cout << "The values are: ";
    OutputArray(array, length);
    cout << endl;

    int compressedSize = length;
    int* compressedArray = CompressArray(array, compressedSize);

    cout << "Array after Compression: ";
    OutputArray(compressedArray, compressedSize);
    cout << endl;

    // Don't forget to deallocate the memory
    delete[] compressedArray;

    return 0;
}
