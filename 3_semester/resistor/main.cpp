//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Resistor.h"

int main() try {
    auto* p1 = new Resistor(1, 2);
    std::cout << *p1 << "\n";

    auto* p2 = new Resistor(3, 4);
    std::cout << *p2 << "\n";

    auto* p_parallel = p1->parallel(p2);
    std::cout << "parallel: " << *p_parallel << "\n";

    auto* p_consis = p1->consistently(p2);
    std::cout << "consistently: " << *p_consis << "\n";
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
};

