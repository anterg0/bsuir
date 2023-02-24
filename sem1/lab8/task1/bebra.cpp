#include <stdio.h>
#include <ctype.h>
#include "bebra.hpp"

int ind = 0;
Zavod *zavody = new Zavod[300];
bool arrayIsCreated = false;

void func1() {
    if (arrayIsCreated) {
        printf("Массив уже создан. Вы можете его дополнить или изменить.\n");
    } else {
        bool rabochie;
        printf("Введите кол-во структур: ");
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            rabochie = false;
            Zavod zavod;
            printf("Введите номер цеха: ");
            if (scanf("%d", &zavod.ceh.cehID) != 1) {
                printf("Повторите ввод.\n");
                i--;
                fflush(stdin);
                continue;
            }
            for (int j = 0; j < ind; j++) if (zavod.ceh.cehID == zavody[j].ceh.cehID) rabochie = true;
            if (!(rabochie)) {
                printf("Введите кол-во рабочих в цеху: ");
                if (scanf("%d", &zavod.ceh.workersNum) != 1 || zavod.ceh.workersNum < 1) {
                    printf("Повторите ввод.\n");
                    i--;
                    fflush(stdin);
                    continue;
                }
            }
            printf("Введите наименование выпущенного продукта: ");
            scanf("%s", zavod.product.name);
            printf("Введите кол-во выпущенной продукции: ");
         
            if (scanf("%d", &zavod.product.quantity) != 1 || zavod.product.quantity < 0) {
                printf("Повторите ввод.\n");
                i--;
                fflush(stdin);
                continue;
            }
            printf("Введите кол-во бракованного продукта: ");
            if (scanf("%d", &zavod.product.failedQuantity) != 1 || zavod.product.failedQuantity < 0) {
                printf("Повторите ввод.\n");
                i--;
                fflush(stdin);
                continue;
            }
            zavody[ind] = zavod;
            ind++;
            arrayIsCreated = true;
            int cont;
            bool bruh = true;
            if (i != n - 1) while (bruh) {
                printf("Продолжить ввод? \n1. Да \n2. Нет\n");
                scanf("%d", &cont);
                switch (cont) {
                    case 1:
                        bruh = false;
                        break;
                    case 2:
                        bruh = false;
                        i = n;
                        break;
                    default:
                        printf("Неправильно, попробуй ещё раз.\n");
                        break;
                }
            }
        }
    }
}

void func2() {
    if (arrayIsCreated) {
        bool arrayIsEmpty = true;
        for (int i = 0; i < ind; i++) {
            if (zavody[i].deleted == true) continue;
            else {
                printf("%s были выпущены в кол-ве %d, в цехе под номером %d с кол-вом рабочих %d, кол-во брака %d\n", zavody[i].product.name, zavody[i].product.quantity, zavody[i].ceh.cehID, zavody[i].ceh.workersNum, zavody[i].product.failedQuantity);
                arrayIsEmpty = false;
            }
        }
        if (arrayIsEmpty) printf("Массив пуст.\n");
    } else printf("Массив ещё не создан.\n");
}

