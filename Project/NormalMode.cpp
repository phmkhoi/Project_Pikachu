#include "NormalMode.h"
#include "NormalCheck.h"
#include "Struct.h"
#include "Utility.h"
#include "LeaderBoard.h"
#include "Sound.h"

using namespace std;

void initBoard(NormalMode** board) {
	int pair = (NORMAL_WIDTH * NORMAL_HEIGHT) / 2;
	while (pair) { 
		int index, pair_amount = 2;
		char c = 65 + rand() % 3;
		while (pair_amount) { // 
			index = rand() % (NORMAL_WIDTH * NORMAL_HEIGHT);
			if (board[index / NORMAL_WIDTH][index % NORMAL_WIDTH].p_mon == ' ') {
				board[index / NORMAL_WIDTH][index % NORMAL_WIDTH].p_mon = c;
				pair_amount--;
			}
		}
		pair--;
	}
}

//delete GameBoard
void deleteBoard(NormalMode** board) {
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		for (int j = 0; j < NORMAL_WIDTH; j++) {
			if (board[i][j].exist) {
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
void printBoard(NormalMode** board) {
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		for (int j = 0; j < NORMAL_WIDTH; j++) {
			board[i][j].drawCell(112);
		}
	}
}

void move(NormalMode** board, Position& pos, int& status, Player& p, Position selectedPos[], int& couple) {
    int temp, key;
    temp = _getch();
    if (temp && temp != 224) { //If not arrow key
        if (temp == ESC_KEY) {
            status = 2;
        }
        else if (temp == ENTER_KEY) {
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                board[selectedPos[0].y][selectedPos[0].x].drawCell(70);
                Sleep(500);

                board[selectedPos[0].y][selectedPos[0].x].is_selected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };
                p.life--;
                gotoXY(70, 0);
                cout << "Life: " << p.life;
            }
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                board[pos.y][pos.x].is_selected = 1;
                couple--;

                //If 1 pair is selected
                if (couple == 0) {
                    if (board[selectedPos[0].y][selectedPos[0].x].p_mon == board[selectedPos[1].y][selectedPos[1].x].p_mon) {  // neu cap nay hop nhau
                        if (allCheck(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
                            p.point += 20;

                            //Update Score
                            gotoXY(40, 0);
                            cout << "Point: " << p.point;

                            board[selectedPos[0].y][selectedPos[0].x].drawCell(40);
                            board[selectedPos[1].y][selectedPos[1].x].drawCell(40);
                            Sleep(500);

                            board[selectedPos[0].y][selectedPos[0].x].exist = 0;
                            board[selectedPos[0].y][selectedPos[0].x].deleteCell();
                            //if (selectedPos[0].x < 4) displayBackground(bg, selectedPos[0].x, selectedPos[0].y);

                            board[selectedPos[1].y][selectedPos[1].x].exist = 0;
                            board[selectedPos[1].y][selectedPos[1].x].deleteCell();
                            //if (selectedPos[1].x < 4) displayBackground(bg, selectedPos[1].x, selectedPos[1].y);
                        }
                        else {
                            board[selectedPos[0].y][selectedPos[0].x].drawCell(70);
                            board[selectedPos[1].y][selectedPos[1].x].drawCell(70);
                            Sleep(500);

                            p.life--;

                            //Update Life
                            gotoXY(70, 0);
                            cout << "Life: " << p.life;
                        }
                    }
                    else {
                        board[selectedPos[0].y][selectedPos[0].x].drawCell(70);
                        board[selectedPos[1].y][selectedPos[1].x].drawCell(70);
                        Sleep(500);

                        p.life--;
                        gotoXY(70, 0);
                        cout << "Life: " << p.life;
                    }
                    
                    //reset
                    board[selectedPos[0].y][selectedPos[0].x].is_selected = 0;
                    board[selectedPos[1].y][selectedPos[1].x].is_selected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < NORMAL_HEIGHT; i++) {
                        for (int j = pos.x; j < NORMAL_WIDTH; j++) {
                            if (board[i][j].exist) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }

                    //Move To Cell
                    for (int i = 0; i <= pos.y; i++) {
                        for (int j = 0; j <= pos.x; j++) {
                            if (board[i][j].exist) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    //If arrow key
    else
    {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            board[pos.y][pos.x].is_selected = 0;
        switch (key = _getch())
        {
        case UP_KEY:
            for (int i = pos.x; i < NORMAL_WIDTH; i++) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = pos.y - 1; j >= 0; j--) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < NORMAL_WIDTH; i++) {
                for (int j = NORMAL_HEIGHT - 1; j > pos.y; j--) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i >= 0; i--) {
                for (int j = NORMAL_HEIGHT - 1; j > pos.y; j--) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            break;
        case DOWN_KEY:
            for (int i = pos.x; i < NORMAL_WIDTH; i++) {
                for (int j = pos.y + 1; j < NORMAL_HEIGHT; j++) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = pos.y + 1; j < NORMAL_HEIGHT; j++) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x; i < NORMAL_WIDTH; i++) {
                for (int j = 0; j < pos.y; j++) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }

            for (int i = pos.x - 1; i >= 0; i--) {
                for (int j = 0; j < pos.y; j++) {
                    if (board[j][i].exist) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }
                }
            }
            break;
        case LEFT_KEY:
            for (int i = pos.y; i >= 0; i--) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < NORMAL_HEIGHT; i++) {
                for (int j = pos.x - 1; j >= 0; j--) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = NORMAL_WIDTH - 1; j > pos.x; j--) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < NORMAL_HEIGHT; i++) {
                for (int j = NORMAL_WIDTH - 1; j > pos.x; j--) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
            break;
        case RIGHT_KEY:
            for (int i = pos.y; i >= 0; i--) {
                for (int j = pos.x + 1; j < NORMAL_WIDTH; j++) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < NORMAL_HEIGHT; i++) {
                for (int j = pos.x + 1; j < NORMAL_WIDTH; j++) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y; i >= 0; i--) {
                for (int j = 0; j < pos.x; j++) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }

            for (int i = pos.y + 1; i < NORMAL_HEIGHT; i++) {
                for (int j = 0; j < pos.x; j++) {
                    if (board[i][j].exist) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }
                }
            }
        default:
            break;
        }
    }
}

//x = 15, y = 6, start = 18
void drawBorder() {
	int x = 15, y = 6;
	//TOP
	for (int i = x - 1; i < x + 9 * 4 + 2; i++) {
		gotoXY(i, y - 1);
		cout << char(205);
		Sleep(50);
	}
	
	//TOP RIGHT
	gotoXY(x + 9 * 4 + 2, y - 1);
	cout << char(187);
	Sleep(50);

	//RIGHT
	for (int j = y; j < y + 4 * 4 + 1; j++) {
		gotoXY(x + 9 * 4 + 2, j);
		cout << char(186);
		Sleep(50);
	}

	//BOTTOM RIGHT
	gotoXY(x + 9 * 4 + 2, y + 4 * 4 + 1);
	cout << char(188);
	Sleep(50);

	//BOTTOM
	for (int i = x + 9 * 4 + 2 - 1; i >= x - 2; i--) {
		gotoXY(i, y + 4 * 4 + 1);
		cout << char(205);
		Sleep(50);
	}

	//BOTTOM LEFT
	gotoXY(x - 2, y + 4 * 4 + 1);
	cout << char(200);
	Sleep(50);

	//LEFT
	for (int j = y + 4 * 4 + 1 - 1; j >= y; j--) {
		gotoXY(x - 2, j);
		cout << char(186);
		Sleep(50);
	}

	//TOP LEFT
	gotoXY(x - 2, y - 1);
	cout << char(201);
	Sleep(50);
}

void normalMode(Player &p) {
	//drawBorder();
	srand(time(0));
	/*getBackground(bg);*/

	//initialize board
	NormalMode** board = new NormalMode* [NORMAL_HEIGHT];
	for (int i = 0; i < NORMAL_HEIGHT; i++) { // gan vi tri cho tung o mot
		board[i] = new NormalMode[NORMAL_WIDTH];
		for (int j = 0; j < NORMAL_WIDTH; j++) {
			board[i][j].j = j;
			board[i][j].i = i;
		}
	}
	initBoard(board);


	gotoXY(10, 0);
	cout << "Name: " << p.name;
	gotoXY(40, 0);
	cout << "Point: " << p.point;
	gotoXY(70, 0);
	cout << "Life: " << p.life;

	setColor(LIGHT_AQUA);
	gotoXY(100, 12);
	cout << "Press arrow key to move";
	gotoXY(100, 13);
	cout << "Press Enter to delete";
	gotoXY(100, 14);
	cout << "Press ESC to quit";
	setColor(WHITE);

	Position selected_pos[] = { {-1, -1}, {-1, -1} };
	int couple = 2;
	Position cur_pos = { 0, 0 };

	/*0: Playing
	1: Finish
	2: Out*/
	int status = 0;
	
	while (!status && p.life) {
		board[cur_pos.y][cur_pos.x].is_selected = 1;

		printBoard(board);

		move(board, cur_pos, status, p, selected_pos, couple);
		if ((!checkValidPairs(board))) status = 1;
	}

	printBoard(board);
	deleteBoard(board);
	Sleep(500);
	system("cls");

	if (p.life && status == 1) {
		//displayStatus(1);
		gotoXY(50, 17);
		char ans;
		cout << "Do you want to continue next game? (Y/N): ";
		cin >> ans;
		cin.ignore();
		system("cls");
		if (ans == 'Y' || ans == 'y') {
			normalMode(p);
		}
		else {
			writeLeaderBoard(p);
		}
	}
	else if (p.life == 0) {
		//displayStatus(0);
		writeLeaderBoard(p);
		Sleep(2000);
	}
	system("cls");
}