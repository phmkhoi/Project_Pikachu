#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Console_Settings.h"

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ESC_KEY 27
#define ENTER_KEY 13

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

using namespace std;

void setColor(int color);
void drawBox(int x, int width, int y, int height, int text_color, int bg_color, string content);
int mainMenu();