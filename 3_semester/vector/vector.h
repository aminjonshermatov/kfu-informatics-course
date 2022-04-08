//
// Created by aminjonshermatov on 10/17/2021.
//

#ifndef INFORMATICS_VECTOR_H
#define INFORMATICS_VECTOR_H

#include "bits/stdc++.h"

typedef long double ld;
typedef long long ll;

template <typename T>
class Vector final {
public:
    Vector();
    explicit Vector(size_t);
    Vector(size_t, const T&);
    Vector(size_t, T&&);
    Vector(const Vector<T>&);
    Vector(Vector<T>&&) noexcept;
    ~Vector();

    Vector<T>& operator=(const Vector<T>&);
    Vector<T>& operator=(Vector<T>&&) noexcept;
    void assign(size_t, const T&);
    void assign(size_t, T&&);
    T at(size_t) const;
    T& at(size_t);
    T operator[](size_t) const;
    T& operator[](size_t);
    T front() const;
    T& front();
    T back() const;
    T& back();
    void clear();
    T& insert(size_t, const T&);
    T& insert(size_t, T&&);
    T& insert(size_t, size_t, const T&);
    T& insert(size_t, size_t, T&&);
    void erase(size_t);
    void erase(const T&);
    void erase(T&&);
    void push_back(const T&);
    void push_back(T&&);
    void resize(size_t);
    void resize(size_t, const T&);
    void resize(size_t, T&&);

    size_t size() const;
    bool empty() const;

    // foreach feature
    T* begin();
    const T* begin() const;
    T* end();
    const T* end() const;

    // operators
    bool operator==(const Vector<T>&);
    bool operator!=(const Vector<T>&);

    // io override operators
    template<typename V>
    friend std::istream& operator>>(std::istream&, Vector<V>&);
    template<typename V>
    friend std::ostream& operator<<(std::ostream&, const Vector<V>&);
private:
    size_t _CAPACITY{},
           _SIZE{};

    T* _storage;

    void _ensureOutOfRangeException(size_t) const;

    constexpr const static ld GOLDEN_RATIO = 1.618033988749L;

    void _allocateNew();
    void _allocateNew(size_t);
    void _deallocate(T*);
};

template<typename T>
Vector<T>::Vector() : Vector(0) { };

template<typename T>
Vector<T>::Vector(size_t size) {
    this->_CAPACITY = this->_SIZE = size;
    this->_storage = new T[this->_SIZE];
}

