#pragma once
#include <iostream>
#include "HardMode.h"
#include "Struct.h"
using namespace std;

//HardMode* findPokeBall(HardMode** board, int r, int c);
//bool IHardCheck(HardMode** board, int r1, int c1, int r2, int c2); 
//bool LHardCheck(HardMode** board, int r1, int c1, int r2, int c2);
//bool UandZcheck(HardMode** board, int r1, int c1, int r2, int c2);
//bool allCheck(HardMode** board, int r1, int c1, int r2, int c2);
//void deleteCell(HardMode** board, int y, int x);
//void deletePair(HardMode** board, int y1, int x1, int y2, int x2);
//bool checkValidPairs(HardMode** board);
////bool haveFinished(HardMode** board);

HardMode* findTheNode(HardMode**, int, int);
bool Icheck(HardMode**, int, int, int, int);
bool Lcheck(HardMode**, int, int, int, int);
bool UandZcheck(HardMode**, int, int, int, int);
bool allCheck(HardMode**, int, int, int, int);
void deleteNode(HardMode**, int, int);
void DifMode(HardMode**, int, int, int, int);
bool checkValidPairs(HardMode**);