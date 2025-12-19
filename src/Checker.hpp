#pragma once 
#include "Board.hpp"
#include "Player.hpp"

bool CheckerInputBoard(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board, int &row, int &column);
bool CheckerFilledBoard(const std::array<std::array<char, 3>, 3> &Board);
bool CheckerDraw(const bool CheckerFilled);
bool CheckerWin(const Player &player1, const std::array<std::array<char, 3>, 3> &Board);
std::array<int, 2> CheckerWinningMove(const Player &player, std::array<std::array<char, 3>, 3> &Board);