//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_UTILS_H
#define INFORMATICS_UTILS_H

#include "sharedModule.h"

namespace utils {
    bool isNumber(const char&);
    bool isString(const char&);
    ui fromCharToInt(const char&);
    ui stoi(const str&);
    static sCh arithOperations = {'+', '-', '*', '/'};
    bool isArithOperation(char);
    bool isNumberSign(char);
};


#endif //INFORMATICS_UTILS_H
