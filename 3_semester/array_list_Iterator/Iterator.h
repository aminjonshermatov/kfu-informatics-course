//
// Created by aminjonshermatov on 12/3/2021.
//

#ifndef INFORMATICS_ITERATOR_H
#define INFORMATICS_ITERATOR_H

#include "bits/stdc++.h"

using namespace std;

template <typename PtrType>
class Iterator {
public:
    explicit Iterator(PtrType* ptr = nullptr)
    : _ptr(ptr) { }

    Iterator<PtrType>& operator=(const Iterator<PtrType>& it) {
        _ptr = it.getPtr();
        return *this;
    };

    Iterator<PtrType>& operator=(PtrType* ptr) {
        _ptr = ptr;
        return *this;
    };

    explicit operator bool() const {
        return _ptr != nullptr;
    }


    bool operator==(const Iterator<PtrType>& it) const {
        return _ptr == it.getConstPtr();
    }
    bool operator!=(const Iterator<PtrType>& it) const {
        return _ptr != it.getConstPtr();
    }


    Iterator<PtrType>& operator+=(const ptrdiff_t& n) {
        _ptr += n;
        return *this;
    }

    Iterator<PtrType>& operator-=(const ptrdiff_t& n) {
        _ptr -= n;
        return *this;
    }

    Iterator<PtrType>& operator++() {
        ++_ptr;
        return *this;
    }

    Iterator<PtrType>& operator--() {
        --_ptr;
        return *this;
    }

    Iterator<PtrType> operator++(int) {
        auto temp{*this};
        ++_ptr;
        return temp;
    }

    Iterator<PtrType> operator--(int) {
        auto temp{*this};
        --_ptr;
        return temp;
    }

    Iterator<PtrType> operator+(const ptrdiff_t& n) {
        auto oldPtr{_ptr};
        _ptr += n;
        auto temp{*this};
        _ptr = oldPtr;
        return temp;
    }

    Iterator<PtrType> operator-(const ptrdiff_t& n) {
        auto oldPtr{_ptr};
        _ptr -= n;
        auto temp{*this};
        _ptr = oldPtr;
        return temp;
    }


    PtrType& operator*() {
        return *_ptr;
    }

    const PtrType& operator*() const {
        return *_ptr;
    }
    PtrType* operator->() {
        return _ptr;
    }


    PtrType* getPtr() const {
        return _ptr;
    }
    const PtrType* getConstPtr() const {
        return _ptr;
    }
protected:
    PtrType* _ptr;
};

template <typename PtrType>
class ReverseIterator : public Iterator<PtrType> {
public:
    explicit ReverseIterator(PtrType* ptr = nullptr)
    : Iterator<PtrType>(ptr) { }

    explicit ReverseIterator(const Iterator<PtrType> it) {
        this->_ptr = it.getPtr();
    }


    ReverseIterator<PtrType>& operator=(const Iterator<PtrType>& it) {
        this->_ptr = it.getPtr();
        return *this;
    }

    ReverseIterator<PtrType>& operator=(const ReverseIterator<PtrType>& rit) {
        this->_ptr = rit.getPtr();
        return *this;
    }

    ReverseIterator<PtrType>& operator=(PtrType* ptr) {
        this->_ptr = ptr;
        return *this;
    }


    ReverseIterator<PtrType>& operator+=(const ptrdiff_t& n) {
        this->_ptr -= n;
        return *this;
    }

    ReverseIterator<PtrType>& operator-=(const ptrdiff_t& n) {
        this->_ptr += n;
        return *this;
    }

    ReverseIterator<PtrType>& operator++() {
        --this->_ptr;
        return *this;
    }

    ReverseIterator<PtrType>& operator--() {
        ++this->_ptr;
        return *this;
    }

    ReverseIterator<PtrType> operator++(int) {
        auto temp{*this};
        --this->_ptr;
        return temp;
    }

    ReverseIterator<PtrType> operator--(int) {
        auto temp{*this};
        ++this->_ptr;
        return temp;
    }

    ReverseIterator<PtrType> operator-(const ptrdiff_t& n) {
        auto oldPtr{this->_ptr};
        this->_ptr += n;
        auto temp{*this};
        this->_ptr = oldPtr;
        return temp;
    }

    ReverseIterator<PtrType> operator+(const ptrdiff_t& n) {
        auto oldPtr{this->_ptr};
        this->_ptr -= n;
        auto temp{*this};
        this->_ptr = oldPtr;
        return temp;
    }
};

#endif //INFORMATICS_ITERATOR_H
