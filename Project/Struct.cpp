#include "Console_Settings.h"
#include "Utility.h"
#include "Struct.h"

//Player
void swapPlayer(Player& p1, Player& p2) {
	swap(p1.name, p2.name);
	swap(p1.life, p2.life);
	swap(p1.point, p2.point);
}

void sortPlayer(PlayerList& p_list) {
	for (int i = 0; i < p_list.size() - 1; i++)
		for (int j = i + 1; j < p_list.size(); j++)
			if (p_list[i].point < p_list[j].point)
				swapPlayer(p_list[i], p_list[j]);
}

void displayPlayer(Player p, int rank) {
	switch (rank) {
	case 0:
		gotoXY(27, 14 + rank);
		setColor(LIGHT_RED);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(LIGHT_RED);
		cout << p.point;
		break;
	case 2:
		gotoXY(27, 14 + rank);
		setColor(GREEN);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(GREEN);
		cout << p.point;
		break;
	case 4:
		gotoXY(27, 14 + rank);
		setColor(LIGHT_AQUA);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(LIGHT_AQUA);
		cout << p.point;
		break;
	default:
		gotoXY(27, 14 + rank);
		setColor(LIGHT_YELLOW);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(LIGHT_YELLOW);
		cout << p.point;
		break;
	}
	setColor(WHITE);
	gotoXY(27, 15 + rank);
	for (int i = 0; i < 79; i++) cout << "-";
}


char cell[5][11] = {
	{"+--------+"},
	{"|        |"},
	{"|        |"},
	{"|        |"},
	{"+--------+"},
};

//draw cell in gameboard
void CELL_1::drawCell(int color) {
	/*if (!is_valid) {
		return;
	}*/

	int x = j + 1, y = i + 1; //coordinate of cell

	for (int i = 0; i < 5; i++) {
		gotoXY(x * 9, y * 4 + i);
		cout << cell[i];
	}

	//if (is_selected) {
	//	setColor(color + WHITE * 16);
	//	for (int i = 1; i < 4; i++) {
	//		gotoXY(x * 10 + 1, y * 4 + i);
	//		cout << "         ";
	//	}

	//	//print letter in cell
	//	gotoXY(x * 10 + 5, y * 4 + 2);
	//	cout << letter;
 //		setColor(WHITE); //Reset Color
	//}
	//else {

	//	//print letter in cell
	//	gotoXY(x * 10 + 5, y * 4 + 2);
	//	setColor(color + WHITE * 16);
	//	cout << letter;
	//	setColor(WHITE); //Reset Color
	//}
}

void CELL_1::deleteCell() {
	int x = j + 1, y = i + 1; //coordinate of cell

	//delete cell
	for (int i = 0; i < 5; i++) {
		gotoXY(x * 10, y * 4 + i);
		cout << "         ";
	}
}
