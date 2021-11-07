//
// Created by aminjonshermatov on 11/5/2021.
//

#ifndef INFORMATICS_LINKEDLIST_H
#define INFORMATICS_LINKEDLIST_H

#include "bits/stdc++.h"

#include "Iterator.h"
#include "Node.h"

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(LinkedList<T>&);
    LinkedList(LinkedList<T>&&) noexcept;

    virtual LinkedList<T>& operator=(LinkedList<T>&);
    virtual LinkedList<T>& operator=(LinkedList<T>&&) noexcept;
    ~LinkedList();

    size_t size() const;

    Iterator<Node<T>> iterator() const;
    void reset();
    void move();
    void move(size_t);
    bool empty() const;
    void del();

    virtual void add_after(const T&);
    virtual void add_after(T&&);
    virtual void add_before(const T&);
    virtual void add_before(T&&);

    template<class S>
    friend ostream& operator<<(ostream& out, const LinkedList<S>& rhs);
protected:
    Node<T> *_head, *_cur, *_prev;
    size_t _size;
};

template <typename T>
LinkedList<T>::LinkedList()
    : _head{nullptr}, _size{0}, _cur(nullptr), _prev(nullptr) {}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &rhs) : LinkedList() {
    auto it = rhs.iterator();

    _head = _cur = &*it;
    ++it;
    while (_cur != nullptr && !it.isNull()) {
        _cur->next = &*it;
        ++it;
    }
    reset();
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& rhs) noexcept {
    auto it = rhs.iterator();

    _head = _cur = &*it;
    ++it;
    while (_cur != nullptr && !it.isNull()) {
        _cur->next = &*it;
        ++it;
    }
    reset();
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T>& rhs) {
    auto it = rhs.iterator();

    _head = _cur = &*it;
    ++it;
    while (_cur != nullptr && !it.isNull()) {
        _cur->next = &*it;
        ++it;
    }
    reset();

    return *this;
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T>&& rhs) noexcept {
    auto it = rhs.iterator();

    _head = _cur = &*it;
    ++it;
    while (_cur != nullptr && !it.isNull()) {
        _cur->next = &*it;
        ++it;
    }
    reset();

    return *this;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    while (_head != nullptr) {
        auto* temp = _head;
        _head = _head->next;
        delete temp;
    }
}

template<typename T>
size_t LinkedList<T>::size() const {
    return _size;
}

template<typename T>
Iterator<Node<T>> LinkedList<T>::iterator() const {
    return Iterator<Node<T>>(_cur);
}

template<typename T>
void LinkedList<T>::reset() {
    _prev = nullptr;
    _cur = _head;
}

template<typename T>
void LinkedList<T>::move() {
    if (_cur == nullptr) {
        throw out_of_range("");
    }

    _prev = _cur;
    _cur = _cur->next;
}

template<typename T>
void LinkedList<T>::move(size_t n) {
    size_t i = 0;

    while (i++ < n) {
        if (_cur == nullptr) {
            throw out_of_range("");
        }

        _prev = _cur;
        _cur = _cur->next;
    }
}

template<typename T>
bool LinkedList<T>::empty() const {
    return _size == 0;
}

template<typename T>
void LinkedList<T>::del() {
    if (_prev == nullptr) {
        delete _cur;
        _cur = _head = nullptr;
    } else {
        auto* temp = _cur;
        _prev->next = _cur->next;
        _cur = _prev->next;
        delete temp;
    }
}

template<typename T>
void LinkedList<T>::add_after(const T& val) {
    if (_cur == nullptr) {
        _head = _cur = new Node<T>{val};
    } else {
        _prev = _cur;
        _cur->next = new Node<T>{val};
        _cur = _cur->next;
    }
}

template<typename T>
void LinkedList<T>::add_after(T && val) {
    if (_cur == nullptr) {
        _head = _cur = new Node<T>{T{val}};
    } else {
        _prev = _cur;
        _cur->next = new Node<T>{T{val}};
        _cur = _cur->next;
    }
}

template<typename T>
void LinkedList<T>::add_before(const T& val) {
    if (_cur == nullptr) {
        _head = _cur = new Node<T>{val};
    } else {
        if (_prev == nullptr) {
            _prev = new Node<T>{val, _cur};
        } else {
            _prev->next = new Node<T>{val, _cur};
        }
    }
}

template<typename T>
void LinkedList<T>::add_before(T&& val) {
    if (_cur == nullptr) {
        _prev = nullptr;
        _head = _cur = new Node<T>{T{val}};
    } else {
        if (_prev == nullptr) {
            _head = _prev = new Node<T>{T{val}, _cur};
        } else {
            _prev->next = new Node<T>{T{val}, _cur};
        }
    }
}

template <typename S>
ostream& operator<<(ostream &out, const LinkedList<S> &rhs) {
    auto* it = rhs._head;

    while (it != nullptr) {
        out << it->val << ' ';
        it = it->next;
    }

    return out;
}

#endif //INFORMATICS_LINKEDLIST_H
