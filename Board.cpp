#include "Board.h"

Board::Board()
{
    m_size = 0;
    m_arr == NULL;
}
Board::Board(int size)
{
    if(size > 10)
    {
        m_size = 10;
    }
    else if(size < 4)
    {
        m_size = 4;
    }
    else 
    {
        m_size = size;
    }
    m_arr = new Point* [m_size];
    for(int i = 0; i < m_size; i++)
    {
        m_arr[i] = new Point[size];
    }
}
Board::~Board()
{
    for(int i = 0; i < m_size; i++) delete[] m_arr[i];
    delete[] m_arr;
}
void Board::setSize(int size)
{
    m_size = size;
}
int Board::getSize()
{
    return m_size;
}
int Board::getXAt(int i, int j)
{
    return m_arr[i][j].getX();
}
int Board::getYAt(int i, int j)
{
    return m_arr[i][j].getY();
}
void Board::setXO(int i, int j, int value)
{
    if(m_size == 0) return;
    m_arr[i][j].setCheck(value);
}
int Board::getXO(int i, int j)
{
    return m_arr[i][j].getCheck();
}