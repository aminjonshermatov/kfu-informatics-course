//
// Created by aminjonshermatov on 11/7/2021.
//

#include "MyString.h"

MyString::MyString() : _size{0}, _capacity{3}, _str(new char[_capacity]) {}

MyString::MyString(const string& str) : _size{str.size()}, _capacity{_size}, _str{new char[_capacity]} {
    size_t i = 0;

    while (i < _size) _str[i] = str[i++];
}

MyString::MyString(string && str) : _size{str.size()}, _capacity{_size}, _str{new char[_capacity]} {
    size_t i = 0;

    while (i < _size) _str[i] = str[i++];
}

MyString::MyString(char ch) : _size{1}, _capacity{_size}, _str{new char[_capacity]} {
    _str[0] = ch;
}

MyString::MyString(const MyString& my_str) : _size{my_str.size()}, _capacity{_size}, _str{new char[_capacity]} {
    size_t i = 0;

    while (i < _size) _str[i] = my_str[i++];
}

MyString::~MyString() {
    delete[] _str;
}

size_t MyString::size() const {
    return _size;
}

size_t MyString::capacity() const {
    return _capacity;
}

void MyString::clear() {
    _size = 0;
    delete[] _str;
    _str = nullptr;
}

void MyString::reverse() {
    for (size_t i = 0; i < (_size >> 1); ++i) {
        char temp = _str[i];
        _str[i] = _str[_size - i - 1];
        _str[_size - i - 1] = temp;
    }
}

char& MyString::operator[](size_t idx) {
    if (idx < 0 || idx >= _size) throw out_of_range("");

    return _str[idx];
}

char MyString::operator[](size_t idx) const {
    if (idx < 0 || idx >= _size) throw out_of_range("");

    return _str[idx];
}

MyString& MyString::operator=(const string& str) {
    _size = str.size();
    delete[] _str;
    _str = new char[_size];

    size_t i = 0;
    while (i < _size) _str[i] = str[i++];

    return *this;
}

MyString& MyString::operator=(string&& str) {
    _size = str.size();
    delete[] _str;
    _str = new char[_size];

    size_t i = 0;
    while (i < _size) _str[i] = str[i++];

    return *this;
}

MyString& MyString::operator=(const MyString &my_str) {
    _size = my_str.size();
    delete[] _str;
    _str = new char[_size];

    size_t i = 0;
    while (i < _size) _str[i] = my_str[i++];

    return *this;
}

char MyString::front() {
    if (_size == 0) throw out_of_range("");

    return _str[0];
}

char MyString::back() {
    if (_size == 0) throw out_of_range("");

    return _str[_size - 1];
}

char MyString::begin() {
    return front();
}

char MyString::end() {
    return back();
}

bool MyString::empty() const {
    return _size == 0;
}

MyString& MyString::insert(size_t idx, size_t count, char ch) {
    if (idx < 0 || idx > _size) throw out_of_range("");

    if (_size + count >= _capacity) {
        auto* temp = new char[_size + count];

        size_t i = 0;

        while (i < _size) {
            if (i == idx) {
                size_t j = 0;

                while (j++ < count) {
                    temp[i + j] = ch;
                }
            } else {
                temp[i] = _str[i];
            }
            ++i;
        }

        delete[] _str;
        _str = temp;
        _size += count;
        _capacity = _size;
    } else {
        auto* temp = new char[_capacity];

        size_t i = 0;

        while (i < _size) {
            if (i == idx) {
                size_t j = 0;

                while (j++ < count) {
                    temp[i + j] = ch;
                }
            } else {
                temp[i] = _str[i];
            }
            ++i;
        }

        delete[] _str;
        _str = temp;
        _size += count;
    }

    return *this;
}

MyString& MyString::erase(size_t idx, size_t count) {
    if (idx < 0 || idx + 1 >= _size) throw out_of_range("");

    auto* temp = new char[_capacity];

    size_t i = 0, j = count;

    while (i < _size) {
        if (i == idx && j--) continue;

        temp[i] = _str[i + count - j];
        ++i;
    }

    delete[] _str;
    _size -= count;
    _str = temp;
    return *this;
}

void MyString::push_back(char ch) {
    if (_size == _capacity) {
        _capacity = (size_t)(_capacity * GOLDEN_RATIO);

        auto* temp = new char[_capacity];

        size_t i = 0;
        while (i < _size) {
            temp[i] = _str[i++];
        }

        temp[i] = ch;
        ++_size;
        delete[] _str;
        _str = temp;
    } else {
        _str[_size++] = ch;
    }
}

void MyString::pop_back() {
    if (_size == 0) throw out_of_range("");
    --_size;
}

MyString& MyString::operator+=(const MyString& rhs) {
    if (_size + rhs.size() > _capacity) {
        do {
            _capacity = (size_t)(_capacity * GOLDEN_RATIO);
        } while (_size + rhs.size() > _capacity);

        auto* temp = new char[_capacity];

        size_t i = 0;

        while (i < _size) temp[i] = _str[i++];

        i = 0;
        while (i < rhs.size()) temp[i + _size] = rhs[i++];

        delete[] _str;
        _str = temp;
        _size += rhs.size();
    } else {
        size_t i = 0;
        while (i < rhs.size()) _str[i + _size] = rhs[i++];
    }

    return *this;
}

MyString &MyString::operator+=(const string& rhs) {
    if (_size + rhs.size() > _capacity) {
        do {
            _capacity = (size_t)(_capacity * GOLDEN_RATIO);
        } while (_size + rhs.size() > _capacity);

        auto* temp = new char[_capacity];

        size_t i = 0;

        while (i < _size) temp[i] = _str[i++];

        i = 0;
        while (i < rhs.size()) temp[i + _size] = rhs[i++];

        delete[] _str;
        _str = temp;
        _size += rhs.size();
    } else {
        size_t i = 0;
        while (i < rhs.size()) _str[i + _size] = rhs[i++];
    }

    return *this;
}

