//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_STACK_H
#define INFORMATICS_STACK_H

#include "sharedModule.h"
#include "List.h"

template<class T>
class Stack {
public:
    Stack();
    ui getSize() const;
    void push_back(ui data);
    ui pop();
    ui top();
    void clear();

private:
    ui size;
    List<T>* head;
    List<T>* tail;
};


#endif //INFORMATICS_STACK_H
