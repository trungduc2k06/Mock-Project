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

void InOut::inputSizeBoard()
{
    int size;
    showInput("Input size board: ");
    cin >> size;
    m_board.setSize(size);
}
void InOut::inputPlayerAccount()
{
    m_player1->initPlayer();
    showInput("Input player 1: \n");
    m_player1->setName(inputPlayerName());
    m_player2->initPlayer();
    showInput("Input player 2: \n");
    m_player2->setName(inputPlayerName());
}
void InOut::showNamePlayer1()
{
    showInput(m_player1->getName(), P1);
}
void InOut::showNamePlayer2()
{
    showInput(m_player2->getName(), P2);
}
void InOut::inputPlayerMove()
{
    int inputCol, inputRow;
    if(m_game.getTurn() == true)
    {
        showInput("Player ");
        showInput(m_player1->getName() + "'s ", P1);
        showInput("turn:");
        do
        {
            cin >> inputRow;
            cin >> inputCol;
        }while((inputRow < 0) || (inputCol < 0) || (inputCol > m_board.getSize() - 1) || (inputRow > m_board.getSize() - 1) || (m_board.getXO(inputCol, inputRow) != 0));
        m_board.setXO(inputCol, inputRow, VX);
    }
    if(m_game.getTurn() == false)
    {
        showInput("Player ");
        showInput(m_player2->getName() + "'s ", P2);
        showInput("turn:");
        do
        {
            cin >> inputRow;
            cin >> inputCol;
        }while((inputRow < 0) || (inputCol < 0) || (inputCol > m_board.getSize() - 1) || (inputRow > m_board.getSize() - 1) || (m_board.getXO(inputCol, inputRow) != 0));
        m_board.setXO(inputCol, inputRow, VO);
    }
}
