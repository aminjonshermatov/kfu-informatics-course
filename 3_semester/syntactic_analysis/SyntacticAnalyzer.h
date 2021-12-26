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
    explicit SyntacticAnalyzer(int identifierLen);
    SyntacticAnalyzer(int identifierLen, Logger* logger);
    SyntacticAnalyzer(int identifierLen, Logger* logger, const uMapChI& customPriority);
    ~SyntacticAnalyzer();

    static uMapChI operationsPriority;

    uMapVar<T> analyse(std::istream* in);
    void setLogger(Logger* logger);
private:
    const int _identifierLen;
    Logger* _logger;
    uMapVar<T> _vars;
    str _lastInsertedKeyVar;
    Stack<T> _valueStack;
    Stack<char> _operationsStack;

    void computeLast();
    void computeStack();
    void computeStack(char ch);
    str removeWhiteSpaces(std::istream*);
    void clearData();
};


template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen)
: _identifierLen(identifierLen)
, _logger(new Logger(&std::cout)) { }

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen, Logger *logger)
: _identifierLen(identifierLen)
, _logger(logger) { }

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen, Logger* logger, const uMapChI& customPriority)
: _identifierLen(identifierLen)
, _logger(new Logger(&std::cout)) {
    SyntacticAnalyzer<T>::operationsPriority = customPriority;
}

template<class T>
SyntacticAnalyzer<T>::~SyntacticAnalyzer() {
    this->clearData();
}

template<class T>
uMapChI SyntacticAnalyzer<T>::operationsPriority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

template<class T>
uMapVar<T> SyntacticAnalyzer<T>::analyse(std::istream* in) {
    this->clearData();
    // var1 := 1 + -3 + 4; => var1 = 2
    // var2 := 3 * 2 + var1; => var2 = 8;

    ui line = 1, charAt = 0;
    short int curNumberSign = 1;
    str cur;
    bool isBeforeAssigning = true;
    int openBrackenCount = 0;

    str removedWs = this->removeWhiteSpaces(in);

    (*this->_logger) << '\n' << "Given expression:" << '\t' << removedWs << '\n';

    for (int i = 0; i < removedWs.size(); ++i) {
        charAt++;
        const char ch = removedWs[i];

        if (isBeforeAssigning) {
            if (utils::isString(ch)) {
                if (cur.size() == this->_identifierLen)
                    (*this->_logger)(Logger::ERROR, line, charAt) << "Identifier length is great than limit expected " << this->_identifierLen << '\n';

                cur.push_back(ch);
            } else if (utils::isNumber(ch)) {
                cur.push_back(ch);
                (*this->_logger)(Logger::ERROR, line, charAt) << "Identifier should not contain number" << '\n';
            } else if (i + 1 < removedWs.size() && removedWs[i] == ':' && removedWs[i + 1] == '=') {
                if (!cur.empty()) {
                    this->_vars.insert({cur, NULL});
                    this->_lastInsertedKeyVar = cur;
                    cur.clear();
                    isBeforeAssigning = false;
                    ++i;
                    ++charAt;
                } else
                    (*this->_logger)(Logger::ERROR, line, charAt) << "Identifier must be non-empty string" << '\n';
            } else
                (*this->_logger)(Logger::ERROR, line, charAt) << "Unexpected character '" << ch << "' before equal symbol" << '\n';
        } else {
            if (utils::isArithOperation(ch)) {
                if (!cur.empty()) {
                    if (utils::isNumber(cur.front())) {
                        this->_valueStack.push_back(curNumberSign * utils::stoi(cur));
                        cur.clear();
                        curNumberSign = 1;
                    }
                    else {
                        if (this->_vars.count(cur) == 0)
                            (*this->_logger)(Logger::ERROR, line, charAt) << "Undefined identifier" << '\n';
                        else {
                            this->_valueStack.push_back(curNumberSign * this->_vars[cur]);
                            cur.clear();
                            curNumberSign = 1;
                        }
                    }
                }

                if (this->_valueStack.getSize() == this->_operationsStack.getSize() - openBrackenCount) {
                    if (utils::isNumberSign(ch))
                        curNumberSign = ch == '+' ? 1 : -1;
                    else
                        (*this->_logger)(Logger::WARNING, line, charAt) << "Unexpected character " << ch << '\n';
                } else {
                    this->computeStack(ch);
                    this->_operationsStack.push_back(ch);
                }
            } else if (utils::isNumber(ch) || utils::isString(ch))
                cur.push_back(ch);
            else if (ch == '(') {
                this->_operationsStack.push_back('(');
                ++openBrackenCount;
            }
            else if (ch == ')') {
                if (!cur.empty()) {
                    if (utils::isNumber(cur.front())) {
                        this->_valueStack.push_back(curNumberSign * utils::stoi(cur));
                        cur.clear();
                        curNumberSign = 1;
                    }
                    else {
                        if (this->_vars.count(cur) == 0)
                            (*this->_logger)(Logger::ERROR, line, charAt) << "Undefined identifier" << '\n';
                        else {
                            this->_valueStack.push_back(curNumberSign * this->_vars[cur]);
                            cur.clear();
                            curNumberSign = 1;
                        }
                    }
                }

                while (this->_operationsStack.getSize() > 0 && this->_operationsStack.top() != '(')
                    this->computeLast();

                if (this->_operationsStack.top() == '(')
                    this->_operationsStack.pop();
                else
                    (*this->_logger)(Logger::ERROR, line, charAt) << "Occurred close bracket without open" << '\n';
            }

            if (ch == ';' || ch == '\n') {
                if (!cur.empty()) {
                    if (utils::isNumber(cur.front())) {
                        this->_valueStack.push_back(curNumberSign * utils::stoi(cur));
                        cur.clear();
                        curNumberSign = 1;
                    }
                    else {
                        auto find = this->_vars.find(cur);

                        if (find == this->_vars.end())
                            (*this->_logger)(Logger::ERROR, line, charAt) << "Undefined identifier" << '\n';
                        else {
                            this->_valueStack.push_back(curNumberSign * this->_vars[cur]);
                            cur.clear();
                            curNumberSign = 1;
                        }
                    }
                }

                this->computeStack();
                this->_vars[this->_lastInsertedKeyVar] = this->_valueStack.pop();
                line++;
                charAt = 0;
                cur.clear();
                isBeforeAssigning = true;
            }
        }
    }

    return this->_vars;
}

