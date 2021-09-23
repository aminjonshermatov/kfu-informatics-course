//
// Created by aminjonshermatov on 9/23/2021.
//

#include "utils.h"

int utils::random(pii p) {
    static bool first = true;

    if (first) {
        srand(std::time(nullptr) );
        first = false;
    }

    return p.first + rand() % (p.second - p.first + 1);
}
