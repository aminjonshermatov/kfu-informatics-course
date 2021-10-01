//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Student.h"

Student::Student(
    const str& name,
    const str& surname,
    int age
) : Person(
    name,
    surname,
    age,
    "student"
) {
    Student::studStore.insert({this->getId(), this});
};

void Student::print() {
    std::cout << "I'm a "
        << this->_role
        << ", my name is "
        << this->getFullName().str()
        << ", "
        << this->_age
        << "years old.\n";
}

void Student::addSubject(const str& subject) {
    this->_subjects.push_back(subject);
}

v<> Student::getSubjects() const {
    return this->_subjects;
}

void Student::setPreparation(int min, int max) {
    this->_preparation = mk(min, max);
}

pii Student::getPreparation() const {
    return this->_preparation;
}

Student* Student::getById(int idx) {
    auto findStud = Student::studStore.find(idx);

    if (findStud == Student::studStore.end())
        return nullptr;
    else
        return findStud->second;
}

mP<Student> Student::studStore;