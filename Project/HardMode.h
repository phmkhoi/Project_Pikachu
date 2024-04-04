#pragma once
#include "HardCheck.h"
#include "Struct.h"
#include <iostream>
using namespace std;

#define HARD_HEIGHT 6
#define HARD_WIDTH 6

void push(HardMode*&, HardMode*);
void initList(HardMode**);
void deleteList(HardMode**);
void renderList(HardMode**);
void move(HardMode**, Position&, int&, Player&, Position[], int&);
void drawHardSuggestCell(HardMode**, int, int, int, char);
void moveHardSuggestion(HardMode**);
void difficultMode(Player&);