
#include <iostream>
#include "lib.hpp"

int** CreateMatrix(int n, int k){
    int** array = new int*[n];
    for (int i = 0; i < n; i++) array[i] = new int[k];
    return array;
}


void FillMatrixA(int** array, int n, int k) {
    for (int i = 0; i < n; i++) for(int j = 0; j < k; j++) {
        if (i <= 3) array[i][j] = (2 * i * j * j) - (2 * j);
        else if (i > 3) array[i][j] = (2 * i * j) - 2;
        else if (i <= 9) array[i][j] = (2 * i * j) - 2;
        else if (i > 9) array[i][j] = (3 * i * j * j) - (3 * j);
    }
}


void FillMatrixB(int** array, int** arr, int n, int k) {
    for (int i = 0; i < n; i++) for(int j = 0; j < k; j++) {
        array[i][j] = arr[i][j] * arr[i][j];
    }
}


void Delete2DMatrix(int** arr, int n, int k) {
    for (int i = 0; i < n; i++) delete[] arr[i];
    delete[] arr;
}

void ArrayOutput(int** array, int n, int k) {
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void EvenColsSum(int** array, int n, int k) {
    int result = 0;
    for (int i = 0; i < k; i++) {
        if (i % 2 != 0) for (int j = 0; j < n; j++) {
            result += array[j][i];
        }
    }
    std::cout << "\nSum = " << result << "\n";
}
