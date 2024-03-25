#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include <Windows.h>
#include "Utility.h"
using namespace std;

struct Player {
	string name = " ";
	int point, life;
};
typedef vector<Player> PlayerList;

void swapPlayer(Player& p1, Player& p2);
void sortPlayer(PlayerList& p_list);
void displayPlayer(Player p, int rank);

//p_mon stands for pokemon
struct NormalMode {
	int i, j;
	char p_mon = ' ';
	bool exist = 1, is_selected = 0;

	void drawCell(int);
	void deleteCell();
};

struct HardMode {
	int i, j;
	char p_mon = ' ';
	bool exist = 1, is_selected = 0;
	HardMode* p_next;

	void drawCell(int);
	void deleteCell();
};

struct Position {
	int x, y;
};