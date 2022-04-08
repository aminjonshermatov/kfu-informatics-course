//
// Created by aminjonshermatov on 12/7/2021.
//

#ifndef INFORMATICS_POLYNOMIAL_H
#define INFORMATICS_POLYNOMIAL_H

#include "bits/stdc++.h"

using namespace std;

template <typename T = int>
class Polynomial {
    size_t n_;
    T* coefficient_;

public:
    Polynomial() = delete;

    explicit Polynomial(T c)
    : n_{0}
    , coefficient_{new T[n_ + 1]} {
        coefficient_[0] = c;
    }

    explicit Polynomial(vector<T> coeff) {
        if (coeff.size() < 1) throw invalid_argument("Array of coefficients must be non-zero.");

        n_ = coeff.size() - 1;
        coefficient_ = new T[static_cast<int>(coeff.size())];

        int idx = n_;
        for (const auto& el : coeff) coefficient_[idx--] = el;
    }

    Polynomial(const Polynomial<T>& polynomial) {
        n_ = polynomial.n_;
        coefficient_ = new T[n_ + 1];

        for (size_t i{0}; i <= n_; ++i) coefficient_[i] = polynomial.coefficient_[i];
    }

    ~Polynomial() {
        // delete[] coefficient_;
    }

    Polynomial<T> operator+(const Polynomial<T>& polynomial) const {
        size_t maxPolynomial{max(n_, polynomial.n_)};

        Polynomial<T> result(-1);
        result.n_ = maxPolynomial;
        result.coefficient_ = new T[maxPolynomial + 1];

        for (size_t i{0}; i <= maxPolynomial; ++i) {
            result.coefficient_[i] = 0;

            if (i <= n_) result.coefficient_[i] += coefficient_[i];
            if (i <= polynomial.n_) result.coefficient_[i] += polynomial.coefficient_[i];
        }

        return result;
    }

    Polynomial<T> operator-(const Polynomial<T>& polynomial) const {
        size_t maxPolynomial{max(n_, polynomial.n_)};

        Polynomial<T> result(-1);
        result.n_ = maxPolynomial;
        result.coefficient_ = new T[maxPolynomial + 1];

        for (size_t i{0}; i <= maxPolynomial; ++i) {
            result.coefficient_[i] = 0;

            if (i <= n_) result.coefficient_[i] += coefficient_[i];
            if (i <= polynomial.n_) result.coefficient_[i] -= polynomial.coefficient_[i];
        }

        return result;
    }

    Polynomial<T> operator*(const Polynomial<T>& polynomial) const {
        size_t maxPolynomial{n_ + polynomial.n_};

        Polynomial<T> result(-1);
        result.n_ = maxPolynomial;
        result.coefficient_ = new T[maxPolynomial + 1];

        for (size_t i{0}; i <= n_ + polynomial.n_; ++i) result.coefficient_[i] = 0;

        for (size_t i{0}; i <= n_; ++i) {
            for (size_t j{0}; j <= polynomial.n_; ++j) {
                result.coefficient_[i + j] += coefficient_[i] * polynomial.coefficient_[j];
            }
        }

        return result;
    }

    Polynomial<T>& operator+=(const Polynomial<T>& polynomial) {
        size_t maxPolynomial{max(n_, polynomial.n_)};

        if (n_ < maxPolynomial) grow_(maxPolynomial);

        for (size_t i{0}; i <= maxPolynomial; ++i) {
            if (i <= polynomial.n_) coefficient_[i] += polynomial.coefficient_[i];
        }

        return *this;
    }

    Polynomial<T>& operator-=(const Polynomial<T>& polynomial) {
        size_t maxPolynomial{max(n_, polynomial.n_)};

        if (n_ < maxPolynomial) grow_(maxPolynomial);

        for (size_t i{0}; i <= maxPolynomial; ++i) {
            if (i <= polynomial.n_) coefficient_[i] -= polynomial.coefficient_[i];
        }

        return *this;
    }

    Polynomial<T>& operator*=(const Polynomial<T>& polynomial) {
        size_t maxPolynomial{n_ + polynomial.n_};

        Polynomial<T> temp(-1);
        temp.n_ = maxPolynomial;
        temp.coefficient_ = new T[maxPolynomial + 1];

        for (size_t i{0}; i <= maxPolynomial; ++i) temp.coefficient_[i] = 0;

        for (size_t i{0}; i <= n_; ++i) {
            for (size_t j{0}; j <= polynomial.n_; ++j) {
                temp.coefficient_[i + j] += coefficient_[i] * polynomial.coefficient_[j];
            }
        }

        n_ = temp.n_;
        for (size_t i{0}; i <= maxPolynomial; ++i) coefficient_[i] = temp.coefficient_[i];

        return *this;
    }

    Polynomial<T>& operator=(const Polynomial<T>& polynomial) {
        if (this == &polynomial) return *this;

        n_ = polynomial.n_;
        delete[] coefficient_;
        coefficient_ = new T[n_ + 1];

        for (size_t i{0}; i <= n_; ++i) coefficient_[i] = polynomial.coefficient_[i];

        return *this;
    }

    bool operator==(const Polynomial<T>& polynomial) const {
        if (this == &polynomial) return true;

        if (n_ != polynomial.n_) return false;

        for (size_t i{0}; i <= n_; ++i) {
            if (coefficient_[i] != polynomial.coefficient_[i]) return false;
        }

        return true;
    }

    bool operator!=(const Polynomial<T>& polynomial) const {
        if (this == &polynomial) return false;

        if (n_ != polynomial.n_) return true;

        for (size_t i{0}; i <= n_; ++i) {
            if (coefficient_[i] != polynomial.coefficient_[i]) return true;
        }

        return false;
    }

    friend ostream& operator<<(ostream& out, const Polynomial<T>& polynomial) {
        bool isFirst = true;
        for (int i{static_cast<int>(polynomial.n_)}; i >= 0; --i) {
            if (polynomial.coefficient_[i] == 0) {
                if (isFirst && i == 0) out << "0";
            } else {
                if (!isFirst && polynomial.coefficient_[i] > 0) out << '+';
                isFirst = false;

                if (abs(polynomial.coefficient_[i]) == 1 && i != 0) {
                    if (polynomial.coefficient_[i] < 0) out << '-';
                } else {
                    out << polynomial.coefficient_[i];
                }

                if (i != 0) {
                    out << "x";

                    if (i != 1) out << "^" << i;
                }
            }
        }

        return out;
    }

    T operator()(const T& x) const {
        T xPow = T{1},
          res = T{0};

        for (size_t i{0}; i <= n_; ++i) {
            res += coefficient_[i] * xPow;
            xPow *= x;
        }

        return res;
    }

    inline int lastNonZeroIdx_() const {
        int i;

        for (i = n_; i >= 0; --i) {
            if (coefficient_[i] != T{0}) break;
        }

        return i;
    }

    int operator[](int idx) const {
        return coefficient_[idx];
    }

private:
    void grow_(size_t newSize) {
        auto *newCoefficient = new T[newSize + 1];

        for (size_t i{0}; i <= newSize; ++i) {
            newCoefficient[i] = 0;

            if (i <= n_) newCoefficient[i] += coefficient_[i];
        }

        delete[] coefficient_;

        coefficient_ = newCoefficient;
        n_ = newSize;
    }
};

#endif //INFORMATICS_POLYNOMIAL_H
