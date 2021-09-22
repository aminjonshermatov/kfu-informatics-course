//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_BOOLEAN_H
#define INFORMATICS_BOOLEAN_H

#include <iostream>

class Boolean {
public:
    Boolean();
    Boolean(bool arr[4]);
    Boolean(const Boolean& b);

    void setData(int idx, bool val);
    bool getData(int idx) const;

    Boolean* conjunction(const Boolean* b);
    Boolean* disjunction(const Boolean* b);

    friend std::ostream& operator<<(std::ostream& os, const Boolean& b);
private:
    bool data[4]{};
};


#endif //INFORMATICS_BOOLEAN_H
