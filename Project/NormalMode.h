#pragma once
#include <conio.h>
#include <ctime>
#include "Console_Settings.h"
#include "Utility.h"
#include "Struct.h"

#define NORMAL_HEIGHT 4
#define NORMAL_WIDTH 4

void initBoard(CELL_1** board);
void deleteBoard(CELL_1** board);
void printBoard(CELL_1** board);
void normalMode();