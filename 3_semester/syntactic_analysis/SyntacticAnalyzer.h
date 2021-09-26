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
    SyntacticAnalyzer(int identifierLen, Logger* logger, const uMapChI& customPriority);
    ~SyntacticAnalyzer();

    static uMapChI operationsPriority;

    uMapVar<T> analyse(const str& code);
private:
    const int identifierLen;
    Logger* logger;
    uMapVar<T> vars;
    str lastInsertedKeyVar;
    Stack<T> valueStack;
    Stack<char> operationsStack;

    void computeLast();
    str removeWhiteSpaces(const str* givenStr);
};


template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen)
        : identifierLen(identifierLen), logger(new Logger(&std::cout)) { }

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen, Logger *logger)
        : identifierLen(identifierLen), logger(logger) { }

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen, Logger* logger, const uMapChI& customPriority)
        : identifierLen(identifierLen), logger(new Logger(&std::cout)) {
    SyntacticAnalyzer<T>::operationsPriority = customPriority;
}

template<class T>
SyntacticAnalyzer<T>::~SyntacticAnalyzer() {
    this->computationStack.clear();
    this->operationsStack.clear();
}

template<class T>
uMapChI SyntacticAnalyzer<T>::operationsPriority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

template<class T>
uMapVar<T> SyntacticAnalyzer<T>::analyse(const str& code) {
    // var1 := 1 + -3 + 4; => var1 = 2
    // var2 := 3 * 2 + var1; => var2 = 8;

    (*this->logger) << "Given expression:\t" << code << "\n";

    ui line = 1, charAt = 0;
    short int curNumberSign = 1;
    str cur;
    bool isBeforeAssigning = true;

    str removedWs = this->removeWhiteSpaces(&code);

    for (int i = 0; i < removedWs.size(); ++i) {
        charAt++;
        const char ch = removedWs[i];

        if (ch == ' ')
            continue;

        if (isBeforeAssigning) {
            if (utils::isString(ch)) {
                if (cur.size() == this->identifierLen)
                    (*this->logger)(Logger::ERROR, line, charAt) << "Identifier length is great than limit expected " << this->identifierLen << "\n";

                cur.push_back(ch);
            }
            else if (utils::isNumber(ch)) {
                cur.push_back(ch);
                (*this->logger)(Logger::ERROR, line, charAt) << "Identifier should not contain number\n";
            }
            else if (i + 1 < removedWs.size() && removedWs[i] == ':' && removedWs[i + 1] == '=') {
                if (!cur.empty()) {
                    this->vars.insert({cur, NULL});
                    this->lastInsertedKeyVar = cur;
                    cur.clear();
                    isBeforeAssigning = false;
                    ++i;
                    ++charAt;
                } else
                    (*this->logger)(Logger::ERROR, line, charAt) << "Identifier must be non-empty string\n";
            } else
                (*this->logger)(Logger::ERROR, line, charAt) << "Unexpected character '" << ch << "' before equal symbol\n";
        } else {
            if (utils::isArithOperation(ch)) {
                if (!cur.empty()) {
                    if (utils::isNumber(cur.front())) {
                        this->valueStack.push_back(curNumberSign * utils::stoi(cur));
                        cur.clear();
                        curNumberSign = 1;
                    }
                    else {
                        auto find = this->vars.find(cur);

                        if (find == this->vars.end())
                            (*this->logger)(Logger::ERROR, line, charAt) << "Undefined identifier\n";
                        else {
                            this->valueStack.push_back(curNumberSign * find->second);
                            cur.clear();
                            curNumberSign = 1;
                        }
                    }
                }

                if (this->valueStack.getSize() == this->operationsStack.getSize()) {
                    if (utils::isNumberSign(ch))
                        curNumberSign = ch == '+' ? 1 : -1;
                    else
                        (*this->logger)(Logger::WARNING, line, charAt) << "Unexpected character " << ch << "\n";
                } else {
                    while (this->operationsStack.getSize() > 0 && SyntacticAnalyzer<T>::operationsPriority[ch] >= SyntacticAnalyzer<T>::operationsPriority[this->operationsStack.top()])
                        this->computeLast();

                    this->operationsStack.push_back(ch);
                }
            } else if (utils::isNumber(ch) || utils::isString(ch))
                cur.push_back(ch);

            if (ch == ';' || ch == '\n') {
                if (!cur.empty()) {
                    if (utils::isNumber(cur.front())) {
                        this->valueStack.push_back(curNumberSign * utils::stoi(cur));
                        cur.clear();
                        curNumberSign = 1;
                    }
                    else {
                        auto find = this->vars.find(cur);

                        if (find == this->vars.end())
                            (*this->logger)(Logger::ERROR, line, charAt) << "Undefined identifier\n";
                        else {
                            this->valueStack.push_back(curNumberSign * this->vars[cur]);
                            cur.clear();
                            curNumberSign = 1;
                        }
                    }
                }

                this->computeLast();
                this->vars[this->lastInsertedKeyVar] = this->valueStack.pop();
                line++;
                charAt = 0;
                cur.clear();
                isBeforeAssigning = true;
            }
        }
    }

    return this->vars;
}

template<class T>
void SyntacticAnalyzer<T>::computeLast() {
    if (this->valueStack.getSize() >= 2 && this->operationsStack.getSize() >= 1) {
        T last = this->valueStack.pop();
        T preLast = this->valueStack.pop();
        const char operation = this->operationsStack.pop();

        T result = 0;

        switch (operation) {
            case '+':
                result = preLast + last;
                break;
            case '-':
                result = preLast - last;
                break;
            case '*':
                result = preLast * last;
                break;
            case '/':
                if (last == 0)
                    throw excep("Denominator must be non-zero.");

                result = preLast / last;
                break;
            default:
                break;
        }

        this->valueStack.push_back(result);
    }
}

template<class T>
str SyntacticAnalyzer<T>::removeWhiteSpaces(const str* givenStr) {
    str removedWhiteSpace;

    for (char i : *givenStr) {
        if (i == ' ')
            continue;

        removedWhiteSpace.push_back(i);
    }

    if (removedWhiteSpace.back() != ';' && removedWhiteSpace.back() != '\n')
        removedWhiteSpace.push_back(';');

    return removedWhiteSpace;
}


#endif //INFORMATICS_SYNTACTICANALYZER_H
