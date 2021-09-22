//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Person.h"

Person::Person(
        std::string& uuid,
        std::string& name,
        std::string& surname,
        int age,
        std::string& role
) {
    this->setUUID(uuid);
    this->setName(name);
    this->setSurname(surname);
    this->setAge(age);
    this->setRole(role);
}

void Person::setUUID(std::string &uuid) {
    if (uuid == "")
        throw std::exception("UUID must be non-empty");

    this->uuid = uuid;
}

std::string Person::getUUID() const {
    return this->uuid;
}

void Person::setName(std::string &name) {
    if (name == "")
        throw std::exception("Name must be non-empty");

    this->name = name;
}

std::string Person::getName() const {
    return this->name;
}

void Person::setSurname(std::string &surname) {
    if (surname == "")
        throw std::exception("Surname must be non-empty");

    this->surname = surname;
}

std::string Person::getSurname() const {
    return this->surname;
}

void Person::setAge(int age) {
    if (age < 0 || age > 100)
        throw std::exception("Age of Person is not valid");

    if (age < 15)
        throw std::exception("Person is too young");

    this->age = age;
}

int Person::getAge() const {
    return this->age;
}

void Person::setRole(std::string &role) {
    if (role == "" || !(role == "student" || role == "teacher"))
        throw std::exception("Invalid role");

    this->role = role;
}

std::string Person::getRole() const {
    return this->role;
}
