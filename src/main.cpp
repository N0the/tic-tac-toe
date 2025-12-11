#include <iostream>
#include <array>
#include "Player.hpp"
#include "Board.hpp"
#include "Mode.hpp"
#include "Checker.hpp"

int main()
{
    Player Player1 = create_player();
    std::array<std::array<char, 3>, 3> Board = {{{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}};
    draw_game_board(Board);
    int Mode2Jeu = ModeJeu();
    if (Mode2Jeu == 1)
    {
        std::cout << "Deuxieme joueur alors !" <<std::endl;
        Player Player2 = create_player();
        if (Player1.symbol == Player2.symbol)
        {
            std::cout << "Vous ne pouvez pas choisir le meme symbole ou le meme nom..." <<std::endl;
            Player2 = create_player();
        }
        bool CheckerFilled = CheckerFilledBoard(Player1, Player2, Board);
        while (CheckerFilled == false)
        {
            Board = PlayerTurn(Player1, Player2, Board);
            CheckerFilled = CheckerFilledBoard(Player1, Player2, Board);
            if (CheckerFilled == true)
            {
                std::cout << "Partie terminee, egalite !" << std::endl;
                break;
            };
            Board = PlayerTurn(Player2, Player1, Board);
            if (CheckerFilled == true)
            {
                std::cout << "Partie terminee, egalite !" << std::endl;
                break;
            };
        }
    }

    return 0;
}
