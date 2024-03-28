#pragma once
#include <iostream>
#include "Struct.h"
#include "NormalMode.h"
using namespace std;

bool lineCheck(NormalMode**, int, int, int, int);
bool INormalCheck(NormalMode**, int, int, int, int);
bool LNormalCheck(NormalMode**, int, int, int, int);
bool ZNormalCheck(NormalMode**, int, int, int, int);
bool UNormalCheck(NormalMode**, int, int, int, int);
bool allCheck(NormalMode**, int, int, int, int);
bool checkValidPairs(NormalMode**);
bool haveFinished(NormalMode**);
