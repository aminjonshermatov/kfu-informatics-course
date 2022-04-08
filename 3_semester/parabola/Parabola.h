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
    Parabola(double, double, double);
    Parabola(const Parabola&);

    double getA() const;
    void setA(double);

    double getB() const;
    void setB(double);

    double getC() const;
    void setC(double);

    bool operator==(const Parabola&) const;
    bool operator!=(const Parabola&) const;

    friend std::ostream &operator<<(std::ostream&, const Parabola&);

    IRoot intersectionXAxis() const;
private:
    double _a, _b, _c;
};


#endif //INFORMATICS_PARABOLA_H
