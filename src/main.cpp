#include <iostream>
#include <array>
#include "Player.hpp"
#include "Board.hpp"
#include "Mode.hpp"
#include "Checker.hpp"

int main()
{
    Player Player1 = create_player();
    std::array<std::array<char,3>, 3> Tableau = {{{'1','2','3'},{'4','5','6'},{'7','8','9'}}};
    draw_game_board(Tableau);
    int Mode2Jeu = ModeJeu();
    if (Mode2Jeu == 1){
        Player Player2 = create_player();
        bool CheckerFilled = CheckerFilledBoard(Player1,Player2,Tableau);
        if (CheckerFilled == 
    }
    
    return 0;
}
