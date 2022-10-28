#include "Player.h"

Player::Player()
{
    m_name = " ";
    m_win = 0;
    m_lose = 0;
    m_draw = 0;
}
Player::~Player()
{

}
void Player::setName(string name)
{
    m_name = name;
}
string Player::getName()
{
    return m_name;
}
void Player::setWin(int win)
{
    m_win = win;
}
void Player::setLose(int lose)
{
    m_lose = lose;
}
void Player::setDraw(int draw)
{
    m_draw = draw;
}
int Player::getWin()
{
    return m_win;
}
int Player::getLose()
{
    return m_lose;
}
int Player::getDraw()
{
    return m_draw;
}
void Player::increWin()
{
    m_win++;
}
void Player::increLose()
{
    m_lose++;
}
void Player::increDraw()
{
    m_draw++;
}