#include <iostream>
#include <conio.h>
#include "Console_Settings.h"
#include "Struct.h"
#include "Utility.h"

using namespace std;

int main() {
	initWindow(1000, 500);
	int choice;
	while ((choice = mainMenu()) != 3) {
		switch (choice) {
		case 0: 
			break;
		case 1: 
			break;
		case 2: 
			readLeaderBoard();
			break;
		default:
			break;
		}
	}
	return 0;
}