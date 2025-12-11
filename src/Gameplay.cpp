#include <iostream>
#include "Gameplay.hpp"
#include "Checker.hpp"
#include "Board.hpp"
#include <array>

std::array<std::array<char, 3>, 3> PlayerTurn(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &Board)
{
    bool CheckerInputBoardVar = false;
    int PositionX{0};
    while (CheckerInputBoardVar == false)
    {
        std::cout << player1.name << ", choisissez une case valable du morpion entre 1 et 9 : " << std::endl;
        while (!(std::cin >> PositionX) || PositionX < 1 || PositionX > 9)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Mauvaise valeur " << player1.name << ", choisissez une case valable du morpion entre 1 et 9 : " << std::endl;
        }
        PositionX--;
        int row = PositionX / 3;
        int column = PositionX % 3;
        CheckerInputBoardVar = CheckerInputBoard(player1, player2, Board, row, column);
        if (CheckerInputBoardVar == false)
        {
            std::cout << "Case deja prise" << std::endl;
            continue;
        }
        else
        {
            Board[row][column] = player1.symbol;
        }
    }
    draw_game_board(Board);
    return Board;
}