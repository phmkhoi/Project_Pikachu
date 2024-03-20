#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
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
	char p_mon;
	bool exist = true;
};


struct HardMode {
	char p_mon;
	HardMode* p_next;
};
