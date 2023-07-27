
/*This C++ program demonstrates matrix manipulation to separate different types of characters (alphabets, numbers, 
and special characters) from the user-provided matrix. It uses dynamic memory allocation for 2D character arrays 
and functions to allocate, input, display, and separate characters in the matrix. The 'SeparateCharacters' function 
counts occurrences of alphabets, numbers, and special characters and dynamically allocates separate arrays for each 
type. The program prevents memory leaks by deallocating dynamic memory after use.*/
#include <iostream>
using namespace std;

char** AllocateMemory(int& rows, int& cols) {
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    char** matrix = new char* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new char[cols];
    }

    return matrix;
}

char** InputMatrix(char** matrix, const int rows, const int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void DisplayMatrix(char** matrix, const int& rows, const int& cols) {
    cout << "Sample Matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void SeparateCharacters(char** matrix, const int rows, const int cols,
                        char*& alphabets, char*& numbers, char*& specialchar) {
    // Count the occurrences of each character type
    int alphabetCount = 0, numberCount = 0, specialCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isalpha(matrix[i][j])) {
                alphabetCount++;
            } else if (isdigit(matrix[i][j])) {
                numberCount++;
            } else {
                specialCount++;
            }
        }
    }

    // Resize the arrays
    alphabets = new char[alphabetCount];
    numbers = new char[numberCount];
    specialchar = new char[specialCount];

    // Separate the characters
    int alphabetIndex = 0, numberIndex = 0, specialIndex = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (isalpha(matrix[i][j])) {
                alphabets[alphabetIndex++] = matrix[i][j];
            } else if (isdigit(matrix[i][j])) {
                numbers[numberIndex++] = matrix[i][j];
            } else {
                specialchar[specialIndex++] = matrix[i][j];
            }
        }
    }
}

int main() {
    int rows, cols;
    char** matrix = AllocateMemory(rows, cols);

    InputMatrix(matrix, rows, cols);
    DisplayMatrix(matrix, rows, cols);

    char* alphabets;
    char* numbers;
    char* specialchar;

    SeparateCharacters(matrix, rows, cols, alphabets, numbers, specialchar);

    // Display the separated arrays
    cout << endl;
    cout << "alphabets = ";
    for (int i = 0; i < rows * cols; i++) {
        cout << alphabets[i] << " ";
    }
    cout << endl;

    cout << "numbers = ";
    for (int i = 0; i < rows * cols; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "specialchar = ";
    for (int i = 0; i < rows * cols; i++) {
        cout << specialchar[i] << " ";
    }
    cout << endl;

    // Deallocate dynamic memory
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    delete[] alphabets;
    delete[] numbers;
    delete[] specialchar;

    return 0;
}
