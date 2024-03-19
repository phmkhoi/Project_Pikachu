#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Console_Settings.h"

#define UP_KEY 72
#define DOWN_KEY 80
#define LEFT_KEY 75
#define RIGHT_KEY 77
#define ESC_KEY 27
#define ENTER_KEY 13
#define BLACK 0
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define BRIGHT_WHITE 15

using namespace std;

void setColor(int color) {
	HANDLE hcolor;
	hcolor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcolor, color);
}

void drawBox(int x, int width, int y, int height, int text_color, int bg_color, string content) {
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

	gotoXY(x, y); cout << char(218);
	gotoXY(x + width - 1, y); cout << char(191);
	gotoXY(x, y + height - 1); cout << char(192);
	gotoXY(x + width - 1, y + height - 1); cout << char(217);

	setColor(text_color + bg_color * 16);
	for (int ix = x + 1; ix < x + width - 1; ix++) {
		for (int iy = y + 1; iy < y + height - 1; iy++) {
			gotoXY(ix, iy);
			cout << " ";
		}
	}

	gotoXY(x + (width - content.length()) / 2, y + (height - 1) / 2);
	cout << content;
	setColor(WHITE);
}

int mainMenu() {
	//Draw Word
	gotoXY(10, 4);
	setColor(GREEN);
	cout << " _____   _   _   _____";
	gotoXY(10, 5);
	cout << "|_   _| | | | | |  ___|";
	gotoXY(10, 6);
	setColor(AQUA);
	cout << "  | |   | |_| | | |__  ";
	gotoXY(10, 7);
	cout << "  | |   |  _  | |  __| ";
	gotoXY(10, 8);
	setColor(YELLOW);
	cout << "  | |   | | | | | |___ ";
	gotoXY(10, 9);
	cout << "  \\_/   \\_| |_/ \\____/ ";

	gotoXY(10, 11);
	setColor(GREEN);
	cout << "___  ___  ___  _____  _____  _   _  _____  _   _  _____ ";
	gotoXY(10, 12);
	cout << "|  \\/  | / _ \\|_   _|/  __ \\| | | ||_   _|| \\ | ||  __ \\";
	gotoXY(10, 13);
	setColor(AQUA);
	cout << "| .  . |/ /_\\ \\ | |  | /  \\/| |_| |  | |  |  \\| || |  \\/";
	gotoXY(10, 14);
	cout << "| |\\/| ||  _  | | |  | |    |  _  |  | |  | . ` || | __ ";
	gotoXY(10, 15);
	setColor(YELLOW);
	cout << "| |  | || | | | | |  | \\__/\\| | | | _| |_ | |\\  || |_\\ \\";
	gotoXY(10, 16);
	cout << "\\_|  |_/\\_| |_/ \\_/   \\____/\\_| |_/ \\___/ \\_| \\_/ \\____/";

	gotoXY(10, 18);
	setColor(GREEN);
	cout << " _____   ___  ___  ___ _____ ";
	gotoXY(10, 19);
	cout << "|  __ \\ / _ \\ |  \\/  ||  ___|";
	gotoXY(10, 20);
	setColor(AQUA);
	cout << "| |  \\// /_\\ \\| .  . || |__  ";
	gotoXY(10, 21);
	cout << "| | __ |  _  || |\\/| ||  __| ";
	gotoXY(10, 22);
	setColor(YELLOW);
	cout << "| |_\\ \\| | | || |  | || |___ ";
	gotoXY(10, 23);
	cout << " \\____/\\_| |_/\\_|  |_/\\____/ ";

	setColor(WHITE);
	int x_menu = 100, y_menu = 4;

	for (int x_border = x_menu - 5; x_border <= x_menu + 16 + 4; x_border++) {
		setColor(GREEN);
		gotoXY(x_border, y_menu - 2);
		cout << char(205);
		setColor(YELLOW);
		gotoXY(x_border, y_menu + 5 * 4 + 1);
		cout << char(205);
	}

	setColor(WHITE);
	for (int y_border = y_menu - 2; y_border <= y_menu + 5 * 4 + 1; y_border++) {
		if (y_border <= y_menu - 2 + 7) {
			setColor(GREEN);
		}
		else if (y_border <= y_menu - 2 + 16) {
			setColor(AQUA);
		}
		else {
			setColor(YELLOW);
		}
		gotoXY(x_menu - 5, y_border);
		cout << char(186);
		gotoXY(x_menu + 16 + 4, y_border);
		cout << char(186);
	}
	setColor(GREEN);
	gotoXY(x_menu - 5, y_menu - 2); cout << char(201);
	gotoXY(x_menu + 16 + 4, y_menu - 2); cout << char(187);
	setColor(YELLOW);
	gotoXY(x_menu - 5, y_menu + 5 * 4 + 1); cout << char(200);
	gotoXY(x_menu + 16 + 4, y_menu + 5 * 4 + 1); cout << char(188);

	setColor(WHITE);

	int choice[4] = { 0, 0, 0, 0 }, cur_choice = 0, key, temp_key;
	while (1) {
		choice[cur_choice] = 1;

		if (choice[0]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu, 5, 12, 10, "NORMAL");
			gotoXY(x_menu - 3, y_menu + 2);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 2);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu, 5, 7, 0, "NORMAL");
			setColor(0 * 0);
			gotoXY(x_menu - 3, y_menu + 2);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 2);
			cout << "  ";
		}

		if (choice[1]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 5, 5, 12, 3, "HARD");
			gotoXY(x_menu - 3, y_menu + 5 + 2);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 5 + 2);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 5, 5, 7, 0, "HARD");
			setColor(0 * 0);
			gotoXY(x_menu - 3, y_menu + 5 + 2);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 5 + 2);
			cout << "  ";
		}

		if (choice[2]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 10, 5, 12, 3, "LEADER BOARD");
			gotoXY(x_menu - 3, y_menu + 10 + 2);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 10 + 2);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 10, 5, 7, 0, "LEADER BOARD");
			gotoXY(x_menu - 3, y_menu + 10 + 2);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 10 + 2);
			cout << "  ";
		}

		if (choice[3]) {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 15, 5, 12, 6, "EXIT");
			gotoXY(x_menu - 3, y_menu + 15 + 2);
			cout << ">>";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 15 + 2);
			cout << "<<";
		}
		else {
			setColor(WHITE);
			drawBox(x_menu, 16, y_menu + 15, 5, 7, 0, "EXIT");
			gotoXY(x_menu - 3, y_menu + 15 + 2);
			cout << "  ";
			gotoXY(x_menu + 16 - 1 + 2, y_menu + 15 + 2);
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