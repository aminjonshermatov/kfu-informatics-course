//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_TEACHER_H
#define INFORMATICS_TEACHER_H

#include "sharedModule.h"
#include "Person.h"
#include "GradeBook.h"

class Teacher : public Person {
public:
    Teacher(
        const str& name,
        const str& surname,
        int age,
        const str& department,
        const str& subject
    );

    void setGrade(GradeBook* gb, Student* stud);
    str getDepartment() const;
    str getSubject() const;

    void print() override;

    static Teacher* getById(int idx) ;
    static mP<Teacher> teachStore;
private:
    str department;
    str subject;
};


#endif //INFORMATICS_TEACHER_H
