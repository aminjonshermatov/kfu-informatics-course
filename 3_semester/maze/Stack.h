//
// Created by aminjonshermatov on 10/7/2021.
//

#ifndef INFORMATICS_STACK_H
#define INFORMATICS_STACK_H

#include "shared.h"

template <typename T>
class Stack {
public:
    Stack();
    explicit Stack(T val);
    ~Stack();

    void push(T val);
    T top();
    T pop();
    bool isEmpty();
    void clear();

    template <typename V>
    friend std::ostream& operator<<(std::ostream&, const Stack<V>&);
private:
    class Node {
    public:
        explicit Node(T);
        Node(T, Node*);

        bool hasNext();
        T getValue();

        T value;
        Node* next;
    };

    size_t _size;
    Node* _top;
};

template <typename T>
Stack<T>::Node::Node(T val) : Node(val, nullptr) {}

template <typename T>
Stack<T>::Node::Node(T val, Node* n) : value(val), next(n) {}

template <typename T>
bool Stack<T>::Node::hasNext() {
    return this->next != nullptr;
}

template <typename T>
T Stack<T>::Node::getValue() {
    return this->value;
}

template <typename T>
Stack<T>::Stack() : _size(0), _top(nullptr) {}

template <typename T>
Stack<T>::Stack(T val) {
    this->push(val);
}

template <typename T>
Stack<T>::~Stack<T>() {
    this->clear();
}

template <typename T>
void Stack<T>::push(T val) {
    if (this->_size == 0) {
        this->_top = new Node(val);
    } else {
        this->_top = new Node(val, this->_top);
    }

    ++this->_size;
}

template <typename T>
T Stack<T>::top() {
    if (this->_size == 0) {
        throw std::runtime_error("Stack is empty");
    }

    return this->_top->getValue();
}

template <typename T>
T Stack<T>::pop() {
    if (this->_size == 0) {
        throw std::runtime_error("Stack is empty");
    }

    auto* temp = this->_top;
    T res = temp->getValue();

    this->_top = this->_top->next;

    delete temp;
    --this->_size;

    return res;
}

template <typename T>
bool Stack<T>::isEmpty() {
    this->_size == 0;
}

template <typename T>
void Stack<T>::clear() {
    if (this->_size > 0) {
        while (this->_top != nullptr) {
            auto* temp = this->_top;
            this->_top = this->_top->next;
            delete temp;
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s) {
    auto* temp = s._top;

    while (temp != nullptr) {
        os << temp->getValue() << " ";
        temp = temp->next;
    }

    return os << "\n";
}


#endif //INFORMATICS_STACK_H
