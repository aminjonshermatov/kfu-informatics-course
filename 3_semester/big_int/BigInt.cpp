//
// Created by aminjonshermatov on 9/26/2021.
//

#include "BigInt.h"

BigInt::BigInt()
    : _a(0), _b(0) { }

BigInt::BigInt(li t) {
    this->_a = t;

    while (t >> 15 > 0) {
        t >>= 15;
        this->_a++;
    }

    this->_b = t;
}

BigInt::BigInt(li a, li b) {
    this->_a = a;

    while (b >> 15 > 0) {
        b >>= 15;
        this->_a++;
    }

    this->_b = b;
}

void BigInt::setA(li a) {
    this->_a = a;
}

li BigInt::getA() const {
    return this->_a;
}

void BigInt::setB(li b) {
    this->_b = b;
}

li BigInt::getB() const {
    return this->_b;
}

BigInt *BigInt::addition(const BigInt* bi) const {
    return new BigInt(this->getA() + bi->getA(), this->getB() + bi->getB());
}

BigInt *BigInt::operator+(const BigInt* bi) const {
    return this->addition(bi);
}

BigInt *BigInt::subtraction(const BigInt* bi) const {
    return new BigInt(this->getA() - bi->getA(), this->getB() - bi->getB());
}

BigInt *BigInt::operator-(const BigInt* bi) const {
    return this->subtraction(bi);
}

BigInt *BigInt::multiply(const BigInt* bi) const {
    // (a_1*2**15+b_1)(a_2*2**15+b_2)=a_1*_a_2*2**30+b_1*a_2*2**15+a_1*b_2*2**15+b_1*b_2
    return new BigInt(this->getA() * bi->getA() * (1 << 15), this->getB() * bi->getB());
}

BigInt *BigInt::operator*(const BigInt* bi) const {
    return this->multiply(bi);
}

BigInt *BigInt::division(const BigInt* bi) const {
    // (a_1*2**15+b_1)/(a_2*2**15+b_2)=a_1/(a_2*2**15+b_2)*2**15+b1/(a_2*2**15+b_2)
    return new BigInt(this->getA() / (bi->getA() * (1 << 15) + bi->getB()), this->getB() / (bi->getA() * (1 << 15) + bi->getB()));
}

BigInt *BigInt::operator/(const BigInt* bi) const {
    return this->division(bi);
}

bool BigInt::operator==(BigInt* bi) const {
    return this->getA() == bi->getA() && this->getB() == bi->getB();
}

bool BigInt::operator!=(BigInt* bi) const {
    return !this->operator==(bi);
}

bool BigInt::operator>(BigInt* bi) const {
    if (this->getA() >= bi->getA()) {
        if (this->getB() > bi->getB())
            return true;
        else
            return false;
    } else
        return false;
}

bool BigInt::operator>=(BigInt* bi) const {
    return this->operator==(bi) || this->operator>(bi);
}

bool BigInt::operator<(BigInt* bi) const {
    return !this->operator>(bi);
}

bool BigInt::operator<=(BigInt* bi) const {
    return this->operator==(bi) || this->operator<(bi);
}

std::ostream& operator<<(std::ostream& os, const BigInt& bi) {
    os << bi.getA() << " * 2**15 ";

    if (bi.getB() < 0)
        os << "- " << -1 * bi.getB();
    else
        os << "+ " << bi.getB();

    return os;
}


