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
    RationalNumber(int, int);

    int getA() const;
    void setA(int);

    int getB() const;
    void setB(int);

    // generator
    RationalNumber* multiplication(const RationalNumber*);

    // modificator
    void addition(const RationalNumber*);

    bool operator==(const RationalNumber&) const;
    bool operator!=(const RationalNumber&) const;
    friend std::ostream &operator<<(std::ostream&, const RationalNumber&);

private:
    int _a, _b;

    void fraction();
    int gcd(int, int);
};


#endif //INFORMATICS_RATIONALNUMBER_H
