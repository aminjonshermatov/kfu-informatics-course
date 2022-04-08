//
// Created by aminjonshermatov on 19.09.2021.
//

#include <iostream>
#include <vector>
#include "RationalNumber.h"


#define pb(el) push_back(el)

#define TEST_RatioanalNumber true
#define TEST_ScalarMultiplication true
#define TEST_Matrix true

using RationalArray = std::vector<RationalNumber*>;
using RationalArray2D = std::vector<RationalArray>;

void fillMatrix(int h, int w, RationalArray2D& matrix);
void showMatrix(const RationalArray2D& matrix, const std::string& label);
void multiplyMatrix(const RationalArray2D& matrixA, const RationalArray2D& matrixB, RationalArray2D& matrixC);

int main() try {
    if (TEST_RatioanalNumber) {
        auto* mr1 = new RationalNumber(1, 2);
        auto* mr2 = new RationalNumber(3, 4);

        auto* mr3 = mr1->multiplication(mr2); // 1/2 * 3/4 = 3/8
        std::cout << *mr3 << "\n";

        mr3->addition(mr2); // 3/8 + 3/4 = 9/8
        std::cout << *mr3 << "\n";

        auto* mr4 = new RationalNumber(7, 8);
        mr4->addition(mr3); // 7/8 + 9/8 = 16/8 = 2
        std::cout << *mr4 << "\n";

        auto* mr5 = new RationalNumber(2, 1);
        auto* mr6 = mr1->multiplication(mr5); // 1/2 * 2/1 = 2/1 = 2
        std::cout << *mr6 << "\n";
    }

    if (TEST_ScalarMultiplication) {
        const int SIZE = 4;

        RationalArray vector1;
        RationalArray vector2;
        RationalArray scalarMult;

        for (int i = 0; i < SIZE; ++i) {
            vector1.pb(new RationalNumber(i + 1, i + 2));
            vector2.pb(new RationalNumber(i + 2, i + 3));
            scalarMult.pb(vector1[i]->multiplication(vector2[i]));
        }

        // vector1:		[{1/2},{2/3},{3,4},{4,5}]
        // vector2:		[{2/3},{3/4},{4,5},{5,6}]
        // scalarMult:	[{1/3},{1/2},{3,5},{2,3}]

        std::cout << "\n";
        for (auto& num : scalarMult)
            std::cout << *num << " ";
        std::cout << "\n";
    }

    if (TEST_Matrix) {
        RationalArray2D matrixA;
        fillMatrix(2, 3, matrixA);
        showMatrix(matrixA, "Matrix A");

        RationalArray2D matrixB;
        fillMatrix(3, 2, matrixB);
        showMatrix(matrixB, "Matrix B");

        RationalArray2D matrixC;
        multiplyMatrix(matrixA,matrixB,matrixC);
        showMatrix(matrixC, "Matrix C");
    }
}
catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
}

void fillMatrix(int h, int w, RationalArray2D& matrix) {
    for (int i = 0; i < h; ++i) {
        RationalArray matrixArr;

        for (int j = 0; j < w; ++j)
            matrixArr.pb(new RationalNumber(i + 1, j + 1));

        matrix.pb(matrixArr);
    }
};

void showMatrix(const RationalArray2D& matrix, const std::string& label) {
    std::cout << "\n" << label << ":\n";

    std::cout << "[\n";
    for (auto& row : matrix) {
        std::cout << "\t[";

        for (auto& el : row)
            std::cout << "\t" << *el;

        std::cout << "]\n";
    }

    std::cout << "\n]";
};

void multiplyMatrix(const RationalArray2D& matrixA, const RationalArray2D& matrixB, RationalArray2D& matrixC) {
    const unsigned int widthA = matrixA[0].size();
    const unsigned int heightA = matrixA.size();
    const unsigned int widthB = matrixB[0].size();
    const unsigned int heightB = matrixB.size();

    // check widthOfMatrixA != widthOfMatrixB
    if (widthA != heightB)
        throw std::runtime_error("Width of matrix A is not equal to height of matrix B");

    for (int i = 0; i < heightA; ++i) {
        RationalArray rowMatrixC;

        for (int j = 0; j < widthB; ++j) {
            auto* sum = new RationalNumber();

            for (int m = 0; m < widthA; ++m)
                sum->addition(matrixA[i][m]->multiplication(matrixB[m][j]));

            rowMatrixC.pb(sum);
        }

        matrixC.pb(rowMatrixC);
    }
};