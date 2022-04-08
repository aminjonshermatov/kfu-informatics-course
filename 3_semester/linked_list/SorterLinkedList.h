//
// Created by aminjonshermatov on 11/5/2021.
//

#ifndef INFORMATICS_SORTERLINKEDLIST_H
#define INFORMATICS_SORTERLINKEDLIST_H

#include "LinkedList.h"

template <typename T>
class SorterLinkedList : public LinkedList<T> {
public:
    SorterLinkedList() : LinkedList<T>() {};

    explicit SorterLinkedList(LinkedList<T>&);
    SorterLinkedList(LinkedList<T>&&) noexcept;

    SorterLinkedList(SorterLinkedList<T>&);
    SorterLinkedList(SorterLinkedList<T>&&) noexcept ;
    SorterLinkedList<T>& operator=(SorterLinkedList<T>&);
    SorterLinkedList<T>& operator=(SorterLinkedList<T>&&) noexcept ;

    void add_after(const T&) override;
    void add_after(T&&) override;
    void add_before(const T&) override;
    void add_before(T&&) override;
private:
    void _add(const T&);
    void _add(T&&);
};

template<typename T>
void SorterLinkedList<T>::_add(const T& val) {
    if (this->_head == nullptr) {
        this->_head = this->_cur = new Node<T>(val);
    } else if (this->_head->val > val) {
        this->_head = new Node<T>(val, this->_head);
    } else {
        Node<T> *temp = this->_head, *pre = nullptr;
        while (temp != nullptr && temp->val < val) {
            pre = temp;
            temp = temp->next;
        }

        pre->next = new Node<T>(val, temp);
    }
    ++this->_size;
}

template<typename T>
void SorterLinkedList<T>::_add(T&& val) {
    if (this->_head == nullptr) {
        this->_head = this->_cur = new Node<T>(val);
    } else if (this->_head->val > val) {
        this->_head = new Node<T>(val, this->_head);
    } else {
        Node<T> *temp = this->_head, *pre = nullptr;
        while (temp != nullptr && temp->val < val) {
            pre = temp;
            temp = temp->next;
        }

        pre->next = new Node<T>(val, temp);
    }
    ++this->_size;
}

template<typename T>
SorterLinkedList<T>::SorterLinkedList(LinkedList<T>& rhs) {
    auto it = rhs.iterator();

    while (!it.isNull()) {
        _add(*it);
        ++it;
    }
}

template<typename T>
SorterLinkedList<T>::SorterLinkedList(LinkedList<T>&& rhs) noexcept {
    auto it = rhs.iterator();

    while (!it.isNull()) {
        _add(*it);
        ++it;
    }
}

template<typename T>
SorterLinkedList<T>::SorterLinkedList(SorterLinkedList<T>& rhs) {
    auto it = rhs.iterator();

    this->_head = this->_cur = &*it;
    ++it;
    while (this->_cur != nullptr && !it.isNull()) {
        this->_cur->next = &*it;
        ++it;
    }
    this->reset();
}

template<typename T>
SorterLinkedList<T>::SorterLinkedList(SorterLinkedList<T>&& rhs) noexcept {
    auto it = rhs.iterator();

    this->_head = this->_cur = &*it;
    ++it;
    while (this->_cur != nullptr && !it.isNull()) {
        this->_cur->next = &*it;
        ++it;
    }
    this->reset();
}

template<typename T>
SorterLinkedList<T>& SorterLinkedList<T>::operator=(SorterLinkedList<T>& rhs) {
    auto it = rhs.iterator();

    this->_head = this->_cur = &*it;
    ++it;
    while (this->_cur != nullptr && !it.isNull()) {
        this->_cur->next = &*it;
        ++it;
    }
    this->reset();

    return *this;
}

template<typename T>
SorterLinkedList<T> &SorterLinkedList<T>::operator=(SorterLinkedList<T>&& rhs)  noexcept {
    auto it = rhs.iterator();

    this->_head = this->_cur = &*it;
    ++it;
    while (this->_cur != nullptr && !it.isNull()) {
        this->_cur->next = &*it;
        ++it;
    }
    this->reset();

    return *this;
}

template<typename T>
void SorterLinkedList<T>::add_after(const T& val) {
    _add(val);
}

template<typename T>
void SorterLinkedList<T>::add_after(T&& val) {
    _add(T{val});
}

template<typename T>
void SorterLinkedList<T>::add_before(const T& val) {
    _add(val);
}

template<typename T>
void SorterLinkedList<T>::add_before(T&& val) {
    _add(T{val});
}


#endif //INFORMATICS_SORTERLINKEDLIST_H
