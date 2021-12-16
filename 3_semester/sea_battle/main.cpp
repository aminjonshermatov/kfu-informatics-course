//
// Created by aminjonshermatov on 12/14/2021.
//

#include "bits/stdc++.h"

#include "game.h"

using namespace std;

void t_1() {
    Game game(8, {3, 2, 2, 1});
    game.setShip(1, 'A', 3, Game::Position::VERTICAL);
    game.setShip(2, 'D', 2, Game::Position::HORIZONTAL);
    game.setShip(4, 'D', 2, Game::Position::VERTICAL);
    game.setShip(7, 'G', 1, Game::Position::VERTICAL);

    game.run();
}

int main() try {
    t_1();
} catch (const exception& ex) {
    cerr << ex.what() << '\n';
}