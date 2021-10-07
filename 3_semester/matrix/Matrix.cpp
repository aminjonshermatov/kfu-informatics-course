//
// Created by aminjonshermatov on 10/6/2021.
//

#include "Matrix.h"

Matrix::Matrix() : Matrix(1e5, 1e5, 0) {}

Matrix::Matrix(size_t size) : Matrix(size, size) {}

Matrix::Matrix(size_t height, size_t width) : Matrix(height, width, 0) {}

Matrix::Matrix(size_t height, size_t width, ld value) : _height(height), _width(width) {
    this->matrix = new ld*[this->_height];

    for (size_t i = 0; i < this->_height; ++i) {
        this->matrix[i] = new ld[this->_width];

        for (size_t j = 0; j < this->_width; ++j) {
            this->matrix[i][j] = value;
        }
    }
}

Matrix::Matrix(size_t size, std::istream& in) : Matrix(size, size, in) {}

Matrix::Matrix(size_t height, size_t width, std::istream& in) : _height(height), _width(width) {
    this->matrix = new ld*[this->_height];

    for (size_t i = 0; i < this->_height; ++i) {
        this->matrix[i] = new ld[this->_width];

        for (size_t j =0; j < this->_width; ++j) {
            in >> this->matrix[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& m) : _height(m.getHeight()), _width(m.getWidth()) {
    this->matrix = new ld*[this->_height];

    for (size_t i = 0; i < this->_height; ++i) {
        this->matrix[i] = new ld[this->_width];

        for (size_t j = 0; j < this->_width; ++j) {
            this->matrix[i][j] = m.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < this->_height; ++i) {
        delete[] this->matrix[i];
    }

    delete[] this->matrix;
}

size_t Matrix::getHeight() const {
    return this->_height;
}

size_t Matrix::getWidth() const {
    return this->_width;
}

Matrix* Matrix::operator+(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getHeight()) {
        throw std::runtime_error("HeightOrWidthNotEqualException");
    }

    auto* temp = new Matrix(this->_height, this->_width);

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_width; ++j) {
            temp->matrix[i][j] = this->matrix[i][j] + m->matrix[i][j];
        }
    }

    return temp;
}

Matrix* Matrix::operator-(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getHeight()) {
        throw std::runtime_error("HeightOrWidthNotEqualException");
    }

    auto* temp = new Matrix(this->_height, this->_width);

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_width; ++j) {
            temp->matrix[i][j] = this->matrix[i][j] - m->matrix[i][j];
        }
    }

    return temp;
}

Matrix* Matrix::operator*(const Matrix* m) const {
    if (this->_width != m->getHeight()) {
        throw std::runtime_error("WidthNotEqualToHeightException");
    }

    auto* temp = new Matrix(this->_height, m->getWidth());

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < m->getWidth(); ++j) {
            for (size_t k = 0; k < m->getWidth(); ++k) {
                temp->matrix[i][j] += this->matrix[i][k] * m->matrix[k][j];
            }
        }
    }

    return temp;
}

Matrix* Matrix::operator/(const Matrix* m) const {
    auto* inversedM = m->inverse();

    if (this->_width != inversedM->getHeight()) {
        throw std::runtime_error("WidthNotEqualToHeightException");
    }

    // A*B=A*(B**-1)
    return this->operator*(inversedM);
}

void Matrix::operator+=(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getHeight()) {
        throw std::runtime_error("HeightOrWidthNotEqualException");
    }

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_width; ++j) {
            this->matrix[i][j] += m->matrix[i][j];
        }
    }
}

void Matrix::operator-=(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getHeight()) {
        throw std::runtime_error("HeightOrWidthNotEqualException");
    }

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_width; ++j) {
            this->matrix[i][j] -= m->matrix[i][j];
        }
    }
}

void Matrix::operator*=(const Matrix* m) const {
    if (this->_width != m->getHeight()) {
        throw std::runtime_error("WidthNotEqualToHeightException");
    }

    auto* initialMatrix = new Matrix(*this);

    for (ll i = 0; i < this->_height; ++i) {
        for (ll j = 0; j < m->getWidth(); ++j) {
            this->matrix[i][j] = 0;
            for (ll k = 0; k < m->getWidth(); ++k) {
                this->matrix[i][j] += initialMatrix->matrix[i][k] * m->matrix[k][j];
            }
        }
    }
}

void Matrix::operator/=(const Matrix* m) const {
    auto* inversedM = m->inverse();

    if (this->_width != inversedM->getHeight()) {
        throw std::runtime_error("WidthNotEqualToHeightException");
    }

    // A*B=A*(B**-1)
    this->operator*=(inversedM);
}

