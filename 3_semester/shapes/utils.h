//
// Created by aminjonshermatov on 11/10/2021.
//

#ifndef INFORMATICS_UTILS_H
#define INFORMATICS_UTILS_H

namespace utils {
    bool isTriangle(size_t a, size_t b, size_t c) {
        return a >= 0 && b >= 0 && c >= 0 && a + b > c && a + c > b && b + c > a;
    }
}

#endif //INFORMATICS_UTILS_H
