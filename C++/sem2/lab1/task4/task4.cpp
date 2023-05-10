#include <iostream>

class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

class Number : public Expression {
public:
    Number(double value) : value_(value) {}
    double evaluate() const { return value_; }
private:
    double value_;
};

class BinaryOperation : public Expression {
public:
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left_(left), right_(right), op_(op) {}
    double evaluate() const {
        double left = left_->evaluate();
        double right = right_->evaluate();
        switch (op_) {
        case '+': return left + right;
        case '-': return left - right;
        case '*': return left * right;
        case '/': return left / right;
        }
        return 0;
    }
    ~BinaryOperation() {
        delete left_;
        delete right_;
    }
private:
    Expression const * left_;
    Expression const * right_;
    char op_;
};

bool check_equals(Expression const *left, Expression const *right) {
    return *(void **)left == *(void **)right;
}

int main() {
    Expression* sub = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sub);
    std::cout << expr->evaluate() << std::endl; // out 25.5
    std::cout << check_equals(new Number(2), new Number(3)); // out: 1
    delete expr;
    return 0;
}

