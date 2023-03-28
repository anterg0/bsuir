#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H

struct DoubleNode {
    double num;
};

class stackDouble
{
private:
    int Top;
    int capacity;
    DoubleNode* arr;

public:
    stackDouble(int capacity);

    double pop();

    void push(double num);
};

#endif // STACKDOUBLE_H