bool Matrix::operator==(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getWidth()) {
        return false;
    }

    bool res = true;

    for (size_t i = 0; i < this->_height && res; ++i) {
        for (size_t j = 0; j < this->_width && res; ++j) {
            if (this->matrix[i][j] != m->matrix[i][j]) res = false;
        }
    }

    return res;
}

bool Matrix::operator!=(const Matrix* m) const {
    return !this->operator==(m);
}

Matrix* Matrix::inverse() const {
    ld det = this->determinant();

    if (det == 0) {
        throw std::runtime_error("Determinant must be non-empty");
    }

    auto* temp = this->adjoint();
    temp->multiplyByNumber(1 / det);

    return temp;
}

Matrix* Matrix::transpose() const {
    auto* temp = new Matrix(this->_width, this->_height);

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_width; ++j) {
            temp->matrix[j][i] = this->matrix[i][j];
        }
    }

    return temp;
}

Matrix* Matrix::pow(ll power) const {
    if (power == 0) return Matrix::identityMatrix(this->_height);
    else if (power > 0) {
        auto* temp = new Matrix(*this);

        for (size_t i = 0; i < power - 1; ++i) {
            *temp *= this;
            std::cout << *temp;
        }

        return temp;
    } else {
        auto* iden = Matrix::identityMatrix(this->_height);
        auto* temp = new Matrix(*this);

        power *= -1;

        for (size_t i = 0; i < power; ++i) {
            *temp /= iden;
        }

        return temp;
    }
}

Matrix* Matrix::adjoint() const {
    if (this->_height != this->_width) {
        throw std::runtime_error("Matrix is not square matrix");
    }

    auto* temp = new Matrix(this->_height);
    auto* adj = new Matrix(this->_height);
    shi sign = 1;

    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_width; ++j) {
            Matrix::cofactor(this->matrix, temp->matrix, i, j, this->_height);

            sign = (i + j & 1) ? 1 : -1;

            adj->matrix[j][i] = sign * this->determinant(temp, this->_height - 1);
        }
    }

    return adj;
}

void Matrix::multiplyByNumber(ld k) const {
    for (size_t i = 0; i < this->_height; ++i) {
        for (size_t j = 0; j < this->_height; ++j) {
            this->matrix[i][j] *= k;
        }
    }
}

ld Matrix::determinant() const {
    if (this->_height != this->_width) {
        throw std::runtime_error("For determinant height and width must be equal to each other");
    }

    return this->determinant(this, this->_height);
}

ld Matrix::determinant(const Matrix* mat, size_t n) const {
    if (n > mat->getHeight()) {
        throw std::runtime_error("OutOfBoundException");
    }

    if (n == 1) return mat->matrix[0][0];

    ld determinant = 0;

    auto* temp = new Matrix(n - 1);
    shi sign = 1;

    for (size_t i = 0; i < n; ++i) {
        Matrix::cofactor(mat->matrix, temp->matrix, 0, i, n);

        determinant += sign * mat->matrix[0][i] * this->determinant(temp, n - 1);
        sign *= -1;
    }

    return determinant;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (size_t i = 0; i < m.getHeight(); ++i) {
        for (size_t j = 0; j < m.getWidth(); ++j) {
            os << std::setw(6) << m.matrix[i][j];
        }

        os << "\n";
    }

    return os << "\n";
}

std::istream& operator>>(std::istream& is, const Matrix& m) {
    for (size_t i = 0; i < m.getHeight(); ++i) {
        for (size_t j = 0; j < m.getWidth(); ++j) {
            is >> m.matrix[i][j];
        }
    }

    return is;
}

void Matrix::cofactor(ld** mat, ld** temp, ll y_0, ll x_0, ll n) {
    size_t i_t = 0, j_t = 0;

    for (size_t i_m = 0; i_m < n; ++i_m) {
        for (size_t j_m = 0; j_m < n; ++j_m) {
            if (i_m != y_0 && j_m != x_0) {
                temp[i_t][j_t++] = mat[i_m][j_m];

                if (j_t == n - 1) {
                    j_t = 0;
                    i_t++;
                }
            }
        }
    }
}

Matrix* Matrix::identityMatrix(size_t n) {
    auto* temp = new Matrix(n);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i == j) temp->matrix[i][j] = 1;
            else temp->matrix[i][j] = 0;
        }
    }

    return temp;
}
