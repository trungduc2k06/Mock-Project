#ifndef _GAME_H_
#define _GAME_H_

#include "Board.h"
#include "Player.h"

class Game
{
    private:
        Player m_player1;
        Player m_player2;
        Board* m_board;
        bool m_turn; //Luat: true -> nguoi 1 choi, false -> nguoi 2 choi
        bool m_exit; //quyet dinh thoat game hay khong
        bool m_wongame;//kiem tra game da co nguoi thang chua
        int m_playerwon;//Luu nguoi thang game
    public:
        Game(int);
        ~Game();
        void initGame(int);
		void setPlayer1(Player);
		Player& getPlayer1();
		void setPlayer2(Player);
		Player& getPlayer2();
		void setTurn(bool);
		bool getTurn();
		Board* getBoard();
		void setExit(bool);
		bool getExit();
		bool isWonGame();
		void setWonGame(bool);
		void setPlayerWon(int);
		int getPlayerWon();
};

#endif