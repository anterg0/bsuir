template <class T>
class MyDeque {
private:
    T** data;
    int _size;
    int _capacity;
    int headindex;
    int tailindex;
public:
    MyDeque(int capacity) : _capacity(capacity) {
        data = new T*[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = new T;
        }
        _size = 0;
        headindex = 0;
        tailindex = 0;
    }
    ~MyDeque() {
        clear();
    }
    void push_back(T value) {
        if (_size == _capacity) {
            resize();
        }
        data[tailindex] = new T(value);
        tailindex = (tailindex + 1) % _capacity;
        _size++;
    }
    bool empty() {
        return _size == 0;
    }
    void clear() {
        if (_size == 0) {
            return;
        }
        for (int i = 0; i < _size; i++) {
            delete data[i];
        }
        _size = 0;
        headindex = 0;
        tailindex = 0;
    }
    void push_front(T value) {
        if (_size == _capacity) {
            resize();
        }
        headindex = (headindex - 1 + _capacity) % _capacity;
        data[headindex] = new T(value);
        _size++;
    }

    T pop_back() {
        if (_size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        tailindex = (tailindex - 1 + _capacity) % _capacity;
        T value = *(data[tailindex]);
        delete data[tailindex];
        data[tailindex] = nullptr;
        _size--;
        return value;
    }

    T pop_front() {
        if (_size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        T value = *(data[headindex]);
        delete data[headindex];
        data[headindex] = nullptr;
        headindex = (headindex + 1) % _capacity;
        _size--;
        return value;
    }

    int size() {
        return _size;
    }
    void resize() {
        int newCapacity = _capacity * 2;
        T** newData = new T*[newCapacity];
        for (int i = 0; i < newCapacity; i++) {
            newData[i] = nullptr;
        }
        for (int i = 0; i < _size; i++) {
            newData[i] = new T(*(data[(headindex + i) % _capacity]));
        }
        for (int i = 0; i < _capacity; i++) {
            delete data[i];
        }
        delete[] data;
        data = newData;
        headindex = 0;
        tailindex = _size;
        _capacity = newCapacity;
    }
    class Iterator {
    private:
        MyDeque<T>* deque;
        int index;

    public:
        Iterator(MyDeque<T>* deque, int index) : deque(deque), index(index) {}

        const T& operator*() const {
            return *(deque->data[(deque->headindex + index) % deque->_capacity]);
        }

        T& operator*() {
            return *(deque->data[(deque->headindex + index) % deque->_capacity]);
        }

        Iterator& operator++() {
            index++;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }
    };

    Iterator begin() {
        return Iterator(this, 0);
    }

    Iterator end() {
        return Iterator(this, _size);
    }
};
