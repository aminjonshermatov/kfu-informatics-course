//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Person.h"

Person::Person(
        const str& name,
        const str& surname,
        int age,
        const str& role
) : _uuid(Person::uuidSeries++),
    _name(name),
    _surname(surname),
    _age(age),
    _role(role) { }

li Person::uuidSeries = 0;

int Person::getId() const {
    return this->_uuid;
}

ss Person::getFullName() const {
    ss s;
    s << this->_name << " " << this->_surname;
    return s;
}
