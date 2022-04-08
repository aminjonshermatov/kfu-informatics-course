//
// Created by aminjonshermatov on 10/7/2021.
//

#include "Maze.h"

Maze::Maze(std::istream& is)
: _s_x(0)
, _s_y(0)
, _sol{new Stack<std::pair<int, int>>()} {
    size_t tempH, tempW;
    is >> tempH >> tempW;

    _f_y = tempH - 1;
    _f_x = tempW - 1;
    _mapH = tempH;
    _mapW = tempW;

    _map = new char*[tempH];
    _visited = new bool*[tempH];

    for (size_t i{0}; i < tempH; ++i) {
        _map[i] = new char[tempW];
        _visited[i] = new bool[tempW];

        for (size_t j{0}; j < tempW; ++j) {
            is >> _map[i][j];
            _visited[i][j] = false;
        }
    }
}

Maze::Maze(char ** map, size_t h, size_t w)
: _mapH{h}
, _mapW{w}
, _s_x{0}
, _s_y{0}
, _f_x{w - 1}
, _f_y{h - 1}
, _sol{new Stack<std::pair<int, int>>()} {
    _map = new char*[_mapH];
    _visited = new bool*[_mapH];

    for (size_t i{0}; i < _mapH; ++i) {
        _map[i] = new char[_mapW];
        _visited[i] = new bool[_mapW];

        for (size_t j{0}; j < _mapW; ++j) {
            _map[i][j] = map[i][j];
            _visited[i][j] = false;
        }
    }
}

Maze::~Maze() {
    for (size_t i{0}; i < _mapH; ++i) {
        delete[] _map[i];
        delete[] _visited[i];
    }

    delete[] _map;
    delete[] _visited;

    _sol->clear();
}

void Maze::setStartPoint(size_t x_0, size_t y_0) {
    _s_x = x_0;
    _s_y = y_0;
}

void Maze::setTargetPoint(size_t f_x, size_t f_y) {
    _f_x = f_x;
    _f_y = f_y;
}

void Maze::setMap(char** newMap, size_t h, size_t w) {
    if (h != _mapH || w != _mapW) {
        for (size_t i{0}; i < _mapH; ++i) {
            delete[] _map[i];
        }

        delete[] _map;
    }

    _mapH = h;
    _mapW = w;

    _map = new char*[_mapH];
    for (size_t i{0}; i < _mapH; ++i) {
        _map[i] = new char[_mapW];

        for (size_t j{0}; j < _mapW; ++j) {
            _map[i][j] = newMap[i][j];
        }
    }

    restore();
}

void Maze::findPath() {
    _sol->push({_s_x, _s_y});

    // 0 -> can move
    // 1 -> can't move/wall
    while (!_sol->isEmpty()) {
        auto [cur_x, cur_y] = _sol->top();

        if (cur_x == _f_x && cur_y == _f_y) return;
        _visited[cur_y][cur_x] = true;

        // right
        if (
                cur_x + 1 < _mapW
                && !_visited[cur_y][cur_x + 1]
                && _map[cur_y][cur_x + 1] == '0'
                ) {
            _sol->push({cur_x + 1, cur_y});
            continue;
        }

        // down
        if (
                cur_y + 1 < _mapH
                && !_visited[cur_y + 1][cur_x]
                && _map[cur_y + 1][cur_x] == '0'
                ) {
            _sol->push({cur_x, cur_y + 1});
            continue;
        }

        // left
        if (
                cur_x - 1 >= 0
                && !_visited[cur_y][cur_x - 1]
                && _map[cur_y][cur_x - 1] == '0'
                ) {
            _sol->push({cur_x - 1, cur_y});
            continue;
        }

        // up
        if (
                cur_y - 1 >= 0
                && !_visited[cur_y - 1][cur_x]
                && _map[cur_y - 1][cur_x] == '0'
                ) {
            _sol->push({cur_x, cur_y - 1});
            continue;
        }

        _sol->pop();
    }

    throw std::runtime_error("Maze hasn't path to finish");
}

void Maze::restore() {
    for (size_t i{0}; i < _mapH; ++i) {
        for (size_t j{0}; j < _mapW; ++j) {
            _visited[i][j] = false;
        }
    }

    _sol->clear();
}

void Maze::showMap() {
    std::cout << "Map:" << '\n';

    for (size_t i{0}; i < _mapH; ++i) {
        std::cout.width(6);
        for (size_t j{0}; j < _mapW; ++j) {
            std::cout << _map[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void Maze::showSol() {
    std::cout << '\n' << "Start point:" << '\t' << '(' << _s_x << ", " << _s_y << ')' << '\n'
                      << "Finish point:" << '\t' << '(' << _f_x << ", " << _f_y << ')' << '\n'
                      << "Solution:" << '\n';

    auto** tempMap = new char*[_mapH];

    for (size_t i{0}; i < _mapH; ++i) {
        tempMap[i] = new char[_mapW];

        for (size_t j{0}; j < _mapW; ++j) {
            tempMap[i][j] = _map[i][j];
        }
    }

    auto* temp = _sol->_top;

    while (temp != nullptr) {
        auto [x, y] = temp->getValue();

        tempMap[y][x] = '*';
        temp = temp->next;
    }

    for (size_t i{0}; i < _mapH; ++i) {
        std::cout .width(6);
        for (size_t j{0}; j < _mapW; ++j) {
            std::cout << tempMap[i][j] << ' ';
        }

        std::cout << '\n';
    }
}
