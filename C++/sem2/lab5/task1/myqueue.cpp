#include <iostream>

struct Node {
    Node* next;
    std::string data;
    Node(const std::string& data) : next(nullptr), data(data) {}
};

class queue {
private:
    Node* tail;
    size_t _size;
public:
    queue() {
        tail = nullptr;
        _size = 0;
    }
    void enqueue(std::string data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            tail = newNode;
            _size++;
        }
        else {
            Node* check = tail;
            while (check->next != nullptr) {
                check = check->next;
            }
            check->next = newNode;
            _size++;
        }
    }
    std::string dequeue() {
        if (tail == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        Node* check = tail;
        tail = tail->next;
        std::string data = check->data;
        delete check;
        _size--;
        return data;
    }
    size_t size() {
        return _size;
    }
    void clear() {
        while (tail != nullptr) {
            Node* check = tail;
            tail = tail->next;
            delete check;
        }
        _size = 0;
    }
    std::string front() {
        if (tail == nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        return tail->data;
    }
    bool empty() {
        return tail == nullptr;
    }
    bool operator==(const queue& other) {
        Node* check = tail;
        Node* otherCheck = other.tail;
        while (check != nullptr && otherCheck != nullptr) {
            if (check->data != otherCheck->data) {
                return false;
            }
            check = check->next;
            otherCheck = otherCheck->next;
        }
        return true;
    }
    bool operator!=(const queue& other) const {
        Node* check = tail;
        Node* otherCheck = other.tail;
        while (check != nullptr && otherCheck != nullptr) {
            if (check->data != otherCheck->data) {
                return true;
            }
            check = check->next;
            otherCheck = otherCheck->next;
        }
        return false;
    }
};

class circular_queue : public queue {
private:
    Node* head;
    Node* tail;
    size_t _capacity;
public:
    circular_queue(size_t capacity) : queue(), head(nullptr), tail(nullptr), _capacity(capacity) {}

    ~circular_queue() {
        while (!is_empty()) {
            dequeue();
        }
    }

    void enqueue(std::string data) {
        if (is_full()) {
            Node* temp = head;
            head = head->next;
            delete temp;
            _size--;
        }
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
            _size++;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            _size++;
        }
        tail->next = head;
    }

    std::string dequeue() {
        if (is_empty()) {
            throw std::out_of_range("Circular queue is empty");
        }
        Node* temp = head;
        std::string data = temp->data;
        head = head->next;
        tail->next = head;
        delete temp;
        _size--;
        return data;
    }

    std::string front() {
        if (is_empty()) {
            throw std::out_of_range("Circular queue is empty");
        }
        return head->data;
    }

    bool is_full() {
        return _size == _capacity;
    }

    bool is_empty() {
        return _size == 0;
    }
};
