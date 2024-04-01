#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

struct Player {
	string name = " ";
	int point, life;
};
typedef vector<Player> PlayerList;

void swapPlayer(Player&, Player&);
void sortPlayer(PlayerList&);
void displayPlayer(Player, int);
void getPlayerInfo(Player&);

struct NormalMode {
	int row, column;

	//pokemon
	char p_mon = ' ';

	bool exist = 1;
	bool is_selected = 0;

	void drawCell(int);
	void deleteCell();
};

struct HardMode {
	int row, column;

	//pokemon
	char p_mon = ' ';

	bool is_selected = 0;
	HardMode* p_next;

	void drawCell(int);
	void deleteCell();
};

struct Position {
	int x, y;
};