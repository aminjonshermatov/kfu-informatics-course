//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_PERSON_H
#define INFORMATICS_PERSON_H

#include "sharedModule.h"

class Person {
public:
    Person(const str&, const str&, int, const str&);

    virtual void print() = 0;
    virtual int getId() const;
    virtual ss getFullName() const;
protected:
    int _uuid;
    str _name;
    str _surname;
    int _age;
    str _role;
private:
    static li uuidSeries;
};


#endif //INFORMATICS_PERSON_H
