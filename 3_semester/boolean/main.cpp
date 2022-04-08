//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Boolean.h"

int main() try {
    bool data1[4] = { false, false, true, true };
    auto* mb1 = new Boolean(data1);

    bool data2[4] = { false, true, false, true };
    auto* mb2 = new Boolean(data2);

    auto* mb3 = mb1->conjunction(mb2);
    auto* mb4 = mb1->disjunction(mb2);

    std::cout << *mb1;
    std::cout << *mb2;
    std::cout << *mb3;
    std::cout << *mb4;
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
}
