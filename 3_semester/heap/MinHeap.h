//
// Created by aminjonshermatov on 10/20/2021.
//

#ifndef INFORMATICS_MINHEAP_H
#define INFORMATICS_MINHEAP_H

#include <bits/stdc++.h>
#include "IHeap.h"

template<typename T>
class MinHeap : public Heap<T> {
public:
    using Comparator = bool(const T&, const T&);

    MinHeap();
    explicit MinHeap(size_t);
    explicit MinHeap(std::function<Comparator>);
    MinHeap(size_t, std::function<Comparator>);
    explicit MinHeap(const std::vector<T>&);
    explicit MinHeap(const std::vector<T>&, std::function<Comparator>);
    explicit MinHeap(std::vector<T>&&);
    explicit MinHeap(std::vector<T>&&, std::function<Comparator>);
    ~MinHeap();

    MinHeap<T>& operator=(const std::vector<T>&);
    MinHeap<T>& operator=(std::vector<T>&&);
    void siftDown(size_t) override;
    void siftUp(size_t) override;
    void insert(const T&) override;
    void insert(T&&) override;

    T extract();
private:
    size_t _CAPACITY{},
           _SIZE{};
    T* _store;

     // Comparator _comp = [&](T& lhs, T& rhs) -> bool { return lhs < rhs; };
    Comparator _comp;

    void _ensureRanges(size_t) const;
};

template<typename T>
MinHeap<T>::MinHeap() : MinHeap(1e5) {};

template<typename T>
MinHeap<T>::MinHeap(std::function<Comparator> comp) : MinHeap(1e5) {
    this->_comp = comp;
};

template<typename T>
MinHeap<T>::MinHeap(size_t size) : _SIZE(0), _CAPACITY(size) {
    this->_store = new T[this->_CAPACITY];
};

template<typename T>
MinHeap<T>::MinHeap(size_t size, std::function<Comparator> comp) : MinHeap(size) {
    this->_comp = comp;
}

template<typename T>
MinHeap<T>::MinHeap(const std::vector<T>& v) : MinHeap(v.size()) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
MinHeap<T>::MinHeap(const std::vector<T>& v, std::function<Comparator> comp) : MinHeap(v.size()) {
    this->_comp = comp;
    for (const auto& el : v) this->insert(el);
};

template<typename T>
MinHeap<T>::MinHeap(std::vector<T>&& v) : MinHeap(v.size()) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
MinHeap<T>::MinHeap(std::vector<T>&& v, std::function<Comparator> comp) : MinHeap(v.size()) {
    this->_comp = &comp;
    for (const auto& el : v) this->insert(el);
}

template<typename T>
MinHeap<T>::~MinHeap() {
     delete[] this->_store;
}

template<typename T>
MinHeap<T>& MinHeap<T>::operator=(const std::vector<T>& v) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
MinHeap<T>& MinHeap<T>::operator=(std::vector<T>&& v) {
    for (const auto& el : v) this->insert(el);
}

template<typename T>
void MinHeap<T>::siftDown(size_t pos) {
    while (2 * pos + 1 < this->_SIZE) {
        size_t leftChildIdx = 2 * pos + 1;
        size_t rightChildIdx = 2 * pos + 2;

        size_t temp = leftChildIdx;

        if (rightChildIdx < this->_SIZE && this->_store[rightChildIdx] < this->_store[leftChildIdx]) {
            temp = rightChildIdx;
        }

        if (this->_store[pos] <= this->_store[temp])
            break;

        std::swap(this->_store[temp], this->_store[pos]);
        pos = temp;
    }
}

template<typename T>
void MinHeap<T>::siftUp(size_t pos) {
    while (pos > 0 && this->_store[pos] < this->_store[(pos - 1) / 2]) {
        std::swap(this->_store[pos], this->_store[(pos - 1) / 2]);
        pos = (pos - 1) / 2;
    }
}

template<typename T>
void MinHeap<T>::insert(const T& val) {
    this->_ensureRanges(this->_SIZE);

    this->_store[this->_SIZE++] = val;
    this->siftUp(this->_SIZE - 1);
}

template<typename T>
void MinHeap<T>::insert(T&& val) {
    this->_ensureRanges(this->_SIZE);

    this->_store[this->_SIZE++] = val;
    this->siftUp(this->_SIZE - 1);
}

template<typename T>
T MinHeap<T>::extract() {
    if (this->_SIZE == 0)
        throw std::runtime_error("Heap is empty");

    T minEl = this->_store[0];
    this->_store[0] = this->_store[--this->_SIZE];
    this->siftDown(0);
    return minEl;
}

template<typename T>
void MinHeap<T>::_ensureRanges(size_t pos) const {
    if (pos < 0 || pos >= this->_CAPACITY) {
        std::stringstream ss;
        ss << "Current size: " << this->_SIZE << ", requested position: " << pos;
        throw std::out_of_range(ss.str());
    }
}

#endif //INFORMATICS_MINHEAP_H
