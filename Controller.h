#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Library.h"
#include "Board.h"
#include "Game.h"
#include "InOut.h"

class Controller
{
    private:
        Board m_board;
        Game m_game;
        InOut m_inOut;
        char m_option;
    public:
        void inputOption();
        void setOption(char);
        char getOption();
        bool checkFullBoard();
        bool horiWin(int, int);
        bool vertiWin(int, int);
        bool lCrossWin(int, int);
        bool rCrossWin(int, int);
        void checkWinGame();
        void updateWinLoseRecord();
        void updateDrawRecord();
        void changePlayer();
		void playInBoard();
        void newGame();
};

#endif