//
// Created by aminjonshermatov on 9/23/2021.
//

#include "GradeBook.h"

GradeBook::GradeBook(const v<>& subjects) {
    for (auto& sub : subjects) {
        this->store.insert({sub, {}});
    }
}

void GradeBook::setGrade(ss tFullName, const str& subject, Student *stud) {
    v<str> subjects = stud->getSubjects();

    if (findAll(subjects, subject) == subjects.end())
        throw exp("Student does not learn this subject");

    auto findSubject = this->store.find(subject);

    if (findSubject == this->store.end())
        throw exp("Invalid subject does not exist in grade-book");

    auto findStud = this->store[subject].find(stud->getId());

    if (findStud == this->store[subject].end()) {
        this->store[subject].insert({stud->getId(), {}});
    }

    this->store[subject][stud->getId()].push_back(utils::random(stud->getPreparation()));

    std::cout << "Teacher "
            << tFullName.str()
            << " appreciated student "
            << stud->getFullName().str()
            << " in "
            << subject
            << " subject "
            << this->store[subject][stud->getId()].back()
            << "\n";
}

std::ostream &operator<<(std::ostream &os, const GradeBook &gBook) {
    os << "\n";
    for (auto& sub : gBook.store) {
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
