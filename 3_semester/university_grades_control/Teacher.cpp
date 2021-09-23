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
), department(department), subject(subject) {
    Teacher::teachStore.insert({this->uuid, this});
}

void Teacher::setGrade(GradeBook *gb, Student* stud) {
    gb->setGrade(this->getFullName(), this->getSubject(), stud);
}

str Teacher::getDepartment() const {
    return this->department;
}

str Teacher::getSubject() const {
    return this->subject;
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
        << this->role
        << ", my name is "
        << this->getFullName().str()
        << ", "
        << this->age
        << "years old."
        << " I'm work in "
        << this->getDepartment()
        << " department and teach in "
        << this->getSubject()
        << " subject.\n";
}

