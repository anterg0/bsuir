#ifndef STACK_H
#define STACK_H
#include <QChar>

struct Node {
    QChar letter;
    double num;
    Node() {
        letter = '\0';
//        num = NAN;
    };
};

class stack {
private:
    int Top;
    int capacity;
    Node* arr;

public:
    stack(int capacity);

//    void push(QChar letter, double num);
    void push(QChar letter);
//    void push(double num);

    void pop();

    bool empty();

    bool isFull();

    Node* top();

    void clear();
};

#endif // STACK_H
