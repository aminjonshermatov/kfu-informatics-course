//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_UTILS_H
#define INFORMATICS_UTILS_H

#include "sharedModule.h"

namespace utils {
    bool isNumber(const char& ch);
    bool isString(const char& ch);
    ui fromCharToInt(const char& ch);
    ui stoi(const str& s);
    static sCh arithOperations = {'+', '-', '*', '/'};
    bool isArithOperation(const char ch);
    bool isNumberSign(const char ch);
};


#endif //INFORMATICS_UTILS_H
