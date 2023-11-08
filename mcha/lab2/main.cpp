#include <iostream>
#include <cmath>
const int n = 5;
using namespace std;
// Проверка на сходимость
bool check_norm(double B[n][n]) {
    // Первая норма
    double norm = 0;
    for (int j = 0; j < n; j++) {
        norm += abs(B[0][j]);
    }
    for (int i = 1; i < n; i++) {
        double temp=0;
        for (int j = 0; j < n; j++) {
            temp += abs(B[i][j]);
        }
        if (temp > norm)norm = temp;
    }
    if (norm < 1) { return true; }
    // Вторая норма
    norm = 0;
    for (int j = 0; j < n; j++) {
        norm += abs(B[j][0]);
    }
    for (int i = 1; i < n; i++) {
        double temp=0;
        for (int j = 0; j < n; j++) {
            temp += abs(B[j][i]);
        }
        if (temp > norm)norm = temp;
    }
    if (norm < 1) { return true; }
    // Третья норма
    norm = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            norm += B[j][i] * B[j][i];
        }
    }
    norm = sqrt(norm);
    if (norm < 1) { return true; }
    return false;
}

double* simple_iterations(double A[n][n], double b[n]) {
    double B[n][n];
    double c[n];
    for (int i = 0; i < n; i++) {                       // B = E - A
        for (int j = 0; j < n; j++) {
            B[i][j] = -A[i][j];
            if (i == j)B[i][j]++;
        }
    }
    for (int i = 0; i < n; i++)                          // c = b
        c[i] = b[i];


    // Альтернативный случай матрицы B
    if (check_norm(B) == false) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                B[i][j] = -A[i][j]/ A[i][i];
                if (i == j)B[i][j]=0;
            }
        }
        // Альтернативный случай вектора с
        for (int i = 0; i < n; i++)
            c[i] = b[i]/A[i][i];
    }

    if (check_norm(B) == false) {
        std::cout << "Для рассматриваемых матриц B итерационный метод неприменим\n";
        double* x = new double[n];
        for (int i = 0; i < n; i++)
            x[i] = 0;
        return x;
    }

    double* x = new double[n];
    double* x2 = new double[n];
    for (int i = 0; i < n; i++)
        x2[i] = c[i];

    double maxE;
    do{
        for (int i = 0; i < n; i++) {
            x[i] = x2[i];
        }

        for (int i = 0; i < n; i++) {
            x2[i] = c[i];
            for (int j = 0; j < n; j++) {
                x2[i] += B[i][j]*x[j];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << x2[i] << " ";
        }
        cout << "\n";
        // Максимальная разница между значениями итераций
        maxE = abs(x2[0] - x[0]);
        for (int i = 1; i < n; i++) {
            if(abs(x2[i] - x[i])>maxE)maxE = abs(x2[0] - x[0]);
        }

    }while(maxE >0.00001);
    return x2;
}


double* seidel(double A[n][n], double b[n]) {
    // Проверка на диагональное преобладание
    bool diagonal_dominance = 1;
    for (int i = 0; i < n; i++) {
        double temp = 0;
        for (int j = 0; j < n; j++) {
            if (j != i)temp += abs(A[j][i]);
        }
        if(temp>abs(A[i][i]))diagonal_dominance = 0;
    }
    if (!diagonal_dominance) {
        diagonal_dominance = 1;
        for (int i = 0; i < n; i++) {
            double temp = 0;
            for (int j = 0; j < n; j++) {
                if (j != i)temp += abs(A[j][i]);
            }
            if (temp > abs(A[i][i]))diagonal_dominance = 0;
        }
        if (!diagonal_dominance) {
            std::cout << "У данной матрицы отсутствует диагональное преобладание, метод Зейделя может быть неприменим к данной матрице\n";
            double* x = new double[n];
            for (int i = 0; i < n; i++)
                x[i] = 0;
            return x;
        }
    }

    double B[n][n];
    double c[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = -A[i][j] / A[i][i];
            if (i == j)B[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
        c[i] = b[i] / A[i][i];

    double* x = new double[n];
    double* x2 = new double[n];
    for (int i = 0; i < n; i++)
        x[i] = c[i];

    double maxE;
    do {
        for (int i = 0; i < n; i++) {
            x2[i] = x[i];
        }

        for (int i = 0; i < n; i++) {
            double temp = c[i];
            for (int j = 0; j < n; j++) {
                temp += B[i][j] * x[j];
            }
            x[i] = temp;
        }

        for (int i = 0; i < n; i++) {
            cout << x2[i] << " ";
        }
        cout << "\n";
        // Максимальная разница между значениями итераций
        maxE = abs(x2[0] - x[0]);
        for (int i = 1; i < n; i++) {
            if (abs(x2[i] - x[i]) > maxE)maxE = abs(x2[0] - x[0]);
        }

    } while (maxE > 0.00001);
    return x2;
}


int main()
{
    std::cout.precision(9);
    double C[n][n] = { {0.01, 0, -0.02, 0, 0},
                       {0.01, 0.01, -0.02, 0, 0},
                       {0, 0.01, 0.01, 0, -0.02},
                       {0, 0, 0.01, 0.01, 0},
                       {0, 0, 0, 0.01, 0.01} };

    // double D[n][n] = { {4, 1, 1, 1, 1},
    //                     {1, 5, 1, 1, 1},
    //                     {1, 1, 6, 1, 1},
    //                     {1, 1, 1, 7, 1},
    //                     {1, 1, 1, 1, 8} };

    // double D[n][n] = { {1.33, 0.21, 0.17, 0.12, -0.13},
    //                     {-0.13, -1.33, 0.11, 0.17, 0.12},
    //                     {0.12, -0.13, -1.33, 0.11, 0.17},
    //                     {0.17, 0.12, -0.13, -1.33, 0.11},
    //                     {0.11, 0.67, 0.12, -0.13, -1.33} };
    double D[n][n] = { {1.66, 0.42, 0.34, 0.24, -0.23},
                       {-0.23, -1.66, 0.22, 0.34, 0.24},
                       {0.24, -0.23, -1.66, 0.34, 0.34},
                       {0.34, 0.24, -0.23, -1.66, 0.5},
                       {0.11, 0.67, 0.24, -0.23, -1.66} };
    double A[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = D[i][j] + 14 * C[i][j];

    double b[n] = { 1.2, 2.2, 4.0, 0, -1.2 };
    cout << "Метод простых итераций.\n";
    cout << "Промежуточные вычисления: \n";
    double* x = simple_iterations(A, b);
    cout << "Итоговый результат: \n";
    cout.precision(5);
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << "\n";
    }
    cout << "\nМетод Зейделя\n";
    cout << "Промежуточные вычисления: \n";
    double* y = seidel(A, b);
    cout << "Итоговый результат: \n";
    cout.precision(5);
    for (int i = 0; i < n; i++)
    {
        cout << y[i] << "\n";
    }
    cout << "\n";
}
