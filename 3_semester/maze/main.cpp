//
// Created by aminjonshermatov on 10/7/2021.
//

#include "Maze.h"

int main() try {
    freopen("../3_semester/maze/input.txt", "r", stdin);
    freopen("../3_semester/maze/output.txt", "w", stdout);

    auto* maze = new Maze(std::cin);

    maze->setStartPoint(0, 0);
    maze->showMap();
    maze->findPath();
    maze->showSol();
    return 0;
} catch(std::runtime_error& re) {
    std::cout << "Exception occurred:\t" << re.what() << "\n";
}
