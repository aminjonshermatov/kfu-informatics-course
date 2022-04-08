//
// Created by aminjonshermatov on 11/5/2021.
//

#ifndef INFORMATICS_NODE_H
#define INFORMATICS_NODE_H

template <typename T>
struct Node {
    Node() : val(T{}), next(nullptr) {}
    explicit Node(T const& v) : val(v), next(nullptr) {}
    Node(T const& v, Node* n) : val(v), next(n) {}
    Node(const Node<T> &node) : val(node.val), next(node.next) {}
    explicit Node(const Node<T>* node) : val(node->val), next(node->next) {}
    Node(const Node<T>&& node) noexcept : val(node.val), next(node.next) {}

    template<typename S>
    friend ostream& operator<<(ostream& out, Node<S>& node) { return out << node.val; }

    T val;
    Node* next;
};

#endif //INFORMATICS_NODE_H