void func3() {
    if (arrayIsCreated) {
        int num;
        bool rabochie;
        while (true) {
            printf("Введите число на сколько элементов вы хотите дополнить массив: ");
            if (scanf("%d", &num) != 1 || num < 0) {
                printf("Повторите ввод.\n");
                fflush(stdin);
            } else break;
        }
        for (int i = 0; i < num; i++) {
            rabochie = false;
            Zavod zavod;
            printf("Введите номер цеха: ");
            if (scanf("%d", &zavod.ceh.cehID) != 1) {
                printf("Повторите ввод.\n");
                i--;
                fflush(stdin);
                continue;
            }
            for (int j = 0; j < ind; j++) if (zavod.ceh.cehID == zavody[j].ceh.cehID) rabochie = true;
            if (!(rabochie)) {
                printf("Введите кол-во рабочих в цеху: ");
                if (scanf("%d", &zavod.ceh.workersNum) != 1 || zavod.ceh.workersNum < 1) {
                    printf("Повторите ввод.\n");
                    i--;
                    fflush(stdin);
                    continue;
                }
            }
            printf("Введите наименование выпущенного продукта: ");
            scanf("%s", zavod.product.name);
            printf("Введите кол-во выпущенной продукции: ");
            if (scanf("%d", &zavod.product.quantity) != 1 || zavod.product.quantity < 0) {
                printf("Повторите ввод.\n");
                i--;
                fflush(stdin);
                continue;
            }
            printf("Введите кол-во бракованного продукта: ");
            if (scanf("%d", &zavod.product.failedQuantity) != 1 || zavod.product.failedQuantity < 0) {
                printf("Повторите ввод.\n");
                i--;
                fflush(stdin);
                continue;
            }
            zavody[ind] = zavod;
            ind++;
            int cont;
            bool bruh = true;
            if (i != num - 1) while (bruh) {
                printf("Продолжить ввод? \n1. Да \n2. Нет\n");
                scanf("%d", &cont);
                switch (cont) {
                    case 1:
                        bruh = false;
                        break;
                    case 2:
                        bruh = false;
                        i = num;
                        break;
                    default:
                        printf("Неправильно, попробуй ещё раз.\n");
                        break;
                }
            }
        }
    } else printf("Массив ещё не создан.\n");
}

void func4() {
    if (arrayIsCreated) {
        int bebra, ceh, quant, count = 0, workers, fail;
        char name[300]{};
        printf("Выберите по какому элементу выводить структуру: \n");
        printf("1. По номеру цеха\n");
        printf("2. По наименованию продукта\n");
        printf("3. По кол-ву продукта\n");
        printf("4. По кол-ву рабочих в цеху\n");
        printf("5. По кол-ву брака\n");
        printf("(Введите 6 для выхода из функции)\n");
        while (true) {
            scanf("%d", &bebra);
            switch (bebra) {
                case 1:
                    while (true) {
                        printf("Введите номер цеха: ");
                        if (scanf("%d", &ceh) != 1) {
                            printf("Повторите ввод.\n");
                            fflush(stdin);
                        } else break;
                    }
                    printf("В данном цеху были выпущены такие продукты как: \n");
                    for (int i = 0; i < ind; i++) {
                        if (ceh == zavody[i].ceh.cehID) {
                            count++;
                            printf("%d. %s в кол-ве %d, в том числе кол-во брака %d\n", count, zavody[i].product.name, zavody[i].product.quantity, zavody[i].product.failedQuantity);
                        }
                    }
                    break;
                case 2:
                    printf("Введите наименование продукта: ");
                    scanf("%s", name);
                    printf("'%s' было выпущено: \n", name);
                    for (int i = 0; i < ind; i++) {
                        bool nameEqual = true;
                        for (int j = 0; j < 300; j++) {
                            if (name[j] != zavody[i].product.name[j]) nameEqual = false;
                        }
                        if (nameEqual) {
                            count++;
                            printf("%d. из цеха %d в кол-ве %d, в том числе кол-во брака %d\n", count, zavody[i].ceh.cehID, zavody[i].product.quantity, zavody[i].product.failedQuantity);
                        }
                    }
                    break;
                case 3:
                    while (true) {
                        printf("Введите число выпущенной продукции: ");
                        if (scanf("%d", &quant) != 1) {
                            printf("Повторите ввод.\n");
                            fflush(stdin);
                        } else break;
                    }
                    printf("В таком кол-ве были выпущены следующие продукты: \n");
                    for (int i = 0; i < ind; i++) {
                        if (quant == zavody[i].product.quantity) {
                            count++;
                            printf("%d. '%s' из цеха %d, кол-во брака %d\n", count, zavody[i].product.name, zavody[i].ceh.cehID, zavody[i].product.failedQuantity);
                        }
                    }
                    break;
                case 4:
                    while (true) {
                        printf("Введите кол-во рабочих: ");
                        if (scanf("%d", &workers) != 1) {
                            printf("Повторите ввод.\n");
                            fflush(stdin);
                            continue;
                        } else break;
                    }
                    for (int i = 0; i < ind; i++) {
                        if (workers == zavody[i].ceh.workersNum) {
                            count = 0;
                            printf("В цеху под номером %d были выпущены следующие продукты: \n", zavody[i].ceh.cehID);
                            for (int j = 0; j < ind; j++) if (zavody[j].ceh.cehID == zavody[i].ceh.cehID) {
                                count++;
                                printf("%d. '%s' кол-вом %d и кол-вом брака %d\n", count, zavody[j].product.name, zavody[j].product.quantity, zavody[j].product.failedQuantity);
                            }
                        }
                    }
                    break;
                case 5:
                    while (true) {
                        printf("Введите кол-во брака: ");
                        if (scanf("%d", &fail) != 1) {
                            printf("Повторите ввод.\n");
                            fflush(stdin);
                            continue;
                        } else break;
                    }
                    for (int i = 0; i < ind; i++) {
                        if (fail == zavody[i].product.failedQuantity) {
                            printf("Такое же кол-во брака имеют следующие продукты: \n");
                            if (zavody[i].product.failedQuantity == fail) {
                                count++;
                                printf("%d. '%s' кол-вом %d, выпущено из цеха номер %d с кол-вом рабочих %d\n", count, zavody[i].product.name, zavody[i].product.quantity, zavody[i].ceh.cehID, zavody[i].ceh.workersNum);
                            }
                        }
                    }
                    break;
                case 6:
                    return;
                    break;
                    
                default:
                    printf("Неправильно, попробуй ещё раз.\n");
                    continue;
                    break;
            }
            return;
        }
    } else printf("Массив ещё не создан.\n");
}

