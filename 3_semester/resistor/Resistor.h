//
// Created by aminjonshermatov on 9/20/2021.
//

#ifndef INFORMATICS_RESISTOR_H
#define INFORMATICS_RESISTOR_H

#include <iostream>
#include <cmath>

class Resistor {
public:
    Resistor();
    Resistor(double i, double r);
    Resistor(const Resistor& r);

    double getI() const;
    void setI(double i);

    double getR() const;
    void setR(double r);

    bool operator==(const Resistor &rhs) const;
    bool operator!=(const Resistor &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Resistor &resistor);

    Resistor* parallel(const Resistor* r);
    Resistor* consistently(const Resistor* r);

    double getU() const;
    double getW() const;

private:
    double i{}, r{};
};


#endif //INFORMATICS_RESISTOR_H
