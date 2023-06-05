#include <list>
template<class T>
class Weak_ptr;

template <class T>
class Shared_ptr {
public:
    Shared_ptr(T* ptr = nullptr) : m_ptr(ptr), m_counter(new int(1)) {}
    Shared_ptr(const Shared_ptr& other) : m_ptr(other.m_ptr), m_counter(other.m_counter) {
        ++(*m_counter);
    }
    ~Shared_ptr() {
        if (--(*m_counter) == 0) {
            delete m_ptr;
            delete m_counter;
        }
    }
    Shared_ptr(Weak_ptr<T>& x);

    Shared_ptr& operator=(Weak_ptr<T>& x);

    Shared_ptr& operator=(const Shared_ptr& other) {
        if (this != &other) {
            if (--(*m_counter) == 0) {
                delete m_ptr;
                delete m_counter;
            }
            m_ptr = other.m_ptr;
            m_counter = other.m_counter;
            ++(*m_counter);
        }
        return *this;
    }
    T& operator*() const {
        return *m_ptr;
    }
    T* operator->() const {
        return m_ptr;
    }

    bool operator==(const Shared_ptr& other) const {
        return m_ptr == other.m_ptr;
    }
    bool operator!=(const Shared_ptr& other) const {
        return m_ptr != other.m_ptr;
    }
private:
    T* m_ptr;
    int* m_counter;
    friend class Weak_ptr<T>;
};

template<class T>
class Weak_ptr {
public:
    T* m_ptr;
    int* m_references_count;
    friend class Shared_ptr<T>;

    Weak_ptr(Shared_ptr<T>& x);

    Weak_ptr& operator=(Shared_ptr<T>& x);

    Shared_ptr<T> lock() {
        return Shared_ptr<T>(*this);
    }


};
