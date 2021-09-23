//
// Created by aminjonshermatov on 9/23/2021.
//

#ifndef INFORMATICS_GRADEBOOK_H
#define INFORMATICS_GRADEBOOK_H

class Teacher;

#include <ostream>
#include "sharedModule.h"
#include "utils.h"
#include "Student.h"

class GradeBook {
public:
    GradeBook(const v<>& subjects);

    void setGrade(ss tFullName, const str& subject, Student *stud);

    friend std::ostream &operator<<(std::ostream &os, const GradeBook &gBook);

private:
    /*
     * {} -> map
     * [] -> vector
     *
     * {
     *      math: {
     *          [stud_id]: [4,5,6, ...],
     *          [stud_id]: [1,2,3,4, ...]
     *      },
     *      chemistry: {
     *          [stud_id]: [2,3,4,5, ...]
     *      }
     * }
     * */
    um_sii store;
};


#endif //INFORMATICS_GRADEBOOK_H
