#include "Utility.h"
#include "Struct.h"
#include "Sound.h"

//Set Color
void setColor(int color) {
	HANDLE hcolor;
	hcolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcolor, color);
}

//Draw Box
void drawBox(int x, int width, int y, int height, int text_color, int bg_color, string content) {
	//BORDER
	for (int ix = x; ix < x + width; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + height - 1);
		cout << char(196);
	}

	for (int iy = y; iy < y + height; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + width - 1, iy);
		cout << char(179);
	}

	gotoXY(x, y); cout << char(218); //TOP LEFT CORNER
	gotoXY(x + width - 1, y); cout << char(191); //TOP RIGHT CORNER
	gotoXY(x, y + height - 1); cout << char(192); //BOTTOM LEFT CORNER
	gotoXY(x + width - 1, y + height - 1); cout << char(217); //BOTTOM RIGHT CORNER

	//Draw bg inside box
	setColor(text_color + bg_color * 16);
	for (int ix = x + 1; ix < x + width - 1; ix++) {
		for (int iy = y + 1; iy < y + height - 1; iy++) {
			gotoXY(ix, iy);
			cout << " ";
		}
	}

	//Print content
	gotoXY(x + (width - content.length()) / 2, y + (height - 1) / 2);
	cout << content;
	setColor(WHITE);
}

