//
// Created by aminjonshermatov on 11/7/2021.
//

#ifndef INFORMATICS_MYSTRINGIDENTIFIER_H
#define INFORMATICS_MYSTRINGIDENTIFIER_H

#include "MyString.h"

class MyStringIdentifier : public MyString {
public:
    MyStringIdentifier();
    MyStringIdentifier(const string&);
    MyStringIdentifier(string&&);
    MyStringIdentifier(char);
    MyStringIdentifier(const MyStringIdentifier&);

    MyStringIdentifier& insert(size_t, size_t, char) override;
    void push_back(char) override;
    MyStringIdentifier& operator+=(const MyString&) override;
    MyStringIdentifier& operator+=(const string&) override;
private:
    bool _isValid(const string&);
    bool _isValid(const MyString&);
    bool _isValid(char);

    inline bool isAlphabet(char);
    inline bool isNumber(char);
    const size_t _BLACK_LIST_SIZE = 11;
    unordered_set<char> _identifierBlackList = {'!', '?', '+', '-', '*', '/', '@', '#', '^', '(', ')'};
};


#endif //INFORMATICS_MYSTRINGIDENTIFIER_H
