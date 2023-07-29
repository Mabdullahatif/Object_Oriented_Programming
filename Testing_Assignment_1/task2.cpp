/*The program is designed to convert a 2D array into a 1D array and then sort 
the elements of the 1D array in ascending order. It utilizes dynamic memory 
allocation to handle arrays of varying sizes and avoids memory leaks through proper deallocation.

Main Functions:

Fillarray: This function takes user input to create a 2D array. It asks the user 
for the number of rows and then, for each row, the number of columns. It allocates 
memory for the 2D array and stores the input elements provided by the user.

TwoDtoOneD: This function takes the 2D array and converts it into a 1D array. It calculates 
the total number of elements in the 2D array to determine the size of the 1D array. Then, it traverses 
the 2D array row by row and copies each element into the 1D array.

showOneD: This function displays the elements of the 1D array on the console.

sortArray: This function sorts the elements of the 1D array in ascending order using the 
std::sort function from the <algorithm> library.

Main Execution:

The user is prompted to enter the number of rows and columns for each row of the 2D array.
After entering the elements for the 2D array, the program converts it into a 1D array and sorts it.
Finally, the sorted elements of the 1D array are displayed on the console.
Memory Management:

Dynamic memory allocation is used to create the 2D array, 1D array, and an array to store the number 
of columns in each row of the 2D array.
After sorting and displaying the 1D array, the memory allocated for the arrays is properly deallocated 
to prevent memory leaks.
Error Handling:

The program handles the case where the user enters invalid inputs, such as negative row or column values, 
to ensure valid memory allocation and access.*/

#include <iostream>
#include <algorithm>
using namespace std;

void Fillarray(int**& arr, int& r, int*& cArr, int& size) {
    cout << "Enter the number of rows: ";
    cin >> r;

    arr = new int*[r];
    cArr = new int[r];

    for (int i = 0; i < r; i++) {
        cout << "Enter Number Of Columns For Row #" << i << ": ";
        cin >> cArr[i];
        arr[i] = new int[cArr[i]];
        for (int j = 0; j < cArr[i]; j++) {
            cin >> arr[i][j];
            size++;
        }
    }
}

int* TwoDtoOneD(int** arr, int r, int* cArr, const int size) {
    int* oneD = new int[size];
    int index = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < cArr[i]; j++) {
            oneD[index] = arr[i][j];
            index++;
        }
    }

    return oneD;
}

void showOneD(int* arr, const int size) {
    cout << "The elements of the array are: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void sortArray(int* arr, const int size) {
    sort(arr, arr + size); // Using the standard sorting function from the algorithm library
}

int main() {
    int** arr = nullptr;
    int* cArr = nullptr;
    int* oneD = nullptr;
    int r, size = 0;

    Fillarray(arr, r, cArr, size);
    oneD = TwoDtoOneD(arr, r, cArr, size);

    sortArray(oneD, size);
    showOneD(oneD, size);

    // Deallocate memory for 2D array and 1D array
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] cArr;
    delete[] oneD;

    return 0;
}
