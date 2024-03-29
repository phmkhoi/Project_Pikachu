#include <iostream>
#include <conio.h>
#include "Console_Settings.h"
#include "Struct.h"
#include "Utility.h"
#include "LeaderBoard.h"
#include "NormalMode.h"
#include "HardMode.h"
using namespace std;

int main() {
	initWindow(1000, 500);

	int choice;
	Player p;

	do {
		choice = mainMenu();
		switch (choice) {
		case 0:
			getPlayerInfo(p);
			normalMode(p);
			break;
		case 1:
			getPlayerInfo(p);
			difficultMode(p);
			break;
		case 2:
			readLeaderBoard();
			break;
		case 3:
			exit(0);
		}
	} while (choice >= 0 && choice <= 3);
	system("pause");
	return 0;
}