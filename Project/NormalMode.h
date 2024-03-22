#pragma once
#include <conio.h>
#include <ctime>
#include "Console_Settings.h"
#include "Utility.h"
#include "Struct.h"

#define NORMAL_HEIGHT 4
#define NORMAL_WIDTH 4

void initBoard(NormalMode** board);
void deleteBoard(NormalMode** board);
void printBoard(NormalMode** board);
void move(NormalMode** board, Position& pos, int& status, Position selected_pos[], int& pair);
void normalMode();