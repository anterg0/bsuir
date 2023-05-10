#include <iostream>

#define MAX 16384
int** array;

void odd(int n) {
    int v = 0, m = n / 2;
    for (int i = 1; i <= n * n; i++) {
        array[v][m] = i;
        v--;
        m++;
        if (v < 0 && m > n - 1) {
            v = v + 2; m = m - 1;
        }
        else if (v < 0) {
            v = v + n;
        }
        else if (m > n - 1) {
            m = m - n;
        }
        else if (array[v][m] != 0) {
            v = v + 2; m = m - 1;
        }
    }
}

void multiple_of4(int n) {
    int n0 = n / 4;
    for (int i = 1, v = 0; v < n; v++) for (int m = 0; m < n && i <= n * n;i++,m++) {
        array[v][m] = i;
    }
    for (int i = 1, v = n - 1; v >= 0; v--) {
        for (int m = n - 1; m >= 0 && i <= n * n;m--) {
            if ((m >= n - n0 || m <= n0 - 1) && (v < n - n0 && v >= n0)) array[v][m] = i;
            if ((m >= n0 && m < n - n0) && (v >= n0 && v < n - n0)) array[v][m] = n * n - i + 1;
            else if (m < n - n0 && m > n0 - 1) {
                array[v][m] = i;
            }
            i++;
        }
    }
}

void multiple_of2(int n) {
    int n0 = n / 2;
    odd(n0);
    for (int i = 0; i < n0; i++) {
        for (int j = 0; j < n0; j++) {
            array[i + n0][j + n0] = array[i][j] + n0 * n0;
            array[i][j + n0] = array[i + n0][j + n0] + n0 * n0;
            array[i + n0][j] = array[i][j + n0] + n0 * n0;
        }
    }
    int k = (n - 2) / 4;
    for (int i = 0; i < n0; i++) {
        for (int j = 0; j < k; j++) {
            if (i == n0 / 2) {
                std::swap(array[i][i + j], array[i + n0][i + j]);
            }
            else {
                std::swap(array[i][j], array[i + n0][j]);
            }
        }
    }
    for (int i = 0; i < n0; i++) {
        for (int j = n0 + n0 / 2; j > n0 + n0 / 2 - (k - 1); j--) {
            std::swap(array[i][j], array[i + n0][j]);
        }
    }
}


void Array_Output(int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << "\n";
        for (int j = 0; j < n; j++)
        {
            std::cout << array[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

/* void isMagicSquare (int n) {
    int n0 = 0, n1 = 0, n2 = 0;
    for (int j = 0; j < n; j++) n0 += array[0][j];
    for (int j = 0; j < n; j++) n1 += array[j][0];
    for (int i = 0, j = 0; j < n; j++, i++) n2 += array[i][j];
    if (n0 == n1 && n1 == n2) std::cout << "Данный квадрат - магический";
    else std::cout << "Данный квадрат не является магическим";
}
 */

int main()
{
    std::cout << "Построить магический квадрат.Порядок квадрата задаётся пользователем.Максимальный размер магического квадрата не превышает 2^32 - 1 \n";
    std::cout << "\nВыполнил Шпаковский А.В. \n\n";
    while(true) {
        std::cout << "Введите порядок магического квадрата: ";
        int n;
        std::cin >> n;
        if ( n <= 0 || (std::cin.peek() != '\n')) {
            std::cout << "Неверный ввод";
            std::cin.clear();
            std::cin.ignore(1000000000, '\n');
            std::cout << "\nЖелаете повторить? (y/n)";
            char a;
            std::cin >> a;
            switch(a) {
                case 'y':
                    continue;
                    break;
                case 'n':
                    return 0;
                    break;
                default:
                    return 0;
                    break;
            }
        }
        if (n > MAX) {
            std::cout << "Воу воу воу, смотри оперативную память не забивай. Введи порядок заново.\n";
            continue;
        }
        array = (int**)(calloc(n, sizeof(int*)));
        for (int i = 0; i < n; i++) array[i] = (int*)calloc(n, sizeof(int));
        if (n == 1) {
            std::cout << 1;
        }
        else if (n == 2) {
            std::cout << "Такого магического квадрата не существует.\n";
        }
        
        else if ((n % 2) != 0) {
            odd(n);
            Array_Output(n);
            //isMagicSquare(n);
            std::cout << "\n";
        }
        
        else if (!(n % 4)) {
            multiple_of4(n);
            Array_Output(n);
            //isMagicSquare(n);
            std::cout << "\n";
        }
        
        else {
            multiple_of2(n);
            Array_Output(n);
            //isMagicSquare(n);
            std::cout << "\n";
        }
        for (int i = 0; i < n; i++) free(array[i]);
        free(array);
        std::cout << "\nДля повтора введите 'f', либо что угодно другое для завершения программы.\n";
        char a;
        std::cin >> a;
        switch(a) {
            case 'f':
                continue;
                break;
            default:
                return 0;
                break;
        }
        
    }
    return 0;
}