//Game Start UI
int mainMenu() {
	//Draw Word
	//THE
	//https://www.patorjk.com/software/taag/#p=display&f=Doom&t=THE%20MATCHING%20GAME, font: DOOM
	gotoXY(9, 1);
	setColor(LIGHT_GREEN);
	cout << " _____  _   _  _____";
	gotoXY(9, 2);
	cout << "|_   _|| | | ||  ___|";
	gotoXY(9, 3);
	cout << "  | |  | |_| || |__  ";
	gotoXY(9, 4);
	setColor(LIGHT_AQUA);
	cout << "  | |  |  _  ||  __| ";
	gotoXY(9, 5);
	cout << "  | |  | | | || |___ ";
	gotoXY(9, 6);
	cout << "  \\_/  \\_| |_/\\____/ ";

	//MATCHING
	//https://www.patorjk.com/software/taag/#p=display&f=Doom&t=THE%20MATCHING%20GAME, font: DOOM
	gotoXY(35, 1);
	setColor(LIGHT_GREEN);
	cout << "___  ___  ___  _____  _____  _   _  _____  _   _  _____ ";
	gotoXY(35, 2);
	cout << "|  \\/  | / _ \\|_   _|/  __ \\| | | ||_   _|| \\ | ||  __ \\";
	gotoXY(35, 3);
	cout << "| .  . |/ /_\\ \\ | |  | /  \\/| |_| |  | |  |  \\| || |  \\/";
	gotoXY(35, 4);
	setColor(LIGHT_AQUA);
	cout << "| |\\/| ||  _  | | |  | |    |  _  |  | |  | . ` || | __ ";
	gotoXY(35, 5);
	cout << "| |  | || | | | | |  | \\__/\\| | | | _| |_ | |\\  || |_\\ \\";
	gotoXY(35, 6);
	cout << "\\_|  |_/\\_| |_/ \\_/   \\____/\\_| |_/ \\___/ \\_| \\_/ \\____/";

	//GAME
	//https://www.patorjk.com/software/taag/#p=display&f=Doom&t=THE%20MATCHING%20GAME, font: DOOM
	gotoXY(96, 1);
	setColor(LIGHT_GREEN);
	cout << " _____   ___  ___  ___ _____ ";
	gotoXY(96, 2);
	cout << "|  __ \\ / _ \\ |  \\/  ||  ___|";
	gotoXY(96, 3);
	cout << "| |  \\// /_\\ \\| .  . || |__  ";
	gotoXY(96, 4);
	setColor(LIGHT_AQUA);
	cout << "| | __ |  _  || |\\/| ||  __| ";
	gotoXY(96, 5);
	cout << "| |_\\ \\| | | || |  | || |___ ";
	gotoXY(96, 6);
	cout << " \\____/\\_| |_/\\_|  |_/\\____/ ";

	//PIKACHU
	//https://www.asciiart.eu/text-to-ascii-art, font: 3D-ASCII
	setColor(LIGHT_YELLOW);
	gotoXY(34, 8);
	cout << " ________  ___  ___  __    ________  ________  ___  ___  ___  ___     ";
	gotoXY(34, 9);
	cout << "|\\   __  \\|\\  \\|\\  \\|\\  \\ |\\   __  \\|\\   ____\\|\\  \\|\\  \\|\\  \\|\\  \\    ";
	gotoXY(34, 10);
	cout << "\\ \\  \\|\\  \\ \\  \\ \\  \\/  /|\\ \\  \\|\\  \\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\\\\\  \\   ";
	gotoXY(34, 11);
	cout << " \\ \\   ____\\ \\  \\ \\   ___  \\ \\   __  \\ \\  \\    \\ \\   __  \\ \\  \\\\\\  \\  ";
	gotoXY(34, 12);
	cout << "  \\ \\  \\___|\\ \\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\ \\  \\____\\ \\  \\ \\  \\ \\  \\\\\\  \\ ";
	gotoXY(34, 13);
	cout << "   \\ \\__\\    \\ \\__\\ \\__\\\\ \\__\\ \\__\\ \\__\\ \\_______\\ \\__\\ \\__\\ \\_______\\";
	gotoXY(34, 14);
	cout << "    \\|__|     \\|__|\\|__| \\|__|\\|__|\\|__|\\|_______|\\|__|\\|__|\\|_______|";

	//Reset Color
	setColor(WHITE);

	//COORDINATE OF MENU
	int x_menu = 60, y_menu = 16;

	//Menu
	int choice[4] = { 0, 0, 0, 0 }, cur_choice = 0, key, temp_key;
	while (1) {
		choice[cur_choice] = 1;

		if (choice[0]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu, 3, BLACK, WHITE, "NORMAL");
			gotoXY(x_menu - 3, y_menu + 1);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 1);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu, 3, WHITE, BLACK, "NORMAL");
			setColor(0 * 0);
			gotoXY(x_menu - 3, y_menu + 1);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 1);
			cout << "  ";
		}

		if (choice[1]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 3, 3, BLACK, WHITE, "HARD");
			gotoXY(x_menu - 3, y_menu + 3 + 1);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 3 + 1);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 3, 3, WHITE, BLACK, "HARD");
			setColor(0 * 0);
			gotoXY(x_menu - 3, y_menu + 3 + 1);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 3 + 1);
			cout << "  ";
		}

		if (choice[2]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 6, 3, BLACK, WHITE, "LEADER BOARD");
			gotoXY(x_menu - 3, y_menu + 6 + 1);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 6 + 1);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 6, 3, WHITE, BLACK, "LEADER BOARD");
			gotoXY(x_menu - 3, y_menu + 6 + 1);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 6 + 1);
			cout << "  ";
		}

		if (choice[3]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 9, 3, BLACK, WHITE, "EXIT");
			gotoXY(x_menu - 3, y_menu + 9 + 1);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 9 + 1);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 9, 3, WHITE, BLACK, "EXIT");
			gotoXY(x_menu - 3, y_menu + 9 + 1);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 9 + 1);
			cout << "  ";
		}

		setColor(WHITE);
		if (temp_key = _getch()) {
			if (temp_key != 224 && temp_key) {
				if (temp_key == ENTER_KEY) {
					system("cls");
					return cur_choice;
				}
			}
			else {
				key = _getch();
				switch (key) {
				case UP_KEY:
					choice[cur_choice] = 0;
					if (cur_choice > 0) {
						cur_choice--;
					}
					else {
						cur_choice = 3;
					}
					break;
				case DOWN_KEY:
					choice[cur_choice] = 0;
					if (cur_choice < 3) {
						cur_choice++;
					}
					else {
						cur_choice = 0;
					}
					break;
				default:
					break;
				}
			}
		}
	}
}

void getNormalBackground(char bg[][41]) {
	ifstream ifs;
	ifs.open("NormalBG.txt", ios::in);
	if (ifs) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 41; j++) {
				bg[i][j] = ifs.get();
			}
			ifs.ignore();
		}
		ifs.close();
	}
	else {
		memset(bg, ' ', sizeof(bg));
	}
}

void displayNormalBackground(char bg[][41], int x, int y) {
	//set bg color
	setColor(LIGHT_AQUA);

	//print bg from each cell
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			gotoXY((x + 1) * 10 + j + 6, (y + 1) * 4 + i + 2);
			cout << bg[y * 4 + i][x * 10 + j];
		}
	}

	//reset color
	setColor(WHITE);
}

void getHardBackground(char bg[][50]) {
	ifstream ifs;
	ifs.open("HardBG.txt", ios::in);
	if (ifs) {
		for (int i = 0; i < 25; i++) {
			for (int j = 0; j < 50; j++) {
				bg[i][j] = ifs.get();
			}
			ifs.ignore();
		}
		ifs.close();
	}
	else {
		memset(bg, ' ', sizeof(bg));
	}
}

