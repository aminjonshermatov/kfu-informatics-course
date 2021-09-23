//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Person.h"

Person::Person(
        const str& name,
        const str& surname,
        int age,
        const str& role
) : uuid(Person::uuidSeries++),
    name(name),
    surname(surname),
    age(age),
    role(role) { }

li Person::uuidSeries = 0;

int Person::getId() const {
    return this->uuid;
}

ss Person::getFullName() const {
    ss s;
    s << this->name << " " << this->surname;
    return s;
}
