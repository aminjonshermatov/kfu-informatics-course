//
// Created by aminjonshermatov on 12/10/2021.
//

#include "Polynomial.h"

template <typename T = int>
class Exponent {
    using polynomial_t_ = Polynomial<T>;
    polynomial_t_ s_;
public:
    Exponent() = delete;

    explicit Exponent(T c)
    : s_{polynomial_t_{c}} {}

    explicit Exponent(vector<T> coeff)
    : s_{polynomial_t_{coeff}} {}

    Exponent(const Exponent<T>& exponent)
    : s_{exponent.s_} {}

    ~Exponent() = default;

    static constexpr double E = 2.7182818284;

    Exponent<T> inverse() const {
        auto temp{*this};
        temp.s_ *= polynomial_t_{-1};

        return temp;
    }

    Exponent<T> operator*(const Exponent<T>& exponent) const {
        auto temp{*this};
        temp.s_ += exponent.s_;

        return temp;
    }

    Exponent<T> operator/(const Exponent<T>& exponent) const {
        auto temp{*this};
        temp.s_ -= exponent.s_;

        return temp;
    }

    Exponent<T>& operator*=(const Exponent<T>& exponent) {
        s_ += exponent.s_;

        return *this;
    }

    Exponent<T>& operator/=(const Exponent<T>& exponent) {
        s_ -= exponent.s_;

        return *this;
    }

    bool operator==(const Exponent<T>& exponent) const {
        if (this == &exponent) return true;

        return s_ == exponent.s_;
    }

    bool operator!=(const Exponent<T>& exponent) const {
        if (this == &exponent) return false;

        return s_ != exponent.s_;
    }

    double operator()(const T& x) const {
        T powRes = s_(x);

        int tempRes = static_cast<int>(powRes);

        if (tempRes == 0) return T{1};
        if (tempRes == -1) return 1 / E;
        if (tempRes == 1) return E;

        return pow<double>(E, powRes);
    }

    friend ostream& operator<<(ostream& out, const Exponent<T>& exponent) {
        int idx = exponent.s_.lastNonZeroIdx_();

        if (idx == -1) return out << 1;
        if (idx == 0 && exponent.s_[idx] == 1) return out << "e";
        if (idx == 0 && exponent.s_[idx] == -1) return out << "e^(-1)";
        return out << "e^(" << exponent.s_ << ')';
    }
};
