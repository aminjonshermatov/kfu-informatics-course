//
// Created by aminjonshermatov on 19.09.2021.
//

#include <iostream>
#include "StraightLine.h"

int main() try {
    auto* sl1 = new StraightLine(1, 2);
    auto* sl2 = new StraightLine(1, 2);

    std::cout << (*sl1 == *sl2) << "\n";

    std::cout << *sl1 << "\n";
    sl1->parallel_transfer(4);
    std::cout << *sl1 << "\n";

    std::cout << *sl2 << "\n";
    sl2->rotate_line(3);
    std::cout << *sl2 << "\n";

    std::cout << (*sl1 == *sl2) << "\n";

    pDD roots = sl1->lines_intersection(sl2);
    std::cout << "x_1: " << roots.first << ", x_2: " << roots.second << "\n";
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
}