#pragma once
#include <iostream>
#include "HardMode.h"
#include "Struct.h"
using namespace std;

HardMode* findPokeBall(HardMode**, int, int);
bool Icheck(HardMode**, int, int, int, int);
bool Lcheck(HardMode**, int, int, int, int);
bool UandZcheck(HardMode**, int, int, int, int);
bool allCheck(HardMode**, int, int, int, int);
void deleteNode(HardMode**, int, int);
void DifMode(HardMode**, int, int, int, int);
bool checkValidPairs(HardMode**);