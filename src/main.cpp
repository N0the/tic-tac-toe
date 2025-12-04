#include <iostream>
#include <array>
#include "Player.hpp"
#include "Board.hpp"

int main()
{
    Player Playertest = create_player();
    std::array<char,3> tablo = {1,2,3};
    std::array<std::array<char,3>,3> tablo2 ={tablo,tablo,tablo};
    draw_game_board(tablo2);
    return 0;
}