//
// Created by aminjonshermatov on 9/24/2021.
//

#ifndef INFORMATICS_LIST_H
#define INFORMATICS_LIST_H

template<typename T>
class List {
public:
    List(T data, List* next = nullptr);
    void setData(T data);
    T getData() const;
    bool hasNext();
    List* getNext() const;
    void setNext(List<T>* next);

    List* getPrev() const;
    void setPrev(List<T>* prev);
private:
    List* next;
    List* prev;
    T data;
};


#endif //INFORMATICS_LIST_H
