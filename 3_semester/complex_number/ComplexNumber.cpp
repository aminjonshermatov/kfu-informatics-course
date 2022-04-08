//
// Created by aminjonshermatov on 9/19/2021.
//

#include "ComplexNumber.h"

ComplexNumber::ComplexNumber() {
    this->setA(0);
    this->setB(0);
}

ComplexNumber::ComplexNumber(double a, double b) {
    this->setA(a);
    this->setB(b);
}

ComplexNumber::ComplexNumber(const ComplexNumber &cn) {
    this->setA(cn.getA());
    this->setB(cn.getB());
}

double ComplexNumber::getA() const {
    return this->_a;
}

void ComplexNumber::setA(double a) {
    this->_a = a;
};

double ComplexNumber::getB() const {
    return this->_b;
}

void ComplexNumber::setB(double b) {
    this->_b = b;
}

bool ComplexNumber::operator==(const ComplexNumber &cn) const {
    return this->_a == cn._a && this->_b == cn._b;
}

bool ComplexNumber::operator!=(const ComplexNumber &cn) const {
    return !this->operator==(cn);
}

std::ostream &operator<<(std::ostream &os, const ComplexNumber &cn) {
    os << cn.getA();

    if (cn.getB() >= 0)
        os << "+i" << cn.getB();
    else
        os << "-i" << -1 * cn.getB();

    return os << "\n";
}

ComplexNumber *ComplexNumber::addition(const ComplexNumber *cn) const {
    auto *add = new ComplexNumber();

    add->setA(this->getA() + cn->getA());
    add->setB(this->getB() + cn->getB());

    return add;
}

ComplexNumber *ComplexNumber::operator+(const ComplexNumber *cn) const {
    return this->addition(cn);
}

ComplexNumber *ComplexNumber::subtraction(const ComplexNumber *cn) const {
    auto *sub = new ComplexNumber();

    sub->setA(this->getA() - cn->getA());
    sub->setB(this->getB() - cn->getB());

    return sub;
}

ComplexNumber *ComplexNumber::operator-(const ComplexNumber *cn) const {
    return this->subtraction(cn);
}

ComplexNumber *ComplexNumber::multiplication(const ComplexNumber *cn) const {
    auto *mul = new ComplexNumber();

    //(a1 + i*b1)*(a2+i*b2) = a1*a2 - b1*b2 + i*(b1*a2 + a1 * b2)
    mul->setA(this->getA() * cn->getA() - this->getB() * cn->getB());
    mul->setB(this->getB() * cn->getA() + this->getA() * cn->getB());

    return mul;
}

ComplexNumber *ComplexNumber::operator*(const ComplexNumber *cn) const {
    return this->multiplication(cn);
}

ComplexNumber *ComplexNumber::division(const ComplexNumber *cn) const {
    if (cn->getA() == 0 && cn->getB() == 0)
        throw std::runtime_error("Koefficients of denominator must be nonzero;");

    auto* div = new ComplexNumber();

    // (a1 + i*b1)/(a2 + i*b2) = (a1*a2 + b1*b2) / (a2**2 + b2**2) + i*(b1 * a2 - a1 * b2) / (a2**2 + b2**2)
    double denominator = cn->getA() * cn->getA() + cn->getB() * cn->getB();

    div->setA((this->getA() * cn->getA() + this->getB() * cn->getB()) / denominator);
    div->setB((this->getB() * cn->getA() - this->getA() * cn->getB()) / denominator);

    return div;
};

ComplexNumber *ComplexNumber::operator/(const ComplexNumber *cn) const {
    return this->division(cn);
};
