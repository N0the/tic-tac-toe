#pragma once 
#include "Board.hpp"
#include "Player.hpp"

bool CheckerInputBoard(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board, int &row, int &column);
bool CheckerFilledBoard(std::array<std::array<char, 3>, 3> &Board);
bool CheckerDraw(bool CheckerFilled);
bool CheckerWin(const Player &player1, std::array<std::array<char, 3>, 3> &Board);
bool CheckerAlmostWin(const Player &player1, std::array<std::array<char, 3>, 3> &Board);
std::array<int, 2> CheckerWinningMove(const Player &player, std::array<std::array<char, 3>, 3> &Board);