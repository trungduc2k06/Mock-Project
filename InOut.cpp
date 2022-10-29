#include "InOut.h"

string InOut::inputPlayerName()
{
    string name;
    showInput("Input name: ");
    fflush(stdin);
    getline(cin, name);
    while (!checkName(name))
    {
        showInput("Input name: ");
        fflush(stdin);
        getline(cin, name);
    }    
    return name;
}
string InOut::inputPlayerAccount()
{
    m_player1.initPlayer();
    showInput("Input player 1: ");
    m_player1.setName(inputPlayerName());
    m_player2.initPlayer();
    showInput("Input player 2: ");
    m_player2.setName(inputPlayerName());
}
InOut::inputPlayerMove()
{
    int inputCol, inputRow;
    if(m_game.getTurn() == true)
    {
        showInput("Player ", WHITE);
        showInput(m_player1.getName() + "'s ", P1);
        showInput("turn:", WHITE);
        do
        {
            cin >> inputRow;
            cin >> inputCol;
        }while((inputRow < 0) || (inputCol < 0) || (inputCol > m_board.getSize() - 1) || (inputRow > m_board.getSize() - 1) || (m_board.getXO(inputCol, inputRow) != 0);
        m_board.setXO(inputCol, inputRow, VX);
    }
    if(m_game.getTurn() == false)
    {
        showInput("Player ", WHITE);
        showInput(m_player2.getName() + "'s ", P2);
        showInput("turn:", WHITE);
        do
        {
            cin >> inputRow;
            cin >> inputCol;
        }while((inputRow < 0) || (inputCol < 0) || (inputCol > m_board.getSize() - 1) || (inputRow > m_board.getSize() - 1) || (m_board.getXO(inputCol, inputRow) != 0);
        m_board.setXO(inputCol, inputRow, VO);
    }
}