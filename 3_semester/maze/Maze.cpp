//
// Created by aminjonshermatov on 10/7/2021.
//

#include "Maze.h"

Maze::Maze(std::istream& is) : _s_x(0), _s_y(0), _sol(new Stack<pll>()) {
    size_t tempH, tempW;
    is >> tempH >> tempW;

    this->_f_y = tempH - 1;
    this->_f_x = tempW - 1;
    this->_mapH = tempH;
    this->_mapW = tempW;

    this->_map = new char*[tempH];
    this->_visited = new bool*[tempH];

    for (size_t i = 0; i < tempH; ++i) {
        this->_map[i] = new char[tempW];
        this->_visited[i] = new bool[tempW];

        for (size_t j = 0; j < tempW; ++j) {
            is >> this->_map[i][j];
            this->_visited[i][j] = false;
        }
    }
}

Maze::Maze(char ** map, size_t h, size_t w)
    : _mapH(h), _mapW(w),
    _s_x(0), _s_y(0),
    _f_x(w - 1), _f_y(h - 1),
    _sol(new Stack<pll>()) {
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

Maze::~Maze() {
    for (size_t i = 0; i < this->_mapH; ++i) {
        delete[] this->_map[i];
        delete[] this->_visited[i];
    }

    delete[] this->_map;
    delete[] this->_visited;

    this->_sol->clear();
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
    this->_sol->push(mk(this->_s_x, this->_s_y));

    // 0 -> can move
    // 1 -> can't move/wall
    while (!this->_sol->isEmpty()) {
        pll temp = this->_sol->top();

        if (temp.first == this->_f_x && temp.second == this->_f_y) return;

        // right
        if (
                temp.first + 1 < this->_mapW
                && !this->_visited[temp.second][temp.first + 1]
                && this->_map[temp.second][temp.first + 1] == '0'
                ) {
            this->_sol->push(mk(temp.first + 1, temp.second));
            continue;
        }

        // down
        if (
                temp.second + 1 < this->_mapH
                && !this->_visited[temp.second + 1][temp.first]
                && this->_map[temp.second + 1][temp.first] == '0'
                ) {
            this->_sol->push(mk(temp.first, temp.second + 1));
            continue;
        }

        // left
        if (
                temp.first - 1 >= 0
                && !this->_visited[temp.second][temp.first - 1]
                && this->_map[temp.second][temp.first - 1] == '0'
                ) {
            this->_sol->push(mk(temp.first - 1, temp.second));
            continue;
        }

        // up
        if (
                temp.second - 1 >= 0
                && !this->_visited[temp.second - 1][temp.first]
                && this->_map[temp.second - 1][temp.first] == '0'
                ) {
            this->_sol->push(mk(temp.first, temp.second - 1));
            continue;
        }

        this->_sol->pop();
    }

    throw std::runtime_error("Maze hasn't path to finish");
}

void Maze::restore() {
    for (size_t i = 0; i < this->_mapH; ++i) {
        for (size_t j = 0; j < this->_mapW; ++j) {
            this->_visited[i][j] = false;
        }
    }

    this->_sol->clear();
}

void Maze::showMap() {
    std::cout << "Map:\n";

    for (size_t i = 0; i < this->_mapH; ++i) {
        std::cout.width(6);
        for (size_t j = 0; j < this->_mapW; ++j) {
            std::cout << this->_map[i][j] << " ";
        }

        std::cout << "\n";
    }
}

void Maze::showSol() {
    std::cout << "\nStart point:\t(" << this->_s_x << ", " << this->_s_y << ")\nFinish point:\t(" << this->_f_x << ", " << this->_f_y << ")\nSolution:\n";

    auto** tempMap = new char*[this->_mapH];

    for (size_t i = 0; i < this->_mapH; ++i) {
        tempMap[i] = new char[this->_mapW];

        for (size_t j = 0; j < this->_mapW; ++j) {
            tempMap[i][j] = this->_map[i][j];
        }
    }

    auto* temp = this->_sol->_top;

    while (temp != nullptr) {
        pll point = temp->getValue();

        tempMap[point.second][point.first] = '*';
        temp = temp->next;
    }

    for (size_t i = 0; i < this->_mapH; ++i) {
        std::cout .width(6);
        for (size_t j = 0; j < this->_mapW; ++j) {
            std::cout << tempMap[i][j] << " ";
        }

        std::cout << "\n";
    }
}
