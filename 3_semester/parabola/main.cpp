//
// Created by aminjonshermatov on 9/20/2021.
//

#include "Parabola.h"

int main() try {
    auto* p1 = new Parabola(1,0,0);
    std::cout << *p1;
    IRoot root1 = p1->intersectionXAxis();
    std::cout << "x_1: " << root1.first << ", x_2: " << root1.second << "\n";

    auto* p2 = new Parabola(1, -5, 6);
    std::cout << *p2;
    IRoot root2 = p2->intersectionXAxis();
    std::cout << "x_1: " << root2.first << ", x_2: " << root2.second << "\n";

    auto* p3 = new Parabola(1,1,2);
    std::cout << *p3;
    IRoot root3 = p3->intersectionXAxis();
    std::cout << "x_1: " << root3.first << ", x_2: " << root3.second << "\n";
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
};
