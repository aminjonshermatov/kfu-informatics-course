#ifndef INFORMATICS_BOOLMATRIX_H
#define INFORMATICS_BOOLMATRIX_H

#include <cassert>
#include <iostream>

class BoolMatrix {
public:
    // конструктор без параметров
    BoolMatrix() : size_{0}, offset_{0}, matrix_{nullptr} {};

    // конструктор с параметрами
    BoolMatrix(size_t size, size_t offset) : size_{size}, offset_{offset} {
        matrix_ = new bool*[size_];

        for (size_t i{0}; i < size_; ++i) matrix_[i] = new bool[size_];
    }

    // деструктор
    ~BoolMatrix() {
        // проверка что матрица не nullptr(то есть инициализировано)
        assert(matrix_ != nullptr);

        // в цикле освобождаем динамическую память
        for (size_t i{0}; i < size_; ++i) delete[] matrix_[i];
    }

    // оператор ввода
    friend std::istream& operator>>(std::istream& in, BoolMatrix& matrix) {
        size_t size, offset;

        in >> size >> offset;

        matrix.size_ = size;
        matrix.offset_ = offset;

        matrix.matrix_ = new bool*[size];

        for (size_t i{0}; i < size; ++i) {
            matrix.matrix_[i] = new bool[size];

            for (size_t j{0}; j < size; ++j) {
                in >> matrix.matrix_[i][j];
            }
        }

        return in;
    }

    // оператор вывода
    friend std::ostream& operator<<(std::ostream& out, const BoolMatrix& matrix) {
        for (size_t i{0}; i < matrix.size_; ++i) {
            for (size_t j{0}; j < matrix.size_; ++j) {
                out << matrix.matrix_[i][j] << ' ';
            }
            out << '\n';
        }

        return out;
    }

    // конъюнкция всех элементов по диагонали
    bool Tr() const {
        assert(matrix_ != nullptr);

        bool res = true;

        for (size_t i{0}; i < size_ and res; ++i) res = matrix_[i][i];

        return res;
    };
private:
    // размер квадравтой матрицы
    size_t size_;

    // отступ
    size_t offset_;

    // указатель на начало матрицы
    bool** matrix_;
};

#endif //INFORMATICS_BOOLMATRIX_H