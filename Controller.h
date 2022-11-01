#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Library.h"
#include "Game.h"
#include "View.h"
#include "Validation.h"
#include "FileFunction.h"

class Controller
{
    private:
        Game* m_game;
        View* m_view;
    public:
        Controller(Game*, View*);
        ~Controller();
        char inputOption();
        //Controller
        void initGame(int);
        bool isContinue();
        void exitGame();

        void resetBoard();
        bool checkFullBoard();
        bool horiWin(int, int);
        bool vertiWin(int, int);
        bool lCrossWin(int, int);
        bool rCrossWin(int, int);

        void checkWinGame();
        void updateWinLoseRecord();
        void updateDrawRecord();
        void replayLastGame();
		void replayGameById(char);
        void playerInputAccount();
        void playerChooseAccount();
        void playerInputMove();
        void changePlayer();
		void playInBoard();
        void newGame();
        //Flow of game
        void mainMenu();
        void playWithOtherPlayer();
        void gameOverMenu();
        void askToSaveReplay();
		void replay();
        void playerInformationMenu();
		void showAllPlayer();
		void searchPlayerByName();
		void guide();
        void startGame();
};

#endif