#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Console_Settings.h"
#include "Struct.h"
#include "Sound.h"
using namespace std;

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


void setColor(int);
void drawBox(int, int, int, int, int, int, string);
int mainMenu();
void getNormalBackground(char[][41]);
void displayNormalBackground(char[][41], int, int);
void getHardBackground(char[][50]);
void displayHardBackground(char[][50], int, int);
void drawNormalBorder(Player);
void drawHardBorder(Player p);
void displayStatus(int);
void getPlayerInfo(Player&);
void drawILine(int r1, int c1, int r2, int c2);
void deleteILine(int r1, int c1, int r2, int c2);