//
// Created by aminjonshermatov on 12/3/2021.
//

#ifndef INFORMATICS_ARRAYLIST_H
#define INFORMATICS_ARRAYLIST_H

#include "Iterator.h"

template <typename T>
class ArrayList {
public:
    // iterators
    using iterator =                    Iterator<T>;
    using const_iterator =              Iterator<const T>;

    using reverse_iterator =            ReverseIterator<T>;
    using const_reverse_iterator =      ReverseIterator<const T>;

    iterator begin()                    { return iterator(&_storage[0]); }
    iterator end()                      { return iterator(&_storage[_cur_size]); }

    const_iterator cbegin()             { return const_iterator(&_storage[0]); }
    const_iterator cend()               { return const_iterator(&_storage[_cur_size]); }

    reverse_iterator rbegin()           { return reverse_iterator(&_storage[_cur_size - 1]); }
    reverse_iterator rend()             { return reverse_iterator(&_storage[-1]); }

    const_reverse_iterator crbegin()    { return const_reverse_iterator(&_storage[_cur_size - 1]); }
    const_reverse_iterator crend()      { return const_reverse_iterator(&_storage[-1]); }


    ArrayList()
    : _cur_size{0}
    , _storage_size{10}
    , _storage{new T[_storage_size]} { }

    ArrayList(initializer_list<T> list) {
        _cur_size = 0;
        _storage_size = max<size_t>(10, list.size());
        _storage = new T[_storage_size];

        for (const auto& el : list) _storage[_cur_size++] = el;
    }

    explicit ArrayList(size_t size)
    : _cur_size{0}
    , _storage_size{max<size_t>(10, size)}
    , _storage{new T[_storage_size]} { }

    ArrayList(size_t size, T defaultValue)
    : _cur_size{size}
    , _storage_size{max<size_t>(10, size)}
    , _storage{new T[_storage_size]} {
        for (size_t idx = 0; idx < _cur_size; ++idx) _storage[idx] = defaultValue;
    }

    ~ArrayList() {
        delete[] _storage;
    }

    const T& front() const {
        return _storage[0];
    }

    const T& back() const {
        return _storage[_cur_size - 1];
    }

    void push_back(const T val) {
        if (_cur_size == _storage_size) _grow();

        _storage[_cur_size++] = val;
    }

    void pop_back() {
        --_cur_size;
    }

    T& operator[](const int& idx) {
        return _storage[idx];
    }

    const T& operator[](const int& idx) const {
        return _storage[idx];
    }

    T& at(const int& idx) {
        _assertBoundaries(idx);
        return _storage[idx];
    }

    const T& at(const int& idx) const {
        _assertBoundaries(idx);
        return _storage[idx];
    }

    size_t size() const {
        return _cur_size;
    }

    size_t capacity() const {
        return _storage_size;
    }

    bool empty() const {
        return _cur_size == 0;
    }

private:
    T* _storage;
    size_t _cur_size,
           _storage_size;

    static constexpr double GROWS_COEFFICIENT = 1.61803398875L;

    void _grow() {
        auto newStorageSize = static_cast<size_t>(_storage_size * GROWS_COEFFICIENT);
        auto newStorage{new T[newStorageSize]};

        for (size_t idx = 0; idx < _storage_size; ++idx) newStorage[idx] = _storage[idx];

        delete[] _storage;

        _storage = newStorage;
        _storage_size = newStorageSize;
    }

    void _assertBoundaries(const int& idx) {
        if (idx < 0 || idx >= _cur_size) {
            stringstream errorMsg;
            errorMsg << "Out of range: " << idx;
            throw out_of_range(errorMsg.str());
        }
    }
};

#endif //INFORMATICS_ARRAYLIST_H
