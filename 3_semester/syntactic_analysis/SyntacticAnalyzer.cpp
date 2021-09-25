//
// Created by aminjonshermatov on 9/24/2021.
//

#include "SyntacticAnalyzer.h"

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen)
    : identifierLen(identifierLen), logger(new Logger(&std::cout)) { }

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen, Logger *logger)
    : identifierLen(identifierLen), logger(logger) { }

template<class T>
SyntacticAnalyzer<T>::SyntacticAnalyzer(int identifierLen, Logger* logger, const mapChI& customPriority)
    : identifierLen(identifierLen), logger(new Logger(&std::cout)) {
    SyntacticAnalyzer<T>::operationsPriority = customPriority;
}

template<class T>
SyntacticAnalyzer<T>::~SyntacticAnalyzer() {
    this->computationStack.clear();
    this->operationsStack.clear();
}

template<class T>
mapChI SyntacticAnalyzer<T>::operationsPriority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };

template<class T>
mapVar<T> SyntacticAnalyzer<T>::analyse(const str& code) {
    // var1 := 1 + -3 + 4; => var1 = 2
    // var2 := 3 * 2 + var1; => var2 = 8;

    ui line = 0, charAt = 0;
    short int curNumberSign = 1;
    str cur;
    bool isBeforeAssigning = true;

    for (int i = 0; i < code.size(); ++i) {
        charAt++;
        const char ch = code[i];

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
                (*this->logger)(Logger::ERROR, line, charAt) << "Identifier should not contain number";
            }
            else if (i + 1 < code.size() && code[i] == ':' && code[i + 1] == '=') {
                if (!cur.empty()) {
                    this->vars.insert({cur, NULL});
                    this->lastInsertedKeyVar = cur;
                    cur.clear();
                    isBeforeAssigning = false;
                } else
                    (*this->logger)(Logger::ERROR, line, charAt) << "Identifier must be non-empty string\n";
            }
        } else {
            if (utils::isArithOperation(ch)) {
                if (!cur.empty()) {
                    if (utils::isNumber(cur.front())) {
                        this->valueStack.push_back(curNumberSign * utils::stoi(cur));
                        curNumberSign = 1;
                    }
                    else {
                        auto find = this->vars.find(cur);

                        if (find == this->vars.end())
                            (*this->logger)(Logger::ERROR, line, charAt) << "Undefined identifier\n";
                        else {
                            this->valueStack.push_back(curNumberSign * this->vars[cur]);
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
                    while (SyntacticAnalyzer<T>::operationsPriority[ch] >= SyntacticAnalyzer<T>::operationsPriority[this->operationsStack.top()])
                        this->computeLast();

                    this->operationsStack.push_back(ch);
                }
            } else if (utils::isNumber(ch) || utils::isString(ch))
                cur.push_back(ch);

            if (ch == ';' || ch == '\n') {
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

        T result;

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
