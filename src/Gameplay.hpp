#pragma once
#include "Player.hpp"

std::array<std::array<char, 3>, 3> PlayerTurn(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &Board);
int GamePlayMode1(Player &Player1, std::array<std::array<char, 3>, 3> &Board);