#include "mystring.h"

MyString::MyString() : str_(nullptr), size_(0) {}
MyString::MyString(const char *s) : str_(new char[mystrlen(s) + 1]), size_(mystrlen(s)) {
    mystrcpy(str_, s);
}
MyString::MyString(const MyString& other) {
    str_ = new char[mystrlen(other.str_) + 1];
    size_ = mystrlen(other.str_);
    mystrcpy(str_, other.str_);
}
MyString::MyString(MyString&& other) {
    str_ = other.str_;
    size_ = mystrlen(other.str_);
    other.str_ = nullptr;
}
MyString::~MyString() {
    delete[] str_;
}
char* MyString::c_str() const {
    return str_;
}

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    return os << s.str_;
}

QString MyString::toQString() {
    return QString::fromUtf8(str_);
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        MyString temp(other);
        std::swap(str_, temp.str_);
    }
    return *this;
}

MyString& MyString::operator=(const std::string& str) {
    if (str_) {
        delete[] str_;
    }
    str_ = new char[str.size() + 1];
    mystrcpy(str_, str.c_str());
    return *this;
}

void* mymemcpy(void* s1, const void* s2, size_t n) {
    char* s1copy = static_cast<char*>(s1);
    const char* s2copy = static_cast<const char*>(s2);
    for (size_t i = 0; i < n; ++i) {
        s1copy[i] = s2copy[i];
    }
    return s1;
}

void* mymemmove(void* s1, const void* s2, size_t n) {
    char* s1copy = static_cast<char*>(s1);
    const char* s2copy = static_cast<const char*>(s2);
    if (s1 < s2) {
        for (size_t i = 0; i < n; ++i) {
            s1copy[i] = s2copy[i];
        }
    } else if (s1 > s2) {
        for (size_t i = n; i > 0; --i) {
            s1copy[i] = s2copy[i];
        }
    }
    return s1;
}

char* mystrcpy(char* s1, const char* s2) {
    for (size_t i = 0; s2[i] != '\0'; ++i) {
        s1[i] = s2[i];
    }
    return s1;
}

char* mystrncpy(char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        s1[i] = s2[i];
    }
    return s1;
}

char* mystrcat(char* s1, const char* s2) {
    size_t i = mystrlen(s1);
    for (size_t j = 0; s2[j] != '\0'; ++j) {
        s1[i++] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

char* mystrncat(char* s1, const char* s2, size_t n) {
    size_t i = mystrlen(s1);
    for (size_t j = 0; j < n; ++j) {
        s1[i++] = s2[j];
    }
    s1[i] = '\0';
    return s1;
}

int mymemcmp(const void* s1, const void* s2, size_t n) {
    const char* s1copy = static_cast<const char*>(s1);
    const char* s2copy = static_cast<const char*>(s2);
    for (size_t i = 0; i < n; ++i) {
        if (s1copy[i] != s2copy[i]) {
            return s1copy[i] - s2copy[i];
        }
    }
    return 0;
}

int mystrcmp(const char* s1, const char* s2) {
    for (size_t i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int mystrncmp(const char* s1, const char* s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

int mystrcoll(const char* s1, const char* s2) {
    for (size_t i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}

size_t mystrxfrm(char* s1, const char* s2, size_t n) {

}

char* mystrtok(char* s1, const char* s2) {

}

void* mymemset(void* s, int c, size_t n) {

}

char* mystrerror(int errnum) {

}

size_t mystrlen(const char* s) {
    size_t i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}
