//
// Created by aminjonshermatov on 10/7/2021.
//

#include "Maze.h"

Maze::Maze(char ** map, size_t h, size_t w)
    : _mapH(h), _mapW(w), _s_x(0), _s_y(0), _f_x(w - 1), _f_y(h - 1) {
    this->_map = new char*[this->_mapH];
    this->_visited = new bool*[this->_mapH];

    for (size_t i = 0; i < this->_mapH; ++i) {
        this->_map[i] = new char[this->_mapW];
        this->_visited[i] = new bool[this->_mapW];

        for (size_t j = 0; j < this->_mapW; ++j) {
            this->_map[i][j] = map[i][j];
            this->_visited[i][j] = false;
        }
    }
}

void Maze::setStartPoint(size_t x_0, size_t y_0) {
    this->_s_x = x_0;
    this->_s_y = y_0;
}

void Maze::setTargetPoint(size_t f_x, size_t f_y) {
    this->_f_x = f_x;
    this->_f_y = f_y;
}

void Maze::setMap(char** newMap, size_t h, size_t w) {
    if (h != this->_mapH || w != this->_mapW) {
        for (size_t i = 0; i < this->_mapH; ++i) {
            delete[] this->_map[i];
        }

        delete[] this->_map;
    }

    this->_mapH = h;
    this->_mapW = w;

    this->_map = new char*[this->_mapH];
    for (size_t i = 0; i < this->_mapH; ++i) {
        this->_map[i] = new char[this->_mapW];

        for (size_t j = 0; j < this->_mapW; ++j) {
            this->_map[i][j] = newMap[i][j];
        }
    }

    this->restore();
}

void Maze::findPath() {

}

void Maze::restore() {
    for (size_t i = 0; i < this->_mapH; ++i) {
        for (size_t j = 0; j < this->_mapW; ++j) {
            this->_visited[i][j] = false;
        }
    }

    this->_sol->clear();
}

std::ostream& Maze::solution(std::ostream& os) {
    os << "Map:\n";

    char** temp = new char*[this->_mapH];
    for (size_t i = 0; i < this->_mapH; ++i) {
        temp[i] = new char[this->_mapW];
        for (size_t j = 0; j < this->_mapW; ++j) {
            if (i == this->_s_y && j == this->_s_x) os << 'S';
            else if (i == this->_f_y && j == this->_f_x) os << 'F';
            else os << this->_map[i][j];
            temp[i][j] = this->_map[i][j];
        }

        os << "\n";
    }

    auto tempPoint = this->_sol->pop();

    while (!this->_sol->isEmpty()) {
        temp[tempPoint.first][tempPoint.second] = '*';
    }

    os << "\nSolution/path:\n";
    for (size_t i = 0; i < this->_mapH; ++i) {
        for (size_t j = 0; j < this->_mapW; ++j) {
            os << temp[i][j];
        }

        os << "\n";
    }

    return os;
}
