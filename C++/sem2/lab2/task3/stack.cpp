#include "stack.h"

stack::stack(int capacity)
{
    this->Top = -1;
    this->capacity = capacity;
    this->arr = new Node[capacity];
}

void stack::push(QChar letter) {
    if (Top == capacity - 1) {
        return;
    }
    Top++;
    arr[Top].letter = letter;
}


void stack::pop() {
    if (Top == -1) {
        return;
    }
    Top--;
}

bool stack::empty() {
    return (Top == -1);
}

bool stack::isFull() {
    return (Top == capacity - 1);
}

Node* stack::top() {
    if (Top == -1) {
        return NULL;
    }
    return &arr[Top];
}

void stack::clear() {
    Top = -1;
}
