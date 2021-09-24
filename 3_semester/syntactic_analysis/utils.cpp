//
// Created by aminjonshermatov on 9/24/2021.
//

#include "utils.h"

bool utils::isNumber(const char &ch) {
    return ch >= '0' && ch <= '9';
};

bool utils::isString(const char &ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
};