void displayHardBackground(char bg[][50], int x, int y) {
	//set bg color
	setColor(LIGHT_AQUA);

	//print bg from each cell
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			gotoXY((x + 1) * 10 + j + 1, (y + 1) * 4 + i - 2);
			cout << bg[y * 4 + i][x * 10 + j];
		}
	}

	//reset color
	setColor(WHITE);
}

void drawNormalBorder(Player p) {
	int x = 15, y = 6;

	//GameBorder

	//TOP
	for (int i = x - 1; i < x + 10 * 4 + 4; i++) {
		gotoXY(i, y - 1);
		cout << char(205);
		Sleep(10);
	}

	//TOP RIGHT
	gotoXY(x + 10 * 4 + 4, y - 1);
	cout << char(187);
	Sleep(10);

	//RIGHT
	for (int j = y; j < y + 4 * 4 + 1; j++) {
		gotoXY(x + 10 * 4 + 4, j);
		cout << char(186);
		Sleep(10);
	}

	//BOTTOM RIGHT
	gotoXY(x + 10 * 4 + 4, y + 4 * 4 + 1);
	cout << char(188);
	Sleep(10);

	//BOTTOM
	for (int i = x + 10 * 4 + 4 - 1; i >= x - 2; i--) {
		gotoXY(i, y + 4 * 4 + 1);
		cout << char(205);
		Sleep(10);
	}

	//BOTTOM LEFT
	gotoXY(x - 2, y + 4 * 4 + 1);
	cout << char(200);
	Sleep(10);

	//LEFT
	for (int j = y + 4 * 4 + 1 - 1; j >= y; j--) {
		gotoXY(x - 2, j);
		cout << char(186);
		Sleep(10);
	}

	//TOP LEFT
	gotoXY(x - 2, y - 1);
	cout << char(201);
	Sleep(10);

	//Gridline
	for (int j = 0; j < 4 * 4 + 1; j++) {
		for (int i = 0; i < 10 * 4 + 1; i++) {
			if (i % 10 == 0) {
				gotoXY(x + 1 + i, y + j);
				if (j % 4 == 0) cout << '+';
				else cout << '|';
			}
		}
		Sleep(10);
	}

	for (int i = 0; i < 10 * 4 + 1; i++) {
		for (int j = 0; j < 4 * 4 + 1; j++) {
			if (j % 4 == 0) {
				gotoXY(x + 1 + i, y + j);
				if (i % 10 == 0) cout << '+';
				else cout << '-';
			}
		}
		Sleep(10);
	}

	//Player Border
	x = 90, y = 4;
	//TOP
	for (int i = x; i < x + 40; i++) {
		gotoXY(i, y);
		cout << char(205);
	}

	//TOP RIGHT
	gotoXY(x + 40, y);
	cout << char(187);

	//RIGHT
	for (int j = y + 1; j < y + 7; j++) {
		gotoXY(x + 40, j);
		cout << char(186);
	}

	//BOTTOM RIGHT
	gotoXY(x + 40, y + 7);
	cout << char(188);

	//BOTTOM
	for (int i = x + 40 - 1; i >= x; i--) {
		gotoXY(i, y + 7);
		cout << char(205);
	}

	//BOTTOM LEFT
	gotoXY(x, y + 7);
	cout << char(200);

	//LEFT
	for (int j = y + 6; j >= y; j--) {
		gotoXY(x, j);
		cout << char(186);
	}

	//TOP LEFT
	gotoXY(x, y);
	cout << char(201);

	//"Player's Information"
	gotoXY(x + 12, y + 1);
	cout << "Player's Information";

	setColor(WHITE);
	for (int i = 2; i <= 38; i++) {
		gotoXY(x + i, y + 2);
		if (i == 20) cout << '\\';
		else if (i == 21) cout << '/';
		else cout << '-';
	}

	gotoXY(x + 5, y + 3);
	cout << "Name: ";
	setColor(LIGHT_AQUA);
	cout << p.name;
	setColor(WHITE);

	gotoXY(x + 5, y + 4);
	cout << "Life: ";
	setColor(LIGHT_AQUA);
	cout << p.life;
	setColor(WHITE);

	gotoXY(x + 5, y + 5);
	cout << "Point: ";
	setColor(LIGHT_AQUA);
	cout << p.point;
	setColor(WHITE);

	//Game Information
	//TOP
	for (int i = x; i < x + 40; i++) {
		gotoXY(i, y + 8);
		cout << char(205);
	}

	//TOP RIGHT
	gotoXY(x + 40, y + 8);
	cout << char(187);

	//RIGHT
	for (int j = y + 8 + 1; j < y + 18; j++) {
		gotoXY(x + 40, j);
		cout << char(186);
	}

	//BOTTOM RIGHT
	gotoXY(x + 40, y + 18);
	cout << char(188);

	//BOTTOM
	for (int i = x + 40 - 1; i >= x; i--) {
		gotoXY(i, y + 18);
		cout << char(205);
	}

	//BOTTOM LEFT
	gotoXY(x, y + 18);
	cout << char(200);

	//LEFT
	for (int j = y + 18 - 1; j >= y + 9; j--) {
		gotoXY(x, j);
		cout << char(186);
	}

	//TOP LEFT
	gotoXY(x, y + 8);
	cout << char(201);


	gotoXY(x + 14, y + 9);
	cout << "STAGE:  ";
	setColor(LIGHT_AQUA);
	cout << "NORMAL";

	setColor(WHITE);

	for (int i = 2; i <= 38; i++) {
		gotoXY(x + i, y + 10);
		if (i == 20) cout << '\\';
		else if (i == 21) cout << '/';
		else cout << '-';
	}


	gotoXY(x + 14, y + 12);
	cout << "Game Tutorials";

	for (int i = 2; i <= 38; i++) {
		gotoXY(x + i, y + 13);
		cout << '-';
	}

	setColor(LIGHT_AQUA);
	gotoXY(x + 9, y + 14);
	cout << "Press Arrow Key To Move";
	gotoXY(x + 9, y + 15);
	cout << "Press Enter To Choose";
	gotoXY(x + 9, y + 16);
	cout << "Press ESC TO Exit";
}

