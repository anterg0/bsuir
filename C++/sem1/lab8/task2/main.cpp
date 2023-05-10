#include <iostream>
#include <fstream>
#include <string>

struct Book {
    long long bookID;
    std::string authorSurname;
    std::string authorName;
    std::string name;
    int year;
    std::string publisher;
    int pageCount;
    bool deleted = false;
};
int ind = 0;
Book *books = new Book[1000];

void func1() {
    for (int i = 0; i < ind; i++) {
        if (books[i].deleted) continue;
        std::cout << "########################################################\n";
        std::cout << "Регистрационный номер: \t'" << books[i].bookID << "'\n";
        std::cout << "Фамилия автора: \t    '" << books[i].authorSurname << "'\n";
        std::cout << "Имя автора: \t        '" << books[i].authorName << "'\n";
        std::cout << "Название книги: \t    '" << books[i].name << "'\n";
        std::cout << "Год издания: \t        '" << books[i].year << "'\n";
        std::cout << "Издатель: \t            '" << books[i].publisher << "'\n";
        std::cout << "Число страниц: \t        '" << books[i].pageCount << "'\n";
    }
}

void func2() {
    int n;
    bool alreadyExists;
    std::cout << "Cколько структур вы хотите добавить?\n";
    std::cin >> n;
    for (int i = 0; i < n;i++) {
        while (true) {
            alreadyExists = false;
            Book book;
            std::cout << "Введите регистрационный номер: ";
            std::cin >> book.bookID;
            if (std::cin.fail()) {
                std::cout << "Неверный ввод. Повторите попытку.\n";
                std::cin.clear();
                std::cin.ignore(32676,'\n');
                continue;
            }
            for (int j = 0; j < ind; j++) if (book.bookID == books[j].bookID && !(books[j].deleted)) {
                std::cout << "Такой регистрационный номер уже существует. Введите другой номер.\n";
                alreadyExists = true;
            }
            if (alreadyExists) continue;
            std::cout << "Введите фамилию автора: ";
            while (std::cin >> book.authorSurname) if (std::cin.peek() == '\n') break;
            std::cout << "Введите имя автора: ";
            while (std::cin >> book.authorName) if (std::cin.peek() == '\n') break;
            std::cout << "Введите название книги: ";
            while (std::cin >> book.name) if (std::cin.peek() == '\n') break;
            std::cout << "Введите год издания книги: ";
            std::cin >> book.year;
            if (std::cin.fail()) {
                std::cout << "Неверный ввод. Повторите попытку.\n";
                std::cin.clear();
                std::cin.ignore(32676,'\n');
                continue;
            }
            std::cout << "Введите издателя книги: ";
            while (std::cin >> book.publisher) if (std::cin.peek() == '\n') break;
            std::cout << "Введите кол-во страниц: ";
            std::cin >> book.pageCount;
            if (std::cin.fail()) {
                std::cout << "Неверный ввод. Повторите попытку.\n";
                std::cin.clear();
                std::cin.ignore(32676,'\n');
                continue;
            }
            books[ind] = book;
            ind++;
            break;
        }
    }
}

void func3() {
    for (int i = 0; i < ind; i++) {
        if (books[i].deleted) continue;
        std::cout << "########################################################\n";
        std::cout << "Регистрационный номер: \t'" << books[i].bookID << "'\n";
        std::cout << "Фамилия автора: \t    '" << books[i].authorSurname << "'\n";
        std::cout << "Имя автора: \t        '" << books[i].authorName << "'\n";
        std::cout << "Название книги: \t    '" << books[i].name << "'\n";
        std::cout << "Год издания: \t        '" << books[i].year << "'\n";
        std::cout << "Издатель: \t            '" << books[i].publisher << "'\n";
        std::cout << "Число страниц: \t        '" << books[i].pageCount << "'\n";
    }
    long long n;
    while (true) {
        std::cout << "Введите регистрационный номер книги для удаления структуры: ";
        std::cin >> n;
        bool deleteSuccess = false;
        for (int i = 0; i < ind; i++) {
            if (books[i].deleted == false) if (n == books[i].bookID) {
                books[i].deleted = true;
                deleteSuccess = true;
            }
        }
        if (deleteSuccess) std::cout << "Структура удалена.\n";
        else std::cout << "Либо неправильно введён номер, либо его не существует.\n";
        break;
    }
}

