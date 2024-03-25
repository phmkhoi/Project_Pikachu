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

	Player p;
	p.life = 3;
	p.name = "Khoi";
	p.point = 20;

	int choice;
	do {
		choice = mainMenu();
		switch (choice) {
		case 0:
			normalMode(p);
			break;
		case 1:
			//hardMode(p);
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