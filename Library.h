#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#include <iostream>
#include <string>
#include "windows.h"
#include "conio.h"

using namespace std;
//Common
#define BOARD_SIZE 10
#define VX 1
#define VO 2
#define P1 RED
#define P2 GREEN
//Color
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define YELLOW 14
//
struct Move
{
    int col, row, value;
};
//View
enum choiceType
{
    t_mainmenu = '0',
    t_playWithOther,
    t_replay,
    t_infoPlayer,
    t_showAllPlayer,
    t_searchPlayer,
    t_guide,
    t_exit,
};
//
void setColor(int color);
void showInput(string s);
void showInput(string s, int color);
char* inputStringName(const int k);

#endif