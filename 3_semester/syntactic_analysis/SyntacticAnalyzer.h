//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_SYNTACTICANALYZER_H
#define INFORMATICS_SYNTACTICANALYZER_H

#include "sharedModule.h"
#include "utils.h"

class SyntacticAnalyzer {
public:
    SyntacticAnalyzer(int identifierLen);

    bool analyse(const str& code);
private:
    const int identifierLen;
    int state;
    mapVar vars;
};


#endif //INFORMATICS_SYNTACTICANALYZER_H
