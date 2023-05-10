#include <iostream>

int main(){
    while (true) {
        int n,m;
        char a;
        std::cout << "Введите размеры поля: ";
        std::cin >> n >> m;
        if (std::cin.fail() || std::cin.peek() != '\n' || n < 1 || m < 1) {
            std::cout << "Неверный ввод. Попробуйте снова.\n";
            std::cin.clear();
            std::cin.ignore(100000000,'\n');
            continue;
        }
        char **arr = (char**)malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            arr[i] = (char*)malloc(m * sizeof(char));
        }
        std::cout << "Заполните поле. Введите 1 для установки бомбы или 0 для установки пустого места: ";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cin >> a;
                if (a == '1') {
                    arr[i][j] = '*';
                }
                else if (a == '0') {
                    arr[i][j] = '.';
                }
                else {
                    std::cout << "Неверный ввод. Попробуйте снова.\n";
                    std::cin.clear();
                    std::cin.ignore(100000000,'\n');
                    std::cout << "Введите 1 для установки бомбы или 0 для установки пустого места: ";
                    j--;
                    continue;
                }
            }
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (arr[i][j] == '.') {
                int count = 0;
                for (int k = -1; k <= 1; k++) {
                    for (int v = -1; v <= 1;v++) {
                        if (i + k >= 0 && j + v >= 0 && i + k <= n - 1 && j + v <= m - 1) {
                            if (arr[i + k][j + v] == '*') {
                                count++;
                            }
                        }
                    }
                }
                if (count != 0) arr[i][j] = char(count) + '0';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << '\n';
        }
        for (int i = 0; i < m; i++) {
            free(arr[i]);
        }
        free(arr);
        std::cout << "Желаете повторить? (y/n)";
        char choice;
        std::cin >> choice;
        switch (choice) {
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
}
