#include <iostream>
#include <array>
#include "Board.hpp"
void draw_game_board(std::array<std::array<char, 3>, 3> &Board)
{
    for (int i{0}; i < 3; i++)
    {
        for (int j{0}; j < 3; j++)
        {
            std::cout <<" | "<< Board[i][j];
        }
        std::cout << " |" << std::endl;
    }
};

std::array<std::array<char, 3>, 3> createBoard() {
    std::array<std::array<char, 3>, 3> Board;

    char value = '1';
    for (size_t i {0}; i < Board.size(); ++i) {
        for (size_t j {0}; j < Board.size(); ++j) {
            Board[i][j] = value++;
        }
    }

    return Board;
}