template<typename T>
Vector<T>::Vector(size_t size, const T& value) : Vector(size) {
    for (size_t i = 0; i < this->_SIZE; ++i) {
        this->_storage[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(size_t size, T&& value) : Vector(size) {
    for (size_t i = 0; i < this->_SIZE; ++i) {
        this->_storage[i] = value;
    }
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v) : Vector(v.size()) {
    for (size_t i = 0; i < this->_SIZE; ++i) {
        this->_storage[i] = v[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector<T>&& v) noexcept : Vector(v.size()) {
    for (size_t i = 0; i < this->_SIZE; ++i) {
        this->_storage[i] = v[i];
    }
}

template<typename T>
Vector<T>::~Vector() {
    delete[] this->_storage;
};

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v) {
    this->_allocateNew(v.size());

    for (size_t i = 0; i < v.size(); ++i) {
        this->_storage[i] = v[i];
    }

    return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& v) noexcept {
    this->_allocateNew(v.size());

    for (size_t i = 0; i < v.size(); ++i) {
        this->_storage[i] = v[i];
    }

    return *this;
}

template<typename T>
void Vector<T>::assign(size_t size, const T& value) {
    this->_allocateNew(size);

    for (size_t i = 0; i < size; ++i) {
        this->_storage[i] = value;
    }
}

template<typename T>
void Vector<T>::assign(size_t size, T&& value) {
    this->_allocateNew(size);

    for (size_t i = 0; i < size; ++i) {
        this->_storage[i] = value;
    }
}

template<typename T>
T Vector<T>::at(size_t pos) const {
    this->_ensureOutOfRangeException(pos);
    return this->_storage[pos];
}

template<typename T>
T& Vector<T>::at(size_t pos) {
    this->_ensureOutOfRangeException(pos);
    return &this->_storage[pos];
}

template<typename T>
T Vector<T>::operator[](size_t pos) const {
    return this->_storage[pos];
}

template<typename T>
T& Vector<T>::operator[](size_t pos) {
    return &this->_storage[pos];
}

template<typename T>
T Vector<T>::front() const {
    return this->_storage[0];
}

template<typename T>
T& Vector<T>::front() {
    return &this->_storage[0];
}

template<typename T>
T Vector<T>::back() const {
    return this->_storage[this->_SIZE - 1];
}

template<typename T>
T& Vector<T>::back() {
    return &this->_storage[this->_SIZE - 1];
}

template<typename T>
void Vector<T>::clear() {
    this->_SIZE = this->_CAPACITY = 0;
    this->_deallocate(this->_storage);
    this->_storage = nullptr;
}

template<typename T>
T& Vector<T>::insert(size_t pos, const T& value) {
    this->insert(pos, 1, value);
}

template<typename T>
T& Vector<T>::insert(size_t pos, T&& value) {
    this->insert(pos, 1, value);
}

template<typename T>
T& Vector<T>::insert(size_t pos, size_t count, const T& value) {
    if (count + this->_SIZE > this->_CAPACITY) {
        if (pos < this->_SIZE) {
            do {
                this->_CAPACITY = (size_t)(this->_CAPACITY * Vector<T>::GOLDEN_RATIO);
            } while (count + this->_SIZE > this->_CAPACITY);

            T* newStorage = new T[this->_CAPACITY];

            size_t i = 0, j = 0;

            while (i < this->_SIZE) {
                if (i == pos) {
                    for (size_t k = 0; k < count; ++k)
                        newStorage[j++] = value;
                } else {
                    newStorage[j++] = this->_storage[i++];
                }
            }

            this->_SIZE += count;

            this->_deallocate(this->_storage);
            this->_storage = newStorage;
        } else {
            this->push_back(value);
        }
    } else {
        T temp = T{temp};
        for (size_t i = pos; i < this->_SIZE - 1; ++i) {
            std::swap(temp, this->_storage[i]);
        }
        this->_storage[this->_SIZE++] = temp;
    }
}

template<typename T>
T& Vector<T>::insert(size_t pos, size_t count, T&& value) {
    if (count + this->_SIZE > this->_CAPACITY) {
        if (pos < this->_SIZE) {
            do {
                this->_CAPACITY = (size_t)(this->_CAPACITY * Vector<T>::GOLDEN_RATIO);
            } while (count + this->_SIZE > this->_CAPACITY);

            T* newStorage = new T[this->_CAPACITY];

            size_t i = 0, j = 0;

            while (i < this->_SIZE) {
                if (i == pos) {
                    for (size_t k = 0; k < count; ++k)
                        newStorage[j++] = value;
                } else {
                    newStorage[j++] = this->_storage[i++];
                }
            }

            this->_SIZE += count;

            this->_deallocate(this->_storage);
            this->_storage = newStorage;
        } else {
            this->push_back(value);
        }
    } else {
        T temp = T{temp};
        for (size_t i = pos; i < this->_SIZE - 1; ++i) {
            std::swap(temp, this->_storage[i]);
        }
        this->_storage[this->_SIZE++] = temp;
    }
}

template<typename T>
void Vector<T>::erase(size_t pos) {
    if (pos < 0 || pos >= this->_SIZE) {
        std::stringstream errorMsg;
        errorMsg << "Size: " << this->_SIZE << ", but received: " << pos;
        throw std::out_of_range(errorMsg.str());
    }

    T* newStorage = new T[this->_CAPACITY];

    size_t i = 0, j = 0;
    bool isFound = false;

    while (i < this->_SIZE) {
        if (i == pos) {
            ++i;
            isFound = true;
        } else {
            newStorage[j++] = this->_storage[i++];
        }
    }

    if (isFound) --this->_SIZE;

    this->_deallocate(this->_storage);
    this->_storage = newStorage;
}

template<typename T>
void Vector<T>::erase(const T& value) {
    T* newStorage = new T[this->_CAPACITY];

    size_t i = 0, j = 0;
    bool isFound = false;

    while (i < this->_SIZE) {
        if (!isFound && this->_storage[i] == value) {
            ++i;
            isFound = true;
        } else {
            newStorage[j++] = this->_storage[i++];
        }
    }

    if (isFound) --this->_SIZE;

    this->_deallocate(this->_storage);
    this->_storage = newStorage;
}

template<typename T>
void Vector<T>::erase(T&& value) {
    T* newStorage = new T[this->_CAPACITY];

    size_t i = 0, j = 0;
    bool isFound = false;

    while (i < this->_SIZE) {
        if (!isFound && this->_storage[i] == value) {
            ++i;
            isFound = true;
        } else {
            newStorage[j++] = this->_storage[i++];
        }
    }

    if (isFound) --this->_SIZE;

    this->_deallocate(this->_storage);
    this->_storage = newStorage;
}

template<typename T>
void Vector<T>::resize(size_t newSize) {
    this->_SIZE = newSize;
    this->_allocateNew(newSize);
}

template<typename T>
void Vector<T>::resize(size_t newSize, const T& value) {
    this->_allocateNew(newSize);
    this->_SIZE = newSize;

    for (size_t i = 0; i < this->_SIZE; ++i)
        this->_storage[i] = value;
}

template<typename T>
void Vector<T>::resize(size_t newSize, T&& value) {
    this->_allocateNew(newSize);
    this->_SIZE = newSize;

    for (size_t i = 0; i < this->_SIZE; ++i)
        this->_storage[i] = value;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (this->_SIZE == this->_CAPACITY) {
        this->_allocateNew();
    }

    this->_storage[this->_SIZE++] = value;
}

template<typename T>
void Vector<T>::push_back(T&& value) {
    if (this->_SIZE == this->_CAPACITY) {
        this->_allocateNew();
    }

    this->_storage[this->_SIZE++] = value;
}

template<typename T>
size_t Vector<T>::size() const {
    return this->_SIZE;
}

template<typename T>
bool Vector<T>::empty() const {
    return this->_SIZE == 0;
}

template<typename T>
void Vector<T>::_ensureOutOfRangeException(size_t pos) const {
    if (pos < 0 || pos >= this->_SIZE) {
        std::stringstream errorMsg;
        errorMsg << "Size: " << this->_SIZE << ", but received: " << pos;
        throw std::out_of_range(errorMsg.str());
    }
}

template<typename T>
void Vector<T>::_allocateNew() {
    if (this->_CAPACITY < 1) {
        ++this->_CAPACITY;
        return;
    }

    size_t oldCapacity = this->_CAPACITY;

    if (this->_CAPACITY == 1)
        ++this->_CAPACITY;
    else
        this->_CAPACITY = (size_t)(this->_CAPACITY * Vector<T>::GOLDEN_RATIO);

    T* newStorage = new T[this->_CAPACITY];

    for (size_t i = 0; i < oldCapacity; ++i) {
        newStorage[i] = this->_storage[i];
    }

    this->_deallocate(this->_storage);
    this->_storage = newStorage;
}

template<typename T>
void Vector<T>::_allocateNew(size_t newSize) {
    if (this->_CAPACITY == newSize) return;
    else if (this->_CAPACITY < 1) {
        ++this->_CAPACITY;
        return;
    }

    T* newStorage = new T[newSize];

    size_t min = std::min(this->_SIZE, newSize);
    for (size_t i = 0; i < min; ++i) {
        newStorage[i] = this->_storage[i];
    }

    this->_deallocate(this->_storage);
    this->_storage = newStorage;
}

template<typename T>
void Vector<T>::_deallocate(T* memory) {
    delete[] memory;
}

// foreach feature
template<typename T>
T* Vector<T>::begin() {
    return &this->_storage[0];
}

template<typename T>
const T* Vector<T>::begin() const {
    return &this->_storage[0];
}

template<typename T>
T* Vector<T>::end() {
    return &this->_storage[this->_SIZE];
}

template<typename T>
const T* Vector<T>::end() const {
    return &this->_storage[this->_SIZE];
}

template<typename T>
bool Vector<T>::operator==(const Vector<T>& v) {
    if (this->_SIZE != v.size()) return false;
    else {
        bool isEqual = true;

        for (size_t i = 0; i < this->_SIZE && isEqual; ++i)
            if (this->_storage[i] != v[i]) isEqual = false;

        return isEqual;
    }
}

template<typename T>
bool Vector<T>::operator!=(const Vector<T>& v) {
    return !this->operator==(v);
}

template<typename T>
std::istream& operator>>(std::istream& in, Vector<T>& v) {
    T temp;

    while (in >> temp) v.push_back(temp);

    return in;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    os << '[';

    for (size_t i = 0; i < v._SIZE; ++i) {
        os << v[i];

        if (i != v._SIZE - 1) os << ", ";
    }

    return os << ']';
}

#endif //INFORMATICS_VECTOR_H
