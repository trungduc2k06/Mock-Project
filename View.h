#ifndef _VIEW_H_
#define _VIEW_H_

#include "Library.h"

class View
{
    private:
        
    public:
        View();
        ~View();
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