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
    return this->a;
}

void Parabola::setA(double a) {
    this->a = a;
}

double Parabola::getB() const {
    return this->b;
}

void Parabola::setB(double b) {
    this->b = b;
}

double Parabola::getC() const {
    return this->c;
}

void Parabola::setC(double c) {
    this->c = c;
}

bool Parabola::operator==(const Parabola &p) const {
    return this->a == p.a && this->b == p.b && this->c == p.c;
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
    os << abs(parabola.getB()) << "x";

    if (parabola.getC() >= 0)
        os << "+";
    else
        os << "-";

    os << abs(parabola.getC()) << "=0\n";

    return os;
}

IRoot Parabola::intersectionXAxis() const {
    IRoot root;

    if (this->getA() == 0) {
        if (this->b == 0) {
            if (this->c == 0)
                throw std::exception("x_1 and x_2 cat take any numbers");
            else
                throw std::exception("Parabola haven't any root");
        }
        else
            root.first = root.second = (-1) * this->getC() / this->getB();
    }
    else {
        double diskriminant = pow(this->getB(), 2) - 4 * this->getA() * this->getC();

        if (diskriminant < 0)
            throw std::exception("Parabola function is over than x axis");
        else {
            root.first = ((-1) * this->getB() - sqrt(diskriminant)) / 2 / this->getA();
            root.second= ((-1) * this->getB() + sqrt(diskriminant)) / 2 / this->getA();
        }
    }

    return root;
}
