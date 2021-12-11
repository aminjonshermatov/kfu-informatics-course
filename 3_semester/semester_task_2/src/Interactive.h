//
// Created by aminjonshermatov on 12/10/2021.
//

#include "bits/stdc++.h"
#include "regex"

using namespace std;

class InterActive {
    using variant_t_ = variant<Exponent<int>*, Exponent<double>*, Exponent<float>*, Exponent<long>*,
                               Polynomial<int>*, Polynomial<double>*, Polynomial<float>*, Polynomial<long>*>;

    // stores (valName, anyClass)
    unordered_map<string, variant_t_> storage_;
    stringstream commands_;

    // \new foo exp int 1 2 3
    // \new bar pol double 0
    const regex newReg_{R"(\\new (\w+) (exp|pol) (int|double|float|long) (.+))"};

    // \expression a + b
    // \expression a - b
    // \expression a * b
    // \expression a += b
    // \expression a -= b
    // \expression a *= b
    // \expression a == b
    // \expression a != b
    const regex expReg_{R"(\\expression (\w+) (\+|\-|\*|/|\+=|\-=|\*=|/=|==|!=) (\w+))"};

    // \inverse a
    const regex invReg_{R"(\\inverse (\w+))"};

    // \calc a(0)
    const regex calcReg_{R"(\\calc (\w+)\(([0-9].?[0-9]*)\))"};

    // \print a
    const regex printReg_{R"(\\print (\w+))"};

    // \exit
    const regex exitReg_{R"(\\exit)"};

    enum ClassType { EXPONENT, POLYNOMIAL };
    template<typename T>
    void createNew(string& varName,
                   vector<T> parameters,
                   ClassType type) {
        switch (type) {
            case EXPONENT:
                if (parameters.size() == 1) storage_[varName] = new Exponent<T>(*parameters.begin());
                else storage_[varName] = new Exponent<T>(parameters);
                break;
            case POLYNOMIAL:
                if (parameters.size() == 1) storage_[varName] = new Polynomial<T>(*parameters.begin());
                else storage_[varName] = new Polynomial<T>(parameters);
                break;
        }

    }

    template<typename T>
    inline vector<T> read_list_(const string& list) {
        istringstream iss(list);
        vector<T> res;
        T temp;
        while (iss >> temp) res.push_back(temp);

        return res;
    }

public:
    InterActive() {
        commands_ << "Commands:" << '\n'
                 << '\t' << R"(Enter '\new {varName} {exp|pol} {template} {...parameters}' - create/store variable.)" << '\n'
                 << '\t' << '\t' << R"(- {varName} - unique key name of variable.)" << '\n'
                 << '\t' << '\t' << R"(- {exp|pol} - indicates type of variable Exponent either Polynomial/)" << '\n'
                 << '\t' << '\t' << R"(- {template} - template type of {int|double|float|long}.)" << '\n'
                 << '\t' << '\t' << R"(- {...parameters} - constructor parameters.)" << '\n'
                 << '\t' << R"(Enter '\expression {varName1} {operation} {varName2}' - to do some computation.)" << '\n'
                 << '\t' << '\t' << R"(- {varName1} - left hand side of expression. Note varName1 must be created before use.)" << '\n'
                 << '\t' << '\t' << R"(- {operation})" << '\n'
                 << '\t' << '\t' << '\t' << R"(- for Exponent it can be {'*', '/', '*=', '/=', '==', '!='}.)" << '\n'
                 << '\t' << '\t' << '\t' << R"(- for Polynomial it can be {'+', '-', '*', '+=', '-=', '*=', '==', '!='}.)" << '\n'
                 << '\t' << '\t' << R"(- {varName2} - right hand side of expression. Note varName2 must be created before use.)" << '\n'
                 << '\t' << R"(Enter '\inverse {expVarName}' - to inverse exponent variable.)" << '\n'
                 << '\t' << '\t' << R"(- {expVarName} - name of variable that before created.)" << '\n'
                 << '\t' << R"(Enter '\calc {expVarName}({point})' - calculate expression value at given point.)" << '\n'
                 << '\t' << '\t' << R"(- {expVarName} - name of variable that before created.)" << '\n'
                 << '\t' << '\t' << R"(- {point} - point at which the value will calculated.)" << '\n'
                 << '\t' << R"(Enter '\print {expVarName}' to print variable.)" << '\n'
                 << '\t' << '\t' << R"(- {expVarName} - name of variable that before created.)" << '\n'
                 << '\t' << "Enter '\\exit' - to exit from program." << '\n';
    }

