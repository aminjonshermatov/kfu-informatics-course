//
// Created by aminjonshermatov on 9/24/2021.
//

#include "Stack.h"

template<class T>
Stack<T>::Stack() {
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

template<class T>
ui Stack<T>::getSize() const {
    return this->size;
}

template<class T>
void Stack<T>::push_back(ui data) {
    if (this->head == nullptr)
        this->head = this->tail = new List<T>(data);
    else {
        auto* el = new List<T>(data);
        this->tail->setNext(el);
        this->tail = el;
    }

    this->size++;
}

template<class T>
ui Stack<T>::pop_back() {
    auto* last = this->tail;

    auto* prev = last->getPrev();
    prev->setNext(nullptr);

    ui result = last->getData();

    delete last;
    return result;
}

template<class T>
ui Stack<T>::top() {
    return this->top();
}
