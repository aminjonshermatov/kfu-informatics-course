//
// Created by aminjonshermatov on 9/19/2021.
//

#ifndef INFORMATICS_RATIONALNUMBER_H
#define INFORMATICS_RATIONALNUMBER_H

#include <iostream>
#include <exception>

// x = a/b
class RationalNumber {
public:
    RationalNumber();
    RationalNumber(int a, int b);

    int getA() const;
    void setA(int a);

    int getB() const;
    void setB(int b);

    // generator
    RationalNumber* multiplication(const RationalNumber* rn);

    // modificator
    void addition(const RationalNumber* rn);

    bool operator==(const RationalNumber &rn) const;
    bool operator!=(const RationalNumber &rn) const;
    friend std::ostream &operator<<(std::ostream &os, const RationalNumber &rn);

private:
    int a, b;

    void fraction();
    int gcd(int a, int b);
};


#endif //INFORMATICS_RATIONALNUMBER_H