template<class T>
void SyntacticAnalyzer<T>::computeLast() {
    if (this->_valueStack.getSize() >= 2 && this->_operationsStack.getSize() >= 1) {
        T last = this->_valueStack.pop();
        T preLast = this->_valueStack.pop();
        const char operation = this->_operationsStack.pop();

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

        this->_valueStack.push_back(result);
    }
}

template<class T>
void SyntacticAnalyzer<T>::computeStack() {
    while (this->_operationsStack.getSize() > 0)
        this->computeLast();
}

template<class T>
void SyntacticAnalyzer<T>::computeStack(char ch) {
    while (this->_operationsStack.getSize() > 0 && SyntacticAnalyzer<T>::operationsPriority[ch] <= SyntacticAnalyzer<T>::operationsPriority[this->_operationsStack.top()])
        this->computeLast();
}

template<class T>
str SyntacticAnalyzer<T>::removeWhiteSpaces(std::istream* in) {
    str removedWhiteSpace;

    char ch;
    while (*in >> ch) {
        if (ch == ' ')
            continue;

        removedWhiteSpace.push_back(ch);
    }

    if (removedWhiteSpace.back() != ';' && removedWhiteSpace.back() != '\n')
        removedWhiteSpace.push_back(';');

    return removedWhiteSpace;
}

template<typename T>
void SyntacticAnalyzer<T>::clearData() {
    this->_valueStack.clear();
    this->_operationsStack.clear();
    this->_vars.clear();
}

template<class T>
void SyntacticAnalyzer<T>::setLogger(Logger* logger) {
    this->_logger = logger;
}

#endif //INFORMATICS_SYNTACTICANALYZER_H
