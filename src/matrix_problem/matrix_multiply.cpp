#include <iostream>

void
matrixMultiply(int **A, int **B, int **C, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int
main() {
    int rowsA = 2, colsA = 3, rowsB = 3, colsB = 2;

    int **A = new int *[rowsA];
    int **B = new int *[rowsB];
    int **C = new int *[rowsA];

    for (int i = 0; i < rowsA; i++) {
        A[i] = new int[colsA];
        C[i] = new int[colsB];
    }
    for (int i = 0; i < rowsB; i++) {
        B[i] = new int[colsB];
    }

    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;

    B[0][0] = 7;
    B[0][1] = 8;
    B[1][0] = 9;
    B[1][1] = 10;
    B[2][0] = 11;
    B[2][1] = 12;

    std::cout << "矩阵 A:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n矩阵 B:\n";
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            std::cout << B[i][j] << " ";
        }
        std::cout << "\n";
    }

    matrixMultiply(A, B, C, rowsA, colsA, colsB);

    std::cout << "\n矩阵 C = A × B:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << "\n";
    }

    for (int i = 0; i < rowsA; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    for (int i = 0; i < rowsB; i++) {
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}