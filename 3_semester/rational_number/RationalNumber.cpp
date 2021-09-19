//
// Created by aminjonshermatov on 9/19/2021.
//

#include "RationalNumber.h"

RationalNumber::RationalNumber() {
    this->setA(0);
    this->setB(1);
}

RationalNumber::RationalNumber(int a, int b) {
    this->setA(a);
    this->setB(b);
}

int RationalNumber::getA() const {
    return this->a;
}

void RationalNumber::setA(int a) {
    this->a = a;
}

int RationalNumber::getB() const {
    return this->b;
}

void RationalNumber::setB(int b) {
    if (b == 0)
        throw std::exception("The denominator must be nonzero");

    this->b = b;
}

bool RationalNumber::operator==(const RationalNumber &rn) const {
    return this->a == rn.a && this->b == rn.b;
}

bool RationalNumber::operator!=(const RationalNumber &rn) const {
    return !this->operator==(rn);
}

std::ostream &operator<<(std::ostream &os, const RationalNumber &rn) {
    if (rn.getA() / rn.getB() == 1)
        return os << 1;

    os << rn.getA();

    if (rn.getB() > 1)
        os << "/" << rn.getB();

    return os;
}

RationalNumber* RationalNumber::multiplication(const RationalNumber *rn) {
    auto* mul = new RationalNumber();

    mul->setA(this->getA() * rn->getA());
    mul->setB(this->getB() * rn->getB());
    mul->fraction();

    return mul;
}

void RationalNumber::addition(const RationalNumber *rn) {
    this->setA(this->getA() * rn->getB() + this->getB() * rn->getA());
    this->setB(this->getB() * rn->getB());

    this->fraction();
}

void RationalNumber::fraction() {
    int gcd = this->gcd(this->getA(), this->getB());

    this->setA(this->getA() / gcd);
    this->setB(this->getB() / gcd);
}

int RationalNumber::gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return this->gcd(b, a % b);
}
