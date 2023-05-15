#ifndef MYSTRING_H
#define MYSTRING_H

#include "MyString_global.h"
#include <cstddef>
#include <iostream>
#include <QString>

template<class MyString>
class Iterator {
public:

    Iterator(MyString* ptr) : memberPtr(ptr) {}

    Iterator& operator++() {
        memberPtr++;
        return *this;
    }

    Iterator operator++(int) {
        Iterator iterator = *this;
        ++(*this);
        return iterator;
    }

    Iterator& operator--() {return *(memberPtr - 1);}

    Iterator operator--(int) {
        Iterator iterator = *this;
        --(*this);
        return iterator;
    }

    MyString& operator[](int index) {return *(memberPtr + index);}

    MyString* operator->() {return memberPtr;}

    MyString& operator*() {return *memberPtr;}

    bool operator ==(const Iterator& other) const {return memberPtr == other.memberPtr;}

    bool operator !=(const Iterator& other) const {return !(*this == other);}
    Iterator operator+=(int value) {
        memberPtr += value;
        return *this;
    }
    Iterator operator+(int offset) {return *(memberPtr + offset);}
    Iterator operator-(int offset) {return *(memberPtr - offset);}
private:
    MyString* memberPtr;
};

class MYSTRING_EXPORT MyString
{
private:
    char* str_;
    size_t size_;
public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);
    MyString(MyString&& other);
    ~MyString();
    char* c_str() const;
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    QString toQString();
    MyString& operator=(const MyString& other);
    MyString& operator=(const std::string& str);
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
//    Iterator<MyString> begin();
//    Iterator<MyString> begin() const;
};

void* mymemcpy(void* s1, const void* s2, size_t n);
void* mymemmove(void* s1, const void* s2, size_t n);
char* mystrcpy(char* s1, const char* s2);
char* mystrncpy(char* s1, const char* s2, size_t n);
char* mystrcat(char* s1, const char* s2);
char* mystrncat(char* s1, const char* s2, size_t n);
int mymemcmp(const void* s1, const void* s2, size_t n);
int mystrcmp(const char* s1, const char* s2);
int mystrncmp(const char* s1, const char* s2, size_t n);
int mystrcoll(const char* s1, const char* s2);
char* mystrtok(char* s1, const char* s2);
void* mymemset(void* s, int c, size_t n);
size_t mystrlen(const char* s);

#endif // MYSTRING_H