void func5() {
    if (arrayIsCreated) {
        while (true) {
            printf("Выберите действие: \n");
            printf("1. Изменение элементов\n");
            printf("2. Удаление элементов\n");
            printf("3. Завершить функцию\n");
            int choice1, choice, delCount = 0, ceh, quant, fail, workers;
            char name[300]{};
            scanf("%d", &choice1);
            switch (choice1) {
                case 1:
                    printf("Для изменения элемента требуется наименование продукта и номер цеха, где был произведён данный продукт.\n");
                    printf("Введите наименование продукта: ");
                    scanf("%s", name);
                    while (true) {
                        printf("Введите номер цеха: ");
                        if (scanf("%d", &ceh) != 1) {
                            printf("Повторите ввод.\n");
                            fflush(stdin);
                            continue;
                        } else break;
                    }
                    for (int i = 0; i < ind; i++) {
                        bool nameEqual = true;
                        for (int j = 0; j < 300; j++) {
                            if (name[j] != zavody[i].product.name[j]) nameEqual = false;
                        }
                        if (ceh == zavody[i].ceh.cehID && nameEqual) {
                            printf("Элемент найден.\n");
                            while (true) {
                                printf("Что вы хотите изменить?\n1. Номер цеха\n2. Наименование продукта\n3. Кол-во продукции\n4. Кол-во брака\n5. Завершить функцию\n");
                                scanf("%d", &choice);
                                switch (choice) {
                                    case 1:
                                        while (true) {
                                            printf("Введите номер цеха: ");
                                            if (scanf("%d", &ceh) != 1) {
                                                printf("Повторите ввод.\n");
                                                fflush(stdin);
                                                continue;
                                            } else break;
                                        }
                                        zavody[i].ceh.cehID = ceh;
                                        break;
                                    case 2:
                                        printf("Введите наименование продукции: ");
                                        scanf("%s", name);
                                        for (int m = 0; m < 300; i++) zavody[i].product.name[m] = name[m];
                                        break;
                                    case 3:
                                        while (true) {
                                            printf("Введите кол-во продукции: ");
                                            if (scanf("%d", &quant) != 1 || quant < 0) {
                                                printf("Повторите ввод.\n");
                                                fflush(stdin);
                                                continue;
                                            } else break;
                                        }
                                        zavody[i].product.quantity = quant;
                                        break;
                                    case 4:
                                        while (true) {
                                            printf("Введите кол-во брака: ");
                                            if (scanf("%d", &fail) != 1 || fail < 0) {
                                                printf("Повторите ввод.\n");
                                                fflush(stdin);
                                                continue;
                                            } else break;
                                        }
                                        zavody[i].product.failedQuantity = fail;
                                        break;
                                    case 5:
                                        return;
                                        break;
                                        
                                    default:
                                        printf("Неправильно, попробуй ещё раз.\n");
                                        break;
                                }
                            }
                        } else printf("Элемент не найден.\n");
                    }
                    break;
                case 2:
                    while (true) {
                        printf("По какому критерию удалять элементы?\n");
                        printf("1. По номеру цеха\n");
                        printf("2. По наименованию продукта\n");
                        printf("3. По кол-ву продукции\n");
                        printf("4. По кол-ву брака\n");
                        printf("5. По кол-ву рабочих\n");
                        printf("6. Завершить функцию\n");
                        scanf("%d", &choice);
                        switch (choice) {
                            case 1:
                                while (true) {
                                    printf("Введите номер цеха: ");
                                    if (scanf("%d", &ceh) != 1) {
                                        printf("Повторите ввод.\n");
                                        fflush(stdin);
                                        continue;
                                    } else break;
                                }
                                for (int i = 0; i < ind; i++) {
                                    if (ceh == zavody[i].ceh.cehID) {
                                        zavody[i].deleted = true;
                                        delCount++;
                                    }
                                }
                                printf("Было найдено и удалено %d элементов.\n", delCount);
                                break;
                            case 2:
                                printf("Введите наименование продукции: ");
                                scanf("%s", name);
                                for (int i = 0; i < ind; i++) {
                                    bool nameEqual = true;
                                    for (int j = 0; j < 300; j++) {
                                        if (name[j] != zavody[i].product.name[j]) nameEqual = false;
                                    }
                                    if (nameEqual) {
                                        zavody[i].deleted = true;
                                        delCount++;
                                    }
                                }
                                if (delCount) printf("Было найдено и удалено %d элементов.\n", delCount);
                                else printf("Таких элементов не существует.\n");
                                break;
                            case 3:
                                while (true) {
                                    printf("Введите кол-во продукции: ");
                                    if (scanf("%d", &quant) != 1) {
                                        printf("Повторите ввод.\n");
                                        fflush(stdin);
                                        continue;
                                    } else break;
                                }
                                for (int i = 0; i < ind; i++) {
                                    if (quant == zavody[i].product.quantity) {
                                        zavody[i].deleted = true;
                                        delCount++;
                                    }
                                }
                                if (delCount) printf("Было найдено и удалено %d элементов.\n", delCount);
                                else printf("Таких элементов не существует.\n");
                                break;
                            case 4:
                                while (true) {
                                    printf("Введите кол-во брака: ");
                                    if (scanf("%d", &fail) != 1) {
                                        printf("Повторите ввод.\n");
                                        fflush(stdin);
                                        continue;
                                    } else break;
                                }
                                for (int i = 0; i < ind; i++) {
                                    if (fail == zavody[i].product.failedQuantity) {
                                        zavody[i].deleted = true;
                                        delCount++;
                                    }
                                }
                                if (delCount) printf("Было найдено и удалено %d элементов.\n", delCount);
                                else printf("Таких элементов не существует.\n");
                                break;
                            case 5:
                                while (true) {
                                    printf("Введите кол-во рабочих: ");
                                    if (scanf("%d", &workers) != 1) {
                                        printf("Повторите ввод.\n");
                                        fflush(stdin);
                                        continue;
                                    } else break;
                                }
                                for (int i = 0; i < ind; i++) {
                                    if (workers == zavody[i].ceh.workersNum) {
                                        zavody[i].deleted = true;
                                        delCount++;
                                    }
                                }
                                if (delCount) printf("Было найдено и удалено %d элементов.\n", delCount);
                                else printf("Таких элементов не существует.\n");
                                break;
                            case 6:
                                return;
                                break;
                            default:
                                printf("Повторите ввод: ");
                                continue;
                                break;
                        }
                    }
                    break;
                case 3:
                    return;
                    break;
                default:
                    printf("Неправильно, попробуй ещё раз.\n");
                    continue;
                    break;
            }
        }
    } else printf("Массив ещё не создан.\n");
}

