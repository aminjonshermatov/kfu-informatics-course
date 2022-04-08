//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_STUDENT_H
#define INFORMATICS_STUDENT_H

#include "sharedModule.h"
#include "Person.h"

class Student : public Person {
public:
    Student(const str&, const str&, int);

    void addSubject(const str&);
    v<> getSubjects() const;
    void setPreparation(int, int);
    pii getPreparation() const;

    void print() override;

    static Student* getById(int);
    static mP<Student> studStore;
private:
    v<> _subjects;
    pii _preparation;
};


#endif //INFORMATICS_STUDENT_H
