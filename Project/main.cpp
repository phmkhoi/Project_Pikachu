#include <iostream>
#include <conio.h>
#include "Console_Settings.h"
#include "Struct.h"
#include "Utility.h"
#include "LeaderBoard.h"
using namespace std;

int main() {
	initWindow(1000, 500);
	int choice = mainMenu();
	while (choice >= 0 && choice <= 3) {
		switch (choice) {
		case 0:
			break;
		case 1:
			break;
		case 2:
			readLeaderBoard();
			break;
		case 3:
			exit(0);
		default:
			break;
		}
	}
	_getch();
	return 0;
}