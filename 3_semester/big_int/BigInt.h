//
// Created by aminjonshermatov on 9/26/2021.
//

#ifndef INFORMATICS_BIGINT_H
#define INFORMATICS_BIGINT_H

#include <iostream>

using li = long int;

class BigInt {
    // n = a * 2 ** 15 + b
public:
    BigInt();
    BigInt(li t);
    BigInt(li a, li b);

    void setA(li a);
    li getA() const;
    void setB(li b);
    li getB() const;

    BigInt* addition(const BigInt*) const;
    BigInt* operator+(const BigInt*) const;

    BigInt* subtraction(const BigInt*) const;
    BigInt* operator-(const BigInt*) const;

    BigInt* multiply(const BigInt*) const;
    BigInt* operator*(const BigInt*) const;

    BigInt* division(const BigInt*) const;
    BigInt* operator/(const BigInt*) const;

    bool operator==(BigInt*) const;
    bool operator!=(BigInt*) const;
    bool operator>(BigInt*) const;
    bool operator>=(BigInt*) const;
    bool operator<(BigInt*) const;
    bool operator<=(BigInt*) const;

    friend std::ostream& operator<<(std::ostream&, const BigInt&);
private:
    li _a, _b;
};


#endif //INFORMATICS_BIGINT_H
