#include <iostream>
#include <QApplication>

struct Node {
    int data;
    Node* next;
};

class Stack {
private:

    Node* top;

public:
    Stack() : top(nullptr) {}
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() const {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
            return -1;
        }

        return top->data;
    }

    bool isEmpty() const {
        return top == nullptr;
    }
    Node* getTop() {
        return top;
    }
};

class HashTable {
protected:
    Stack* table;
    int size;
public:
    HashTable(int _size) : size(_size) {
        table = new Stack[size];
    }
    ~HashTable() {
        for (int i = 0; i < size; ++i) {
            while (!table[i].isEmpty()) {
                table[i].pop();
            }
        }
        delete[] table;
    }
    void insert(int value) {
        int index = hashFunction(value);
        table[index].push(value);
    }

    int hashFunction(int value) const {
        return value % size;
    }
    QString getStackContents(int index) {
        if (!(table[index].isEmpty())) {
            Node* bebra = table[index].getTop();
            QString result = "Stack " + QString::number(index) + " contains: ";
            while (bebra) {
                result += QString::number(bebra->data) + " ";
                bebra = bebra->next;
            }
            result += "\n";
            return result;
        }
        return "Stack is empty.\n";
    }
    void clear() {
        for (int i = 0; i < size; ++i) {
            while (!table[i].isEmpty()) {
                table[i].pop();
            }
        }
    }
};

class DerivedHashTable : public HashTable {
public:
    DerivedHashTable(int size) : HashTable(size) {}
    int getIndexOfMaxStack() const {
        int maxIndex = -1;
        int maxNumber = std::numeric_limits<int>::min();

        for (int i = 0; i < size; ++i) {
            Node* currentNode = table[i].getTop();
            while (currentNode) {
                if (currentNode->data > maxNumber) {
                    maxNumber = currentNode->data;
                    maxIndex = i;
                }
                currentNode = currentNode->next;
            }
        }

        return maxIndex;
    }
};
