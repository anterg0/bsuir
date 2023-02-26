#ifndef READER_H
#define READER_H
#include <QApplication>
#include <QDate>
struct Book {
    int bookID;
    QString name;
    QString author;
    QString language;
    int year;
    QDate returnDate;
    Book() {}
    Book(int ID, QString nam, QString autho, QString languag, int yea, QDate returnDat) : bookID(ID), name(nam), author(autho), language(languag), year(yea), returnDate(returnDat) {}
    Book(int ID, QString nam, QString autho, QString languag, int yea) : bookID(ID), name(nam), author(autho), language(languag), year(yea) {}
};


class Reader {
private:
    int ID;
    QString fullName;
    QString phoneNumber;
    QString contactAddress;
    QList<Book> borrowedBooks;
    bool Debtor = false;
public:
    Reader();
    Reader(int ID, const QString &name, const QString &number, const QString &address);
    void setName(QString name);
    void setReaderID(int id);
    void setNumber(QString number);
    void setContantAddress(QString address);
    int getID();
    QString getName();
    QString getNumber();
    QString getAddress();
    void addBorrowedBook(Book book);
    QList<Book> getBorrowedBooks();
    void isDebtor();
};

#endif // READER_H