void drawHardBorder(Player p) {
	//x = 11, y = 3, length = 10 * 6 + 1
	int x = 9, y = 2;

	////GameBorder

	//TOP
	for (int i = x - 2; i < x + 10 * 6 + 4; i++) {
		gotoXY(i, y - 1);
		cout << char(205);
		Sleep(10);
	}

	//TOP RIGHT
	gotoXY(x + 10 * 6 + 4, y - 1);
	cout << char(187);
	Sleep(10);

	//RIGHT
	for (int j = y; j < y + 4 * 6 + 1; j++) {
		gotoXY(x + 10 * 6 + 4, j);
		cout << char(186);
		Sleep(10);
	}

	//BOTTOM RIGHT
	gotoXY(x + 10 * 6 + 4, y + 6 * 4 + 1);
	cout << char(188);
	Sleep(10);

	//BOTTOM
	for (int i = x + 10 * 6 + 4 - 1; i > x - 2; i--) {
		gotoXY(i, y + 6 * 4 + 1);
		cout << char(205);
		Sleep(10);
	}

	//BOTTOM LEFT
	gotoXY(x - 2, y + 6 * 4 + 1);
	cout << char(200);
	Sleep(10);

	//LEFT
	for (int j = y + 4 * 6 + 1 - 1; j >= y; j--) {
		gotoXY(x - 2, j);
		cout << char(186);
		Sleep(10);
	}

	//TOP LEFT
	gotoXY(x - 2, y - 1);
	cout << char(201);
	Sleep(10);

	//Gridline
	for (int j = 0; j < 4 * 6 + 1; j++) {
		for (int i = 0; i < 10 * 6 + 1; i++) {
			if (i % 10 == 0) {
				gotoXY(x + 1 + i, y + j);
				if (j % 4 == 0) cout << '+';
				else cout << '|';
			}
		}
		Sleep(10);
	}

	for (int i = 0; i < 10 * 6 + 1; i++) {
		for (int j = 0; j < 4 * 6 + 1; j++) {
			if (j % 4 == 0) {
				gotoXY(x + 1 + i, y + j);
				if (i % 10 == 0) cout << '+';
				else cout << '-';
			}
		}
		Sleep(10);
	}

	//Player Border
	x = 90, y = 4;
	//TOP
	for (int i = x; i < x + 40; i++) {
		gotoXY(i, y);
		cout << char(205);
	}

	//TOP RIGHT
	gotoXY(x + 40, y);
	cout << char(187);

	//RIGHT
	for (int j = y + 1; j < y + 7; j++) {
		gotoXY(x + 40, j);
		cout << char(186);
	}

	//BOTTOM RIGHT
	gotoXY(x + 40, y + 7);
	cout << char(188);

	//BOTTOM
	for (int i = x + 40 - 1; i >= x; i--) {
		gotoXY(i, y + 7);
		cout << char(205);
	}

	//BOTTOM LEFT
	gotoXY(x, y + 7);
	cout << char(200);

	//LEFT
	for (int j = y + 6; j >= y; j--) {
		gotoXY(x, j);
		cout << char(186);
	}

	//TOP LEFT
	gotoXY(x, y);
	cout << char(201);

	//"Player's Information"
	gotoXY(x + 12, y + 1);
	cout << "Player's Information";

	setColor(WHITE);
	for (int i = 2; i <= 38; i++) {
		gotoXY(x + i, y + 2);
		if (i == 20) cout << '\\';
		else if (i == 21) cout << '/';
		else cout << '-';
	}

	gotoXY(x + 5, y + 3);
	cout << "Name: ";
	setColor(LIGHT_AQUA);
	cout << p.name;
	setColor(WHITE);

	gotoXY(x + 5, y + 4);
	cout << "Life: ";
	setColor(LIGHT_AQUA);
	cout << p.life;
	setColor(WHITE);

	gotoXY(x + 5, y + 5);
	cout << "Point: ";
	setColor(LIGHT_AQUA);
	cout << p.point;
	setColor(WHITE);

	//Game Information
	//TOP
	for (int i = x; i < x + 40; i++) {
		gotoXY(i, y + 8);
		cout << char(205);
	}

	//TOP RIGHT
	gotoXY(x + 40, y + 8);
	cout << char(187);

	//RIGHT
	for (int j = y + 8 + 1; j < y + 18; j++) {
		gotoXY(x + 40, j);
		cout << char(186);
	}

	//BOTTOM RIGHT
	gotoXY(x + 40, y + 18);
	cout << char(188);

	//BOTTOM
	for (int i = x + 40 - 1; i >= x; i--) {
		gotoXY(i, y + 18);
		cout << char(205);
	}

	//BOTTOM LEFT
	gotoXY(x, y + 18);
	cout << char(200);

	//LEFT
	for (int j = y + 18 - 1; j >= y + 9; j--) {
		gotoXY(x, j);
		cout << char(186);
	}

	//TOP LEFT
	gotoXY(x, y + 8);
	cout << char(201);


	gotoXY(x + 16, y + 9);
	cout << "STAGE:  ";
	setColor(LIGHT_AQUA);
	cout << "HARD";

	setColor(WHITE);

	for (int i = 2; i <= 38; i++) {
		gotoXY(x + i, y + 10);
		if (i == 20) cout << '\\';
		else if (i == 21) cout << '/';
		else cout << '-';
	}


	gotoXY(x + 14, y + 12);
	cout << "Game Tutorials";

	for (int i = 2; i <= 38; i++) {
		gotoXY(x + i, y + 13);
		cout << '-';
	}

	setColor(LIGHT_AQUA);
	gotoXY(x + 9, y + 14);
	cout << "Press Arrow Key To Move";
	gotoXY(x + 9, y + 15);
	cout << "Press Enter To Choose";
	gotoXY(x + 9, y + 16);
	cout << "Press ESC TO Exit";
}

