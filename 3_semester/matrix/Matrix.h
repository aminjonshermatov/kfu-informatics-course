//
// Created by aminjonshermatov on 10/6/2021.
//

#ifndef INFORMATICS_MATRIX_H
#define INFORMATICS_MATRIX_H

#include <bits/stdc++.h>

using ll = long long;
using ld = long double;

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

    ld* operator[](ll) const;

    Matrix* operator+(const Matrix*) const;
    Matrix* operator-(const Matrix*) const;
    Matrix* operator*(const Matrix*) const;
    Matrix* operator/(const Matrix*) const;

    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator/=(const Matrix&);

    bool operator==(const Matrix&);
    bool operator!=(const Matrix&);

    Matrix* inverse() const;
    Matrix* transpose() const;
    Matrix* pow() const;

    ld determinant() const;
    ld norm() const;

    friend std::ostream& operator<<(std::ostream&, const Matrix&);
    friend std::istream& operator>>(std::istream&, const Matrix&);
private:
    size_t _height;
    size_t _width;
};


#endif //INFORMATICS_MATRIX_H
