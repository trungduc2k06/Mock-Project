#include "Controller.h"

void Controller::inputOption()
{
    char op;
    cin >> op;  
    if(op >= '0' && op <= '9')
    {
        m_option = op;
    }
}
void Controller::setOption(char op)
{
    m_option = op;
}
char Controller::getOption()
{
    return m_option;
}
bool Controller::checkFullBoard()
{
    int count = 0;
    for(int x = 0; x <= m_board.getSize() - 1; x++)
    {
        for(int y = 0; y <= m_board.getSize() - 1; y++)
        {
            if(m_board.getXO(x, y) == 0)
            {
                count++;
            }
        }
    }
    if(count == 0) return true;
    return false;
}
bool Controller::horiWin(int x, int y)
{
    if(m_board.getXO(x, y) == 0) return false;
    int player1 = m_board.getXO(x, y);
    int count = 0;
    int opcount = 0;
    for(int i = x; i >= 0; i--)
    {
        if(m_board.getXO(i, y) == player1)
        {
            count++;
        }
        else if(m_board.getXO(i,y) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    for(int i = x + 1; i <= m_board.getSize() - 1; i++)
    {
        if(m_board.getXO(i, y) == player1)
        {
            count++;
        }
        else if(m_board.getXO(i, y) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    if(opcount >= 2) return false;
    if(count >= 4) return true;
    return false;
}
bool Controller::vertiWin(int x, int y)
{
    if(m_board.getXO(x, y) == 0) return false;
    int player1 = m_board.getXO(x, y);
    int count = 0;
    int opcount = 0;
    for(int i = y; i >= 0; i--)
    {
        if(m_board.getXO(x, i) == player1)
        {
            count++;
        }
        else if(m_board.getXO(x, i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    for(int i = y + 1; i <= m_board.getSize() - 1; i++)
    {
        if(m_board.getXO(x, i) == player1)
        {
            count++;
        }
        else if(m_board.getXO(x, i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    if(opcount >= 2) return false;
    if(count >= 4) return true;
    return false;
}
bool Controller::lCrossWin(int x, int y)
{
    if(m_board.getXO(x, y) == 0) return false;
    int player1 = m_board.getXO(x, y);
    int count = 0;
    int opcount = 0;
    int m = min(x, y);
    for(int i = 0; i <= m; i++)
    {
        if(m_board.getXO(x - i, y - i) == player1)
        {
            count++;
        }
        else if(m_board.getXO(x - i, y - i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(m_board.getSize() - x, m_board.getSize() - y);
    for(int i = 1; i <= m; i++)
    {
        if(m_board.getXO(x + i, y + i) == player1)
        {
            count++;
        }
        else if(m_board.getXO(x +i, y + i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    if(opcount >= 2) return false;
    if(count >= 4) return true;
    return false;
}
bool Controller::rCrossWin(int x, int y)
{
    if(m_board.getXO(x, y) == 0) return false;
    int player1 = m_board.getXO(x, y);
    int count = 0;
    int opcount = 0;
    int m = min(x, m_board.getSize() - y);
    for(int i = 0; i <= m; i++)
    {
        if(m_board.getXO(x - i, y + i) == player1)
        {
            count++;
        }
        else if(m_board.getXO(x - i, y + i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(m_board.getSize() - x, y);
    for(int i = 1; i <= m; i++)
    {
        if(m_board.getXO(x + i, y - i) == player1)
        {
            count++;
        }
        else if(m_board.getXO(x + i, y - i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    if(opcount >= 2) return false;
    if(count >= 4) return true;
    return true;
}
void Controller::checkWinGame()
{
    for(int x = 0; x <= m_board.getSize() - 1; x++)
    {
        for (int y = 0; y < m_board.getSize() - 1; y++)
        {
            if(horiWin(x, y) || vertiWin(x, y) || lCrossWin(x, y) || rCrossWin(x, y))
            {
                m_game.setWonGame(true);
                m_game.setPlayerWon(m_board.getXO(x,y));
                if(m_game.isWonGame() == true) break;
            }
        }
        if(m_game.isWonGame() == true) break;
    }
}
void Controller::updateWinLoseRecord()
{
    Player player1 = m_game.getPlayer1();
    Player player2 = m_game.getPlayer2();
    if(m_game.getPlayerWon() == VX)
    {
        player1.increWin();
        player2.increLose();
    }
    else if(m_game.getPlayerWon() == VO)
    {
        player1.increLose();
        player2.increWin();
    }
}
void Controller::updateDrawRecord()
{
    Player player1 = m_game.getPlayer1();
    Player player2 = m_game.getPlayer2();
    player1.increDraw();
    player2.increDraw();
}
void Controller::changePlayer()
{
    if(m_game.getTurn() == true)
    {
        m_game.setTurn(false);
    }
    else if(m_game.getTurn() == false)
    {
        m_game.setTurn(true);
    }
}
void Controller::playInBoard()
{
    m_inOut.inputPlayerMove();
    changePlayer();
    checkWinGame();
}
void Controller::newGame()
{
    m_board.resetBoard();
    m_game.setTurn(true);
    m_game.setExit(false);
    m_game.setWonGame(false);
    m_game.setPlayerWon(0);
}