#ifndef _BOARD_H_
#define _BOARD_H_

#include "Library.h"
#include "Point.h"

class Board
{
    private:
        int m_size;
        Point** m_arr;
    public:
        Board();
        Board(int);
        ~Board();
        int setSize(int);
        int getSize();
        int getXAt(int, int);
        int getYAt(int, int);
        void resetBoard();
        void drawBoard();
        bool checkFullBoard();
        void setXO(int, int ,int);
        int getXO(int, int);
};

#endif