#include <iostream>
#include "Checker.hpp"
#include <array>

bool CheckerInputBoard(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &Board, int &row, int &column)
{
    if (Board[row][column] != player1.symbol && Board[row][column] != player2.symbol)
        return true;

    return false;
}
bool CheckerFilledBoard(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &Board)
{
    bool checker{false};
    int checkerincrement{0};
    for (int i{0}; i < 3; i++)
    {
        for (int j{0}; j < 3; j++)
        {
            if (Board[i][j] == player1.symbol || Board[i][j] == player2.symbol)
            {
                checkerincrement++;
            }
        }
    }
    if (checkerincrement == 9)
    {
        checker = true;
    }
    return checker;
}

bool CheckerWin(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &Board)
{

}