//
// Created by aminjonshermatov on 10/6/2021.
//

#ifndef INFORMATICS_MATRIX_H
#define INFORMATICS_MATRIX_H

#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using shi = short int;

class Matrix {
public:
    Matrix();
    explicit Matrix(size_t);
    Matrix(size_t, size_t);
    Matrix(size_t, size_t, ld);
    Matrix(size_t, std::istream&);
    Matrix(size_t, size_t, std::istream&);
    Matrix(const Matrix&);
    ~Matrix();

    ld** matrix;

    size_t getHeight() const;
    size_t getWidth() const;

    Matrix* operator+(const Matrix*) const;
    Matrix* operator-(const Matrix*) const;
    Matrix* operator*(const Matrix*) const;
    Matrix* operator/(const Matrix*) const;

    void operator+=(const Matrix*) const;
    void operator-=(const Matrix*) const;
    void operator*=(const Matrix*) const;
    void operator/=(const Matrix*) const;

    bool operator==(const Matrix*) const;
    bool operator!=(const Matrix*) const;

    Matrix* inverse() const;
    Matrix* transpose() const;
    Matrix* pow(ll) const;
    Matrix* adjoint() const;
    void multiplyByNumber(ld) const;

    ld determinant() const;

    static Matrix* identityMatrix(size_t);

    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, const Matrix&);
private:
    size_t _height;
    size_t _width;

    ld determinant(const Matrix* , size_t) const;
    static void cofactor(ld**, ld**, ll, ll, ll);
};


#endif //INFORMATICS_MATRIX_H
