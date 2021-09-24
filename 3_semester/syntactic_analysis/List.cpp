//
// Created by aminjonshermatov on 9/24/2021.
//

#include "List.h"

template<typename T>
List<T>::List(T data, List *next) : data(data) ,next(next) { }

template<typename T>
void List<T>::setData(T data) {
    this->data = data;
}

template<typename T>
T List<T>::getData() const {
    return this->data;
};

template<typename T>
bool List<T>::hasNext() {
    return this->next != nullptr;
}

template<typename T>
List<T>* List<T>::getNext() const {
    return this->next;
}

template<typename T>
void List<T>::setNext(List<T> *next) {
    this->next = next;
}

template<typename T>
List<T> *List<T>::getPrev() const {
    return this->prev;
}

template<typename T>
void List<T>::setPrev(List<T> *prev) {
    this->prev = prev;
}
