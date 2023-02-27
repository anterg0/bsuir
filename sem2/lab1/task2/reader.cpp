#include "reader.h"

void Reader::setName(QString name) {
    fullName = name;
}

void Reader::setNumber(QString number) {
    phoneNumber = number;
}

void Reader::setReaderID(int id) {
    ID = id;
}

void Reader::setContantAddress(QString address) {
    contactAddress = address;
}

void Reader::addBorrowedBook(Book book) {
    borrowedBooks.append(book);
}

QList<Book> Reader::getBorrowedBooks() {
    return borrowedBooks;
}

Reader::Reader(int ID, const QString &name, const QString &number, const QString &address) : ID(ID), fullName(name), phoneNumber(number), contactAddress(address) {}

Reader::Reader() {
    fullName = "";
    phoneNumber = "";
}

QString Reader::getName() {
    return fullName;
}

QString Reader::getNumber() {
    return phoneNumber;
}

QString Reader::getAddress() {
    return contactAddress;
}

int Reader::getID() {
    return ID;
}

void Reader::isDebtor() {
    int count = borrowedBooks.size();
    for (int i = 0; i < count; i++) {
        QDate newDate = borrowedBooks[i].returnDate.addDays(10);
        if (QDate::currentDate() > newDate) {
            Debtor = true;
            borrowedBooks[i].debt = true;
        }
    }
}

bool Reader::isDebt() {
    return Debtor;
}

void Reader::delBorrowedBook(int index) {
    borrowedBooks.removeAt(index);
}
