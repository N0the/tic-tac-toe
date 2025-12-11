#include <iostream>
#include "Mode.hpp"
#include "Checker.hpp"
#include <array>

std::array<std::array<char, 3>, 3> PlayerTurn(Player &player1, Player &player2, std::array<std::array<char, 3>, 3> &plato)
{
    bool CheckerInputBoardVar = true;
    int PositionX{0};
    int PositionY{0};
    while (CheckerInputBoardVar == true)
    {
        std::cout << "Choisissez une case du morpion entre 1 et 9 : " << std::endl;
        while (PositionX < 0 || PositionX > 9 || !(std::cin >> PositionX))
        {
            std::cout << "Mauvaise valeur, choisissez une case valable du morpion entre 1 et 9 : " << std::endl;
            std::cin >> PositionX;
        }
        PositionX--;
        int row = PositionX / 3;
        int column = PositionX % 3;
        plato[row][column] = player1.symbol;
        CheckerInputBoardVar = CheckerInputBoard(player1, player2, plato, row, column);
    }
    return plato;
}

int ModeJeu()
{
    int mode = {0};
    std::cout << "Veuillez choisir un mode de jeu :\n"
                 "1. Jouer avec un autre joueur\n"
                 "2. Jouer avec une IA\n"
              << std::endl;
    std::cin >> mode;
    while (mode != 1 && mode != 2)
    {
        std::cout << "Mauvaise valeur entrée :\n"
                     "Veuillez choisir un mode de jeu entre 1 et 2 :\n"
                     "1. Jouer avec un autre joueur\n"
                     "2. Jouer avec une IA\n"
                  << std::endl;
        std::cin >> mode;
    }
    return mode;
}