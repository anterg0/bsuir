
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

char& MyString::operator[](size_t index) {
    if (index >= size_) {
        throw "Index out of range";
    }
    return str_[index];
}

const char& MyString::operator[](size_t index) const {
    if (index >= size_) {
        throw "Index out of range";
    }
    return str_[index];
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
    char* s1_ptr = s1;
    while (*s2 != '\0') {
        *s1_ptr++ = *s2++;
    }
    *s1_ptr = '\0';
    return s1;
}


char* mystrncpy(char* s1, const char* s2, size_t n) {
    char* s1_ptr = s1;
    for (int i = 0; i < n && *s2 != '\0'; ++i) {
        *s1_ptr++ = *s2++;
    }
    *s1_ptr++ = '\0';
    return s1;
}

char* mystrcat(char* s1, const char* s2) {
    char* s1_ptr = s1;
    while (*s1_ptr != '\0') {
        ++s1_ptr;
    }
    while (*s2 != '\0') {
        *s1_ptr++ = *s2++;
    }
    *s1_ptr = '\0';
    return s1;
}

char* mystrncat(char* s1, const char* s2, size_t n) {
    char* s1_ptr = s1;
    while (*s1_ptr != '\0') {
        ++s1_ptr;
    }
    for (int i = 0; i < n && *s2 != '\0'; ++i) {
        *s1_ptr++ = *s2++;
    }
    *s1_ptr = '\0';
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

char* mystrtok(char* s1, const char* s2) {
    static char* lastToken = nullptr;
    if (s1 != nullptr) {
        lastToken = s1;
    }
    if (lastToken == nullptr) {
        return nullptr;
    }
    const size_t str1len = mystrlen(lastToken);
    const size_t str2len = mystrlen(s2);
    size_t i = 0, j = 0;
    for (i = 0; i < str1len-1; i++) {
        for (j = 0; j < str2len-1; j++) {
            if (lastToken[i] == s2[j]) {

                lastToken[i] = '\0';
                const char* result = lastToken;
                lastToken += i + 1;
                return const_cast<char*>(result);
            }
        }
    }
    const char* result = lastToken;
    lastToken = nullptr;
    return const_cast<char*>(result);
}

void* mymemset(void* s, int c, size_t n) {
    unsigned char* p = static_cast<unsigned char*>(s);
    unsigned char v = static_cast<unsigned char>(c);
    for (size_t i = 0; i < n; ++i) {
        *p++ = v;
    }
    return s;
}

size_t mystrlen(const char* s) {
    size_t i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    return i;
}
