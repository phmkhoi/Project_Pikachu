#pragma once
#include <conio.h>
#include <ctime>
#include "Console_Settings.h"
#include "Utility.h"
#include "Struct.h"
#include "NormalCheck.h"
#include "LeaderBoard.h"
#include "Sound.h"
using namespace std;

#define NORMAL_HEIGHT 4
#define NORMAL_WIDTH 4

void initBoard(NormalMode**);
void deleteBoard(NormalMode**);
void printBoard(NormalMode**);
void move(NormalMode**, Position&, int&, Player&, Position[], int&);
void drawNormalSuggestCell(NormalMode**, int, int, int);
void moveNormalSuggestion(NormalMode**);
void normalMode(Player&);