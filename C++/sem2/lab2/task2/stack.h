#ifndef STACK_H
#define STACK_H
#include <QChar>

struct Node {
    QChar bracket;
    int line;
    int column;
    Node() {
        bracket = '\t';
        line = -1;
        column = -1;
    };
};

class stack {
private:
    int top;
    int capacity;
    Node* arr;

public:
    stack(int capacity);

    void push(QChar bracket, int line, int column);

    void pop();

    bool isEmpty();

    bool isFull();

    Node* getTop();

    void clear();
};

#endif // STACK_H
