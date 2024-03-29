#pragma once
#include <iostream>
#include "HardMode.h"
#include "Struct.h"
using namespace std;

HardMode* findPokeBall(HardMode**, int, int);
bool IHardCheck(HardMode**, int, int, int, int);
bool LHardCheck(HardMode**, int, int, int, int);
bool ZHardCheck(HardMode**, int, int, int, int);
bool UHardCheck(HardMode**, int, int, int, int);
bool allCheck(HardMode**, int, int, int, int);
void deleteNode(HardMode**, int, int, char[][50]);
void DifMode(HardMode**, int, int, int, int, char [][50]);
bool checkValidPairs(HardMode**);