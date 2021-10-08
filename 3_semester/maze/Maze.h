//
// Created by aminjonshermatov on 10/7/2021.
//

#ifndef INFORMATICS_MAZE_H
#define INFORMATICS_MAZE_H

#include "shared.h"
#include "Stack.h"

class Maze {
public:
    explicit Maze(std::istream&);
    Maze(char**, size_t, size_t);
    ~Maze();

    void setStartPoint(size_t, size_t);
    void setTargetPoint(size_t, size_t);
    void setMap(char**, size_t, size_t);
    void findPath();
    void restore();

    void showMap();
    void showSol();
private:
    char** _map;
    size_t _mapH, _mapW, _s_x, _s_y, _f_x, _f_y;
    bool** _visited;

    Stack<pll>* _sol;
};


#endif //INFORMATICS_MAZE_H