void displayStatus(int status) {
	switch (status) {
	case 1:
		winSound();
		//Draw YOU WIN
		//Source: https://patorjk.com/software/taag/#p=display&h=1&v=0&f=3D%20Diagonal&t=YOU%20WIN
		setColor(LIGHT_GREEN);
		Sleep(200);
		gotoXY(25, 4);
		cout << "                 ,----..                                                          ,--.";
		Sleep(200);
		gotoXY(25, 5);
		cout << "                /   /   \\                                   .---.   ,---,       ,--.'|";
		Sleep(200);
		gotoXY(25, 6);
		cout << "        ,---,  /   .     :          ,--,                   /. ./|,`--.' |   ,--,:  : |";
		Sleep(200);
		gotoXY(25, 7);
		cout << "       /_ ./| .   /   ;.  \\       ,'_ /|               .--'.  ' ;|   :  :,`--.'`|  ' :";
		Sleep(200);
		gotoXY(25, 8);
		cout << " ,---, |  ' :.   ;   /  ` ;  .--. |  | :              /__./ \\ : |:   |  '|   :  :  | |";
		setColor(LIGHT_AQUA);
		Sleep(200);
		gotoXY(25, 9);
		cout << "/___/ \\.  : |;   |  ; \\ ; |,'_ /| :  . |          .--'.  '   \\' .|   :  |:   |   \\ | :";
		Sleep(200);
		gotoXY(25, 10);
		cout << " .  \\  \\ ,' '|   :  | ; | '|  ' | |  . .         /___/ \\ |    ' ''   '  ;|   : '  '; |";
		Sleep(200);
		gotoXY(25, 11);
		cout << "  \\  ;  `  ,'.   |  ' ' ' :|  | ' |  | |         ;   \\  \\;      :|   |  |'   ' ;.    ;";
		Sleep(200);
		gotoXY(25, 12);
		cout << "   \\  \\    ' '   ;  \\; /  |:  | | :  ' ;          \\   ;  `      |'   :  ;|   | | \\   |";
		Sleep(200);
		gotoXY(25, 13);
		cout << "    '  \\   |  \\   \\  ',  / |  ; ' |  | '           .   \\    .\\  ;|   |  ''   : |  ; .'";
		setColor(LIGHT_YELLOW);
		Sleep(200);
		gotoXY(25, 14);
		cout << "     \\  ;  ;   ;   :    /  :  | : ;  ; |            \\   \\   ' \\ |'   :  ||   | '`--'";
		Sleep(200);
		gotoXY(25, 15);
		cout << "      :  \\  \\   \\   \\ .'   '  :  `--'   \\            :   '  |--\";    |.' '   : |";
		Sleep(200);
		gotoXY(25, 16);
		cout << "       \\  ' ;    `---`     :  ,      .-./             \\   \\ ;    '---'   ;   |.'";
		Sleep(200);
		gotoXY(25, 17);
		cout << "        `--`                `--`----'                  '---\"             '---'";
		setColor(WHITE);
		Sleep(200);
		break;
	case 2:
		gameOverSound();
		//Draw GAME OVER
		//Source: https://patorjk.com/software/taag/#p=display&h=1&v=0&f=3D%20Diagonal&t=GAME%20OVER
		setColor(LIGHT_GREEN);
		Sleep(200);
		gotoXY(10, 7);
		cout << "                                    ____                        ,----..";
		Sleep(200);
		gotoXY(10, 8);
		cout << "  ,----..      ,---,               ,'  , `.    ,---,.           /   /   \\                  ,---,.,-.----.";
		Sleep(200);
		gotoXY(10, 9);
		cout << " /   /   \\    '  .' \\           ,-+-,.' _ |  ,'  .' |          /   .     :        ,---.  ,'  .' |\\    /  \\";
		Sleep(200);
		gotoXY(10, 10);
		cout << "|   :     :  /  ;    '.      ,-+-. ;   , ||,---.'   |         .   /   ;.  \\      /__./|,---.'   |;   :    \\";
		Sleep(200);
		gotoXY(10, 11);
		cout << ".   |  ;. / :  :       \\    ,--.'|'   |  ;||   |   .'        .   ;   /  ` ; ,---.;  ; ||   |   .'|   | .\\ :  ";
		setColor(LIGHT_AQUA);
		Sleep(200);
		gotoXY(10, 12);
		cout << ".   ; /--`  :  |   /\\   \\  |   |  ,', |  '::   :  |-,        ;   |  ; \\ ; |/___/ \\  | |:   :  |-,.   : |: |";
		Sleep(200);
		gotoXY(10, 13);
		cout << ";   | ;  __ |  :  ' ;.   : |   | /  | |  ||:   |  ;/|        |   :  | ; | '\\   ;  \\ ' |:   |  ;/||   |  \\ :";
		Sleep(200);
		gotoXY(10, 14);
		cout << "|   : |.' .'|  |  ;/  \\   \\'   | :  | :  |,|   :   .'        .   |  ' ' ' : \\   \\  \\: ||   :   .'|   : .  /";
		Sleep(200);
		gotoXY(10, 15);
		cout << ".   | '_.' :'  :  | \\  \\ ,';   . |  ; |--' |   |  |-,        '   ;  \\; /  |  ;   \\  ' .|   |  |-,;   | |  \\";
		Sleep(200);
		gotoXY(10, 16);
		cout << "'   ; : \\  ||  |  '  '--'  |   : |  | ,    '   :  ;/|         \\   \\  ',  /    \\   \\   ''   :  ;/||   | ;\\  \\";
		setColor(LIGHT_YELLOW);
		Sleep(200);
		gotoXY(10, 17);
		cout << "'   | '/  .'|  :  :        |   : '  |/     |   |    \\          ;   :    /      \\   `  ;|   |    \\:   ' | \\.'";
		Sleep(200);
		gotoXY(10, 18);
		cout << "|   :    /  |  | ,'        ;   | |`-'      |   :   .'           \\   \\ .'        :   \\ ||   :   .':   : :-'";
		Sleep(200);
		gotoXY(10, 19);
		cout << " \\   \\ .'   `--''          |   ;/          |   | ,'              `---`           '---\" |   |, '  |   |.'";
		Sleep(200);
		gotoXY(10, 20);
		cout << "  `---`                    '---'           `----'                                      `----'    `---'";
		Sleep(200);
		break;
	}
}

