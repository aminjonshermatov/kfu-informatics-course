//
// Created by aminjonshermatov on 11/7/2021.
//

#include "MyStringIdentifier.h"

MyStringIdentifier::MyStringIdentifier() : MyString() {}

MyStringIdentifier::MyStringIdentifier(const string& str) {
    if (!_isValid(str)) throw invalid_argument("");

    this->_size = str.size();
    this->_capacity = this->_size;
    this->_str = new char[this->_capacity];

    for (int i = 0; i < str.size(); ++i) this->_str[i] = str[i];
}

MyStringIdentifier::MyStringIdentifier(string&& str) {
    if (!_isValid(str)) throw invalid_argument("");

    this->_size = str.size();
    this->_capacity = this->_size;
    this->_str = new char[this->_capacity];

    for (int i = 0; i < str.size(); ++i) this->_str[i] = str[i];
}

MyStringIdentifier::MyStringIdentifier(char ch) {
    if (isNumber(ch) || _identifierBlackList.count(ch) != 0) throw invalid_argument("");

    this->_capacity = 3;
    this->_size = 1;
    this->_str = new char[this->_capacity];
    this->_str[0] = ch;
}

MyStringIdentifier::MyStringIdentifier(const MyStringIdentifier& msi) {
    this->_size = msi.size();
    this->_capacity = max(this->_size, size_t{3});
    this->_str = new char[this->_capacity];

    for (size_t i = 0; i < this->_size; ++i) {
        this->_str[i] = msi[i];
    }
}

bool MyStringIdentifier::_isValid(const string& str) {
    if (str.empty()) return true;

    /**
     * The first character of an identifier should be either an alphabet
     * or an underscore, and then it can be followed by any of the character,
     * digit, or underscore
     *
     * It should not begin with any numerical digit.
     */
    if (!isAlphabet(str[0]) || str[0] != '_' || isNumber(str[0])) return false;

    /**
     * Commas or blank spaces cannot be specified within an identifier.
     */
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == ' ' || str[i] == ',') return false;
    }

    /**
     * The length of the identifiers should not be more than 31 characters.
     */
    if (str.size() > 31) return false;

    /**
     * It should not contain any of: ['!', '?', '+', '-', '*', '/', '@', '#', '^', '(', ')']
     */
    for (int i = 0; i < str.size(); ++i) {
        if (!_isValid(str[i])) {
            return false;
        }
    }
    return true;
}

bool MyStringIdentifier::_isValid(const MyString& my_str) {
    if (my_str.empty()) return true;

    /**
     * The first character of an identifier should be either an alphabet
     * or an underscore, and then it can be followed by any of the character,
     * digit, or underscore
     *
     * It should not begin with any numerical digit.
     */
    if (!isAlphabet(my_str[0]) || my_str[0] != '_' || isNumber(my_str[0])) return false;

    /**
     * Commas or blank spaces cannot be specified within an identifier.
     */
    for (int i = 0; i < my_str.size(); ++i) {
        if (my_str[i] == ' ' || my_str[i] == ',') return false;
    }

    /**
     * The length of the identifiers should not be more than 31 characters.
     */
    if (my_str.size() > 31) return false;

    /**
     * It should not contain any of: ['!', '?', '+', '-', '*', '/', '@', '#', '^', '(', ')']
     */
    for (int i = 0; i < my_str.size(); ++i) {
        if (!_isValid(my_str[i])) {
            return false;
        }
    }
    return true;
}

bool MyStringIdentifier::isAlphabet(char ch) {
    return (ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90);
}

bool MyStringIdentifier::isNumber(char ch) {
    return ch >= 48 && ch <= 57;
}

MyStringIdentifier &MyStringIdentifier::insert(size_t idx, size_t count, char ch) {
    if (idx == 0 && isNumber(ch) || !_isValid(ch)) throw invalid_argument("");
    return dynamic_cast<MyStringIdentifier&>(MyString::insert(idx, count, ch));
}

void MyStringIdentifier::push_back(char ch) {
    if (!_isValid(ch) || (this->_size == 0 && isNumber(ch))) throw invalid_argument("");
    MyString::push_back(ch);
}

bool MyStringIdentifier::_isValid(char ch) {
    return _identifierBlackList.count(ch) == 0;
}

MyStringIdentifier &MyStringIdentifier::operator+=(const MyString& my_str) {
    if (!_isValid(my_str)) throw invalid_argument("");
    return dynamic_cast<MyStringIdentifier &>(MyString::operator+=(my_str));
}

MyStringIdentifier &MyStringIdentifier::operator+=(const string& str) {
    if (!_isValid(str)) throw invalid_argument("");
    return dynamic_cast<MyStringIdentifier &>(MyString::operator+=(str));
}
