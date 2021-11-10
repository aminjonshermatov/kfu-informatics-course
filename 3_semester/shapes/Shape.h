//
// Created by aminjonshermatov on 11/10/2021.
//

#ifndef INFORMATICS_SHAPE_H
#define INFORMATICS_SHAPE_H

#include <utility>

#include "bits/stdc++.h"

using std::cin;
using std::cout;
using std::string;
using std::stringstream;
using std::invalid_argument;
using std::exception;
using std::move;

class Shape {
public:
    explicit Shape(string t) : type(move(t)) {}
    virtual double getArea() const = 0;
    virtual void printType() {
        stringstream msg;
        msg << "Type of shape is:\t" << type << '\n';
        cout << msg.str();
    }

    virtual string getType() const {
        return type;
    }

protected:
    string type;
};

#endif //INFORMATICS_SHAPE_H
