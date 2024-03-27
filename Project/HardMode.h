#pragma once
#include "HardCheck.h"
#include "Struct.h"
#include <iostream>
using namespace std;

#define HARD_HEIGHT 6
#define HARD_WIDTH 6

//void push(HardMode*& head, HardMode* p);
//void initList(HardMode** board);
//void deleteList(HardMode** board);
//void printList(HardMode** board);
//void move(HardMode** board, Position& pos, int& status, Player& p, Position selectedPos[], int& couple);
//void hardMode(Player& p);

void push(HardMode*&, HardMode*);
void initList(HardMode**);
void deleteList(HardMode**);
void renderList(HardMode**);
void move(HardMode**, Position&, int&, Player&, Position[], int&);
void difficultMode(Player&);