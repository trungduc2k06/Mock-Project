#include "View.h"

void View::drawGameScreen()
{
    showInput("Player: ");
    //showInput(m_user1.getName(), P1);
    m_inOut.showNamePlayer1();
    showInput(" = ", YELLOW);
    showInput("X, ", P1);
    showInput("Player: ", BLACK);
    //showInput(m_user2.getName(), P2);
    m_inOut.showNamePlayer2();
    showInput(" = ", YELLOW);
    showInput("O:", P2);
    showInput("\n");
    m_board.drawBoard();
}
void View::mainMenu()
{
    showInput("*-------", YELLOW);
    showInput("MAIN MENU");
    showInput("-------*\n", YELLOW);
    showInput("1.New ", RED);
    showInput("game \n");
    showInput("2.Replay\n", RED);
    showInput("3.Players' Information\n", RED);
    showInput("4.Guide\n", RED);
    showInput("5.Exit\n", RED);
    showInput("Press number to choice:");
}
void View::gameOverMenu()
{

}
void View::playerInformationMenu()
{

}
void View::showAllPlayer()
{

}
void View::searchPlayerByName()
{

}
void View::guide()
{
    showInput("*-------", YELLOW);
    showInput("Guide");
    showInput("-------*\n", YELLOW);
    showInput("*Trong qua trinh choi, ban lan luot nhap toa do vi tri muon danh = (so dong, so cot)\n");
    showInput("*Ban khong duoc nhap vao vi tri da duoc danh dau hoac ngoai pham vi ban co, neu nhap sai se phai nhap lai\n");
    showInput("*Dieu kien de chien thang tro choi la ben nao co duoc 4 quan co lien tiep theo duong cheo, hang ngang hay \ncot doc truoc va chi bi chan mot dau\n");
    showInput(" VD: XXXX -> Win\n");
    showInput("     OXXXX -> Win\n");
    showInput("     OXXXXO -> NO Win\n");
    showInput("     OXXXX O -> Win\n");
    showInput("*Neu ma tat ca cac o bi danh dau het ma chua co nguoi thang thi 2 nguoi choi se hoa nhau\n");
    showInput("*Tro choi se chi dung lai khi mot trong hai nguoi choi thang hoac ca hai hoa nhau\n");
    showInput("*Thank you! Chuc ban choi vui ve\n");
}
void View::userInformation()
{

}
void View::startGame()
{
    m_control.newGame();
    while (m_isContinue)
    {
        system("cls");
        mainMenu();
        m_control.inputOption();
        switch(m_control.getOption())
        {
        case t_play:
            system("cls");
            setColor(15);
            m_inOut.inputPlayerAccount();
            while(m_control.getOption() != '0')
            {
                if(m_game.isWonGame() == false)
                {
                    system("cls");
                    drawGameScreen();
                    if(!m_control.checkFullBoard())
                    {
                        m_control.updateDrawRecord();
                        showInput("DRAW!\n", YELLOW);
                        showInput("1.Play again\n", RED);
                        showInput("2.Back to MAIN MENU\n", RED);
                        showInput("Press number to choice: ");
                        m_control.inputOption();
                        while (m_control.getOption() < '1' || m_control.getOption() > '2')
                        {
                            showInput("Press again!");
                            m_control.inputOption();
                        }
                        switch (m_control.getOption())
                        {
                        case '1':
                            m_control.newGame();
                            break;
                        case '2':
                            m_control.newGame();
                            m_control.setOption('0');
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        m_control.playInBoard();
                    }
                }
                if(m_game.isWonGame() == true)
                {
                    m_control.updateWinLoseRecord();
                    system("cls");
                    drawGameScreen();
                    showInput("Player: ");
                    if(m_game.getPlayerWon() == VX)
                    {
                        showInput(m_user1.getName(), P1);
                    }
                    else if(m_game.getPlayerWon() == VO)
                    {
                        showInput(m_user2.getName(), P2);
                    }
                    showInput(" won!\n", YELLOW);
                    showInput("1.Play again\n", RED);
                    showInput("2.Back to MAIN MENU\n", RED);
                    showInput("Press number to choice: ");
                    m_control.inputOption();
                    while (m_control.getOption() < '1' || m_control.getOption() > '2')
                    {
                        showInput("Press again!");
                        m_control.inputOption();
                    }
                    switch (m_control.getOption())
                    {
                    case '1':
                        m_control.newGame();
                        break;
                    case '2':
                        m_control.newGame();
                        m_control.setOption('0');
                        break;
                    default:
                        break;
                    }
                }
            }
            break;
            case t_replay:
                break;
            case t_info:
                break;
            case t_guide:
                while(m_control.getOption() != '0')
                {
                    system("cls");
                    guide();
                    showInput("1.Back to MAIN MENU\n", RED);
                    showInput("Press number to choice: ");
                    m_control.inputOption();
                    if(m_control.getOption() == '1')
                    {
                        m_control.setOption('0');
                    }
                }
                break;
            case t_exit:
                m_isContinue = 0;
                break;
        default:
            break;
        }
    }
    
}