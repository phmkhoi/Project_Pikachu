#pragma once
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include "NormalCheck.h"
#include "HardCheck.h"
using namespace std;

void winSound();
void gameOverSound();
void rightPairSound();
void wrongPairSound();
void gameStartSound();
