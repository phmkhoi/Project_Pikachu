#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

void gotoXY(int x, int y);
void setCursor(bool visible);
void resizeWindow(int x, int y);
void hideScrollBar();
void initWindow(int width, int length);