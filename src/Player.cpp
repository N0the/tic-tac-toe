#include <iostream>
#include <cctype>
#include "Player.hpp"

Player create_player()
{
    std::string name{""};
    char symbol{' '};
    std::cout << "Veuillez rentrer un nom : " << std::endl;
    std::cin >> name;
    std::cout << "Choisissez  un symbole entre X et O : " << std::endl;
    std::cin >> symbol;
    symbol = std::toupper(symbol);
    while (symbol == 'X' && symbol == 'O') // censez être ||
    {
        std::cout << "Veuillez reessayer, choisissez  un symbole entre X et O : " << std::endl;
        std::cin >> symbol;
        symbol = std::toupper(symbol);
    }
    Player joueur = {
        name,
        symbol
    };
    std::cout << "Vous etes " << joueur.name << " et vous jouez les " << joueur.symbol << std::endl;
    return joueur;
};