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
    ComplexNumber(double, double);
    ComplexNumber(const ComplexNumber&);

    double getA() const;
    void setA(double);

    double getB() const;
    void setB(double);

    ComplexNumber* addition(const ComplexNumber*) const;
    ComplexNumber* operator+(const ComplexNumber*) const;

    ComplexNumber* subtraction(const ComplexNumber*) const;
    ComplexNumber* operator-(const ComplexNumber*) const;

    ComplexNumber* multiplication(const ComplexNumber*) const;
    ComplexNumber* operator*(const ComplexNumber*) const;

    ComplexNumber* division(const ComplexNumber*) const;
    ComplexNumber* operator/(const ComplexNumber*) const;

    bool operator==(const ComplexNumber&) const;
    bool operator!=(const ComplexNumber&) const;

    friend std::ostream &operator<<(std::ostream&, const ComplexNumber&);

private:
    double _a{}, _b{};
};




#endif //INFORMATICS_COMPLEXNUMBER_H
