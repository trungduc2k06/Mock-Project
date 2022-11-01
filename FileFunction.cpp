#include "FileFunction.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include <iomanip>

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
    fout << "  Name    Win    Lose    Draw\n";
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
void searchPlayerByName(string name)
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
            showInput("Name: " + namePlayer + '\n');
            showInput("Num of win: " + numWin + '\n');
            showInput("Num of lose: " + numLose + '\n');
            showInput("Num of draw: " + numDraw + '\n');
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
            showInput("Player same rank!\n", YELLOW;
            showInput("Name: " + namePlayer + '\n');
            showInput("Num of win: " + numWin + '\n');
            showInput("Num of lose: " + numLose + '\n');
            showInput("Num of draw: " + numDraw + '\n');
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