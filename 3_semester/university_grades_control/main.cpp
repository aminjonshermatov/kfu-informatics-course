//
// Created by aminjonshermatov on 9/22/2021.
//

#include "Student.h"
#include "Teacher.h"
#include "utils.h"
#include "GradeBook.h"

int main() {
    v<> subjects = {"math", "physics", "chemistry"};

    auto* gb = new GradeBook(subjects);

    std::cout << *gb;

    auto t1 = new Teacher("t_n_1", "t_s_1", 30, "physics", "physics");
    auto t2 = new Teacher("t_n_2", "t_s_2", 40, "math", "math");
    auto t3 = new Teacher("t_n_3", "t_s_3", 50, "chemistry", "chemistry");

    auto s1 = new Student("s_n_1", "s_s_1", 16);
    s1->setPreparation(2, 5);
    auto s2 = new Student("s_n_2", "s_s_2", 17);
    s2->setPreparation(6, 9);
    auto s3 = new Student("s_n_3", "s_s_3", 18);
    s3->setPreparation(10, 15);

    for (auto& sub : subjects) {
        s1->addSubject(sub);
        s2->addSubject(sub);
        s3->addSubject(sub);
    }

    std::cout << *gb;

    for (auto& teach : Teacher::teachStore)
        for (auto& stud : Student::studStore) {
            teach.second->setGrade(gb, stud.second);
            teach.second->setGrade(gb, stud.second);
            teach.second->setGrade(gb, stud.second);
        }

    std::cout << *gb;

    return 0;
};