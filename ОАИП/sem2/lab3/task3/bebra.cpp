#include <iostream>

template <typename T1, typename T2>
struct pair
{
    T1 fir;
    T2 sec;
    pair() {}
    pair(T1 first, T2 second) : fir(first), sec(second) {}
};


template<class MyVector>
class vectorIterator {
public:

    vectorIterator(MyVector* ptr) : memberPtr(ptr) {}

    vectorIterator& operator++() {
        memberPtr++;
        return *this;
    }

    vectorIterator operator++(int) {
        vectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    vectorIterator& operator--() {return *(memberPtr - 1);}

    vectorIterator operator--(int) {
        vectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    MyVector& operator[](int index) {return *(memberPtr + index);}

    MyVector* operator->() {return memberPtr;}

    MyVector& operator*() {return *memberPtr;}

    bool operator ==(const vectorIterator& other) const {return memberPtr == other.memberPtr;}

    bool operator !=(const vectorIterator& other) const {return !(*this == other);}
    vectorIterator operator+=(int value) {
        memberPtr += value;
        return *this;
    }
    vectorIterator operator+(int offset) {return *(memberPtr + offset);}
    vectorIterator operator-(int offset) {return *(memberPtr - offset);}
private:
    MyVector* memberPtr;
};

template<typename T>
class MyVector {
private:
    T* _data;
    size_t _size;
    size_t _capacity;
public:
    MyVector() {
        _size = 0;
        _capacity = 0;
        _data = nullptr;
    }
    MyVector(std::initializer_list<T> values) {
        int count = 0;
        for (auto& element : values) {
            count++;
        }
        _data = new T[count];
        int i = 0;
        for (auto& element : values) {
            _data[i++] = element;
        }

        _size = count;
        _capacity = count;
    };

    void assign(std::initializer_list<T> values) {
        T* new_data = new T[values.size()];
        int i = 0;
        for (auto& val : values) {
            new_data[i++] = val;
        }
        delete[] _data;
        _data = new_data;
        _capacity = values.size();
        _size = values.size();
    }

    void assign (T value) {
        T* new_data = new T[1];
        new_data[0] = value;
        delete[] _data;
        _data = new_data;
        _capacity = 1;
        _size = 1;
    }

    T& at(int index) {
        if (index > _size) throw std::out_of_range("Index out of range.");
        return _data[index];
    }

    T& back() {
        if (_size == 0) throw std::out_of_range("Vector is empty.");
        return _data[_size - 1];
    }

    vectorIterator<MyVector<T>> begin() {
        return vectorIterator<MyVector<T>>(_data);
    }

    vectorIterator<MyVector<T>> begin() const {
        return vectorIterator<MyVector<T>>(_data);
    }

    size_t capacity() {
        return _capacity;
    }

    vectorIterator<MyVector<T>> cbegin() const {
        return vectorIterator<MyVector<T>>(_data);
    }

    void clear() {
        for (int i = 0; i < _size; i++) {
            _data[i].~T();
        }
        _size = 0;
        _capacity = 0;
        _data = nullptr;
    }

    T* data() {
        if (_size == 0) return nullptr;
        return _data;
    }

    void emplace(int position, T value) {
        if (_size == _capacity) reserve(_size * 2);
        if (position > _size) return;
        for (int i = _size + 1; i > position; i--) {
            std::swap(_data[i], _data[i - 1]);
        }
        _data[position] = value;
        _size++;
    }

    void emplace_back(T value) {
        if (_size == _capacity) reserve(_size * 2);
        _data[_size] = value;
        _size++;
    }

    bool empty() {
        return _size == 0;
    }

    vectorIterator<MyVector<T>> end() {
        return vectorIterator<MyVector<T>>(_data + _size);
    }

    vectorIterator<MyVector<T>> end() const {
        return vectorIterator<MyVector<T>>(_data + _size);
    }

    void erase(int position, int amount) {
        if (position < 0 || position > _size || amount < 0 || amount > _size - position) return;

        int step = amount;
        for (int i = position; i < _size - step; i++) {
            std::swap(_data[i], _data[i + step]);
        }
        _size -= step;
    }

    T& front() {
        if (_size == 0) throw std::out_of_range("Vector is empty.");
        return *_data;
    }

    void insert(size_t index, const T& value) {
        if (index > _size) {
            throw std::out_of_range("Index out of range");
        }
        if (_size == _capacity) {
            reserve(_capacity * 2);
        }
        for (size_t i = _size; i > index; i--) {
            _data[i] = _data[i - 1];
        }
        _data[index] = value;
        _size++;
    }

    void insert(size_t index, std::initializer_list<T> list) {
        if (index > _size) {
            throw std::out_of_range("Index out of range");
        }
        size_t num_new_elems = list.size();
        if (_size + num_new_elems > _capacity) {
            reserve(_size + num_new_elems);
        }
        for (int i = _size; i > index; i--) {
            _data[i + num_new_elems - 1] = _data[i - 1];
        }
        auto it = list.begin();
        for (int i = 0; i < num_new_elems; i++) {
            _data[index + i] = *(it++);
        }
        _size += num_new_elems;
    }


    size_t max_size() {
        return std::allocator<T>().max_size();
    }

    void pop_back() {
        if (_size == 0) return;
        _size--;
    }

    void push_back(T value) {
        if (_size == _capacity) reserve((_size + 1) * 2);
        _data[_size] = value;
        _size++;
    }

    vectorIterator<MyVector<T>> rbegin() {
        return vectorIterator<MyVector<T>>(_data + _size - 1);
    }

    vectorIterator<MyVector<T>> rend() {
        return vectorIterator<MyVector<T>>(_data);
    }

    void reserve(size_t newCapacity) {
        if (newCapacity <= _capacity) return;
        else {
            T* new_data = reinterpret_cast<T*>(new char[(newCapacity * sizeof(T))]);
            for (int i = 0; i < _size; i++) {
                new (new_data + i) T(_data[i]);
            }
            delete[] _data;
            _data = new_data;
            _capacity = newCapacity;
        }
    }

    void resize(int newSize) {
        if (newSize < _capacity) {
            for (int i = _size; i < newSize; i++) {
                _data[i] = {};
            }
            _size = newSize;
            _capacity = newSize;
        }
        else {
            reserve(newSize);
        }
    }

    size_t size() {
        return _size;
    }

    void swap(MyVector<T>& otherVector) {
        std::swap(_data, otherVector._data);
        std::swap(_size, otherVector._size);
        std::swap(_capacity, otherVector._capacity);
    }

    void sort() {
        std::sort(_data, _data + _size);
    }

    T& operator[](int index) {
        return _data[index];
    }
};

