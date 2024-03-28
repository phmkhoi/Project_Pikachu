#pragma once
#include <conio.h>
#include <ctime>
#include "Console_Settings.h"
#include "Utility.h"
#include "Struct.h"
using namespace std;

#define NORMAL_HEIGHT 4
#define NORMAL_WIDTH 4

void initBoard(NormalMode**);
void deleteBoard(NormalMode**);
void printBoard(NormalMode**);
void move(NormalMode**, Position&, int&, Player&, Position[], int&);
void normalMode(Player&);