//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_PERSON_H
#define INFORMATICS_PERSON_H

#include "sharedModule.h"

class Person {
public:
    Person(
        const str& name,
        const str& surname,
        int age,
        const str& role
    );

    virtual void print() = 0;
    virtual int getId() const;
    virtual ss getFullName() const;
protected:
    int uuid;
    str name;
    str surname;
    int age;
    str role;
private:
    static li uuidSeries;
};


#endif //INFORMATICS_PERSON_H
