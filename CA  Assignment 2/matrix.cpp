#include <iostream>

using namespace std;

bool multiplyMatrices(const int mat1[][100], int rowsMat1, int colsMat1,
                      const int mat2[][100], int rowsMat2, int colsMat2,
                      int result[][100]) {
    if (colsMat1 != rowsMat2) {
        cout << "Error: Matrix dimensions do not match for multiplication" << endl;
        return false;  
    }

    for (int i = 0; i < rowsMat1; ++i) {
        for (int j = 0; j < colsMat2; ++j) {
            result[i][j] = 0;  // Initialize result element to 0
            for (int k = 0; k < colsMat1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return true;  
}

void printMatrix(int matrix[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rowsMat1, colsMat1, rowsMat2, colsMat2;

    cout << "Enter the number of rows and columns for the first matrix: ";
    cin >> rowsMat1 >> colsMat1;

    cout << "Enter the number of rows and columns for the second matrix: ";
    cin >> rowsMat2 >> colsMat2;

    if (colsMat1 != rowsMat2) {
        cout << "Error: Matrix dimensions do not match for multiplication" << endl;
        return 1;  
    }

    int mat1[100][100], mat2[100][100], result[100][100];

    cout << "Enter the elements of the first matrix:" << endl;
    for (int i = 0; i < rowsMat1; ++i) {
        for (int j = 0; j < colsMat1; ++j) {
            cin >> mat1[i][j];
        }
    }

    cout << "Enter the elements of the second matrix:" << endl;
    for (int i = 0; i < rowsMat2; ++i) {
        for (int j = 0; j < colsMat2; ++j) {
            cin >> mat2[i][j];
        }
    }

    if (multiplyMatrices(mat1, rowsMat1, colsMat1, mat2, rowsMat2, colsMat2, result)) {
        cout << "Result of matrix multiplication:" << endl;
        printMatrix(result, rowsMat1, colsMat2);
    }

    return 0;
}
