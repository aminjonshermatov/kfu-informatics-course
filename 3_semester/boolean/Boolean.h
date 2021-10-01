//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_BOOLEAN_H
#define INFORMATICS_BOOLEAN_H

#include <iostream>

class Boolean {
public:
    Boolean();
    Boolean(bool[]);
    Boolean(const Boolean&);

    void setData(int, bool);
    bool getData(int) const;

    Boolean* conjunction(const Boolean*);
    Boolean* disjunction(const Boolean*);

    friend std::ostream& operator<<(std::ostream&, const Boolean&);
private:
    bool _data[4]{};
};


#endif //INFORMATICS_BOOLEAN_H
