//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Teacher.h"

Teacher::Teacher(
    const str &name,
    const str &surname,
    int age,
    const str &department,
    const str &subject
) : Person(
    name,
    surname,
    age,
    "teacher"
), _department(department), _subject(subject) {
    Teacher::teachStore.insert({this->_uuid, this});
}

void Teacher::setGrade(GradeBook *gb, Student* stud) {
    gb->setGrade(this->getFullName(), this->getSubject(), stud);
}

str Teacher::getDepartment() const {
    return this->_department;
}

str Teacher::getSubject() const {
    return this->_subject;
}

Teacher *Teacher::getById(int idx) {
    auto findTeacher = Teacher::teachStore.find(idx);

    if (findTeacher == Teacher::teachStore.end())
        return nullptr;
    else
        return findTeacher->second;
}

mP<Teacher> Teacher::teachStore;

void Teacher::print() {
    std::cout << "I'm a "
        << this->_role
        << ", my name is "
        << this->getFullName().str()
        << ", "
        << this->_age
        << "years old."
        << " I'm work in "
        << this->getDepartment()
        << " department and teach in "
        << this->getSubject()
        << " subject.\n";
}

