#include <iostream>
#include <array>
#include "Player.hpp"
#include "Board.hpp"
#include "Mode.hpp"

int main()
{
    Player Player1 = create_player();
    std::array<char,3> tablo1 = {'1','2','3'};
    std::array<char,3> tablo2 = {'4','5','6'};
    std::array<char,3> tablo3 = {'7','8','9'};
    std::array<std::array<char,3>,3> tablo4 ={tablo1,tablo2,tablo3};
    draw_game_board(tablo4);
    int Mode2Jeu = ModeJeu();
    
    return 0;
}
