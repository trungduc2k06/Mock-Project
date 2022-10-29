#ifndef _POINT_H_
#define _POINT_H_

#include "Library.h"

class Point
{
    private:
        int m_x;
        int m_y;
        int m_check;
    public:
        Point();
        Point(int, int);
        ~Point();
        int getX();
        int getY();
        int getCheck();
        void setX(int);
        void setY(int);
        bool setCheck(int);
};

#endif