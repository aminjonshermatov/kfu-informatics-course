//
// Created by aminjonshermatov on 1/17/2022.
//

#ifndef INFORMATICS_DYNAMIC_ARRAY_H
#define INFORMATICS_DYNAMIC_ARRAY_H

#include<iostream>

using namespace std;

template <typename T>
class dynamic_array
{
private:
    int m_size;//размер массива
    int m_capacity;//размер массива
    T* m_data;//сам массив

public:
    //конструктор
    dynamic_array()
    {
        m_size = 0;//присваивание размеру массива 0
        m_capacity = 0;
        m_data = NULL;
    }
    dynamic_array(const dynamic_array<T>& a)
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = NULL;
        if (m_size != 0)
            m_data = new T[m_size];
        else
            m_data = 0;
        for (int i = 0; i < m_size; i++)
            m_data[i] = a.m_data[i];
    }
    dynamic_array(int size)
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new T[size];
        else
            m_data = 0;
    }
    //деструктор
    ~dynamic_array()
    {
        for(int i=0, i<size; i++)//проходимся по каждой строке и удаляем динамические элементы
            delete[] m_data[i];
    }

    //перегрузка оператора []
    T& operator[] (int i, int y)
    {
        return m_data[i][y];//возвращаем определённый элемент массива
    }

    //перегрузка вывода
    ostream& operator << (ostream& out, dynamic_array<T> a)
    {
        for (int i = 0; i < a.size(); i++)//тут мы проходимся по каждому элементу массива
            for(int j=0; j<a.size(); j++)
                out << a[i][j] << " ";//и кидаем в строку "out"
        return out;     //возвращаем строку и уже в главной функции выводим на консоль
    }


};



#endif //INFORMATICS_DYNAMIC_ARRAY_H