void getPlayerInfo(Player& p) {
	gotoXY(50, 12);
	cout << "Enter Player Name: ";
	cin >> p.name;
	cin.ignore();
	p.life = 3;
	p.point = 0;
	system("cls");
}

void drawILine(int r1, int c1, int r2, int c2) {
	int y1 = min(r1, r2);
	int y2 = max(r1, r2);
	int x1 = min(c1, c2);
	int x2 = max(c1, c2);
	x1 = (x1 + 1) * 10 + 11, x2 = (x2 + 1) * 10 + 11, y1 = (y1 + 1) * 4 + 4, y2 = (y2 + 1) * 4 + 4;

	//vertical
	if (y1 == y2) {
		for (int i = x1 + 1; i <= x2 - 1; i++) {
			if (i <= x1 + 4 || i >= x2 - 4) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(i, y1);
			cout << char(205);
		}
		setColor(WHITE);
		return;
	}

	//horizontal
	if (x1 == x2) {
		for (int i = y1 + 1; i <= y2 - 1; i++) {
			if (i <= y1 + 1 || i >= y2 - 1) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(x1, i);
			cout << char(186);
		}
		setColor(WHITE);
		return;
	}
}

void deleteILine(int r1, int c1, int r2, int c2) {
	int y1 = min(r1, r2);
	int y2 = max(r1, r2);
	int x1 = min(c1, c2);
	int x2 = max(c1, c2);
	x1 = (x1 + 1) * 10 + 11, x2 = (x2 + 1) * 10 + 11, y1 = (y1 + 1) * 4 + 4, y2 = (y2 + 1) * 4 + 4;

	setColor(WHITE);

	//vertical
	if (y1 == y2) {
		for (int i = x1 + 1; i <= x2 - 1; i++) {
			gotoXY(i, y1);
			cout << char(32);
		}
		return;
	}

	//horizontal
	if (x1 == x2) {
		for (int i = y1 + 1; i <= y2 - 1; i++) {
			gotoXY(x1, i);
			cout << char(32);
		}
		return;
	}
}

