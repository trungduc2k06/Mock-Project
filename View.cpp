#include "View.h"

void View::drawBoard(Board* board)
{
    for(int y = -1; y <= board->getSize() - 1; y++) //row
    {
        for(int x = -1; x <= board->getSize() - 1; x++) //col
        {
            if(y == -1)
            {
                if(x == -1) cout << "   ";
                else if(x >= 0 && x <= board->getSize() - 1)
                {
                    setColor(RED);
                    cout << "  " << x << " ";
                }
            }
            if(y >= 0 && y <= board->getSize() - 1)
            {
                if(x == -1)
                {
                    setColor(RED);
                    cout << " " << y << " ";
                }
                else if(x >= 0 && x <= board->getSize() - 1)
                {
                    setColor(YELLOW);
                    cout << "| ";
                    if(board->getXO(x, y) == VX)
                    {
                        setColor(P1);
                        cout << 'x';
                    }
                    else if(board->getXO(x, y) == VO)
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
        for(int x = -1; x <= board->getSize() - 1; x++)
        {
            if(x == -1) cout << "   ";
            else if (x >= 0 && x <= board->getSize() - 1)
            {
                setColor(YELLOW);
                cout << "|---";
            }
            else cout << "|";
        }
        cout << endl;
    }
}
void View::drawGameScreen(Game* game)
{
    showInput("Player: ");
    showInput(game->getPlayer1().getName() , P1);
    showInput(" = ", YELLOW);
    showInput("X, ", P1);
    showInput("Player: ", BLACK);
    showInput(game->getPlayer2().getName() , P2);
    showInput(" = ", YELLOW);
    showInput("O:", P2);
    showInput("\n");
    drawBoard(game->getBoard());
}
void View::menuHeader(char choice)
{
    showInput("*-------", YELLOW);
    switch(choice)
    {
    case t_mainmenu:
        showInput("MAIN MENU");
        break;
    case t_playWithOther:
        showInput("Play with other");
        break;
    case t_replay:
        showInput("Replay");
        break;
    case t_infoPlayer:
        showInput("Players's Information");
        break;
    case t_showAllPlayer:
        showInput("Players's Records");
        break;
    case t_searchPlayer:
        showInput("Search Player by Name");
        break;
    case t_guide:
        showInput("Guide");
        break;
    default:
        break;
    }
    showInput("-------*\n", YELLOW);
}
void View::mainMenu()
{
    showInput("1.New ", RED);
    showInput("game \n");
    showInput("2.Replay\n", RED);
    showInput("3.Players' Information\n", RED);
    showInput("4.Guide\n", RED);
    showInput("5.Exit\n", RED);
    showInput("Press number to choice: ");
}
void View::gameOverMenu()
{
    showInput("Do you want to play again?\n", YELLOW);
    showInput("1.Play again\n", RED);
    showInput("2.Back to MAIN MENU\n", RED);
    showInput("Press number to choice: ");
}
void View::playerInformationMenu()
{
    showInput("1.Show All Player\n", RED);
    showInput("2.Search player by Name\n", RED);
    showInput("3.Back to MAIN MENU\n", RED);
    showInput("Press number to choice: ");
}
void View::showAllPlayer()
{

}
void View::searchPlayerByName()
{

}
void View::guide()
{
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