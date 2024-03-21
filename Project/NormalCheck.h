#pragma once
#include <iostream>
#include "Struct.h"
#include "NormalMode.h"
using namespace std;

bool lineCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2);
bool INormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2);
bool LNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2);
bool ZNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2);
bool UNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2);
bool allCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2);
bool haveFinished(NormalMode** p_ball);
