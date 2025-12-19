#pragma once
#include "Player.hpp"

std::array<std::array<char, 3>, 3> PlayerTurn(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board);
int GamePlayMode1(const Player &Player1, std::array<std::array<char, 3>, 3> &Board);
int GamePlayMode2(const Player &Player1, std::array<std::array<char, 3>, 3> &Board);
std::array<std::array<char, 3>, 3> IATurn(const Player &player, const Player &IA, std::array<std::array<char, 3>, 3> &Board);