#include <iostream>
#include <string>
#include <vector>

struct Zavod {
    struct {
        int cehID;
    } ceh;
    struct {
        char name[20]{};
        int quantity;
    } product;
};

std::vector<Zavod> zavody;
bool arrayIsCreated = false;

void func1() {
    if (arrayIsCreated) {
        printf("Массив уже создан. Вы можете его дополнить или изменить.\n");
    } else {
        Zavod zavod;
        printf("Введите номер цеха: ");
        scanf("%d", &zavod.ceh.cehID);
        printf("Введите наименование выпущенного продукта: ");
        scanf("%s", zavod.product.name);
        printf("Введите кол-во выпущенной продукции: ");
        scanf("%d", &zavod.product.quantity);
        zavody.push_back(zavod);
        arrayIsCreated = true;
    }
}

void func2() {
    for (int i = 0; i < zavody.size(); i++) {
        printf("%s были выпущены в кол-ве %d, в цехе под номером %d\n", zavody[i].product.name, zavody[i].product.quantity, zavody[i].ceh.cehID);
    }
}

void func3() {
    if (arrayIsCreated) {
        int num;
        printf("Введите число на сколько элементов вы хотите дополнить массив: ");
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            Zavod zavod;
            printf("Введите номер цеха: ");
            scanf("%d", &zavod.ceh.cehID);
            printf("Введите наименование выпущенного продукта: ");
            scanf("%s", zavod.product.name);
            printf("Введите кол-во выпущенной продукции: ");
            scanf("%d", &zavod.product.quantity);
            zavody.push_back(zavod);
        }
    } else printf("Массив ещё не создан.\n");
}

void func4() {
    if (arrayIsCreated) {
        int bebra,ceh,quant,count = 0;
        char name[300]{};
        printf("Выберите по какому элементу выводить структуру: ");
        printf("1. По номеру цеха\n");
        printf("2. По наименованию продукта\n");
        printf("3. По кол-ву продукта\n");
        printf("(Введите 4 для выхода из функции)");
        while (true) {
            scanf("%d", &bebra);
            switch (bebra) {
                case 1:
                    printf("Введите номер цеха: ");
                    scanf("%d", &ceh);
                    printf("В данном цеху были выпущены такие продукты как: ");
                    for (int i = 0; i < zavody.size(); i++) {
                        if (ceh == zavody[i].ceh.cehID) {
                            count++;
                            printf("%d. %s в кол-ве %d\n", count, zavody[i].product.name, zavody[i].product.quantity);
                        }
                    }
                    break;
                case 2:
                    printf("Введите наименование продукта: ");
                    scanf("%d", &ceh);
                    printf("Такие продукты: ");
                    for (int i = 0; i < zavody.size(); i++) {
                        if (ceh == zavody[i].ceh.cehID) {
                            count++;
                            printf("%d. %s в кол-ве %d\n", count, zavody[i].product.name, zavody[i].product.quantity);
                        }
                    }
                    break;
                case 3:
                    printf("Введите номер цеха: ");
                    scanf("%d", &ceh);
                    printf("В данном цеху были выпущены такие продукты как: ");
                    for (int i = 0; i < zavody.size(); i++) {
                        if (ceh == zavody[i].ceh.cehID) {
                            count++;
                            printf("%d. %s в кол-ве %d\n", count, zavody[i].product.name, zavody[i].product.quantity);
                        }
                    }
                    break;
                case 4:
                    return;
                    break;
                    
                default:
                    printf("Неправильно, попробуй ещё раз.\n");
                    continue;
                    break;
            }
            return;
        }
    }
}

void func5() {
    
}

void func6() {
    
}

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
        printf("7. Завершить программу\n");
        scanf("%d", &bebra);
        switch (bebra) {
            case 1:
                func1();
                continue;
                break;
            case 2:
                func2();
                continue;
                break;
            case 3:
                func3();
                break;
            case 4:
                func4();
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
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
