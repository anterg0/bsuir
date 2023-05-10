#include "stack.h"

stack::stack(int capacity)
{
    this->top = -1;
    this->capacity = capacity;
    this->arr = new Node[capacity];
}

void stack::push(QChar bracket, int line, int column) {
    if (top == capacity - 1) {
        return;
    }
    top++;
    arr[top].bracket = bracket;
    arr[top].line = line;
    arr[top].column = column;
}

void stack::pop() {
    if (top == -1) {
        return;
    }
    top--;
}

bool stack::isEmpty() {
    return (top == -1);
}

bool stack::isFull() {
    return (top == capacity - 1);
}

Node* stack::getTop() {
    if (top == -1) {
        return NULL;
    }
    return &arr[top];
}

void stack::clear() {
    top = -1;
}
