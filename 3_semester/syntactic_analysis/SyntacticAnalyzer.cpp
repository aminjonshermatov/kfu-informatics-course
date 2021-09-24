//
// Created by aminjonshermatov on 9/24/2021.
//

#include "SyntacticAnalyzer.h"

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen)
    : identifierLen(identifierLen), state(0) { }

template<class T>
bool SyntacticAnalyzer<T>::analyse(const str& code) {
    bool result;

    for (auto& ch : code) {
    }

    return result;
}