    void run() {

        cout << commands_.str() << '\n';

        while (true) {
            string line;
            getline(cin, line);

            smatch match;
            if (regex_search(line, match, newReg_)) {
                string varName = match[1];
                string classType = match[2];
                string templateType = match[3];

                if (classType == "exp") {
                    if (templateType == "int") createNew<int>(varName, read_list_<int>(match.str(4)), ClassType::EXPONENT);
                    if (templateType == "double") createNew<double>(varName, read_list_<double>(match.str(4)), ClassType::EXPONENT);
                    if (templateType == "float") createNew<float>(varName, read_list_<float>(match.str(4)), ClassType::EXPONENT);
                    if (templateType == "long") createNew<long>(varName, read_list_<long>(match.str(4)), ClassType::EXPONENT);
                } else {
                    if (templateType == "int") createNew<int>(varName, read_list_<int>(match.str(4)), ClassType::POLYNOMIAL);
                    if (templateType == "double") createNew<double>(varName, read_list_<double>(match.str(4)), ClassType::POLYNOMIAL);
                    if (templateType == "float") createNew<float>(varName, read_list_<float>(match.str(4)), ClassType::POLYNOMIAL);
                    if (templateType == "long") createNew<long>(varName, read_list_<long>(match.str(4)), ClassType::POLYNOMIAL);
                }

                cout << varName << " successfully created" << '\n';
            } else if (regex_search(line, match, expReg_)) {
                // expression
                bool flag = false;
                for (const auto& i : {1, 3}) {
                    if (storage_.count(match.str(i)) == 0) {
                        cout << "Before you haven't created variable with name " << match.str(i) << '\n';
                        flag = true;
                    }
                }
                if (flag) continue;

                if (storage_[match.str(1)].index() != storage_[match.str(3)].index()) {
                    cout << match.str(1) << " and " << match.str(3) << R"( types doesn't match)" << '\n';
                    continue;
                }

                switch (storage_[match.str(1)].index()) {
                    // Exponent<int>*
                    case 0: {
                        Exponent<int> *a = get<0>(storage_[match.str(1)]),
                                      *b = get<0>(storage_[match.str(3)]);

                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "/") {
                            cout << *a / *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "/=") {
                            *a /= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Exponent<double>*
                    case 1: {
                        Exponent<double> *a = get<1>(storage_[match.str(1)]),
                                         *b = get<1>(storage_[match.str(3)]);

                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "/") {
                            cout << *a / *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "/=") {
                            *a /= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Exponent<float>*
                    case 2: {
                        Exponent<float> *a = get<2>(storage_[match.str(1)]),
                                        *b = get<2>(storage_[match.str(3)]);

                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "/") {
                            cout << *a / *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "/=") {
                            *a /= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Exponent<long>*
                    case 3: {
                        Exponent<long> *a = get<3>(storage_[match.str(1)]),
                                       *b = get<3>(storage_[match.str(3)]);

                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "/") {
                            cout << *a / *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "/=") {
                            *a /= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Polynomial<int>*
                    case 4: {
                        Polynomial<int> *a = get<4>(storage_[match.str(1)]),
                                        *b = get<4>(storage_[match.str(3)]);

                        if (match.str(2) == "+") {
                            cout << *a + *b << '\n';
                        } else if (match.str(2) == "-") {
                            cout << *a - *b << '\n';
                        }
                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "+=") {
                            *a += *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "-=") {
                            *a -= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Polynomial<double>*
                    case 5: {
                        Polynomial<double> *a = get<5>(storage_[match.str(1)]),
                                           *b = get<5>(storage_[match.str(3)]);

                        if (match.str(2) == "+") {
                            cout << *a + *b << '\n';
                        } else if (match.str(2) == "-") {
                            cout << *a - *b << '\n';
                        }
                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "+=") {
                            *a += *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "-=") {
                            *a -= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Polynomial<float>*
                    case 6: {
                        Polynomial<float> *a = get<6>(storage_[match.str(1)]),
                                          *b = get<6>(storage_[match.str(3)]);

                        if (match.str(2) == "+") {
                            cout << *a + *b << '\n';
                        } else if (match.str(2) == "-") {
                            cout << *a - *b << '\n';
                        }
                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "+=") {
                            *a += *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "-=") {
                            *a -= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                    // Polynomial<long>*
                    case 7: {
                        Polynomial<long> *a = get<7>(storage_[match.str(1)]),
                                         *b = get<7>(storage_[match.str(3)]);

                        if (match.str(2) == "+") {
                            cout << *a + *b << '\n';
                        } else if (match.str(2) == "-") {
                            cout << *a - *b << '\n';
                        }
                        if (match.str(2) == "*") {
                            cout << *a * *b << '\n';
                        } else if (match.str(2) == "==") {
                            cout << (*a == *b ? "Equal" : "Not equal") << '\n';
                        } else if (match.str(2) == "!=") {
                            cout << (*a != *b ? "Not equal" : "Equal") << '\n';
                        } else if (match.str(2) == "+=") {
                            *a += *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "-=") {
                            *a -= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else if (match.str(2) == "*=") {
                            *a *= *b;
                            storage_[match.str(1)] = a;
                            cout << *a << '\n';
                        } else {
                            cout << "Invalid operation for this type" << '\n';
                        }
                        break;
                    }
                }
            } else if (regex_search(line, match, invReg_)) {
                // inverse
                if (storage_.count(match.str(1)) == 0) {
                    cout << "Before you haven't created variable with name " << match.str(1) << '\n';
                    continue;
                } else {
                    visit([](auto&& arg) {
                        using T = decay_t<decltype(arg)>;

                        if constexpr (is_same_v<T, Exponent<int>*>
                                    || is_same_v<T, Exponent<double>*>
                                    || is_same_v<T, Exponent<float>*>
                                    || is_same_v<T, Exponent<long>*>) {
                            cout << arg->inverse() << '\n';
                        } else {
                            cout << "Invalid variable type polynomial cannot be inversed" << '\n';
                        }
                    }, storage_[match.str(1)]);
                }
            } else if (regex_search(line, match, calcReg_)) {
                // calculate
                if (storage_.count(match.str(1)) == 0) {
                    cout << "Before you haven't created variable with name " << match.str(1) << '\n';
                    continue;
                } else {
                    visit([&match](auto&& arg) {
                        using T = decay_t<decltype(arg)>;

                        if constexpr (is_same_v<T, Exponent<int>*> || is_same_v<T, Polynomial<int>*>) {
                            cout << (*arg)(stoi(match.str(2))) << '\n';
                        } else if (is_same_v<T, Exponent<double>*> || is_same_v<T, Polynomial<double>*>) {
                            cout << (*arg)(stod(match.str(2))) << '\n';
                        } else if (is_same_v<T, Exponent<float>*> || is_same_v<T, Polynomial<float>*>) {
                            cout << (*arg)(stof(match.str(2))) << '\n';
                        } else if (is_same_v<T, Exponent<long>*> || is_same_v<T, Polynomial<long>*>) {
                            cout << (*arg)(stol(match.str(2))) << '\n';
                        } else {
                            cout << "Invalid variable type" << '\n';
                        }
                    }, storage_[match.str(1)]);
                }
            } else if (regex_search(line, match, printReg_)) {
                if (storage_.count(match.str(1)) == 0) {
                    cout << "Before you haven't created variable with name " << match.str(1) << '\n';
                    continue;
                } else {
                    visit([](auto&& arg){ cout << *arg << '\n'; }, storage_[match.str(1)]);
                    continue;
                }
            } else if (regex_search(line, match, exitReg_)) {
                cout << "Bye!" << '\n';
                break;
            } else {
                cout << "Unknown command: " << line << '\n'
                     << commands_.str();
            }
        }
    }
};
