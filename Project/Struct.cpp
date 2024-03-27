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
void NormalMode::drawCell(int color) {
	if (!exist) return;

	int x = j + 1, y = i + 1; //coordinate of cell

	for (int i = 0; i < 5; i++) {
		gotoXY(x * 9 + 6, y * 4 + i + 2);
		cout << cell[i];
	}

	setColor(WHITE);
	if (is_selected) {
		setColor(color + WHITE * 16);
		for (int i = 1; i < 4; i++) {
			gotoXY(x * 9 + 6 + 1, y * 4 + i + 2);
			cout << "        ";
		}

		//print letter in cell
		setColor(color + WHITE * 16);
		gotoXY(x * 9 + 5 + 6, y * 4 + 4);
		cout << p_mon;
 		setColor(WHITE); //reset color
	}
	else {
		//print letter in cell
		setColor(WHITE);
		gotoXY(x * 9 + 5 + 6, y * 4 + 4);
		cout << p_mon;
		setColor(WHITE); //Reset Color
	}
}

void NormalMode::deleteCell() {
	int x = j + 1, y = i + 1; //coordinate of cell

	//delete cell
	for (int i = 0; i < 5; i++) {
		gotoXY(x * 9 + 6, y * 4 + i + 2);
		cout << "          ";
	}
}

void HardMode::drawCell(int color) {
	int x = j + 1, y = i + 1;

	for (int i = 0; i < 5; i++) {
		gotoXY(x * 9 + 6, y * 4 + i + 2);
		cout << cell[i];
	}

	setColor(WHITE);
	if (is_selected) {
		setColor(color + WHITE * 16);
		for (int i = 1; i < 4; i++) {
			gotoXY(x * 9 + 6 + 1, y * 4 + i + 2);
			cout << "        ";
		}

		//print letter in cell
		setColor(color + WHITE * 16);
		gotoXY(x * 9 + 5 + 6, y * 4 + 4);
		cout << p_mon;
		setColor(WHITE); //reset color
	}
	else {
		//print letter in cell
		setColor(WHITE);
		gotoXY(x * 9 + 5 + 6, y * 4 + 4);
		cout << p_mon;
		setColor(WHITE); //Reset Color
	}
}

void HardMode::deleteCell() {
	int x = j + 1, y = i + 1; //coordinate of cell

	//delete cell
	for (int i = 0; i < 5; i++) {
		gotoXY(x * 9 + 6, y * 4 + i + 2);
		cout << "          ";
	}
}