void func4() {
    for (int i = 0; i < ind; i++) {
        if (books[i].deleted) continue;
        std::cout << "########################################################\n";
        std::cout << "Регистрационный номер: \t'" << books[i].bookID << "'\n";
        std::cout << "Фамилия автора: \t    '" << books[i].authorSurname << "'\n";
        std::cout << "Имя автора: \t        '" << books[i].authorName << "'\n";
        std::cout << "Название книги: \t    '" << books[i].name << "'\n";
        std::cout << "Год издания: \t        '" << books[i].year << "'\n";
        std::cout << "Издатель: \t            '" << books[i].publisher << "'\n";
        std::cout << "Число страниц: \t        '" << books[i].pageCount << "'\n";
    }
    long long n, selected = 0;
    bool found = false;
    std::cout << "Введите регистрационный номер книги для изменения структуры: ";
    std::cin >> n;
    for (int i = 0; i < ind; i++) {
        if (n == books[i].bookID && !(books[i].deleted)) {
            selected = i;
            found = true;
            break;
        }
    }
    if (found) {
        std::string surname, name, title, pub;
        long long bebra;
        int pages, year;
        bool alreadyExists = false;
        while (true) {
            std::cout << "Что вы хотите изменить?\n1. Регистрационный номер\n2. Фамилию автора\n3. Имя автора\n4. Название книги\n5. Год издания\n6. Издателя\n7. Число страниц\n";
            std::cin >> n;
            switch (n) {
                case 1:
                    while (true) {
                        std::cout << "Введите регистрационный номер: ";
                        std::cin >> bebra;
                        for (int j = 0; j < ind; j++) if (bebra == books[j].bookID && !(books[j].deleted)) {
                            std::cout << "Такой регистрационный номер уже существует. Введите другой номер.\n";
                            alreadyExists = true;
                        }
                        if (alreadyExists) continue;
                        else break;
                    }
                    books[selected].bookID = bebra;
                    break;
                case 2:
                    std::cout << "Введите фамилию автора: ";
                    while (std::cin >> surname) if (std::cin.peek() == '\n') break;
                    books[selected].authorSurname = surname;
                    break;
                case 3:
                    std::cout << "Введите имя автора: ";
                    while (std::cin >> name) if (std::cin.peek() == '\n') break;
                    books[selected].authorName = name;
                    break;
                case 4:
                    std::cout << "Введите название книги: ";
                    while (std::cin >> title) if (std::cin.peek() == '\n') break;
                    books[selected].name = title;
                    break;
                case 5:
                    std::cout << "Введите год издания: ";
                    std::cin >> year;
                    books[selected].year = year;
                    break;
                case 6:
                    std::cout << "Введите издателя: ";
                    while (std::cin >> pub) if (std::cin.peek() == '\n') break;
                    books[selected].publisher = pub;
                    break;
                case 7:
                    std::cout << "Введите число страниц: ";
                    std::cin >> pages;
                    books[selected].pageCount = pages;
                    break;
                default:
                    std::cout << "Неправильно, попробуй ещё раз.\n";
                    continue;
                    break;
            }
            break;
        }
    } else std::cout << "Такого регистрационного номера нету.\n";
}

void func5() {
    int left = 0;
    int right = ind - 1;
    int year;
    while (left <= right) {
            for (int i = left; i < right; i++) {
                if (books[i].authorSurname > books[i + 1].authorSurname) {
                    std::swap(books[i], books[i + 1]);
                }
            }
            right--;
            for (int i = right; i > left; i--) {
                if (books[i - 1].authorSurname > books[i].authorSurname) {
                    std::swap(books[i - 1], books[i]);
                }
            }
            left++;
    }
    std::cout << "Массив отсортирован.\n";
    std::cout << "\nВведите год: ";
    std::cin >> year;
    for (int i = 0; i < ind; i++) {
        if (books[i].year > year && !(books[i].deleted)) {
            std::cout << "########################################################\n";
            std::cout << "Регистрационный номер: \t'" << books[i].bookID << "'\n";
            std::cout << "Фамилия автора: \t    '" << books[i].authorSurname << "'\n";
            std::cout << "Имя автора: \t        '" << books[i].authorName << "'\n";
            std::cout << "Название книги: \t    '" << books[i].name << "'\n";
            std::cout << "Год издания: \t        '" << books[i].year << "'\n";
            std::cout << "Издатель: \t            '" << books[i].publisher << "'\n";
            std::cout << "Число страниц: \t        '" << books[i].pageCount << "'\n";
        }
    }
}

int main() {
    std::ifstream fin;
    std::ofstream fout;
    fin.open("/Users/anterg0/Documents/bsuir/lab8/task2/input.txt");
    while (!fin.eof()) {
        Book book;
        fin >> book.bookID;
        fin >> book.authorSurname;
        fin >> book.authorName;
        fin >> book.name;
        fin >> book.year;
        fin >> book.publisher;
        fin >> book.pageCount;
        books[ind] = book;
        ind++;
    }
    fin.close();
    while (true) {
        int bebra;
        std::cout << "\nВыберите функцию: \n1. Просмотреть массив структур\n2. Дополнить массив структур\n3. Удалить структуру\n4. Изменить структуру\n5. Выполнить сортировку и вывести все книги изданные после заданного года\n6. Завершить программу и записать в файл\n";
        std::cin >> bebra;
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
                fout.open("/Users/anterg0/Documents/bsuir/lab8/task2/output.txt");
                for (int i = 0; i < ind; i++) {
                    if (books[i].deleted) continue;
                    fout << books[i].bookID << std::endl;
                    fout << books[i].authorSurname << std::endl;
                    fout << books[i].authorName << std::endl;
                    fout << books[i].year << std::endl;
                    fout << books[i].name << std::endl;
                    fout << books[i].publisher << std::endl;
                    fout << books[i].pageCount << std::endl;
                }
                fout.close();
                delete[] books;
                std::cout << "Программа завершена.\n";
                return 0;
                break;
            default:
                std::cout << "Неправильно, попробуй ещё раз.\n";
                break;
        }
    }
}
