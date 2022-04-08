//
// Created by aminjonshermatov on 9/26/2021.
//

#include "BigInt.h"

int main() {
    auto* a = new BigInt(1, 2);
    auto* b = new BigInt(3, 4);

    std::cout << "a:\t" << *a << "\n";
    std::cout << "b:\t" << *b << "\n";

    std::cout << "a + b:\t" << *(*a + b) << "\n";
    std::cout << "a - b:\t" << *(*a - b) << "\n";
    std::cout << "a * b:\t" << *(*a * b) << "\n";
    std::cout << "a / b:\t" << *(*a / b) << "\n";

    std::cout << "a == b:\t" << (*a == b) << "\n";
    std::cout << "a != b:\t" << (*a != b) << "\n";
    std::cout << "a > b:\t" << (*a > b) << "\n";
    std::cout << "a >= b:\t" << (*a >= b) << "\n";
    std::cout << "a < b:\t" << (*a < b) << "\n";
    std::cout << "a <= b:\t" << (*a <= b) << "\n";
};
