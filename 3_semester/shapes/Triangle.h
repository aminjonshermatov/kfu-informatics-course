//
// Created by aminjonshermatov on 11/10/2021.
//

#ifndef INFORMATICS_TRIANGLE_H
#define INFORMATICS_TRIANGLE_H

#include "Shape.h"
#include "utils.h"

// no equal sides: a != b != c
class ScaleneTriangle final : public Shape {
public:
    ScaleneTriangle(int a, int b, int c) : Shape("Scalene Triangle") {
        if (!utils::isTriangle(a, b, c) || a == b || b == c || a == c) throw invalid_argument("Invalid Scalene Triangle");
        _a = a;
        _b = b;
        _c = c;
    };

    double getArea() const override {
        double p = static_cast<double>(_a + _b + _c) / 2.0;
        return sqrt(p * (p - static_cast<double>(_a)) * (p - static_cast<double>(_b)) * (p - static_cast<double>(_c)));
    };
private:
    size_t _a, _b, _c;
};

// right triangle a^2 + b^2 = c^2
class RightTriangle final : public Shape {
public:
    RightTriangle(int a, int b, int c) : Shape("Right Triangle") {
        if (!utils::isTriangle(a, b, c) || (a * a + b * b != c * c)) throw invalid_argument("Invalid Right Triangle");
        _a = a;
        _b = b;
        _c = c;
    };

    double getArea() const override {
        return _a * _b / 2.0;
    }
private:
    size_t _a, _b, _c;
};

// isosceles triangle (a == b) != c
class IsoscelesTriangle final : public Shape {
public:
    IsoscelesTriangle(int a, int b, int c) : Shape("Isosceles Triangle") {
        if (!utils::isTriangle(a, b, c) || (a != b) || 2 * a < c) throw invalid_argument("Invalid Isosceles Triangle");
        _side = a;
        _c = c;
    }

    double getArea() const override {
        return _c * sqrt(4 * _side * _side - _c * _c) / 4.0;
    }

private:
    size_t _side, _c;
};

#endif //INFORMATICS_TRIANGLE_H
