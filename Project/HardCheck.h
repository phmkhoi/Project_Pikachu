#pragma once
#include <iostream>
#include "HardMode.h"
#include "Struct.h"
using namespace std;

HardMode* findPokeBall(HardMode** p_ball, int r, int c);
bool IHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2); 
bool LHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2); 
bool ZHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2);
bool UHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2);
bool allCheck(HardMode** p_ball, int r1, int c1, int r2, int c2);
bool isPlaying(HardMode** p_ball, int r1, int c1, int r2, int c2);
