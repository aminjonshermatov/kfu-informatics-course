//
// Created by aminjonshermatov on 11/10/2021.
//

#ifndef INFORMATICS_CIRCLE_H
#define INFORMATICS_CIRCLE_H

#include "Shape.h"
#include "utils.h"

class Circle final : public Shape {
public:
    explicit Circle(int r) : Shape("Circle") {
        if (r < 0) throw invalid_argument("Circle's radius must be non-zero");
        _r = r;
    }

    double getArea() const override {
        return PI * static_cast<double>(_r * _r);
    }

    static constexpr double PI = 3.141592653589793238462643383279502884197;
private:
    size_t _r;
};

#endif //INFORMATICS_CIRCLE_H
