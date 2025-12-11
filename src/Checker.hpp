#pragma once 
#include "Board.hpp"
#include "Player.hpp"

bool CheckerInputBoard(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &plato, int &row, int &column);
bool CheckerFilledBoard(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &plato);