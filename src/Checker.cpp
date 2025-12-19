#include <iostream>
#include "Checker.hpp"
#include <array>

bool CheckerInputBoard(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board, int &row, int &column)
{
    if (Board[row][column] >= '1' && Board[row][column] <= '9')
        return true;

    return false;
}
bool CheckerFilledBoard(const std::array<std::array<char, 3>, 3> &Board)
{
    for (size_t i{0}; i < Board.size(); i++)
    {
        for (size_t j{0}; j < Board.size(); j++)
        {
            if (Board[i][j] >= '1' && Board[i][j] <= '9')
            {
                return false;
            }
        }
    }

    return true;
}
bool CheckerDraw(const bool CheckerFilled)
{
    if (CheckerFilled == true)
    {
        std::cout << "Partie terminee, egalite !" << std::endl;
        return true;
    };
    return false;
}

bool CheckerWin(const Player &player1, const std::array<std::array<char, 3>, 3> &Board)
{
    /* Check lignes*/
    for (size_t i{0}; i < Board.size(); i++)
    {
        if (Board[i][0] == player1.symbol && Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2])
        {
            std::cout << "Partie terminee, " << player1.name << " a gagne !" << std::endl;
            return true;
        }
    }
    /* Check colonnes*/
    for (size_t j{0}; j < Board.size(); ++j)
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

std::array<int, 2> CheckerWinningMove(const Player &player, std::array<std::array<char, 3>, 3> &Board)
{
    for (size_t i{0}; i < Board.size(); ++i)
    {
        for (size_t j{0}; j < Board.size(); ++j)
        {
            if (Board[i][j] >= '1' && Board[i][j] <= '9')
            {
                char PositionOriginal = Board[i][j];
                Board[i][j] = player.symbol;
                bool isWin = CheckerWin(player, Board);
                Board[i][j] = PositionOriginal;
                
                if (isWin)
                {
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
    }
    return {-1, -1}; // Pour contourner le problème du retour ici, je mets des coordonnées pas accessible, je ne sais pas comment faire autrement pour être honnête
}
