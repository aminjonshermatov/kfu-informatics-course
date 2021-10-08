//
// Created by aminjonshermatov on 10/7/2021.
//

#include "Maze.h"

int main() try {
    freopen("D:/kfu/informatics/3_semester/maze/input.txt", "r", stdin);

    auto* maze = new Maze(std::cin);

    maze->setStartPoint(3, 1);
    maze->showMap();
    maze->findPath();
    maze->showSol();
    return 0;
} catch(std::runtime_error& re) {
    std::cout << "Exception occurred:\t" << re.what() << "\n";
}
