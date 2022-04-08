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
    Teacher( const str&, const str&, int, const str&, const str&);

    void setGrade(GradeBook*, Student*);
    str getDepartment() const;
    str getSubject() const;

    void print() override;

    static Teacher* getById(int) ;
    static mP<Teacher> teachStore;
private:
    str _department;
    str _subject;
};


#endif //INFORMATICS_TEACHER_H
