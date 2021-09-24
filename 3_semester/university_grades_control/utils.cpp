//
// Created by aminjonshermatov on 9/23/2021.
//

#include "utils.h"

int utils::random(pii p) {
    static bool isFirst = true;

    if (isFirst) {
        srand(std::time(nullptr) );
        isFirst = false;
    }

    return p.first + rand() % (p.second - p.first + 1);
}
