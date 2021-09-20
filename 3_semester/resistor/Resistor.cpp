//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Resistor.h"

Resistor::Resistor() {
    this->setI(0);
    this->setR(0);
}

Resistor::Resistor(double i, double r) {
    this->setI(i);
    this->setR(r);
}

Resistor::Resistor(const Resistor &r) {
    this->setI(r.getI());
    this->setR(r.getR());
}

double Resistor::getI() const {
    return this->i;
}

void Resistor::setI(double i) {
    this->i = i;
}

double Resistor::getR() const {
    return this->r;
}

void Resistor::setR(double r) {
    this->r = r;
}

bool Resistor::operator==(const Resistor &r) const {
    return this->i == r.i && this->r == r.r;
}

bool Resistor::operator!=(const Resistor &r) const {
    return !this->operator==(r);
}

std::ostream &operator<<(std::ostream &os, const Resistor &resistor) {
    return os << "i=" << resistor.getI() << ", r=" << resistor.getR();
}

Resistor *Resistor::parallel(const Resistor *r) {
    auto* paral = new Resistor();

    // r_parallel = r_1 * r_2 / (r_1 + r_2)
    paral->setR(this->getR() * r->getR() / (this->getR() + r->getR()));

    // i_parallel = i_1 = i_2
    paral->setI(this->getI() + r->getI());

    return paral;
}

Resistor *Resistor::consistently(const Resistor *r) {
    auto* consis = new Resistor();

    // r_consistently = r_1 = r_2
    consis->setR(this->getR() + r->getR());

    // i_consistently = (u_1 + u_2) / r_consistently
    consis->setI((this->getU() + r->getU()) / consis->getR());

    return consis;
}

double Resistor::getU() const {
    return this->getI() * this->getR();
}

double Resistor::getW() const {
    return pow(this->getI(), 2) * this->getR();
}
