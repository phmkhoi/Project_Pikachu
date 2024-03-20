#include "NormalMode.h"
#include "Struct.h"
#include "Utility.h"

using namespace std;

void initBoard(CELL_1** board) {
	int pair = (NORMAL_WIDTH * NORMAL_HEIGHT) / 2;
	while (pair) { 
		int index, pair_amount = 2;
		char c = 65 + rand() % 26;
		while (pair_amount) { // 
			index = rand() % 40;
			if (board[index / 8][index % 8].letter == ' ') {
				board[index / 8][index % 8].letter = c;
				pair_amount--;
			}
		}
		pair--;
	}
}

//background
char bg[][41];

//delete GameBoard
void deleteBoard(CELL_1** board) {
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		for (int j = 0; j < NORMAL_WIDTH; j++) {
			if (board[i][j].is_valid) {
				board[i][j].deleteCell();
				//if (j < 4) displayBackground(bg, j, i);
				//Sleep(200);
			}
		}
	}

	//delete pointer
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		delete[] board[i];
	}
	delete[] board;
}

//draw GameBoard
void printBoard(CELL_1** board) {
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		for (int j = 0; j < NORMAL_WIDTH; j++) {
			board[i][j].drawCell(112);
		}
	}
}

//void move(CELL_1** board, Position& pos, int& status, Player& p, Position selected_pos[],
//	int& pair) {
//	int temp, key;
//	temp = _getch();
//	if (temp && temp != 224) {//If not arrow key
//		if (temp == ESC_KEY) {
//			status = 2; //Finish Game
//		}
//		else if (temp == ENTER_KEY) {
//			if (pos.x == selected_pos[0].x && pos.y == selected_pos[0].y) {
//				board[selected_pos[0].y][selected_pos[0].x].drawCell(70);
//				Sleep(500);
//
//				board[selected_pos[0].y][selected_pos[0].x].is_selected = 0;
//				pair = 2;
//				selected_pos[0] = { -1, -1 };
//				--p.life;
//				gotoXY(70, 0);
//				cout << "Life: " << p.life;
//			}
//			else {
//				selected_pos[2 - pair].x = pos.x;
//				selected_pos[2 - pair].y = pos.y;
//			}
//		}
//	}
//}

void normalMode() {
	srand(time(0));
	/*getBackground(bg);*/

	CELL_1** board = new CELL_1 * [NORMAL_HEIGHT];
	for (int i = 0; i < NORMAL_HEIGHT; i++) { // gan vi tri cho tung o mot
		board[i] = new CELL_1[NORMAL_WIDTH];
		for (int j = 0; j < NORMAL_WIDTH; j++) {
			board[i][j].j = j;
			board[i][j].i = i;
		}
	}
	//int pair = (NORMAL_WIDTH * NORMAL_HEIGHT) / 2;
	//while (pair > 0) {
	//	int index, pair_amount = 2;
	//	char c = 65 + rand() % 26;
	//	while (pair_amount > 0) { // 
	//		index = rand() % 40;
	//		if (board[index / 8][index % 8].letter == ' ') {
	//			board[index / 8][index % 8].letter = c;
	//			pair_amount--;
	//		}
	//	}
	//	pair--;
	//}
	//initBoard(board);
	/*gotoXY(10, 0);
	cout << "Name: " << p.name;
	gotoXY(40, 0);
	cout << "Point: " << p.point;
	gotoXY(70, 0);
	cout << "Life: " << p.life;*/

	setColor(LIGHT_AQUA);
	gotoXY(100, 12);
	cout << "Press arrow key to move";
	gotoXY(100, 13);
	cout << "Press Enter to delete";
	gotoXY(100, 14);
	cout << "Press ESC to quit";
	setColor(WHITE);

	/*0: Playing
	1: Finish
	2: Out*/
	int status = 0;
	printBoard(board);
	char c = _getch();
	if (c == ESC_KEY) deleteBoard(board);
}