#ifndef _FILEFUNCTION_H_
#define _FILEFUNCTION_H_

#include "Player.h"
#include "Library.h"

static const char* recordFile = "PlayerRecord.ini";
static const char* replayFile = "ReplayGame.ini";

bool isFileExist(const char*);
//record
void createRecordFile();
void writePlayerInFile(Player);
void showAllRecordInFile();
bool checkPlayerName(string name);
void searchPlayerByName(string name);
void findPlayerSameRank(string name, int win, int lose);
void eraseOldResultPlayer(string name);
void updateCurentResultPlayer(Player&);

#endif