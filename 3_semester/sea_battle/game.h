//
// Created by aminjonshermatov on 12/14/2021.
//

#ifndef INFORMATICS_GAME_H
#define INFORMATICS_GAME_H

#include "bits/stdc++.h"

using namespace std;

class Game {
public:
    using board_t = vector<vector<char>>;
    enum Position { VERTICAL, HORIZONTAL };
    struct Ship {
        size_t x;
        size_t y;
        size_t len;

        Position position;
    };

private:
    // C - crashed part of ship
    // \d - type of ship
    // x - attacked
    // ' ' - empty
    struct GameBoard {
        size_t board_size_;
        board_t player_1_;
        board_t player_2_;
    };

    struct Stat {
        size_t attack;
        size_t crashed_ship;
    };

    struct Stats {
        Stat player1;
        Stat player2;
    };

    enum PlayerType { Player1, Player2 };

public:
    Game(size_t, initializer_list<size_t>);

    void run();
    void setShip(size_t, char, size_t, Position);
    void attack(size_t, char);

private:
    GameBoard game_board_;
    int board_1_state_;
    int board_2_state_;
    Stats stats_;
    PlayerType state_;

    static void render_boards_(const GameBoard&);
    static bool canAttack(board_t&, size_t, size_t);
    bool canSetShip(const board_t&, const Ship&);
    void setShip(PlayerType, Ship);
    void attack(PlayerType, size_t, size_t);
    void changeState();
    void printResult() const;

    // [min, max]
    static size_t randomrange(size_t, size_t);
};

#endif //INFORMATICS_GAME_H
