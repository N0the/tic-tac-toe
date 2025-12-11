#include <iostream>
#include <array>
#include "Board.hpp"
void draw_game_board(std::array<std::array<char, 3>, 3> &plato)
{
    for (int i{0}; i < 3; i++)
    {
        for (int j{0}; j < 3; j++)
        {
            std::cout <<" | "<< plato[i][j];
        }
        std::cout << " |" << std::endl;
    }
};

