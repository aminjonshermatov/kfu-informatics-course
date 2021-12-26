//
// Created by aminjonshermatov on 9/24/2021.
//

#include "SyntacticAnalyzer.h"

#define IS_INPUT_FROM_FILE true
#define IS_LOG_TO_FILE true

int main() try {
#if (IS_INPUT_FROM_FILE || IS_LOG_TO_FILE)
    const str baseUrl = "../3_semester/syntactic_analysis";
#endif
    Logger* logger;
#if IS_LOG_TO_FILE
    logger = new Logger(new std::ofstream(baseUrl + "/log.txt"));
#else
    logger = new Logger(&std::cout);
#endif

    auto* sa = new SyntacticAnalyzer<int>(1, logger);

#if IS_INPUT_FROM_FILE
    std::ifstream inData1(baseUrl + "/input1.txt");
#else
    std::istringstream inData1("X:=+109;Y:=X--15700;A1:=X/Y;X:=A1++14810;");
#endif

    auto vars1 = sa->analyse(&inData1);

#if IS_INPUT_FROM_FILE
    inData1.close();
#endif
    /*
     * Given expression:       X:=+109;Y:=X--15700;A1:=X/Y;X:=A1++14810;
     * [ERROR] line 3, character at 2: Identifier should not contain number
     * X : 14810
     * A1 : 0
     * Y : 15809
     * */

    for (auto& var : vars1)
        *logger << var.first << " : " << var.second << "\n";

#if IS_INPUT_FROM_FILE
    std::ifstream inData2(baseUrl + "/input2.txt");
#else
    std::istringstream inData2("x:=1+2*3)+4-5*6+7");
#endif

    auto vars2 = sa->analyse(&inData2);

#if IS_INPUT_FROM_FILE
    inData2.close();
#endif
    /*
     * Given expression:       x:=1+2*3)+4-5*6+7
     * [ERROR] line 1, character at 9: Occurred close bracket without open
     * x : -12
     * */

    for (auto& var : vars2)
        *logger << var.first << " : " << var.second << "\n";

#if IS_INPUT_FROM_FILE
    std::ifstream inData3(baseUrl + "/input3.txt");
#else
    std::istringstream inData3("x:=1+2*(2*(3-1*2)+4)*3+7");
#endif

    auto vars3 = sa->analyse(&inData3);

#if IS_INPUT_FROM_FILE
    inData3.close();
#endif
    /*
     * Given expression:       x:=1+2*(2*(3-1*2)+4)*3+7
     * x : 44
     * */

    for (auto& var : vars3)
        *logger << var.first << " : " << var.second << "\n";

#if IS_INPUT_FROM_FILE
    std::ifstream inData4(baseUrl + "/input4.txt");
#else
    std::istringstream inData4("x:=1+2*(2*3+4)*3+7;y:=2*x-(x+2*3)");
#endif

    auto vars4 = sa->analyse(&inData4);

#if IS_INPUT_FROM_FILE
    inData4.close();
#endif
    /*
     * Given expression:       x:=1+2*(2*3+4)*3+7;y:=2*x-(x+2*3)
     * x : 68
     * y : 62
     * */

    for (auto& var : vars4)
        *logger << var.first << " : " << var.second << "\n";
} catch (std::exception& ex) {
    std::cout << "Exception occurred:\t" << ex.what() << "\n";
}