int MyString::compare(MyString& rhs) const {
    int minLen = (int)min(_size, rhs.size());

    for (int i = 0; i < minLen; ++i) {
        if (_str[i] < rhs[i]) return 1;
        else if (_str[i] > rhs[i]) return -1;
    }

    if (_size != rhs.size()) {
        if (minLen == _size) return 1;
        return -1;
    }

    return 0;
}

int MyString::compare(string& rhs) const {
    int minLen = (int)min(_size, rhs.size());

    for (int i = 0; i < minLen; ++i) {
        if (_str[i] < rhs[i]) return 1;
        else if (_str[i] > rhs[i]) return -1;
    }

    if (_size != rhs.size()) {
        if (minLen == _size) return 1;
        return -1;
    }

    return 0;
}

bool MyString::starts_with(MyString& my_str) {
    for (int i = 0; i < my_str.size(); ++i) {
        if (my_str[i] != _str[i]) return false;
    }

    return true;
}

bool MyString::starts_with(string& str) {
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] != _str[i]) return false;
    }

    return true;
}

bool MyString::ends_with(MyString& my_str) {
    for (int i = (int)my_str.size() - 1, j = (int)_size - 1; i >= 0 && j >= 0; --i, --j) {
        if (my_str[i] != _str[j]) return false;
    }

    return true;
}

bool MyString::ends_with(string& str) {
    for (int i = (int)str.size() - 1, j = (int)_size - 1; i >= 0 && j >= 0; --i, --j) {
        if (str[i] != _str[j]) return false;
    }

    return true;
}

bool MyString::contains(MyString& my_str) {
    if (my_str.empty()) return true;

    for (int i = 0; i < _size; ++i) {
        if (_str[i] == my_str[0]) {
            bool isEqual = true;
            for (int j = 1; j < my_str.size() && isEqual; ++j) {
                if (_str[i + j] != my_str[j]) isEqual = false;
            }

            if (isEqual) return true;
        }
    }

    return false;
}

bool MyString::contains(string& str) {
    if (str.empty()) return true;

    for (int i = 0; i < _size; ++i) {
        if (_str[i] == str[0]) {
            bool isEqual = true;
            for (int j = 1; j < str.size() && isEqual; ++j) {
                if (_str[i + j] != str[j]) isEqual = false;
            }

            if (isEqual) return true;
        }
    }

    return false;
}

bool MyString::contains(char ch) {
    for (int i = 0; i < _size; ++i) {
        if (_str[i] == ch) return true;
    }

    return false;
}

MyString &MyString::replace(char what, char with) {
    for (int i = 0; i < _size; ++i) {
        if (_str[i] == what) {
            _str[i] = with;
            break;
        }
    }

    return *this;
}

MyString &MyString::replaceAll(char what, char with) {
    for (int i = 0; i < _size; ++i) {
        if (_str[i] == what) _str[i] = with;
    }

    return *this;
}

MyString MyString::substr(size_t start, size_t count) {
    MyString sub;

    for (int i = 0; i < _size; ++i) {
        if (i == start) {
            while (count--) sub.push_back(_str[i++]);
        }
    }

    return sub;
}

size_t MyString::find(MyString& my_str) {
    if (my_str.empty()) return true;

    for (int i = 0; i < _size; ++i) {
        if (_str[i] == my_str[0]) {
            bool isEqual = true;

            for (int j = 1; j < my_str.size() && isEqual; ++j) {
                if (_str[i + j] != my_str[j]) isEqual = false;
            }

            if (isEqual) return i;
        }
    }

    return npos;
}

size_t MyString::find(string& str) {
    if (str.empty()) return true;

    for (int i = 0; i < _size; ++i) {
        if (_str[i] == str[0]) {
            bool isEqual = true;

            for (int j = 1; j < str.size() && isEqual; ++j) {
                if (_str[i + j] != str[j]) isEqual = false;
            }

            if (isEqual) return i;
        }
    }

    return npos;
}

size_t MyString::find(char ch) {
    for (int i = 0; i < _size; ++i) {
        if (_str[i] == ch) return i;
    }

    return npos;
}

bool MyString::operator==(MyString& my_str) const {
    return compare(my_str) == 0;
}

bool MyString::operator==(string& str) const {
    return compare(str) == 0;
}

bool MyString::operator!=(MyString& my_str) const {
    return compare(my_str) != 0;
}

bool MyString::operator!=(string& str) const {
    return compare(str) != 0;
}

bool MyString::operator<(MyString& my_str) const {
    return compare(my_str) > 0;
}

bool MyString::operator<(string & str) const {
    return compare(str) > 0;
}

bool MyString::operator<=(MyString& my_str) const {
    return compare(my_str) >= 0;
}

bool MyString::operator<=(string & str) const {
    return compare(str) >= 0;
}

bool MyString::operator>(MyString& my_str) const {
    return compare(my_str) < 0;
}

bool MyString::operator>(string & str) const {
    return compare(str) < 0;
}

bool MyString::operator>=(MyString& my_str) const {
    return compare(my_str) <= 0;
}

bool MyString::operator>=(string & str) const {
    return compare(str) <= 0;
}

ostream& operator<<(ostream& out, const MyString& my_str) {
    for (int i = 0; i < my_str.size(); ++i) out << my_str[i];
    return out;
}

istream& operator>>(istream& in, MyString& my_str) {
    while (in.peek() != EOF) {
        char ch;
        in >> ch;
        my_str.push_back(ch);
    }

    return in;
}
