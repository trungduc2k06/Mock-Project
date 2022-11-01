#include "Game.h"

Game::Game()
{
    m_exit = false;
    m_turn = true;
    m_wongame = false;
    m_playerwon = 0;
}
Game::Game(int size)
{
    m_board = new Board(size);
    m_exit = false;
    m_turn = true;
    m_wongame = false;
    m_playerwon = 0;
    m_player1.setWin(0);
    m_player1.setLose(0);
    m_player1.setDraw(0);
    m_player2.setWin(0);
    m_player2.setLose(0);
    m_player2.setDraw(0);
}
Game::~Game()
{
    delete m_board;
}
void Game::initGame(int size)
{
    m_board = new Board(size);
    m_exit = false;
    m_turn = true;
    m_wongame = false;
    m_playerwon = 0;
    m_player1.setWin(0);
    m_player1.setLose(0);
    m_player1.setDraw(0);
    m_player2.setWin(0);
    m_player2.setLose(0);
    m_player2.setDraw(0);
}
void Game::setPlayer1(Player player1)
{
    m_player1 = player1;
}
Player& Game::getPlayer1()
{
    return m_player1;
}
void Game::setPlayer2(Player player2)
{
    m_player2 = player2;
}
Player& Game::getPlayer2()
{
    return m_player2;
}
void Game::setTurn(bool turn)
{
    m_turn = turn;
}
bool Game::getTurn()
{
    return m_turn;
}
Board* Game::getBoard()
{
    return m_board;
}
void Game::setExit(bool exit)
{
    m_exit = exit;
}
bool Game::getExit()
{
    return m_exit;
}
bool Game::isWonGame()
{
    return m_wongame;
}
void Game::setWonGame(bool wongame)
{
    m_wongame = wongame;
}
void Game::setPlayerWon(int playerwon)
{
    m_playerwon = playerwon;
}
int Game::getPlayerWon()
{
    return m_playerwon;
}
void Game::saveMove(int col, int row, int value)
{
    Move move;
    move.col = col;
    move.row = row;
    move.value = value;
    replayMoves.push_back(move);
}
list<Move> Game::getReplayMoves()
{
    return replayMoves;
}
void Game::resetReplayMoves()
{
    replayMoves.clear();
}