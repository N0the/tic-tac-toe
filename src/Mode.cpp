#include <iostream>
#include "Mode.hpp"
#include <array>

int ModeJeu()
{
    int mode = {};
    std::cout << "Veuillez choisir un mode de jeu :\n"
                 "1. Jouer avec un autre joueur\n"
                 "2. Jouer avec une IA\n"
              << std::endl;
    std::cin >> mode;
    while (mode != 1 && mode != 2)
    {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Mauvaise valeur entree :\n"
                     "Veuillez choisir un mode de jeu entre 1 et 2 :\n"
                     "1. Jouer avec un autre joueur\n"
                     "2. Jouer avec une IA\n"
                  << std::endl;
        std::cin >> mode;
    }
    std::cout << "Vous avez choisi le mode " << mode << ", bonne partie !" << std::endl;
    return mode;
}