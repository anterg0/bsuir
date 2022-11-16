#include <iostream>

int** CreateMatrix(int, int);

void FillMatrixA(int**, int, int);

void FillMatrixB(int**, int**, int, int);

void Delete2DMatrix(int**, int, int);

void ArrayOutput(int**, int, int);

void EvenColsSum(int**, int, int);


int main() {
    int** a;
    int** b;
    int n,m;
    std::cin >> n >> m;
    a = CreateMatrix(n, m);
    FillMatrixA(a, n, m);
    ArrayOutput(a, n, m);
    EvenColsSum(a, n, m);
    
    b = CreateMatrix(n, m);
    FillMatrixB(b, a, n, m);
    ArrayOutput(b, n, m);
    EvenColsSum(b, n, m);
    
    Delete2DMatrix(a, n, m);
    Delete2DMatrix(b, n, m);
    return 0;
}
