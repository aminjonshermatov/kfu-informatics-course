//
// Created by aminjonshermatov on 9/24/2021.
//

#include "List.h"

template<class T>
List<T>::List(T data, List *next, List* prev)
    : data(data), prev(prev), next(next) { }

template<class T>
void List<T>::setData(T data) {
    this->data = data;
}

template<class T>
T List<T>::getData() const {
    return this->data;
};

template<class T>
bool List<T>::hasNext() {
    return this->next != nullptr;
}

template<class T>
List<T>* List<T>::getNext() const {
    return this->next;
}

template<class T>
void List<T>::setNext(List<T> *next) {
    this->next = next;
}

template<class T>
List<T> *List<T>::getPrev() const {
    return this->prev;
}

template<class T>
void List<T>::setPrev(List<T> *prev) {
    this->prev = prev;
}
