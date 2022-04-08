//
// Created by aminjonshermatov on 9/23/2021.
//

#include "GradeBook.h"

GradeBook::GradeBook(const v<>& subjects) {
    for (auto& sub : subjects)
        this->_store.insert({sub, {}});
}

void GradeBook::setGrade(ss tFullName, const str& subject, Student *stud) {
    v<str> subjects = stud->getSubjects();

    if (findAll(subjects, subject) == subjects.end())
        throw exp("Student does not learn this subject");

    auto findSubject = this->_store.find(subject);

    if (findSubject == this->_store.end())
        throw exp("Invalid subject does not exist in grade-book");

    auto findStud = this->_store[subject].find(stud->getId());

    if (findStud == this->_store[subject].end())
        this->_store[subject].insert({stud->getId(), {}});

    this->_store[subject][stud->getId()].push_back(utils::random(stud->getPreparation()));

    std::cout << "Teacher "
            << tFullName.str()
            << " appreciated student "
            << stud->getFullName().str()
            << " in "
            << subject
            << " subject "
            << this->_store[subject][stud->getId()].back()
            << "\n";
}

std::ostream &operator<<(std::ostream &os, const GradeBook &gBook) {
    os << "\n";
    for (auto& sub : gBook._store) {
        os << sub.first << ":\n";
        for (auto& stud: sub.second) {
            os << "\t" << Student::getById(stud.first)->getFullName().str() << ": [";

            for (int i = 0; i < stud.second.size(); ++i) {
                os << stud.second[i];

                if (i + 1 != stud.second.size())
                    os << ", ";
            }

            os << "]\n";
        }
        os << "\n";
    }

    return os;
}
