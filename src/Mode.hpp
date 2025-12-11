#pragma once
#include "Player.hpp"

int ModeJeu();
std::array<std::array<char, 3>, 3> PlayerTurn(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &Board);