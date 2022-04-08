//
// Created by aminjonshermatov on 11/10/2021.
//

#ifndef INFORMATICS_RECTANGLE_H
#define INFORMATICS_RECTANGLE_H

#include "Shape.h"
#include "utils.h"

class Rectangle final : public Shape {
public:
    Rectangle(int a, int b) : Shape("Rectangle") {
        if (a < 0 || b < 0) throw invalid_argument("Sides of rectangle must be non-zero");

        _a = a;
        _b = b;
    };

    double getArea() const override {
        return static_cast<double>(_a * _b);
    }
private:
    size_t _a, _b;
};

class Square final : public Shape {
public:
    explicit Square(int a) : Shape("Square") {
        if (a < 0) throw invalid_argument("Side of square must be non-zero");
        _a = a;
    }

    double getArea() const override {
        return static_cast<double>(_a * _a);
    }

private:
    size_t _a;
};

#endif //INFORMATICS_RECTANGLE_H
