#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Library.h"
#include "Board.h"

class Controller
{
    private:
        Board m_board;
    public:
        Controller();
        ~Controller();
        bool horiWin(int, int);
        bool vertiWin(int, int);
        bool lCrossWin(int, int);
        bool rCrossWin(int, int);
        void checkWinGame();
        void updateWinLoseRecord();
        void updateDrawRecord();
        void changePlayer();
		void playInBoard();
		void resetGame();
};

#endif