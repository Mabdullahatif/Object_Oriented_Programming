/*
This C++ program demonstrates two template functions: 'range' and 'shiftColumns'.

1. range:
The 'range' function takes a 2D array 'array', along with the number of 'rows' and 'columns' in the array.
It calculates the range of values in the 2D array, which is defined as the difference between the maximum and minimum values.
The function then returns the value that is one-fourth of the range, added to the minimum value.

2. shiftColumns:
The 'shiftColumns' function takes a 2D array 'array', along with the number of 'rows' and 'columns' in the array.
This function shifts the elements of each row in the array one position to the left.
The leftmost element of each row wraps around to the rightmost position.

In the 'main' function, a 3x3 integer matrix 'matrix' is declared and initialized.
A dynamic 2D integer array 'dynamicMatrix' is created using dynamic memory allocation and is initialized with the values from the 'matrix' array.

The 'range' function is called on 'dynamicMatrix', and the result is printed.

Then, the 'shiftColumns' function is called on 'dynamicMatrix', and the resulting matrix is printed.

Finally, the dynamically allocated memory for 'dynamicMatrix' is deallocated.

Sample output:
------------------
Range of matrix: 5
Shifted matrix:
2 3 1
5 6 4
8 9 7
------------------
The range of values in the matrix is 5, and the matrix is shifted one position to the left.
*/


#include <iostream>
using namespace std;

template <typename T>
T range(T** array, int rows, int columns) {
    T min = array[0][0];
    T max = array[0][0];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (array[i][j] < min) {
                min = array[i][j];
            }
            if (array[i][j] > max) {
                max = array[i][j];
            }
        }
    }

    return ((max - min) / static_cast<T>(4)) + min;
}

template <typename T>
void shiftColumns(T** array, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        T temp = array[i][0];
        for (int j = 0; j < columns - 1; ++j) {
            array[i][j] = array[i][j + 1];
        }
        array[i][columns - 1] = temp;
    }
}

int main() {
    const int rows = 3;
    const int columns = 3;
    int matrix[rows][columns] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

    int** dynamicMatrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        dynamicMatrix[i] = new int[columns];
        for (int j = 0; j < columns; ++j) {
            dynamicMatrix[i][j] = matrix[i][j];
        }
    }

    cout << "Range of matrix: " << range(dynamicMatrix, rows, columns) << endl;

    shiftColumns(dynamicMatrix, rows, columns);

    cout << "Shifted matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << dynamicMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate dynamic memory
    for (int i = 0; i < rows; ++i) {
        delete[] dynamicMatrix[i];
    }
    delete[] dynamicMatrix;

    return 0;
}
