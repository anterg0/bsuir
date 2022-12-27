#include <stdio.h>
#include <ctype.h>
#include "bebra.hpp"

int main() {
    while (true) {
        int bebra;
        printf("Выберите функцию: \n");
        printf("1. Создать массив структур\n");
        printf("2. Просмотр содержимого массива структур\n");
        printf("3. Дополнить массив структур\n");
        printf("4. Поиск и вывод структуры по значению элемента\n");
        printf("5. Удаление и изменение массива структур с заданным значением элемента\n");
        printf("6. Упорядочить массив струтур по одному из элементов\n");
        printf("7. Вывод кол-ва продукции для заданного цеха\n");
        printf("8. Завершить программу\n");
        scanf("%d", &bebra);
        switch (bebra) {
            case 1:
                func1();
                break;
            case 2:
                func2();
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            case 5:
                func5();
                break;
            case 6:
                func6();
                break;
            case 7:
                func7();
                break;
            case 8:
                func8();
                printf("Программа завершена.\n");
                return 0;
                break;
            default:
                printf("Неправильно, попробуй ещё раз.\n");
                continue;
                break;
        }
    }
}
