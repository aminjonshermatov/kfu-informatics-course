//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_LIST_H
#define INFORMATICS_LIST_H

template<class T>
class List {
public:
    List(T data);
    List(T data, List<T>* prev);
    List(T data, List<T>* prev, List<T>* next);
    void setData(T data);
    T getData() const;
    bool hasNext();
    List<T>* getNext() const;
    void setNext(List<T>* next);

    List<T>* getPrev() const;
    void setPrev(List<T>* prev);
private:
    List<T>* _prev;
    List<T>* _next;
    T _data;
};

template<class T>
List<T>::List(T data)
: _data(data)
, _prev(nullptr)
, _next(nullptr) { }

template<class T>
List<T>::List(T data, List<T>* prev)
: _data(data)
, _prev(prev)
, _next(nullptr) { }

template<class T>
List<T>::List(T data, List<T>* prev, List<T>* next)
: _data(data)
, _prev(prev)
, _next(next) { }

template<class T>
void List<T>::setData(T data) {
    this->_data = data;
}

template<class T>
T List<T>::getData() const {
    return this->_data;
};

template<class T>
bool List<T>::hasNext() {
    return this->_next != nullptr;
}

template<class T>
List<T>* List<T>::getNext() const {
    return this->_next;
}

template<class T>
void List<T>::setNext(List<T> *next) {
    this->_next = next;
}

template<class T>
List<T> *List<T>::getPrev() const {
    return this->_prev;
}

template<class T>
void List<T>::setPrev(List<T> *prev) {
    this->_prev = prev;
}

#endif //INFORMATICS_LIST_H
