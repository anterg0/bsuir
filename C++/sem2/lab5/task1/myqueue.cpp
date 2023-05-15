#include <iostream>
#include <memory>
#include <QApplication>
template<class T>
class Shared_ptr {
public:
    Shared_ptr() : ptr_(nullptr), count_(new int(0)) {}
    explicit Shared_ptr(T* ptr) : ptr_(ptr), count_(new int(1)) {}
    Shared_ptr(const Shared_ptr<T>& other) : ptr_(other.ptr_), count_(other.count_) {
        (*count_)++;
    }
    operator bool() const {
        return ptr_ != nullptr;
    }
    Shared_ptr<T>& operator=(const Shared_ptr<T>& other) {
        if (this != &other) {
            if (--(*count_) == 0) {
                delete ptr_;
                delete count_;
            }
            ptr_ = other.ptr_;
            count_ = other.count_;
            (*count_)++;
        }
        return *this;
    }
    Shared_ptr<T>& operator=(std::nullptr_t) {
        if (--(*count_) == 0) {
            delete ptr_;
            delete count_;
            ptr_ = nullptr;
            count_ = new int(0);
        }
        return *this;
    }
    ~Shared_ptr() {
        if (--(*count_) == 0) {
            delete ptr_;
            delete count_;
        }
    }
    T& operator*() const {
        return *ptr_;
    }
    T* operator->() const {
        return ptr_;
    }
private:
    T* ptr_;
    int* count_;
};


struct Node {
    std::string data;
    Shared_ptr<Node> next;
    Shared_ptr<Node> prev;
    Node(std::string d) : data(d), next(nullptr), prev(nullptr) {}
    Node(char d) : data(1, d), next(nullptr), prev(nullptr) {}
};

class queue {
public:
    queue() : tail(nullptr), _size(0) {}
    ~queue() {}

    queue(queue&& other) : tail(std::move(other.tail)), _size(other._size) {
        other._size = 0;
    }
    queue(const queue& other) : tail(nullptr), _size(0) {
        Shared_ptr<Node> otherTail = other.tail;
        while (otherTail) {
            enqueue(otherTail->data);
            otherTail = otherTail->next;
        }
    }
    queue& operator=(queue&& other) {
        tail = other.tail;
        _size = other._size;
        other._size = 0;
        return *this;
    }

    void enqueue(std::string data) {
        Shared_ptr<Node> newNode(new Node(data));
        if (!tail) {
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        _size++;
    }

    std::string dequeue() {
        if (!tail) {
            throw std::out_of_range("queue is empty");
        }
        Shared_ptr<Node> check = tail;
        tail = check->next;
        _size--;
        return check->data;
    }

    int size() const {
        return _size;
    }

private:
    Shared_ptr<Node> tail;
    int _size;
};

class circular_queue {
private:
    Shared_ptr<Node> head;
    Shared_ptr<Node> tail;
    size_t _capacity;
    size_t _size;
public:
    circular_queue(size_t capacity) : head(nullptr), tail(nullptr), _capacity(capacity), _size(0) {}
    circular_queue& operator=(QString bebra) {
        QStringList beb = bebra.split("");
        _capacity = beb.size() - 2;
        for (int i = 1; i < beb.size() - 1; i++) {
            enqueue(beb[i]);
        }
        return *this;
    }
    void enqueue(QString bebra) {
        Shared_ptr<Node> beb(new Node(bebra.toStdString()));
        if (_size == _capacity) {
            del();
        }
        if (_size == 0) {
            head = beb;
            tail = beb;
            head->next = tail;
            head->prev = tail;
        } else {
            tail->next = beb;
            beb->prev = tail;
            tail = beb;
            tail->next = head;
            head->prev = tail;
        }
        _size++;
    }

    QString func() {
        if (_size != _capacity) {
            throw std::out_of_range("It is not circular yet.");
        } else {
        }
    }
    QString dequeue() {
        if (_size == 0) {
            throw std::out_of_range("queue is empty");
        }
        QString data = head->data.c_str();
        head = head->next;
        tail->next = head;
        head->prev = tail;
        _size--;
        return data;
    }
    void del() {
        if (_size == 0) {
            throw std::out_of_range("Queue is empty");
        }
        Shared_ptr<Node> temp = head;
        head = head->next;
        head->prev = tail;
        _size--;
    }
    QString front() {
        if (_size == 0) throw std::out_of_range("Queue is empty");
        return QString::fromStdString(head->data);
    }
    QString print() {
        if (_size == _capacity) {
            QString result;
            Shared_ptr<Node> check = head;
            for (size_t i = 0; i < _size; i++) {
                result += QString::fromStdString(check->data);
                check = check->next;
            }
            return result;
        }
    }
};
