#ifndef BOOKLIST_H
#define BOOKLIST_H
#include <QMessageBox>

struct Node {
    int bookID;
    QString bookName;
    QString bookAuthor;
    int bookYear;
    QString bookPublisher;
    int bookPageAmount;
    Node* next;
    Node* prev;
    Node() {
        bookID = 0;
        bookName = "";
        bookAuthor = "";
        bookYear = 2000;
        bookPublisher = "";
        bookPageAmount = 1;
        next = NULL;
        prev = NULL;
    }
};


class BookList
{
private:
    Node* head;
    Node* tail;
    int size;
public:
    BookList();
    void add(Node* book);
    bool ins(Node* book, int index);
    bool del(int index);
    void debug();
    void clear();
    int getID(int index);
    QString getName(int index);
    QString getAuthor(int index);
    int getYear(int index);
    QString getPublisher(int index);
    int getPages(int index);
    int capacity();
    void Sort(Node** head, bool (*compare)(Node*, Node*));
    Node* getHp();
    Node* getNode(int index);
};

#endif // BOOKLIST_H
