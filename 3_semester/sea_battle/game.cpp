//
// Created by aminjonshermatov on 12/14/2021.
//

#include "game.h"

Game::Game(size_t board_size, initializer_list<size_t> sizes)
: board_1_state_{0}
, board_2_state_{0}
, stats_{
  {0, 0},
  {0, 0}
}
, state_{Player1} {
    game_board_ = {
            board_size,
            board_t{board_size, vector<char>(board_size, ' ')},
            board_t{board_size, vector<char>(board_size, ' ')}
    };

    for (const size_t size : sizes) {
        Ship ship;

        do {
            ship = {
                    randomrange(0, game_board_.board_size_ - 1),
                    randomrange(0, game_board_.board_size_ - 1),
                    size,
                    (randomrange(0, 1) == 1 ? Position::HORIZONTAL : Position::VERTICAL)
            };
        } while (!canSetShip(game_board_.player_2_, ship));

        setShip(PlayerType::Player2, ship);
    }
}

void Game::run() {
    changeState();
}

void Game::render_boards_(const GameBoard& game_board) {
    cout << setw(4);
    for (size_t i = 0; i < game_board.board_size_; ++i) cout << (char)('A' + i);
    cout << setw(3);
    for (size_t i = 0; i < game_board.board_size_; ++i) cout << (char)('A' + i);
    cout << '\n';

    for (size_t i = 0; i < game_board.board_size_; ++i) {
        cout << setw(2) << (i + 1) << ' ';
        for (size_t j = 0; j < game_board.board_size_; ++j) cout << (game_board.player_1_[i][j] != ' ' ? game_board.player_1_[i][j] : 'o');

        cout << setw(3);
        for (size_t j = 0; j < game_board.board_size_; ++j) cout << (game_board.player_2_[i][j] != ' ' ? game_board.player_2_[i][j] : 'o');
        cout << '\n';
    }
    cout << '\n';
}

bool Game::canAttack(board_t& board, size_t y, size_t x) {
    return y < board.size() && x < board.size() && board[y][x] != 'x' && board[y][x] != ' ';
}

bool Game::canSetShip(const board_t& board, const Ship& ship) {
    if (ship.x >= board.size()
    || ship.y >= board.size()
    || ship.position == Position::HORIZONTAL && ship.x + ship.len >= board.size()
    || ship.position == Position::VERTICAL && ship.y + ship.len >= board.size()) return false;

    switch (ship.position) {
        case VERTICAL: {
            for (size_t i = 0; i < ship.len; ++i) {
                if (board[ship.y + i][ship.x] != ' ') {
                    cout << ship.y << ' ' << ship.x << ' ' << ship.len << ' ' << ship.position << '\n';
                    cout << "vertical board: '" << board[ship.y + i][ship.x] << "'\n";

                    return false;
                }
            }
            return true;
        }
        case HORIZONTAL:
            for (size_t i = 0; i < ship.len; ++i) {
                if (board[ship.y][ship.x + i] != ' ') {
                    cout << ship.y << ' ' << ship.x << ' ' << ship.len << ' ' << ship.position << '\n';
                    cout << "horizontal board: '" << board[ship.y + i][ship.x] << "'\n";
                    return false;
                }
            }
            return true;
        default:
            return false;
    }
}

void Game::setShip(size_t y, char x, size_t len, Game::Position position) {
    setShip(PlayerType::Player1, {static_cast<size_t>(x - 'A'), y - 1, len, position});
}

