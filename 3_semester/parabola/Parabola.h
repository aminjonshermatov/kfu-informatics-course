//
// Created by aminjonshermatov on 9/20/2021.
//

#ifndef INFORMATICS_PARABOLA_H
#define INFORMATICS_PARABOLA_H

#include <iostream>
#include <cmath>

using IRoot = std::pair<double, double>;

class Parabola {
public:
    Parabola();
    Parabola(double a, double b, double c);
    Parabola(const Parabola& p);

    double getA() const;
    void setA(double a);

    double getB() const;
    void setB(double b);

    double getC() const;
    void setC(double c);

    bool operator==(const Parabola &rhs) const;
    bool operator!=(const Parabola &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Parabola &parabola);

    IRoot intersectionXAxis() const;
private:
    double a, b, c;
};


#endif //INFORMATICS_PARABOLA_H
