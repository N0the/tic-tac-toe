#include <iostream>
#include "Gameplay.hpp"
#include "Checker.hpp"
#include "Board.hpp"
#include <array>
#include <vector>

std::array<std::array<char, 3>, 3> PlayerTurn(const Player &player1, const Player &player2, std::array<std::array<char, 3>, 3> &Board)
{
    bool CheckerInputBoardVar = false;
    int PositionX{0};
    while (CheckerInputBoardVar == false)
    {
        std::cout << player1.name << ", choisissez une case valable du morpion entre 1 et 9 : " << std::endl;
        while (!(std::cin >> PositionX) || PositionX < 1 || PositionX > 9)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Mauvaise valeur " << player1.name << ", choisissez une case valable du morpion entre 1 et 9 : " << std::endl;
        }
        PositionX--;
        int row = PositionX / 3;
        int column = PositionX % 3;
        CheckerInputBoardVar = CheckerInputBoard(player1, player2, Board, row, column);
        if (CheckerInputBoardVar == false)
        {
            std::cout << "Case deja prise" << std::endl;
            continue;
        }
        else
        {
            Board[row][column] = player1.symbol;
        }
    }
    draw_game_board(Board);
    return Board;
}
std::array<std::array<char, 3>, 3> IATurn(const Player &player, const Player &IA, std::array<std::array<char, 3>, 3> &Board)
{
    std::cout << "C'est au tour de l'IA : " << std::endl;
    // Coup gagnant pour l'ia ?
    std::array<int, 2> IAWinningMove = CheckerWinningMove(IA, Board);
    if (IAWinningMove[0] != -1)
    {
        Board[IAWinningMove[0]][IAWinningMove[1]] = IA.symbol;
        int IAMovePrint = IAWinningMove[0] * 3 + IAWinningMove[1] + 1;
        std::cout << "L'IA a joue a la position " << IAMovePrint << '.' << std::endl;
        draw_game_board(Board);
        return Board;
    }
    // Coup gagnant pour le joueur ? => bloquer le coup
    std::array<int, 2> BlockingMove = CheckerWinningMove(player, Board);
    if (BlockingMove[0] != -1)
    {
        Board[BlockingMove[0]][BlockingMove[1]] = IA.symbol;
        int IAMovePrint = BlockingMove[0] * 3 + BlockingMove[1] + 1;
        std::cout << "L'IA a joue a la position " << IAMovePrint << '.' << std::endl;
        draw_game_board(Board);
        return Board;
    }

    // Play aléatoire
    std::vector<std::array<int, 2>> PlayAvailable{};
    for (int i{0}; i < Board.size(); ++i)
    {
        for (int j{0}; j < Board.size(); ++j)
        {
            if (Board[i][j] >= '1' && Board[i][j] <= '9')
            {
                PlayAvailable.push_back({i, j});
            }
        }
    }
    if (!PlayAvailable.empty())
    {
        int IARandomPlay = rand() % PlayAvailable.size();
        int row = PlayAvailable[IARandomPlay][0];
        int column = PlayAvailable[IARandomPlay][1];
        int IAMovePrint = row * 3 + column + 1;
        Board[row][column] = IA.symbol;
        std::cout << "L'IA a joue a la position " << IAMovePrint << '.' << std::endl;
        draw_game_board(Board);
    }
    return Board;
}
int GamePlayMode1(const Player &Player1, std::array<std::array<char, 3>, 3> &Board)
{
    std::cout
        << "Deuxieme joueur alors !" << std::endl;
    Player Player2 = create_player();
    while (Player1.symbol == Player2.symbol)
    {
        std::cout << "Vous ne pouvez pas choisir le meme symbole..." << std::endl;
        Player2 = create_player();
    }
    bool CheckerFilled = CheckerFilledBoard(Board);
    bool result = false;
    while (CheckerFilled == false)
    {
        // Joueur 1
        Board = PlayerTurn(Player1, Player2, Board);
        CheckerFilled = CheckerFilledBoard(Board);
        if (CheckerWin(Player1, Board))
        {
            break;
        };
        if (result = CheckerDraw(CheckerFilled))
        {
            break;
        }
        // Joueur 2
        Board = PlayerTurn(Player2, Player1, Board);
        CheckerFilled = CheckerFilledBoard(Board);
        if (CheckerWin(Player2, Board))
        {
            break;
        };
        if (result = CheckerDraw(CheckerFilled))
        {
            break;
        }
    }
    return 0;
}

int GamePlayMode2(const Player &Player1, std::array<std::array<char, 3>, 3> &Board)
{
    std::cout
        << "Tu es contre l'IA maintenant, bonne chance..." << std::endl;

    Player IA{"IA", ' '};
    if (Player1.symbol == 'X')
    {
        IA.symbol = 'O';
        std::cout
            << "Voici son symbole : " << IA.symbol << std::endl;
    }
    else
    {
        IA.symbol = 'X';
        std::cout
            << "Voici son symbole : " << IA.symbol << std::endl;
    }
    bool CheckerFilled = CheckerFilledBoard(Board);
    bool result = false;
    while (CheckerFilled == false)
    {
        // Joueur
        Board = PlayerTurn(Player1, IA, Board);
        CheckerFilled = CheckerFilledBoard(Board);
        if (CheckerWin(Player1, Board))
        {
            break;
        };
        if (result = CheckerDraw(CheckerFilled))
        {
            break;
        }
        // IA
        Board = IATurn(Player1, IA, Board);
        CheckerFilled = CheckerFilledBoard(Board);
        if (CheckerWin(IA, Board))
        {
            break;
        };
        if (result = CheckerDraw(CheckerFilled))
        {
            break;
        }
    }
    return 0;
}