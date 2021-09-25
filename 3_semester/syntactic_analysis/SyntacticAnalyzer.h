//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_SYNTACTICANALYZER_H
#define INFORMATICS_SYNTACTICANALYZER_H

#include "Stack.h"
#include "Logger.h"
#include "sharedModule.h"
#include "utils.h"

template<class T>
class SyntacticAnalyzer {
public:
    SyntacticAnalyzer(int identifierLen);
    SyntacticAnalyzer(int identifierLen, Logger* logger);
    SyntacticAnalyzer(int identifierLen, Logger* logger, const mapChI& customPriority);
    ~SyntacticAnalyzer();

    static mapChI operationsPriority;

    mapVar<T> analyse(const str& code);
private:
    const int identifierLen;
    Logger* logger;
    mapVar<T> vars;
    str lastInsertedKeyVar;
    Stack<T> valueStack;
    Stack<char> operationsStack;

    void computeLast();
};


#endif //INFORMATICS_SYNTACTICANALYZER_H
