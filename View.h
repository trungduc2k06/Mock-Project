#ifndef _VIEW_H_
#define _VIEW_H_

#include "Library.h"
#include "Player.h"
#include "InOut.h"
#include "Board.h"
#include "Game.h"
#include "Controller.h"

class View
{
    private:
		InOut m_inOut;
		Board m_board;
		Game m_game;
		Controller m_control;
		bool m_isContinue = 1;
    public:
		Player m_user1 = m_game.getPlayer1();
		Player m_user2 = m_game.getPlayer2();
		void drawGameScreen();
        void mainMenu();
		void gameOverMenu();
		void playerInformationMenu();
		void showAllPlayer();
		void searchPlayerByName();
		void guide();
		void userInformation();
		void startGame();
};


#endif