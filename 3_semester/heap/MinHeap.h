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
    MinHeap();
    explicit MinHeap(size_t);

    T& extractMin();

    void siftDown() override;
    void siftUp() override;
    void insert(const T&) override;
    void insert(T&&) override;
private:
    size_t _SIZE{};
};

template<typename T>
MinHeap<T>::MinHeap() : _SIZE(0) {};

template<typename T>
MinHeap<T>::MinHeap(size_t size) : _SIZE(0) {};

template<typename T>
T& MinHeap<T>::extractMin() {
    return T{};
}

template<typename T>
void MinHeap<T>::siftDown() {}

template<typename T>
void MinHeap<T>::siftUp() {}

template<typename T>
void MinHeap<T>::insert(const T &) {}

template<typename T>
void MinHeap<T>::insert(T&&) {}



#endif //INFORMATICS_MINHEAP_H
