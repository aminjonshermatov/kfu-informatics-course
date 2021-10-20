//
// Created by aminjonshermatov on 10/20/2021.
//

#ifndef INFORMATICS_HEAP_H
#define INFORMATICS_HEAP_H

#include <bits/stdc++.h>

template<typename T>
class Heap {
public:
    using Comparator = std::function<bool(const T&, const T&)>;

    Heap();
    explicit Heap(size_t);
    explicit Heap(Comparator&&);
    Heap(size_t, Comparator&&);
    explicit Heap(const std::vector<T>&);
    explicit Heap(const std::vector<T>&, Comparator&&);
    explicit Heap(std::vector<T>&&);
    explicit Heap(std::vector<T>&&, Comparator&&);
    ~Heap();

    Heap<T>& operator=(const std::vector<T>&);
    Heap<T>& operator=(std::vector<T>&&);
    void siftDown(size_t);
    void siftUp(size_t);
    void insert(const T&);
    void insert(T&&);

    T extractTop();
    size_t size() const;
private:
    size_t _CAPACITY{},
           _SIZE{};
    T* _store;

    Comparator _comp = [&](const T& lhs, const T& rhs) -> bool {
        return lhs < rhs;
    };

    void _ensureRanges(size_t) const;
};

template<typename T>
Heap<T>::Heap() : Heap(1e5) {};

template<typename T>
Heap<T>::Heap(Comparator&& comp) : Heap(1e5) {
    this->_comp = comp;
};

template<typename T>
Heap<T>::Heap(size_t size) : _SIZE(0), _CAPACITY(size) {
    this->_store = new T[this->_CAPACITY];
};

template<typename T>
Heap<T>::Heap(size_t size, Comparator&& comp) : Heap(size) {
    this->_comp = comp;
}

template<typename T>
Heap<T>::Heap(const std::vector<T>& v) : Heap(v.size()) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
Heap<T>::Heap(const std::vector<T>& v, Comparator&& comp) : Heap(v.size()) {
    this->_comp = comp;
    for (const auto& el : v) this->insert(el);
};

template<typename T>
Heap<T>::Heap(std::vector<T>&& v) : Heap(v.size()) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
Heap<T>::Heap(std::vector<T>&& v, Comparator&& comp) : Heap(v.size()) {
    this->_comp = comp;
    for (const auto& el : v) this->insert(el);
}

template<typename T>
Heap<T>::~Heap() {
     delete[] this->_store;
}

template<typename T>
Heap<T>& Heap<T>::operator=(const std::vector<T>& v) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
Heap<T>& Heap<T>::operator=(std::vector<T>&& v) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
void Heap<T>::siftDown(size_t pos) {
    while (2 * pos + 1 < this->_SIZE) {
        size_t leftChildIdx = 2 * pos + 1;
        size_t rightChildIdx = 2 * pos + 2;

        size_t temp = leftChildIdx;

        if (rightChildIdx < this->_SIZE
            && this->_comp(this->_store[rightChildIdx], this->_store[leftChildIdx])) {
            temp = rightChildIdx;
        }

        if (this->_store[pos] == this->_store[temp] || this->_comp(this->_store[pos], this->_store[temp]))
            break;

        std::swap(this->_store[temp], this->_store[pos]);
        pos = temp;
    }
}

template<typename T>
void Heap<T>::siftUp(size_t pos) {
    while (pos > 0
            && this->_comp(this->_store[pos], this->_store[(pos - 1) / 2])) {
        std::swap(this->_store[pos], this->_store[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

template<typename T>
void Heap<T>::insert(const T& val) {
    this->_ensureRanges(this->_SIZE);

    this->_store[this->_SIZE++] = val;
    this->siftUp(this->_SIZE - 1);
}

template<typename T>
void Heap<T>::insert(T&& val) {
    this->_ensureRanges(this->_SIZE);

    this->_store[this->_SIZE++] = val;
    this->siftUp(this->_SIZE - 1);
}

template<typename T>
T Heap<T>::extractTop() {
    if (this->_SIZE == 0)
        throw std::runtime_error("Heap is empty");

    T minEl = this->_store[0];
    this->_store[0] = this->_store[--this->_SIZE];
    this->siftDown(0);
    return minEl;
}

template<typename T>
size_t Heap<T>::size() const {
    return this->_SIZE;
}

template<typename T>
void Heap<T>::_ensureRanges(size_t pos) const {
    if (pos < 0 || pos >= this->_CAPACITY) {
        std::stringstream ss;
        ss << "Current size: " << this->_SIZE << ", requested position: " << pos;
        throw std::out_of_range(ss.str());
    }
}

#endif //INFORMATICS_HEAP_H
