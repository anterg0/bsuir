//
// Created by Антон Шпаковский on 05.05.2023.
//

#ifndef TASK1_LIBA_H
#define TASK1_LIBA_H
#include <cstddef>
#include <iostream>
template<class T>
class Shared_ptr {
public:
    Shared_ptr();
    explicit Shared_ptr(T* ptr);
    Shared_ptr(const Shared_ptr<T>& other);
    Shared_ptr<T>& operator=(const Shared_ptr<T>& other);
    ~Shared_ptr();
    T& operator*() const;
    T* operator->() const;
private:
    T* ptr_;
    int* count_;
};

template<class T>
class Unique
{
    T* m_ptr;

public:

    operator bool() const;
    Unique(T* ptr = nullptr);
    ~Unique();
    Unique(Unique&& x);
    Unique(const Unique& x) = delete;
    Unique& operator=(Unique& a) = delete;
    Unique& operator=(Unique&& x);
    T& operator*() const;
    T* operator->() const;
    bool isNull() const;
};

#endif //TASK1_LIBA_H
