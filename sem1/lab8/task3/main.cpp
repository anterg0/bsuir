#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

union bebra {
    int otdelNum;
};

class Worker {
public:
    int year;
    std::string name;
    std::string job;
    bebra id;
};

void func1(Worker* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "#" << i + 1 << "\nИмя: " << array[i].name;
        std::cout << "\nДолжность: " << array[i].job;
        std::cout << "\nНомер отдела: " << array[i].id.otdelNum;
        std::cout << "\nГод начала работы: " << array[i].year << "\n";
    }
}

Worker* func2(Worker* array, int size, int amount) {
    int new_size = size + amount;
    Worker* bebra = array;
    array = new Worker[new_size];
    for (int i = 0; i < size; i++) {
        array[i].name = bebra[i].name;
        array[i].job = bebra[i].job;
        array[i].id.otdelNum = bebra[i].id.otdelNum;
        array[i].year = bebra[i].year;
    }
    for (int i = size; i < new_size; i++) {
        std::cout << "Имя: ";
        std::cin >> array[i].name;
        std::cout << "Должность: ";
        std::cin >> array[i].job;
        std::cout << "Номер отдела: ";
        std::cin >> array[i].id.otdelNum;
        std::cout << "Год начала работы: ";
        std::cin >> array[i].year;

    }
    size = new_size;
    return array;
}

Worker* func3(Worker* array, int size) {
    int n;
    std::cout << "Какую структуру вы хотите удалить?\n";
    std::cin >> n;
    Worker* temp = array;
    array = new Worker[size - 1];
    int k = 0;
    for (int i = 0; i < size; i++) {
        if (i != n - 1) {
            array[k].name = temp[i].name;
            array[k].job = temp[i].job;
            array[k].id.otdelNum = temp[i].id.otdelNum;
            array[k].year = temp[i].year;
            k++;
        }
    }
    size--;
    std::cout << "Структура удалена.\n";
    return array;
}

void func4(Worker* array) {
    int n;
    std::cout << "Какую структуру вы хотите изменить?\n";
    std::cin >> n;
    std::cout << "Имя: ";
    std::cin >> array[n - 1].name;
    std::cout << "Должность: ";
    std::cin >> array[n - 1].job;
    std::cout << "Номер отдела: ";
    std::cin >> array[n - 1].id.otdelNum;
    std::cout << "Год начала работы: ";
    std::cin >> array[n - 1].year;
}

void func5(Worker *array, int n) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        for (int i = left; i < right; i++) {
            if (array[i].year > array[i + 1].year) {
                std::swap(array[i], array[i + 1]);
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (array[i - 1].year > array[i].year) {
                std::swap(array[i - 1], array[i]);
            }
        }
        left++;
    }
    std::cout << "Массив отсортирован.\n";
}

int main() {
    FILE* file = nullptr;
    file = fopen("/Users/anterg0/Documents/bsuir/lab8/task3/file.bin", "r+b");
    Worker* array = nullptr;
    int amount = 0, start_amount;
    int n = 0;
    fread(&start_amount, sizeof(int), 1, file);
    for (int i = 0; i < start_amount; i++) {
        Worker* bebra = array;
        array = new Worker[n + 1];
        if (n) for (int i = 0; i < n; i++) {
            array[i].name = bebra[i].name;
            array[i].job = bebra[i].job;
            array[i].id.otdelNum = bebra[i].id.otdelNum;
            array[i].year = bebra[i].year;
        }
        fread(&array[amount], sizeof(Worker), 1, file);
        amount = n + 1;
        n++;
    }
    while (true) {
        std::cout << "\nВыберите функцию: \n1. Просмотреть массив структур\n2. Дополнить массив структур\n3. Удалить структуру\n4. Изменить структуру\n5. Выполнить сортировку по стажу\n6. Завершить программу и записать в файл\n";
        int choice, ind;
        std::cin >> choice;
        switch (choice) {
            case 1:
                func1(array, amount);
                break;
            case 2:
                int num;
                std::cout << "Сколько структур вы хотите добавить?\n";
                std::cin >> num;
                array = func2(array, amount, num);
                fseek(file, 0, SEEK_END);
                ind = amount - num;
                for (int i = ind; i < amount; i++) {
                    fwrite(&array[i], sizeof(Worker), 1, file);
                }
                amount += num;
                fseek(file, 0, SEEK_SET);
                fwrite(&amount, sizeof(int), 1, file);
                break;
            case 3:
                func1(array, amount);
                array = func3(array, amount);
                fseek(file, 0, SEEK_SET);
                amount--;
                fwrite(&amount, sizeof(int), 1, file);
                for (int i = 0; i < amount; i++) {
                    fwrite(&array[i], sizeof(Worker), 1, file);
                }
                break;
            case 4:
                func1(array, amount);
                func4(array);
                fseek(file, 0, SEEK_SET);
                fwrite(&amount, sizeof(int), 1, file);
                for (int i = 0; i < amount; i++) {
                    fwrite(&array[i], sizeof(Worker), 1, file);
                }
                break;
            case 5:
                func5(array, amount);
                break;
            case 6:
                fclose(file);
                delete[] array;
                return 0;
                break;
            default:
                std::cout << "Неправильно, попробуй ещё раз.\n";
                break;
        }
    }
}

