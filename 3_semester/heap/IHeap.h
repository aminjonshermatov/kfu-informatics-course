//
// Created by aminjonshermatov on 10/20/2021.
//

#ifndef INFORMATICS_IHEAP_H
#define INFORMATICS_IHEAP_H

template<typename T>
class Heap {
public:
    virtual void siftDown(size_t) = 0;
    virtual void siftUp(size_t) = 0;
    virtual void insert(const T&) = 0;
    virtual void insert(T&&) = 0;
};

#endif //INFORMATICS_IHEAP_H
