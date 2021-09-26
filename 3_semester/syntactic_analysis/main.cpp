//
// Created by aminjonshermatov on 9/24/2021.
//

#include "SyntacticAnalyzer.h"

int main() try {
    auto* logger = new Logger(&std::cout);

    auto* sa = new SyntacticAnalyzer<int>(1, logger);

    auto vars = sa->analyse("X:=+109;Y:=X--15700;A1:=X/Y;X:=A1++14810;");
    /*
     * Given expression:       X:=+109;Y:=X--15700;A1:=X/Y;X:=A1++14810;
     * [ERROR] line 3, character at 2: Identifier should not contain number
     * X : 14810
     * A1 : 0
     * Y : 15809
     * */

    for (auto& var : vars)
        std::cout << var.first << " : " << var.second << "\n";
} catch (std::exception& ex) {
    std::cout << "Exception occurred:\t" << ex.what() << "\n";
};
