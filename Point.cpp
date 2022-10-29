#include "Point.h"

Point::Point()
{
    m_x = 0;
    m_y = 0;
    m_check = 0;
}
Point::Point(int x, int y)
{
    m_x = x;
    m_y = y;
    m_check = 0;
}
Point::~Point()
{

}
int Point::getX()
{
    return m_x;
}
int Point::getY()
{
    return m_y;
}
int Point::getCheck()
{
    return m_check;
}
void Point::setX(int x)
{
    m_x = x;
}
void Point::setY(int y)
{
    m_y = y;
}
bool Point::setCheck(int check)
{
    if(check == 0 || check == VX || check == VO)
    {
        m_check = check;
        return true;
    }
    return false;
}