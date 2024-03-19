#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
#include <string>
using namespace std;

struct Player {
	string name = " ";
	int point = 0;
	int life = 3;
};
typedef vector<Player> PlayerList;

void swapPlayer(Player& p1, Player& p2);
void sortPlayer(PlayerList& p_list);
void displayPlayer(Player p, int rank);