void func6() {
    int choice;
    int left = 0;
    int right = ind - 1;
    while (true) {
        printf("Введите по какому критерию упорядочить массив (по убыванию): \n1. Номер цеха\n2. Наименование продукта\n3. Кол-во выпущенной продукции\n4. Кол-во брака\n5. Кол-во рабочих в цеху\n6. Завершить функцию\n");
        if (scanf("%d", &choice) != 1) {
            printf("Повторите ввод.\n");
            fflush(stdin);
            continue;
        }
        switch (choice) {
            case 1:
                while (left < right) {
                    for (int i = left; i < right; i++) {
                        if (zavody[i].ceh.cehID < zavody[i + 1].ceh.cehID) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i + 1];
                            zavody[i + 1] = temp;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if (zavody[i - 1].ceh.cehID < zavody[i].ceh.cehID) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i - 1];
                            zavody[i - 1] = temp;
                        }
                    }
                    left++;
                }
                printf("Массив упорядочен.\n");
                break;
            case 2:
                while (left < right) {
                    for (int i = left; i < right; i++) {
                        if (tolower(zavody[i].product.name[0]) < tolower(zavody[i + 1].product.name[0])) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i + 1];
                            zavody[i + 1] = temp;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if (tolower(zavody[i - 1].product.name[0]) < tolower(zavody[i].product.name[0])) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i - 1];
                            zavody[i - 1] = temp;
                        }
                    }
                    left++;
                }
                printf("Массив упорядочен.\n");
                break;
            case 3:
                while (left < right) {
                    for (int i = left; i < right; i++) {
                        if (zavody[i].product.quantity < zavody[i + 1].product.quantity) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i + 1];
                            zavody[i + 1] = temp;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if (zavody[i - 1].product.quantity < zavody[i].product.quantity) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i - 1];
                            zavody[i - 1] = temp;
                        }
                    }
                    left++;
                }
                printf("Массив упорядочен.\n");
                break;
            case 4:
                while (left < right) {
                    for (int i = left; i < right; i++) {
                        if (zavody[i].product.failedQuantity < zavody[i + 1].product.failedQuantity) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i + 1];
                            zavody[i + 1] = temp;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if (zavody[i - 1].product.failedQuantity < zavody[i].product.failedQuantity) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i - 1];
                            zavody[i - 1] = temp;
                        }
                    }
                    left++;
                }
                printf("Массив упорядочен.\n");
                break;
            case 5:
                while (left < right) {
                    for (int i = left; i < right; i++) {
                        if (zavody[i].ceh.workersNum < zavody[i + 1].ceh.workersNum) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i + 1];
                            zavody[i + 1] = temp;
                        }
                    }
                    right--;
                    for (int i = right; i > left; i--) {
                        if (zavody[i - 1].ceh.workersNum < zavody[i].ceh.workersNum) {
                            Zavod temp = zavody[i];
                            zavody[i] = zavody[i - 1];
                            zavody[i - 1] = temp;
                        }
                    }
                    left++;
                }
                printf("Массив упорядочен.\n");
                break;
            case 6:
                return;
                break;
            default:
                printf("Неправильно, попробуй ещё раз.\n");
                break;
        }
    }
}

void func7() {
    if (arrayIsCreated) {
        long long result = 0;
        int ceh;
        bool cehIsReal = false;
        printf("Введите номер цеха: ");
        scanf("%d", &ceh);
        for (int i = 0; i < ind; i++) {
            if (ceh == zavody[i].ceh.cehID) {
                result += zavody[i].product.quantity;
                cehIsReal = true;
            }
        }
        if (cehIsReal) printf("В цеху под номером %d всего было выпущено такое кол-во продукции: %lld\n", ceh, result);
        else printf("Цеха под таким номером не существует.\n");
    } else printf("Массив ещё не создан.\n");
}

void func8() {
    delete[] zavody;
}

