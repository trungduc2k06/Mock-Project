#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Library.h"

class Player
{
    private:
        string m_name;
        int m_win;
        int m_lose;
        int m_draw;
    public:
        Player();
        ~Player();
		void initPlayer();
		void setName(string);
        string getName();
		void setWin(int);
		void setLose(int);
		void setDraw(int);
		int getWin();
		int getLose();
		int getDraw();
		void increWin();
		void increLose();
		void increDraw();
};

#endif