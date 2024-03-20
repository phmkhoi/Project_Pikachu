#include "Utility.h"
#include "Struct.h"

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

void getBackground(char bg[][41]) {
	ifstream ifs;
	ifs.open("Background.txt", ios::in);
	if (ifs) {
		for (int i = 0; i < 23; i++) {
			for (int j = 0; j < 41; j++) {
				bg[i][j] = ifs.get();
			}
			ifs.ignore();
		}
	}
	else {
		memset(bg, ' ', sizeof(bg));
	}
	ifs.close();
}

void displayBackground(char bg[][41], int x, int y) {
	//set bg color
	setColor(LIGHT_GREEN);

	//print bg from each cell
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 11; j++) {
			gotoXY((x + 1) * 10 + j, (y + 1) * 4 + j);
			cout << bg[y * 4 + i][x * 10 + j];
		}
	}

	//reset color
	setColor(WHITE);
}