//
// Created by aminjonshermatov on 11/7/2021.
//

#ifndef INFORMATICS_MYSTRING_H
#define INFORMATICS_MYSTRING_H

#include "bits/stdc++.h"

using namespace std;

class MyString {
public:
    MyString();
    MyString(const string&);
    MyString(string&&);
    MyString(char);
    MyString(const MyString&);
    ~MyString();

    MyString& operator=(const string&);
    MyString& operator=(string&&);
    MyString& operator=(const MyString&);

    char front();
    char back();
    char begin();
    char end();

    size_t size() const;
    size_t capacity() const;
    bool empty() const;
    void clear();
    void reverse();

    virtual MyString& insert(size_t, size_t, char);
    MyString& erase(size_t, size_t);
    virtual void push_back(char);
    void pop_back();

    MyString& operator+=(const MyString&);
    MyString& operator+=(const string&);

    int compare(MyString&) const;
    int compare(string&) const;

    bool starts_with(MyString&);
    bool starts_with(string&);
    bool ends_with(MyString&);
    bool ends_with(string&);
    bool contains(MyString&);
    bool contains(string&);
    bool contains(char);

    MyString& replace(char, char);
    MyString& replaceAll(char, char);

    MyString substr(size_t, size_t);

    size_t find(MyString&);
    size_t find(string&);
    size_t find(char);

    char& operator[](size_t);
    char operator[](size_t) const;

    bool operator==(MyString&) const;
    bool operator==(string&) const;
    bool operator!=(MyString&) const;
    bool operator!=(string&) const;
    bool operator<(MyString&) const;
    bool operator<(string&) const;
    bool operator<=(MyString&) const;
    bool operator<=(string&) const;
    bool operator>(MyString&) const;
    bool operator>(string&) const;
    bool operator>=(MyString&) const;
    bool operator>=(string&) const;

    friend ostream& operator<<(ostream&, const MyString&);
    friend istream& operator>>(istream&, MyString&);

    static constexpr size_t npos = -1;
protected:
    size_t _size, _capacity;
    char* _str;

    static constexpr double GOLDEN_RATIO = 1.61803398875;
};


#endif //INFORMATICS_MYSTRING_H