void Game::setShip(PlayerType playerType, Ship ship) {
    switch (playerType) {
        case Player1: {
            if (!canSetShip(game_board_.player_1_, ship)) {
                cout << ship.y << ' ' << ship.x << ' ' << ship.len << ' ' << ship.position << ' ' << playerType << '\n';
                throw runtime_error("Can't set ship");
            }

            for (size_t i = 0; i < ship.len; ++i) {
                if (ship.position == Position::VERTICAL)
                    game_board_.player_1_[ship.y + i][ship.x] = static_cast<char>('0' + ship.len);
                else if (ship.position == Position::HORIZONTAL)
                    game_board_.player_1_[ship.y][ship.x + i] = static_cast<char>('0' + ship.len);
            }
            board_2_state_ += static_cast<int>(ship.len);
        }
        case Player2: {
            if (!canSetShip(game_board_.player_2_, ship)) {
                cout << ship.y << ' ' << ship.x << ' ' << ship.len << ' ' << ship.position << ' ' << playerType << '\n';
                throw runtime_error("Can't set ship");
            }

            for (size_t i = 0; i < ship.len; ++i) {
                if (ship.position == Position::VERTICAL)
                    game_board_.player_2_[ship.y + i][ship.x] = static_cast<char>('0' + ship.len);
                else if (ship.position == Position::HORIZONTAL)
                    game_board_.player_2_[ship.y][ship.x + i] = static_cast<char>('0' + ship.len);
            }
            board_1_state_ += static_cast<int>(ship.len);
        }
    }
}

void Game::attack(size_t y, char x) {
    attack(PlayerType::Player1, y - 1, static_cast<size_t>('A' - x));
}

void Game::attack(Game::PlayerType playerType, size_t y, size_t x) {
    switch (playerType) {
        case Player1: {
            if (!canAttack(game_board_.player_2_, y, x))
                throw runtime_error("Can't attack to this point");

            if (game_board_.player_2_[y][x] >= '1'
                && game_board_.player_2_[y][x] <= '9') {
                game_board_.player_2_[y][x] = 'C';
                --board_2_state_;
                if (board_2_state_ == 0) {
                    printResult();
                    return;
                }
                ++stats_.player1.crashed_ship;
            }
            else {
                game_board_.player_2_[y][x] = 'X';
            }
            ++stats_.player1.attack;
            state_ = Player2;
            break;
        }
        case Player2: {
            if (!canAttack(game_board_.player_1_, y, x))
                throw runtime_error("Can't attack to this point");

            if (game_board_.player_1_[y][x] >= '1'
                && game_board_.player_1_[y][x] <= '9') {
                game_board_.player_1_[y][x] = 'C';
                --board_1_state_;
                if (board_1_state_ == 0) {
                    printResult();
                    return;
                }
                ++stats_.player2.crashed_ship;
            }
            else {
                game_board_.player_1_[y][x] = 'X';
            }
            ++stats_.player2.attack;
            state_ = Player1;
            break;
        }
    }
    changeState();
}

void Game::changeState() {
    render_boards_(game_board_);

    switch (state_) {
        case Player1: {
            cout << "Attack " << "Player!!!" << '\n'
                 << "Set coordinates (Y, X): " << '\n';

            size_t y;
            char x;
            do {
                cin >> y >> x;
            } while (!canAttack(game_board_.player_2_, y, static_cast<size_t>(x - 'A')));

            attack(y, x);
            break;
        }
        case Player2: {
            cout << "Attack " << "AI!!!" << '\n';
            size_t randY, randX;

            do {
                randY = randomrange(0, game_board_.board_size_ - 1);
                randX = randomrange(0, game_board_.board_size_ - 1);
            } while (!canAttack(game_board_.player_1_, randY, randX));

            attack(PlayerType::Player2, randY, randX);
            break;
        }
    }
}

size_t Game::randomrange(size_t min, size_t max) {
    mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution<mt19937::result_type> dist(min, max);

    return dist(rng);
}

void Game::printResult() const {
    auto printStat = [&](const string& name, const Stat& stat) {
        cout << name << '\n';
        cout << "Total Attacks: " << stat.attack << '\n'
             << "Total Crashes: " << stat.crashed_ship << '\n';
    };

    render_boards_(game_board_);
    cout << (board_1_state_ == 0 ? "Player2" : "Player1") << " won" << '\n'
         << "Stats:" << '\n';
    printStat("Player1", stats_.player1);
    printStat("Player2", stats_.player1);
}
