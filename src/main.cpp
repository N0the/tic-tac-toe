#include <iostream>
#include <array>
#include "Player.hpp"
#include "Board.hpp"
#include "Mode.hpp"
#include "Checker.hpp"
#include "Gameplay.hpp"

int main()
{
    const Player Player1 = create_player();
    std::array<std::array<char, 3>, 3> Board = createBoard();
    draw_game_board(Board);
    int Mode2Jeu = ModeJeu();
    if (Mode2Jeu == 1)
    {
        GamePlayMode1(Player1, Board);
    }
    else
    {
        GamePlayMode2(Player1, Board);
    }
    return 0;
}
