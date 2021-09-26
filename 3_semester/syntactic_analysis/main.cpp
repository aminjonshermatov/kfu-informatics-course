//
// Created by aminjonshermatov on 9/24/2021.
//

#include "SyntacticAnalyzer.h"

int main() try {
    auto* logger = new Logger(&std::cout);

    auto* sa = new SyntacticAnalyzer<int>(1, logger);

    auto vars1 = sa->analyse("X:=+109;Y:=X--15700;A1:=X/Y;X:=A1++14810;");
    /*
     * Given expression:       X:=+109;Y:=X--15700;A1:=X/Y;X:=A1++14810;
     * [ERROR] line 3, character at 2: Identifier should not contain number
     * X : 14810
     * A1 : 0
     * Y : 15809
     * */

    for (auto& var : vars1)
        *logger << var.first << " : " << var.second << "\n";

    auto vars2 = sa->analyse("x:=1+2*3+4-5*6+7");
    /*
     * Given expression:       x:=1+2*3+4-5*6+7
     * x : -12
     * */

    for (auto& var : vars2)
        *logger << var.first << " : " << var.second << "\n";

    auto vars3 = sa->analyse("x:=1+2*(2*(3-1*2)+4)*3+7");
    /*
     * Given expression:       x:=1+2*(2*(3-1*2)+4)*3+7
     * x : 44
     * */

    for (auto& var : vars3)
        *logger << var.first << " : " << var.second << "\n";

    auto vars4 = sa->analyse("x:=1+2*(2*3+4)*3+7;y:=2*x-(x+2*3)");
    /*
     * Given expression:       x:=1+2*(2*3+4)*3+7;y:=2*x-(x+2*3)
     * x : 68
     * y : 62
     * */

    for (auto& var : vars4)
        *logger << var.first << " : " << var.second << "\n";
} catch (std::exception& ex) {
    std::cout << "Exception occurred:\t" << ex.what() << "\n";
};
