//
// Created by aminjonshermatov on 10/6/2021.
//

#include "Matrix.h"

Matrix::Matrix() : Matrix(1e5, 1e5, 0) {}

Matrix::Matrix(size_t size) : Matrix(size, size) {}

Matrix::Matrix(size_t height, size_t width) : Matrix(height, width, 0) {}

Matrix::Matrix(size_t height, size_t width, ld value) : _height(height), _width(width) {
    this->matrix = new ld*[this->_height];

    for (ll i = 0; i < this->_height; ++i) {
        this->matrix[i] = new ld[this->_width];

        for (ll j = 0; j < this->_width; ++j) {
            this->matrix[i][j] = value;
        }
    }
}

Matrix::Matrix(size_t size, std::istream& in) : Matrix(size, size, in) {}

Matrix::Matrix(size_t height, size_t width, std::istream& in) : _height(height), _width(width) {
    this->matrix = new ld*[this->_height];

    for (ll i = 0; i < this->_height; ++i) {
        this->matrix[i] = new ld[this->_width];

        for (ll j =0; j < this->_width; ++j) {
            in >> this->matrix[i][j];
        }
    }
}

Matrix::Matrix(const Matrix& m) : _height(m.getHeight()), _width(m.getWidth()) {
    this->matrix = new ld*[this->_height];

    for (ll i = 0; i < this->_height; ++i) {
        this->matrix[i] = new ld[this->_width];

        for (ll j =0; j < this->_width; ++j) {
            this->matrix[i][j] = m[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (ll i = 0; i < this->_height; ++i) {
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

ld* Matrix::operator[](ll col) const {
    return this->matrix[col];
}

Matrix* Matrix::operator+(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getHeight()) {
        throw std::runtime_error("HeightOrWidthNotEqualException");
    }

    auto* temp = new Matrix(this->_height, this->_width);

    for (ll i = 0; i < this->_height; ++i) {
        for (ll j = 0; j < this->_width; ++j) {
            temp->matrix[i][j] = this->matrix[i][j] + *m[i][j];
        }
    }

    return temp;
}

Matrix* Matrix::operator-(const Matrix* m) const {
    if (this->_height != m->getHeight() || this->_width != m->getHeight()) {
        throw std::runtime_error("HeightOrWidthNotEqualException");
    }

    auto* temp = new Matrix(this->_height, this->_width);

    for (ll i = 0; i < this->_height; ++i) {
        for (ll j = 0; j < this->_width; ++j) {
            temp->matrix[i][j] = this->matrix[i][j] - *m[i][j];
        }
    }

    return temp;
}

Matrix* Matrix::operator*(const Matrix* m) const {
    if (this->_width != m->getHeight()) {
        throw std::runtime_error("WidthNotEqualToHeightException");
    }

    auto* temp = new Matrix(this->_height, m->getWidth());

    for (ll i = 0; i < this->_height; ++i) {
        for (ll j = 0; j < m->getWidth(); ++j) {
            for (ll k = 0; k < m->getWidth(); ++k) {
                temp->matrix[i][j] += this->matrix[i][k] * *m[k][j];
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

    auto* temp = new Matrix()
}
