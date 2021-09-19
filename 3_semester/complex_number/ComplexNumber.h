//
// Created by aminjonshermatov on 9/19/2021.
//

#ifndef INFORMATICS_COMPLEXNUMBER_H
#define INFORMATICS_COMPLEXNUMBER_H


#include <ostream>

// t = a + i*b
class ComplexNumber {
public:
    ComplexNumber();
    ComplexNumber(double a, double b);
    ComplexNumber(const ComplexNumber& cn);

    double getA() const;
    void setA(double a);

    double getB() const;
    void setB(double b);

    ComplexNumber* addition(const ComplexNumber* cn) const;
    ComplexNumber* operator+(const ComplexNumber* ch) const;

    ComplexNumber* subtraction(const ComplexNumber* cn) const;
    ComplexNumber* operator-(const ComplexNumber* cn) const;

    ComplexNumber* multiplication(const ComplexNumber* cn) const;
    ComplexNumber* operator*(const ComplexNumber* ch) const;

    ComplexNumber* division(const ComplexNumber* cn) const;
    ComplexNumber* operator/(const ComplexNumber* cn) const;

    bool operator==(const ComplexNumber &cn) const;
    bool operator!=(const ComplexNumber &cn) const;

    friend std::ostream &operator<<(std::ostream &os, const ComplexNumber &cn);

private:
    double a{}, b{};
};




#endif //INFORMATICS_COMPLEXNUMBER_H
