#ifndef _INOUT_H_
#define _INOUT_H_

#include "Library.h"
#include "Player.h"
#include "Game.h"
#include "Board.h"
#include "Validation.h"

class InOut
{
    private:
        Player* m_player1 = new Player;
        Player* m_player2 = new Player;
        Board m_board;
        Game m_game;
    public:
        string inputPlayerName();
        void inputSizeBoard();
        void showNamePlayer1();
        void showNamePlayer2();
        void inputPlayerAccount();
        void inputPlayerMove();
};

#endif