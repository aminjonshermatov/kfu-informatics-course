//
// Created by aminjonshermatov on 9/22/2021.
//

#ifndef INFORMATICS_PERSON_H
#define INFORMATICS_PERSON_H

#include <iostream>

class Person {
public:
    Person(
            std::string& uuid,
            std::string& name,
            std::string& surname,
            int age,
            std::string& role
    );

    virtual void print() = 0;

    void setUUID(std::string& uuid);
    std::string getUUID() const;
    void setName(std::string& name);
    std::string getName() const;
    void setSurname(std::string& surname);
    std::string getSurname() const;
    void setAge(int age);
    int getAge() const;
    void setRole(std::string& role);
    std::string getRole() const;
private:
    std::string uuid;
    std::string name;
    std::string surname;
    int age;
    std::string role;
};


#endif //INFORMATICS_PERSON_H
