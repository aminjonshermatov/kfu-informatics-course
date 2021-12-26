//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_STACK_H
#define INFORMATICS_STACK_H

#include "sharedModule.h"
#include "List.h"

template<class T>
class Stack {
public:
    Stack();
    ui getSize() const;
    void push_back(T data);
    T pop();
    T top();
    void clear();

private:
    ui _size{};
    List<T>* _head;
    List<T>* _tail;
};

template<class T>
Stack<T>::Stack() {
    this->_head = nullptr;
    this->_tail = nullptr;
    this->_size = 0;
}

template<class T>
ui Stack<T>::getSize() const {
    return this->_size;
}

template<class T>
void Stack<T>::push_back(T data) {
    if (this->_head == nullptr)
        this->_head = this->_tail = new List<T>(data);
    else {
        this->_tail = new List<T>(data, this->_tail);
        if (!this->_head->hasNext())
            this->_head->setNext(this->_tail);
    }

    this->_size++;
}

template<class T>
T Stack<T>::pop() {
    if (this->getSize() > 1) {
        auto* last = this->_tail;

        auto* prevLast = last->getPrev();
        prevLast->setNext(nullptr);
        this->_tail = prevLast;

        T result = last->getData();

        delete last;
        this->_size--;
        return result;
    } else if (this->getSize() == 1) {
        T result = this->_head->getData();
        delete this->_head;
        this->_head = nullptr;
        this->_tail = nullptr;
        this->_size--;
        return result;
    }

    return T{};
}

template<class T>
T Stack<T>::top() {
    if (this->getSize() > 0)
        return this->_tail->getData();

    return T{};
}

template<class T>
void Stack<T>::clear() {
    while (this->_head != nullptr) {
        auto* temp = this->_tail->getPrev();

        if (temp == nullptr)
            delete this->_head;
        else {
            delete this->_tail;
            this->_tail = temp;
        }

        this->_size--;
    }
}


#endif //INFORMATICS_STACK_H
