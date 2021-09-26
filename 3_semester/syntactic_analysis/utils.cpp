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

ui utils::fromCharToInt(const char &ch) {
    if (!utils::isNumber(ch))
        throw excep("Couldn't convert non-int char to int");

    return (int)ch - 48;
}

ui utils::stoi(const str& s) {
    // return std::atoi(s.c_str());

    ui res = 0;

    for (auto& ch : s) {
        res *= 10;
        res += utils::fromCharToInt(ch);
    }

    return res;
}

bool utils::isArithOperation(char ch) {
    return utils::arithOperations.find(ch) != utils::arithOperations.end();
}

bool utils::isNumberSign(char ch) {
    return ch == '+' || ch == '-';
}
