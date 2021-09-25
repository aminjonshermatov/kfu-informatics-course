//
// Created by aminjonshermatov on 9/24/2021.
//

#include "SyntacticAnalyzer.h"

int main() try {
    std::cout << "hello\n";

    auto* logger = new Logger(&std::cout);

    auto* sa = new SyntacticAnalyzer<int>(1, logger);

//    auto vars = sa->analyse("x:=1+2;y=3*2");
//
//    for (auto& var : vars)
//        std::cout << var.first << " : " << var.second << "\n";

    return 0;
} catch (std::exception& ex) {
    std::cout << ex.what() << "\n";
};
