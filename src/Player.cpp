#include <iostream>
#include <cctype>
#include "Player.hpp"

Player create_player()
{
    Player player {};
    std::cout << "Veuillez rentrer un nom : " << std::endl;
    std::cin >> player.name;
    std::cout << "Choisissez  un symbole entre X et O : " << std::endl;
    std::cin >> player.symbol;
    player.symbol = std::toupper(player.symbol);
    while (player.symbol != 'X' && player.symbol != 'O') 
    {
        std::cin.clear();
        std::cin.ignore(255,'\n');
        std::cout << "Veuillez reessayer, choisissez  un symbole entre X et O : " << std::endl;
        std::cin >> player.symbol;
        player.symbol = std::toupper(player.symbol);
    }
    std::cout << "Vous etes " << player.name << " et vous jouez les " << player.symbol << std::endl;
    return player;
};