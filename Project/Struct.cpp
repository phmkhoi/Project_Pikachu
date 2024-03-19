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
	case 2:
		gotoXY(27, 6 + rank);
		setColor(RED);
		cout << p.name;
		gotoXY(97, 6 + rank);
		setColor(RED);
		cout << p.point;
		break;
	case 4:
		gotoXY(27, 6 + rank);
		setColor(GREEN);
		cout << p.name;
		gotoXY(97, 6 + rank);
		setColor(GREEN);
		cout << p.point;
		break;
	case 6:
		gotoXY(27, 6 + rank);
		setColor(AQUA);
		cout << p.name;
		gotoXY(97, 6 + rank);
		setColor(AQUA);
		cout << p.point;
		break;
	default:
		gotoXY(27, 6 + rank);
		setColor(YELLOW);
		cout << p.name;
		gotoXY(97, 6 + rank);
		setColor(YELLOW);
		cout << p.point;
		break;
	}
	setColor(WHITE);
	gotoXY(27, 7 + rank);
	for (int i = 0; i < 75; i++) cout << "-";
}

