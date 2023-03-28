#include "stackdouble.h"

stackDouble::stackDouble(int capacity)
{
    this->Top = -1;
    this->capacity = capacity;
    this->arr = new DoubleNode[capacity];
}

double stackDouble::pop() {
    if (Top == -1) {
        return 1;
    }
    return arr[Top--].num;
}

void stackDouble::push(double num) {
    if (Top == capacity - 1) {
        return;
    }
    Top++;
    arr[Top].num = num;
}
