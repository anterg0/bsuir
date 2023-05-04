#ifndef MYSTRING_H
#define MYSTRING_H

#include "MyString_global.h"
#include <cstddef>
#include <iostream>
#include <QString>

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
size_t mystrxfrm(char* s1, const char* s2, size_t n);
char* mystrtok(char* s1, const char* s2);
void* mymemset(void* s, int c, size_t n);
char* mystrerror(int errnum);
size_t mystrlen(const char* s);

#endif // MYSTRING_H
