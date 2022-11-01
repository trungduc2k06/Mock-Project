#ifndef _VIEW_H_
#define _VIEW_H_

#include "Library.h"
#include "Board.h"
#include "Game.h"

class View
{
    public:
		void drawBoard(Board*);
		void drawGameScreen(Game*);
		void menuHeader(char);
        void mainMenu();
		void gameOverMenu();
		void askToSaveReplay();
		void replay();
		void playerInformationMenu();
		void showAllPlayer();
		void searchPlayerByName();
		void guide();
		void userInformation();
		void startGame();
};

#endif