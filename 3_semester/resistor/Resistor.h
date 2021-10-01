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
    Resistor(double, double);
    Resistor(const Resistor&);

    double getI() const;
    void setI(double);

    double getR() const;
    void setR(double);

    bool operator==(const Resistor&) const;
    bool operator!=(const Resistor&) const;

    friend std::ostream &operator<<(std::ostream&, const Resistor&);

    Resistor* parallel(const Resistor*);
    Resistor* consistently(const Resistor*);

    double getU() const;
    double getW() const;

private:
    double _i{}, _r{};
};


#endif //INFORMATICS_RESISTOR_H
