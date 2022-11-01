#include "Controller.h"

Controller::Controller(Game* game, View* view)
{
    m_game = game;
    m_view = view;
}
Controller::~Controller()
{
    delete m_game;
    delete m_view;
}

char Controller::inputOption()
{
    char key;
    cin >> key;  
    return key;
}

//Controller
void Controller::initGame(int size)
{
    m_game->initGame(size);
}
bool Controller::isContinue()
{
    return !m_game->getExit();
}
void Controller::exitGame()
{
    system("cls");
    m_game->setExit(true);
    exit(0);
}

void Controller::resetBoard()
{
    //if(m_game->getBoard()->getSize() == 0) return false;
    for(int i = 0; i < m_game->getBoard()->getSize(); i++)
    {
        for(int j = 0; j < m_game->getBoard()->getSize(); j++)
        {
            m_game->getBoard()->setXO(i, j, 0);
        }
    }
}
bool Controller::checkFullBoard()
{
    int count = 0;
    for(int x = 0; x <= m_game->getBoard()->getSize() - 1; x++)
    {
        for(int y = 0; y <=m_game->getBoard()->getSize() - 1; y++)
        {
            if(m_game->getBoard()->getXO(x, y) == 0)
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
    if(m_game->getBoard()->getXO(x, y) == 0) return false;
    int player1 = m_game->getBoard()->getXO(x, y);
    int count = 0;
    int opcount = 0;
    for(int i = x; i >= 0; i--)
    {
        if(m_game->getBoard()->getXO(i, y) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(i,y) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    for(int i = x + 1; i <= m_game->getBoard()->getSize() - 1; i++)
    {
        if(m_game->getBoard()->getXO(i, y) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(i, y) != 0)
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
    if(m_game->getBoard()->getXO(x, y) == 0) return false;
    int player1 = m_game->getBoard()->getXO(x, y);
    int count = 0;
    int opcount = 0;
    for(int i = y; i >= 0; i--)
    {
        if(m_game->getBoard()->getXO(x, i) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(x, i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    for(int i = y + 1; i <= m_game->getBoard()->getSize() - 1; i++)
    {
        if(m_game->getBoard()->getXO(x, i) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(x, i) != 0)
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
    if(m_game->getBoard()->getXO(x, y) == 0) return false;
    int player1 = m_game->getBoard()->getXO(x, y);
    int count = 0;
    int opcount = 0;
    int m = min(x, y);
    for(int i = 0; i <= m; i++)
    {
        if(m_game->getBoard()->getXO(x - i, y - i) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(x - i, y - i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(m_game->getBoard()->getSize() - x, m_game->getBoard()->getSize() - y);
    for(int i = 1; i <= m; i++)
    {
        if(m_game->getBoard()->getXO(x + i, y + i) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(x +i, y + i) != 0)
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
    if(m_game->getBoard()->getXO(x, y) == 0) return false;
    int player1 = m_game->getBoard()->getXO(x, y);
    int count = 0;
    int opcount = 0;
    int m = min(x, m_game->getBoard()->getSize() - y);
    for(int i = 0; i <= m; i++)
    {
        if(m_game->getBoard()->getXO(x - i, y + i) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(x - i, y + i) != 0)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(m_game->getBoard()->getSize() - x, y);
    for(int i = 1; i <= m; i++)
    {
        if(m_game->getBoard()->getXO(x + i, y - i) == player1)
        {
            count++;
        }
        else if(m_game->getBoard()->getXO(x + i, y - i) != 0)
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
void Controller::checkWinGame()
{
    for(int x = 0; x <= m_game->getBoard()->getSize() - 1; x++)
    {
        for (int y = 0; y < m_game->getBoard()->getSize() - 1; y++)
        {
            if(horiWin(x, y) || vertiWin(x, y) || lCrossWin(x, y) || rCrossWin(x, y))
            {
                m_game->setWonGame(true);
                m_game->setPlayerWon(m_game->getBoard()->getXO(x,y));
                if(m_game->isWonGame() == true) break;
            }
        }
        if(m_game->isWonGame() == true) break;
    }
}
void Controller::updateWinLoseRecord()
{
    if(m_game->getPlayerWon() == VX)
    {
        m_game->getPlayer1().increWin();
        m_game->getPlayer2().increLose();
    }
    else if(m_game->getPlayerWon() == VO)
    {
        m_game->getPlayer1().increLose();
        m_game->getPlayer2().increWin();
    }
    eraseOldResultPlayer(m_game->getPlayer1().getName());
    writePlayerInFile(m_game->getPlayer1());
    eraseOldResultPlayer(m_game->getPlayer2().getName());
    writePlayerInFile(m_game->getPlayer2());
}
void Controller::updateDrawRecord()
{
    m_game->getPlayer1().increDraw();
    m_game->getPlayer2().increDraw();
    eraseOldResultPlayer(m_game->getPlayer1().getName());
    writePlayerInFile(m_game->getPlayer1());
    eraseOldResultPlayer(m_game->getPlayer2().getName());
    writePlayerInFile(m_game->getPlayer2());
}
void Controller::replayLastGame()
{
    list<Move>::iterator iter;
    Game* replayGame = new Game(m_game->getBoard()->getSize());
    list<Move> replayMoves = m_game->getReplayMoves();
    iter = replayMoves.begin();
    while (iter != replayMoves.end())
    {
        system("cls");
        replayGame->setPlayer1(m_game->getPlayer1());
        replayGame->setPlayer2(m_game->getPlayer2());
        replayGame->getBoard()->setXO((*iter).col, (*iter).row, (*iter).value);
        m_view->drawGameScreen(replayGame);
        Sleep(500);
        iter++;
    }
    
}
void Controller::replayGameById(char id)
{
    list<Move> replayMoves = getReplayMoveById(id);
    string user1 = getReplayPlayerById(id, 1);
    string user2 = getReplayPlayerById(id, 2);
    //list<Move>::iterator iter = replayMoves.begin();
    Game* replayGame = new Game(m_game->getBoard()->getSize());
    // while(iter != replayMoves.end())
    // {
    //     system("cls");
    //     replayGame->getPlayer1().setName(user1);
    //     replayGame->getPlayer2().setName(user2);
    //     replayGame->getBoard()->setXO((*iter).col, (*iter).row, (*iter).value);
    //     //m_view->drawGameScreen(replayGame);
    //     //Sleep(500);
    //     cout <<"Bug1: " << (*iter).col << " " << (*iter).row << " " << (*iter).value << endl;
    //     ++iter;
    // }
    for(list<Move>::iterator iter = replayMoves.begin(); iter != replayMoves.end(); iter++)
    {
        system("cls");
        replayGame->getPlayer1().setName(user1);
        replayGame->getPlayer2().setName(user2);
        replayGame->getBoard()->setXO((*iter).col, (*iter).row, (*iter).value);
        //m_view->drawGameScreen(replayGame);
        //Sleep(500);
        cout <<"Bug1: " << (*iter).col << " " << (*iter).row << " " << (*iter).value << endl;
    }
}
void Controller::playerInputAccount()
{
    showInput("Input player 1: ");
    m_game->getPlayer1().initPlayer();
    while (!checkName(m_game->getPlayer1().getName()))
    {
        showInput("Input player 1: ");
        m_game->getPlayer1().initPlayer();
    }
    if(checkPlayerName(m_game->getPlayer1().getName()) == 0)
    {
        writePlayerInFile(m_game->getPlayer1());
    }
    updateCurentResultPlayer(m_game->getPlayer1());
    showInput("Input player 2: ");
    m_game->getPlayer2().initPlayer();
    while (!checkName(m_game->getPlayer2().getName()))
    {
        showInput("Input player 2: ");
        m_game->getPlayer2().initPlayer();
    }
    while (m_game->getPlayer2().getName() == m_game->getPlayer1().getName())
    {
        showInput("Same name as player 1\n", RED);
        showInput("Input player 2: ");
        m_game->getPlayer2().initPlayer();
    }
    if(checkPlayerName(m_game->getPlayer2().getName()) == 0)
    {
        writePlayerInFile(m_game->getPlayer2());
    }    
    updateCurentResultPlayer(m_game->getPlayer2());
}
void Controller::playerChooseAccount()
{
    showInput("List account: \n", RED);
    setColor(BLACK);
    showAllRecordInFile();
    showInput("Input name account you want or create new account: \n");
    playerInputAccount();
}
void Controller::playerInputMove()
{
    char chCol, chRow;
    int inputCol, inputRow;
    if(m_game->getTurn() == true)
    {
        showInput("Player ");
        showInput(m_game->getPlayer1().getName() + "'s ", P1);
        showInput("turn: ");
        do
        {
            cin >> chRow;
            cin >> chCol;
            inputRow = (int)chRow - 48;
            inputCol = (int)chCol - 48;
        } while ((inputCol < 0) || (inputCol > m_game->getBoard()->getSize() - 1) || (inputRow < 0) || (inputRow > m_game->getBoard()->getSize() - 1) || (m_game->getBoard()->getXO(inputCol, inputRow) != 0));
        m_game->getBoard()->setXO(inputCol, inputRow, VX);
        m_game->saveMove(inputCol, inputRow, VX);
    }
    if(m_game->getTurn() == false)
    {
        showInput("Player ");
        showInput(m_game->getPlayer2().getName() + "'s ", P2);
        showInput("turn: ");
        do
        {
            cin >> chRow;
            cin >> chCol;
            inputRow = (int)chRow - 48;
            inputCol = (int)chCol - 48;
        } while ((inputCol < 0) || (inputCol > m_game->getBoard()->getSize() - 1) || (inputRow < 0) || (inputRow > m_game->getBoard()->getSize() - 1) || (m_game->getBoard()->getXO(inputCol, inputRow) != 0));
        m_game->getBoard()->setXO(inputCol, inputRow, VO);
        m_game->saveMove(inputCol, inputRow, VO);
    }
}
void Controller::changePlayer()
{
    if(m_game->getTurn() == true)
    {
        m_game->setTurn(false); 
    }
    else if(m_game->getTurn() == false)
    {
        m_game->setTurn(true);
    }
}
void Controller::playInBoard()
{
    playerInputMove();
    changePlayer();
    checkWinGame();
}
void Controller::newGame()
{
    resetBoard();
    m_game->setTurn(true);
    m_game->setExit(false);
    m_game->setWonGame(false);
    m_game->setPlayerWon(0);
}
//Flow of game
void Controller::mainMenu()
{
    char choice;
    do
    {
        system("cls");
        m_view->menuHeader(t_mainmenu);
        m_view->mainMenu();
        choice = inputOption();
        switch (choice)
        {
        case '1':
            playWithOtherPlayer();
            break;
        case '2':
            replay();
            break;
        case '3':
            playerInformationMenu();
            break;
        case '4':
            guide();
            break;
        case '5':
            exitGame();
            break;
        default:
            break;
        }
    }while(choice < '1' || choice > '5');
}
void Controller::playWithOtherPlayer()
{
    system("cls");
    playerChooseAccount();
    m_game->resetReplayMoves();
    do
    {
        if(m_game->isWonGame() == false)
        {
            system("cls");
            m_view->drawGameScreen(m_game);
            if(checkFullBoard())
            {
                updateDrawRecord();
                showInput("DRAW!\n", YELLOW);
                askToSaveReplay();
                gameOverMenu();
            }
            else
            {
                playInBoard();    
            }
        }
        if(m_game->isWonGame() == true)
        {
            updateWinLoseRecord();
            system("cls");
            m_view->drawGameScreen(m_game);
            showInput("Player: ");
            if(m_game->getPlayerWon() == VX)
            {
                showInput(m_game->getPlayer1().getName(), P1);
            }
            else if(m_game->getPlayerWon() == VO)
            {
                showInput(m_game->getPlayer2().getName(), P2);
            }
            showInput(" won!\n", YELLOW);
            askToSaveReplay();
            gameOverMenu();
        }
    } while (m_game->isWonGame() == false);
}
void Controller::gameOverMenu()
{
    char choice;
    m_view->gameOverMenu();
    do
    {
        choice = inputOption();
        switch (choice)
        {
        case '1':
            newGame();
            m_game->resetReplayMoves();
            break;
        case '2':
            newGame();
            mainMenu();
            break;
        default:
            showInput("Press again!\n");
            break;
        }
    } while(choice < '1' || choice > '2');
}
void Controller::askToSaveReplay()
{
    char choice;
    m_view->askToSaveReplay();
    do
    {
        choice = inputOption();
        switch (choice)
        {
        case '1':
            saveReplayInFile(m_game);
            showInput("Saved successfully!\n", YELLOW);
            break;
        case '2':
            break;
        default:
            showInput("Press again!\n");
            break;
        }
    }while(choice < '1' || choice > '2');
}
void Controller::replay()
{
    char choice;
    char idGame;
    system("cls");
    m_view->menuHeader(t_replay);
    showInput("History Game: \n", YELLOW);
    setColor(BLACK);
    showAllReplayGameInFile();
    showInput("Input id game you want to replay: ");
    cin >> idGame;
    do
    {
        system("cls");
        replayGameById(idGame);
        m_view->replay();
        choice = inputOption();
        switch (choice)
        {
        case '1':
            break;
        case '2':
            replay();
            break;
        case '3':
            mainMenu();
            break;
        default:
            showInput("Press again!\n");
            break;
        }
    } while (choice < '2' || choice > '3');
    
}
void Controller::playerInformationMenu()
{
    char choice;
    do
    {
        system("cls");
        m_view->menuHeader(t_infoPlayer);
        m_view->playerInformationMenu();
        choice = inputOption();
        switch (choice)
        {
        case '1':
            showAllPlayer();
            break;
        case '2':
            searchPlayerByName();
            break;
        case '3':
            mainMenu();
            break;
        default:
            break;
        }
    } while (choice < '1' || choice < '3');
    
}
void Controller::showAllPlayer()
{
    char choice;
    do
    {
        system("cls");
        m_view->menuHeader(t_showAllPlayer);
        showAllRecordInFile();
        m_view->showAllPlayer();
        choice = inputOption();
        switch (choice)
        {
        case '1':
            playerInformationMenu();
            break;
        case '2':
            mainMenu();
            break;
        default:
            break;
        }
    } while (choice < '1' || choice > '2');
    
}
void Controller::searchPlayerByName()
{
    system("cls");
    string nameSearch;
    char choice;
    m_view->menuHeader(t_searchPlayer);
    showInput("Input player's name: ", YELLOW);
    cin >> nameSearch;
    do
    {
        system("cls");
        m_view->menuHeader(t_searchPlayer);
        searchPlayerRecordByName(nameSearch);
        m_view->searchPlayerByName();
        choice = inputOption();
        switch (choice)
        {
        case '1':
            searchPlayerByName();
            break;
        case '2':
            playerInformationMenu();
            break;
        case '3':
            mainMenu();
            break;
        default:
            break;
        }
    } while (choice < '1' || choice > '3');
    
}
void Controller::guide()
{
    char choice;
    do
    {
        system("cls");
        m_view->menuHeader(t_guide);
        m_view->guide();
        choice = inputOption();
        switch (choice)
        {
        case '1':
            mainMenu();
            break;
        default:
            break;
        }
    } while (choice != '1');
}
void Controller::startGame()
{
    newGame();
    while (isContinue())
    {
        mainMenu();
    }  
}