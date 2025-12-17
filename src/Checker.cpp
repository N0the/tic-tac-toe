#include <iostream>
#include "Checker.hpp"
#include <array>

bool CheckerInputBoard(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board, int &row, int &column)
{
    if (Board[row][column] != player1.symbol && Board[row][column] != player2.symbol)
        return true;

    return false;
}
bool CheckerFilledBoard(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board)
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
bool CheckerDraw(bool CheckerFilled)
{
    if (CheckerFilled == true)
    {
        std::cout << "Partie terminee, egalite !" << std::endl;
        return true;
    };
    return false;
}

bool CheckerWin(const Player &player1, std::array<std::array<char, 3>, 3> &Board)
{
    /* Check lignes*/
    for (int i = 0; i < 3; ++i)
    {
        if (Board[i][0] == player1.symbol && Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2])
        {
            std::cout << "Partie terminee, " << player1.name << " a gagne !" << std::endl;
            return true;
        }
    }
    /* Check colonnes*/
    for (int j = 0; j < 3; ++j)
    {
        if (Board[0][j] == player1.symbol && Board[0][j] == Board[1][j] && Board[1][j] == Board[2][j])
        {
            std::cout << "Partie terminee, " << player1.name << " a gagne !" << std::endl;
            return true;
        }
    }
    /*Check diagonales*/
    if (Board[0][0] == player1.symbol &&
        Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
    {
        std::cout << "Partie terminee, " << player1.name << " a gagne !" << std::endl;
        return true;
    }

    if (Board[0][2] == player1.symbol && Board[0][2] == Board[1][1] && Board[1][1] == Board[2][0])
    {
        std::cout << "Partie terminee, " << player1.name << " a gagne !" << std::endl;
        return true;
    }
    
    return false;
}