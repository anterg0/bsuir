#include "liba.h"
template<class T>
Shared_ptr<T>::Shared_ptr() : ptr_(nullptr), count_(new int(0)) {}

template<class T>
Shared_ptr<T>::Shared_ptr(T* ptr) : ptr_(ptr), count_(new int(1)) {}

template<class T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr<T>& other) {
    ptr_ = other.ptr_;
    count_ = other.count_;
    (*count_)++;
}

template<class T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr<T>& other) {
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

template<class T>
Shared_ptr<T>::~Shared_ptr() {
    if (--(*count_) == 0) {
        delete ptr_;
        delete count_;
    }
}

template<class T>
T& Shared_ptr<T>::operator*() const {
    return *ptr_;
}

template<class T>
T* Shared_ptr<T>::operator->() const {
    return ptr_;
}


template<class T>
Unique<T>::Unique(T* ptr) : m_ptr(ptr) {}

template<class T>
Unique<T>::~Unique()
{
    delete m_ptr;
}

template<class T>
Unique<T>::Unique(Unique<T>&& x)
        : m_ptr(x.m_ptr)
{
    x.m_ptr = nullptr;
}

template<class T>
T& Unique<T>::operator*() const { return *m_ptr; }

template<class T>
T* Unique<T>::operator->() const { return m_ptr; }

template<class T>
Unique<T>& Unique<T>::operator=(Unique<T>&& x)
{
    if (&x == this) {
        return *this;
    }
    delete m_ptr;
    m_ptr = x.m_ptr;
    x.m_ptr = nullptr;
    return *this;
}

template<class T>
bool Unique<T>::isNull() const { return m_ptr == nullptr; }