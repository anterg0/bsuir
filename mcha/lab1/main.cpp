#include <iostream>
#include <iomanip>
using namespace std;

const int n = 5;
const int acc = 4;

double* gauss1(double A[n][n], double* b, int n)
{
    double* x = new double[n];
    for (int i = 0; i < n; i++)
    {
        if (A[i][i] != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                double q = A[j][i] / A[i][i];
                for (int k = i; k < n; k++)
                {
                    if (k == i)
                        A[j][k] = 0;
                    else
                        A[j][k] -= q * A[i][k];
                }
                b[j] -= q * b[i];
            }
        }
        else
        {
            cout << "Данным методом невозможно решить систему: ведущий элемент стал равен 0\n";
            return x;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            b[i] -= x[j] * A[i][j];
        }
        x[i] = b[i] / A[i][i];
    }

    return x;
}



double* gauss2(double A[n][n], double* b, int n)
{
    double* x = new double[n];

    for (int i = 0; i < n; i++)
    {
        int max = abs(A[i][i]);
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (abs(A[j][i]) > max)
            {
                maxIndex = j;
                max = abs(A[j][i]);
            }
        }
        for (int j = 0; j < n; j++)
        {
            swap(A[i][j], A[maxIndex][j]);
        }
        swap(b[i], b[maxIndex]);

        if (A[i][i] != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                double q = A[j][i] / A[i][i];
                for (int k = i; k < n; k++)
                {
                    if (k == i)
                        A[j][k] = 0;
                    else
                        A[j][k] -= q * A[i][k];
                }
                b[j] -= q * b[i];
            }
        }
        else
        {
            cout << "Данным методом невозможно решить систему: столбец возможных ведущих элементов стал равен 0\n";
            return x;
        }

    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            b[i] -= x[j] * A[i][j];
        }
        x[i] = b[i] / A[i][i];
    }
    return x;
}

double* gauss3(double A[n][n], double* b, int n)
{
    double* x = new double[n];

    for (int i = 0; i < n; i++)
    {
        double max = abs(A[i][0]);
        int maxIndexX = i;
        int maxIndexY = 0;
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (abs(A[j][k]) > max)
                {
                    maxIndexX = j;
                    maxIndexY = k;
                    max = abs(A[j][k]);
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            swap(A[i][j], A[maxIndexX][j]);
        }
        swap(b[i], b[maxIndexX]);

        if (A[i][maxIndexY] != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                double q = A[j][maxIndexY] / A[i][maxIndexY];
                for (int k = 0; k < n; k++)
                {
                    if (k == maxIndexY)
                        A[j][k] = 0;
                    else
                        A[j][k] -= q * A[i][k];
                }
                b[j] -= q * b[i];
            }
        }
        else
        {
            cout << "Данным методом невозможно решить систему: элементы в оставшихся строках стали нулевыми (система не имеет единственное решение)\n";
            return x;
        }
    }

    bool* xFound = new bool[n];
    for (int i = 0; i < n; i++)
    {
        xFound[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int curX;
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0 && xFound[j] == 0)
            {
                curX = j;
            }
            if (A[i][j] != 0 && xFound[j] == 1)
            {
                b[i] -= x[j] * A[i][j];
            }
        }
        x[curX] = b[i] / A[i][curX];
        xFound[curX] = 1;
    }
    return x;
}

int main()
{
    cout.precision(acc);
    cout.setf(ios::fixed, ios::floatfield);
    double b[n] = { 3.2, 1.2, 7.2, 3.2, 2.2 };
    double A[n][n] = { {0, 0.91, 0.733, 1.33, 3.76},
                       {5.546, 0, 4.2, 2.28, 1.337},
                       {2.435, 0.123, 0, 0.55, 2.66},
                       {0.12, -0.54, 0.12, 0, 3.12},
                       {-2.12, -1.435, 0.564, 2.554, 0} };
    double C[n][n] = {  {0.4,0.03,0.2,0,0},
                        {0,0.2,0,0.2,0},
                        {0.2,0,0.2,0,0.2},
                        {0.8,0.2,0,0.2,0},
                        {0,0.9,0.2,0,0.2} };

    double D[n][n] = {  {3.33,1.81,0.67,0.92,-0.53},
                        {-0.53,2.33,0.81,0.67,0.92},
                        {0.92,-1.53,2.33,0.81,0.67},
                        {0.67,0.92,-0.53,2.33,0.81},
                        {0.81,2.67,0.92,-0.53,2.33} };

    // double b[n] = { 4.2, 4.2, 4.2, 4.2, 4.2 };
    // double A[n][n];
    // double C[n][n] = {  {0.2,0,0.2,0,0},
    //                     {0,0.2,0,0.2,0},
    //                     {0.2,0,0.2,0,0.2},
    //                     {0,0.2,0,0.2,0},
    //                     {0,0,0.2,0,0.2} };

    // double D[n][n] = {  {2.33,0.81,0.67,0.92,-0.53},
    //                     {-0.53,2.33,0.81,0.67,0.92},
    //                     {0.92,-0.53,2.33,0.81,0.67},
    //                     {0.67,0.92,-0.53,2.33,0.81},
    //                     {0.81,0.67,0.92,-0.53,2.33} };

    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         A[i][j] = 29 * C[i][j] + D[i][j];
    int choice;
    while (true)
    {
        cout << "1. Метод Гаусса (схема единственного деления)\n";
        cout << "2. Метод Гаусса (cчема частичного выбора)\n";
        cout << "3. Метод Гаусса (cхема полного выбора)\n";
        cout << "4. Выход\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                double* x = gauss1(A, b, n);
                for (int i = 0; i < n; i++)
                {
                    cout << x[i] << "\n";
                }
                cout << "\n";
                return 0;
                break;
            }
            case 2:
            {
                double* x = gauss2(A, b, n);
                for (int i = 0; i < n; i++)
                {
                    cout << x[i] << "\n";
                }
                cout << "\n";
                return 0;
                break;
            }
            case 3: {
                double* x = gauss3(A, b, n);
                for (int i = 0; i < n; i++)
                {
                    cout << x[i] << "\n";
                }
                cout << "\n";
                return 0;
                break;
            }
            case 4:
            {
                return 0;
            }
        }
    }
}