void casedrawLLine(NormalMode** p_ball, int r1, int c1, int r2, int c2, int corner_y, int corner_x) {
	//top-left corner
	if (c2 > corner_x && r1 > corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//vertical
		for (int i = r1 - 1; i >= corner_y + 1; i--) {
			if (i == r1 - 1) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(c1, i);
			cout << char(186);
		}
		setColor(WHITE);
		//corner
		gotoXY(corner_x, corner_y);
		cout << char(201);

		//horizontal
		for (int i = corner_x + 1; i <= c2 - 1; i++) {
			if (i >= c2 - 4) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(i, r2);
			cout << char(205);
		}
		setColor(WHITE);
		return;
	}

	//top-right corner
	if (c1 < corner_x && r2 > corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//horizontal
		for (int i = c1 + 1; i <= corner_x - 1; i++) {
			if (i <= c1 + 4) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(i, r1);
			cout << char(205);
		}

		//corner
		setColor(WHITE);
		gotoXY(corner_x, corner_y);
		cout << char(187);

		//vertical
		for (int i = corner_y + 1; i <= r2 - 1; i++) {
			if (i >= r2 + 1) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(c2, i);
			cout << char(186);
		}
		setColor(WHITE);
		return;
	}

	//bottom-left corner
	if (c2 > corner_x && r1 < corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//vertical
		for (int i = r1 + 1; i <= corner_y - 1; i++) {
			if (i == r1 + 1) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(c1, i);
			cout << char(186);
		}

		//corner
		setColor(WHITE);
		gotoXY(corner_x, corner_y);
		cout << char(200);

		//horizontal
		for (int i = corner_x + 1; i <= c2 - 1; i++) {
			if (i >= c2 - 4) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(i, r2);
			cout << char(205);
		}
		setColor(WHITE);
		return;
	}

	//bottom-right corner
	if (c1 < corner_x && r2 < corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//horizontal
		for (int i = c1 + 1; i <= corner_x - 1; i++) {
			if (i <= c1 + 4) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(i, r1);
			cout << char(205);
		}

		//corner
		setColor(WHITE);
		gotoXY(corner_x, corner_y);
		cout << char(188);

		//vertical
		for (int i = corner_y - 1; i >= r2 + 1; i--) {
			if (i <= r2 + 1) setColor(WHITE + GREEN * 16);
			else setColor(WHITE);
			gotoXY(c2, i);
			cout << char(186);
		}
		setColor(WHITE);
		return;
	}
}

