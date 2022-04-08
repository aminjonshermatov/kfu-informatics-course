//
// Created by aminjonshermatov on 11/5/2021.
//

#ifndef INFORMATICS_ITERATOR_H
#define INFORMATICS_ITERATOR_H

template <typename T>
class Iterator {
public:
    explicit Iterator(T*);

    Iterator<T> operator++();
    Iterator<T> operator++(int);
    bool operator==(Iterator<T>&);
    bool operator!=(Iterator<T>&);
    T& operator*();
    T* operator->();
    bool isNull();

    template<typename S>
    friend ostream& operator<<(ostream&, Iterator<S>&);
private:
    T* _ptr;
};

template<typename T>
Iterator<T>::Iterator(T* ptr) : _ptr(ptr) {}

template <typename T>
Iterator<T> Iterator<T>::operator++() {
    if (_ptr == nullptr) {
        throw out_of_range("");
    }

    Iterator<T> temp = *this;
    _ptr = _ptr->next;
    return temp;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int) {
    if (_ptr == nullptr) {
        throw out_of_range("");
    }

    _ptr = _ptr->next;
    return *this;
}

template<typename T>
bool Iterator<T>::operator==(Iterator<T> &rhs) {
    return _ptr == rhs._ptr;
}

template<typename T>
bool Iterator<T>::operator!=(Iterator<T> &rhs) {
    return _ptr != rhs._ptr;
}

template<typename T>
bool Iterator<T>::isNull() {
    return _ptr == nullptr;
}

template<typename S>
ostream &operator<<(ostream &out, Iterator<S>& rhs) {
    return out << *rhs._ptr;
}

template<typename T>
T& Iterator<T>::operator*() {
    return *_ptr;
}

template<typename T>
T* Iterator<T>::operator->() {
    return _ptr;
}


#endif //INFORMATICS_ITERATOR_H
