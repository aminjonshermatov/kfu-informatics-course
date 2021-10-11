//
// Created by aminjonshermatov on 10/6/2021.
//

#include "Matrix.h"

int main() try {
    freopen("D:/kfu/informatics/3_semester/matrix/input.txt", "r", stdin);
    freopen("D:/kfu/informatics/3_semester/matrix/output.txt", "w", stdout);

    auto m_1 = new Matrix(4, 4, std::cin);
    auto m_2 = new Matrix(4, 4, std::cin);
    auto m_3 = new Matrix(4, 4, std::cin);
    auto m_4 = new Matrix(3, 3);
    std::cin >> *m_4;

    std::cout << "Matrix_1:\n" << *m_1;
    std::cout << "Matrix_2:\n" << *m_2;

    std::cout << "Matrix_1 + Matrix_2:\n" << *m_1 + m_2;
    std::cout << "Matrix_1 - Matrix_2:\n" << *m_1 - m_2;
    std::cout << "Matrix_1 * Matrix_2:\n" << *m_1 * m_2;
    std::cout << "Matrix_1 / Matrix_2:\n" << *m_1 / m_2;

    std::cout << "Determinant: " << m_1->determinant() << "\n";

    std::cout << *m_3;
    auto adjoint = m_3->adjoint();
    std::cout << "Adjoint:\n" << adjoint;
    auto inverse = m_3->inverse();
    std::cout << "Inverse:\n" << inverse;

    auto cubeOfMatrix = m_4->pow(3);
    std::cout << "Cube of m_4:\n" << cubeOfMatrix;
    std::cout << "Transpose of cube:\n" << cubeOfMatrix.transpose();

    return 0;
} catch (std::runtime_error& re) {
    std::cout << "Exception occurred:\t" << re.what() << "\n";
}