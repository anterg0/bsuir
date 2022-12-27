#include <iostream>
#include <fstream>

struct Book {
    long long bookID;
    struct {
        std::string authorSurname;
        std::string authorName;
    } author;
    std::string name;
    int year;
    std::string publisher;
    int pageCount;
};
int ind = 0;
Book *books = new Book[1000];

std::fstream bebrochka();

int main() {
    while (ind < 3) {
        Book book;
        std::cout << "Введите регистрационный номер книги: ";
        std::cin >> book.bookID;
        std::cout << "Введите фамилию автора: ";
        std::cin >> book.author.authorSurname;
        std::cout << "Введите имя автора: ";
        std::cin >> book.author.authorName;
        std::cout << "Введите название книги: ";
        std::cin >> book.name;
        std::cout << "Введите год издания книги: ";
        std::cin >> book.year;
        std::cout << "Введите издателя книги: ";
        std::cin >> book.publisher;
        std::cout << "Введите кол-во страниц книги: ";
        std::cin >> book.pageCount;
        books[ind] = book;
        ind++;
        bebrochka.open();
        bebrochka << books[0].bookID << " " << books[0].author.authorSurname << " " << books[0].author.authorName << " " << books[0].name << " " << books[0].year << " " << books[0].publisher << " " << books[0].pageCount << std::endl;
        bebrochka.close();
    }
    
    return 0;
}
