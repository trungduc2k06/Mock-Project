#include "FileFunction.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <vector>

bool isFileExist(const char* fileName)
{
    ifstream infile(fileName);
    return infile.good();
}
//record
void createRecordFile()
{
    ofstream fout;
    fout.open(recordFile, ios::out | ios::app);
    fout << "    Name    Win    Lose    Draw\n";
    fout.close();
}
void writePlayerInFile(Player player)
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    ofstream fout;
    fout.open(recordFile, ios::out | ios::app); // cho phep ghi vao file va ghi tiep vao cuoi file noi tiep file truoc
    fout << setw(8) << player.getName();
    fout << setw(8) << player.getWin();
    fout << setw(8) << player.getLose();
    fout << setw(8) << player.getDraw() << '\n';
    fout.close();
}
void showAllRecordInFile()
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    ifstream fin;
    fin.open(recordFile);
    char infoInline[200];
    int count = 0;
    while(!fin.eof())
    {
        fin.getline(infoInline, 200);
        cout << infoInline << endl;
    }
    fin.close();
}
bool checkPlayerName(string name)
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    ifstream fin;
    fin.open(recordFile);
    string namePlayer;
    string infoInline;
    while (!fin.eof())
    {
        getline(fin, infoInline);
        fin >> namePlayer;
        if(namePlayer == name)
        {
            return true;
        }
    }
    fin.close();
    return false;
}
void searchPlayerRecordByName(string name)
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    string namePlayer;
    int numWin, numLose, numDraw;
    ifstream fin;
    fin.open(recordFile);
    string infoInline;
    while (!fin.eof())
    {
        getline(fin, infoInline);
        fin >> namePlayer >> numWin >> numLose >> numDraw;
        if(namePlayer == name)
        {
            showInput("Player's Infomation\n", YELLOW);
            cout << "Name: " << namePlayer << endl;
            cout << "Num of win: " << numWin << endl;
            cout << "Num of lose: " << numLose << endl;
            cout << "Num of draw: " << numDraw << endl;
            findPlayerSameRank(name, numWin, numLose);
            return;
        }
    }
    fin.close();
    showInput("Don't find any player: " + name + '\n', YELLOW);
}
void findPlayerSameRank(string name, int win, int lose)
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    string namePlayer;
    string tmp;
    int numWin, numLose, numDraw;
    ifstream fin;
    fin.open(recordFile);
    string infoInline;
    while (!fin.eof())
    {
        getline(fin, infoInline);
        fin >> namePlayer >> numWin >> numLose >> numDraw;
        if((namePlayer != name) && (numWin == win) && (numLose - lose >= -1) && (numLose - lose <= 1))
        {
            if(tmp == namePlayer) return;
            showInput("Player same rank!\n", YELLOW);
            cout << "Name: " << namePlayer << endl;
            cout << "Num of win: " << numWin << endl;
            cout << "Num of lose: " << numLose << endl;
            cout << "Num of draw: " << numDraw << endl;
            tmp =  namePlayer;
        }
    }
    fin.close();
}
void eraseOldResultPlayer(string name)
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    string line;
    ifstream fin;
    fin.open(recordFile);
    ofstream fout;
    fout.open("Temp.ini");
    while(getline(fin, line))
    {
        if(line.substr(8 - name.size(), name.size()) != name)
        {
            fout << line << endl;
        }
    }
    fin.close();
    fout.close();
    remove(recordFile);
    rename("Temp.ini", recordFile);
}
void updateCurentResultPlayer(Player& player)
{
    if(!isFileExist(recordFile))
    {
        createRecordFile();
    }
    char tmp[] = "     ";
    string namePlayer;
    string infoInline;
    int numWin, numLose, numDraw;
    ifstream fin;
    fin.open(recordFile);
    while(!fin.eof())
    {
        getline(fin, infoInline);
        fin >> namePlayer >> numWin >> numLose >> numDraw;
        if(player.getName() == namePlayer)
        {
            player.setWin(numWin);
            player.setLose(numLose);
            player.setDraw(numDraw);
        }
    }
    fin.close();
}
//Replay
void createReplayFile()
{
    ofstream fout;
    fout.open(replayFile, ios::out | ios::app);
    fout << "      id    Player1    Player2\n";
    fout.close();
}
bool checkGameId(char id)
{
    if(!isFileExist(replayFile))
    {
        createReplayFile();
    }
    ifstream fin;
    fin.open(replayFile);
    char idGame;
    string infoInline;
    while (!fin.eof())
    {
        getline(fin, infoInline);
        fin >> idGame;
        if(idGame == id)
        {
            return true;
        }
    }
    fin.close();
    return false;
}
void saveReplayInFile(Game* game)
{
    if(!isFileExist(replayFile))
    {
        createReplayFile();
    }
    char id = '0';
    char tmp[] = "         ";
    string line;
    int count = 0;
    ofstream fout;
    fout.open(replayFile, ios::out | ios::app);
    while (checkGameId(id) == true)
    {
        id++;
    }
    fout << setw(8) << id;
    fout << setw(12) << game->getPlayer1().getName();
    fout << setw(12) << game->getPlayer2().getName();
    fout << '\n';
    list<Move>::iterator iter;
    Game* replayGame = new Game(game->getBoard()->getSize());
    list<Move> replayMoves = game->getReplayMoves();
    iter = replayMoves.begin();
    while (iter != replayMoves.end())
    {
        fout << setw(8) << '-' << tmp << (*iter).col << ' ' << (*iter).row << ' ' << (*iter).value << endl;
        iter++;
    }
    fout.close();
}
void showAllReplayGameInFile()
{
    if(!isFileExist(replayFile))
    {
        createReplayFile();
    }
    ifstream fin;
    fin.open(replayFile);
    string line;
    while (getline(fin, line))
    {
        if(line.substr(8 - sizeof(char), sizeof(char)) != "-")
        {
            cout << line << endl;
        }
    }
    
}
list<Move> getReplayMoveById(char id)
{
    list<Move> replayMoves;
    int col, row, value;
    string infoInline;
    char idGame;
    if(!isFileExist(replayFile))
    {
        createReplayFile();
    }
    ifstream fin;
    fin.open(replayFile);
    while (!fin.eof())
    {
        getline(fin, infoInline);
        fin >> idGame;
        if(idGame == id && idGame != '-')
        {
            do
            {
                getline(fin, infoInline);
                fin >> idGame >> col >> row >> value;
                if(idGame == '-')
                {
                    Move move;
                    move.col = col;
                    move.row = row;
                    move.value = value;
                    replayMoves.push_back(move);
                }
            } while (idGame == '-' && !fin.eof());
            return replayMoves;
        } 
    }
    fin.close();
    cout << "Don't find any game id: " << id << endl;
    return replayMoves;
}
string getReplayPlayerById(char id, int user)
{
    string user1, user2;
    char idGame;
    string infoInline;
    if(!isFileExist(replayFile))
    {
        createReplayFile();
    }
    ifstream fin;
    fin.open(replayFile);
    while(!fin.eof())
    {
        getline(fin, infoInline);
        fin >> idGame >> user1 >> user2;
        if(idGame == id)
        {
            if(user == 1)
            {
                return user1;
            }
            else if(user == 2)
            {
                return user2;
            }
            else
                return "";
        }
    }
    fin.close();
    return "";
}