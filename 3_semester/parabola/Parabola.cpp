//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Parabola.h"

Parabola::Parabola() {
    this->setA(0);
    this->setB(0);
    this->setC(0);
}

Parabola::Parabola(double a, double b, double c) {
    this->setA(a);
    this->setB(b);
    this->setC(c);
}

Parabola::Parabola(const Parabola &p) {
    this->setA(p.getA());
    this->setB(p.getB());
    this->setC(p.getC());
}

double Parabola::getA() const {
    return this->_a;
}

void Parabola::setA(double a) {
    this->_a = a;
}

double Parabola::getB() const {
    return this->_b;
}

void Parabola::setB(double b) {
    this->_b = b;
}

double Parabola::getC() const {
    return this->_c;
}

void Parabola::setC(double c) {
    this->_c = c;
}

bool Parabola::operator==(const Parabola &p) const {
    return this->_a == p._a && this->_b == p._b && this->_c == p._c;
}

bool Parabola::operator!=(const Parabola &p) const {
    return !this->operator==(p);
}

std::ostream &operator<<(std::ostream &os, const Parabola &parabola) {
    if (parabola.getA() != 1)
        os << parabola.getA();

    os << "x^2";

    if (parabola.getB() >= 0)
        os << "+";
    else
        os << "-";
    os << std::abs(parabola.getB()) << "x";

    if (parabola.getC() >= 0)
        os << "+";
    else
        os << "-";

    os << std::abs(parabola.getC()) << "=0\n";

    return os;
}

IRoot Parabola::intersectionXAxis() const {
    IRoot root;

    if (this->getA() == 0) {
        if (this->_b == 0) {
            if (this->_c == 0)
                throw std::runtime_error("x_1 and x_2 cat take any numbers");
            else
                throw std::runtime_error("Parabola haven't any root");
        }
        else
            root.first = root.second = -this->getC() / this->getB();
    }
    else {
        double diskriminant = pow(this->getB(), 2) - 4 * this->getA() * this->getC();

        if (diskriminant < 0)
            throw std::runtime_error("Parabola function is over than x axis");
        else {
            root.first = (-this->getB() - sqrt(diskriminant)) / 2 / this->getA();
            root.second= (-this->getB() + sqrt(diskriminant)) / 2 / this->getA();
        }
    }

    return root;
}
