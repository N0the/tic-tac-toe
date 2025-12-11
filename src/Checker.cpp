#include <iostream>
#include "Checker.hpp"
#include <array>

bool CheckerInputBoard(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &plato, int &row, int &column)
{
    bool checker{false};

    if (plato[row][column] == player1.symbol || plato[row][column] == player2.symbol)
    {
        checker = true;
        return checker;
    }
    return checker;
}
bool CheckerFilledBoard(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &plato)
{
    bool checker {false};
    int checkerincrement {0};
    for (int i{0}; i < 3; i++)
    {
        for (int j{0}; j < 3; j++)
        {
            if (plato[i][j] == player1.symbol || plato[i][j] == player2.symbol)
            {
                checkerincrement++;
            }
        }
    }
    if (checkerincrement == 9){
        checker = true;
    }
    return checker;
}