void drawLLine(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	int corner_x, corner_y;
	if (c1 > c2) {
		swap(c1, c2);
		swap(r1, r2);
	}

	corner_x = c1;
	corner_y = r2;
	if (p_ball[corner_y][corner_x].exist == false) {
		if (lineCheck(p_ball, r1, c1, corner_y, corner_x) && lineCheck(p_ball, r2, c2, corner_y, corner_x)) {
			casedrawLLine(p_ball, r1, c1, r2, c2, corner_y, corner_x);
			return;
		}
	}

	corner_x = c2;
	corner_y = r1;
	if (p_ball[corner_y][corner_x].exist == false) {
		if (lineCheck(p_ball, r1, c1, corner_y, corner_x) && lineCheck(p_ball, r2, c2, corner_y, corner_x)) {
			casedrawLLine(p_ball, r1, c1, r2, c2, corner_y, corner_x);
			return;
		}
	}
}

void caseDeleteLLine(NormalMode** p_ball, int r1, int c1, int r2, int c2, int corner_y, int corner_x) {
	setColor(WHITE);
	//top-left corner
	if (c2 > corner_x && r1 > corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//vertical
		for (int i = r1 - 1; i >= corner_y + 1; i--) {
			gotoXY(c1, i);
			cout << char(32);
		}

		//corner
		gotoXY(corner_x, corner_y);
		cout << char(32);

		//horizontal
		for (int i = corner_x + 1; i <= c2 - 1; i++) {
			gotoXY(i, r2);
			cout << char(32);
		}
		return;
	}

	//top-right corner
	if (c1 < corner_x && r2 > corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//horizontal
		for (int i = c1 + 1; i <= corner_x - 1; i++) {
			gotoXY(i, r1);
			cout << char(32);
		}

		//corner
		gotoXY(corner_x, corner_y);
		cout << char(32);

		//vertical
		for (int i = corner_y + 1; i <= r2 - 1; i++) {
			gotoXY(c2, i);
			cout << char(32);
		}
		return;
	}

	//bottom-left corner
	if (c2 > corner_x && r1 < corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//vertical
		for (int i = r1 + 1; i <= corner_y - 1; i++) {
			gotoXY(c1, i);
			cout << char(32);
		}

		//corner
		gotoXY(corner_x, corner_y);
		cout << char(32);

		//horizontal
		for (int i = corner_x + 1; i <= c2 - 1; i++) {
			gotoXY(i, r2);
			cout << char(32);
		}
		return;
	}

	//bottom-right corner
	if (c1 < corner_x && r2 < corner_y) {
		c1 = (c1 + 1) * 10 + 11; c2 = (c2 + 1) * 10 + 11; corner_x = (corner_x + 1) * 10 + 11;
		r1 = (r1 + 1) * 4 + 4; r2 = (r2 + 1) * 4 + 4; corner_y = (corner_y + 1) * 4 + 4;
		//horizontal
		for (int i = c1 + 1; i <= corner_x - 1; i++) {
			gotoXY(i, r1);
			cout << char(32);
		}

		//corner
		gotoXY(corner_x, corner_y);
		cout << char(32);

		//vertical
		for (int i = corner_y - 1; i >= r2 + 1; i--) {
			gotoXY(c2, i);
			cout << char(32);
		}
		return;
	}
}

void deleteLLine(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	int corner_x, corner_y;
	if (c1 > c2) {
		swap(c1, c2);
		swap(r1, r2);
	}

	corner_x = c1;
	corner_y = r2;
	if (p_ball[corner_y][corner_x].exist == false) {
		if (lineCheck(p_ball, r1, c1, corner_y, corner_x) && lineCheck(p_ball, r2, c2, corner_y, corner_x)) {
			caseDeleteLLine(p_ball, r1, c1, r2, c2, corner_y, corner_x);
			return;
		}
	}

	corner_x = c2;
	corner_y = r1;
	if (p_ball[corner_y][corner_x].exist == false) {
		if (lineCheck(p_ball, r1, c1, corner_y, corner_x) && lineCheck(p_ball, r2, c2, corner_y, corner_x)) {
			caseDeleteLLine(p_ball, r1, c1, r2, c2, corner_y, corner_x);
			return;
		}
	}
}