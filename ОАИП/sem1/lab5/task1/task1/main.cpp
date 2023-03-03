#include <iostream>

bool intValidation(char, int);

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
    std::cout << "Определить сумму элементов четных столбцов для каждого массива-матрицы A и Б. На экран вывести массивы-матрицы А, В и значения сумм.\nВариант 12.\nВыполнил Шпаковский Антон.";
    while (true) {
        std::cin >> n;
        char j = getchar();
        if (intValidation(j,n)) {
            std::cout << "Неверный ввод.\nВведи заново размер: ";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
        std::cin >> m;
        if (intValidation(j,m)) {
            std::cout << "Неверный ввод.\nВведи заново размер: ";
            std::cin.clear();
            std::cin.ignore(32767,'\n');
            continue;
        }
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
        std::cout << "Введите 'f' для повтора программы, либо любой другой символ для завершения программы.";
        char bebra;
        std::cin >> bebra;
        switch (bebra) {
            case 'f':
                continue;
                break;
            default:
                return 0;
                break;
        }
    }
}
