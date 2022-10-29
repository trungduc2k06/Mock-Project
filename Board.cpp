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
int Board::setSize(int size)
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
void Board::resetBoard()
{
    if(m_size == 0) return;
    for(int i = 0; i < m_size; i++)
    {
        for(int j = 0; j < m_size; j++)
        {
            m_arr[i][j].setCheck(0);
        }
    }
}
void Board::drawBoard()
{
    for(int y = -1; y <= m_size - 1; y++) //row
    {
        for(int x = -1; x <= m_size - 1; x++) //col
        {
            if(y == -1)
            {
                if(x == -1) cout << "   ";
                else if(x >= 0 && x <= getSize() - 1)
                {
                    setColor(RED);
                    cout << "  " << x << " ";
                }
            }
            if(y >= 0 && y <= getSize() - 1)
            {
                if(x == -1)
                {
                    setColor(RED);
                    cout << " " << y << " ";
                }
                else if(x >= 0 && x <= getSize() - 1)
                {
                    setColor(YELLOW);
                    cout << "| ";
                    if(getXO(x, y) == VX)
                    {
                        setColor(P1);
                        cout << 'x';
                    }
                    else if(getXO(x, y) == VO)
                    {
                        setColor(P2);
                        cout << 'o';
                    }
                    else 
                    {
                        cout << ' ';
                    }
                    setColor(YELLOW);
                    cout << " ";
                }
                else 
                {
                    cout << "|";
                }
            }
        }
        cout << endl;
        for(int x = -1; x <= getSize() - 1; x++)
        {
            if(x == -1) cout << "   ";
            else if (x >= 0 && x <= getSize() - 1)
            {
                setColor(YELLOW);
                cout << "|---";
            }
            else cout << "|";
        }
        cout << endl;
    }
}
bool Board::checkFullBoard()
{
    int count = 0;
    for(int x = 0; x <= getSize() - 1; x++)
    {
        for(int y = 0; y <= getSize() - 1; y++)
        {
            if(getXO(x, y) == 0)
            {
                count++;
            }
        }
    }
    if(count == 0) return true;
    return false;
}
bool Board::horiWin(int x, int y)
{
    
}
bool Board::vertiWin(int, int)
{

}
bool Board::lCrossWin(int, int)
{

}
bool Board::rCrossWin(int, int)
{

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