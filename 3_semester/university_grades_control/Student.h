//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_STUDENT_H
#define INFORMATICS_STUDENT_H

#include "sharedModule.h"
#include "Person.h"

class Student : public Person {
public:
    Student(
        const str& name,
        const str& surname,
        int age
    );

    void addSubject(const str& subject);
    v<> getSubjects() const;
    void setPreparation(int min, int max);
    pii getPreparation() const;

    void print() override;

    static Student* getById(int idx);
    static mP<Student> studStore;
private:
    v<> subjects;
    pii preparation;
};


#endif //INFORMATICS_STUDENT_H
