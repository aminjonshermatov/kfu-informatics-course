//
// Created by aminjonshermatov on 9/19/2021.
//

#include <iostream>
#include "ComplexNumber.h"

int main() try {
    auto* mc1 = new ComplexNumber(1, 2);
    auto* mc2 = new ComplexNumber(3, 4);

    auto* add1 = mc1->addition(mc2); // (1 + i2)+(3 + i4) = 4 + 6i
    std::cout << "add1:\t" << *add1 << "\n";

    auto* add2 = *mc1 + mc2;
    std::cout << "add2:\t" << *add2 << "\n";


    auto* sub1 = mc1->subtraction(mc2); // (1 + i2)-(3 + i4) = -2 + -2i
    std::cout << "sub1:\t" << *sub1 << "\n";

    auto* sub2 = *mc1 - mc2;
    std::cout << "sub2:\t" << *sub2 << "\n";


    auto* mul1 = mc1->multiplication(mc2); // (1 + i2)*(3 + i4) = 3 - 8 + i(6 + 4) = -5 + i10
    std::cout << "mul1:\t" << *mul1 << "\n";

    auto* mul2 = *mc1 * mc2;
    std::cout << "mul2:\t" << *mul2 << "\n";


    auto* div1 = mc1->division(mc2); // (1 + i2)/(3 + i4) = (1 + i2)(3 - i4)/(3**2 + 4**2) = (3 + 8)/(3**2 + 4**2) + i(2*3 - 1*4)/(3**2 + 4**2) = 11/25 + i2/25 = 0.44 + i0.08
    std::cout << "div1:\t" << *div1 << "\n";

    auto* div2 = *mc1 / mc2;
    std::cout << "div2:\t" << *div2 << "\n";
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
}
