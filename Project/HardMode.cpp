#include "HardMode.h"
#include "HardCheck.h"
#include "Struct.h"
#include "LeaderBoard.h"

#define HARD_HEIGHT 8
#define HARD_WIDTH 8

//void push(HardMode* &head, HardMode* p_new) {
//	if (head == NULL) head = p_new;
//	else {
//		HardMode* p_temp = head;
//		while (p_temp->p_next != NULL) {
//			p_temp = p_temp->p_next;
//		}
//		p_temp->p_next = p_new;
//	}
//}
//
//void initList(HardMode** board) {
//	int pair = (HARD_WIDTH * HARD_HEIGHT) / 2;
//	while (pair) {
//		int i, j, pair_amount = 2;
//		char c = 65 + rand() % 26;
//		while (pair_amount) { // 
//			i = rand() % HARD_HEIGHT;
//			j = rand() % HARD_WIDTH;
//			HardMode* p = findPokeBall(board, i, j);
//			if (p->p_mon == ' ') {
//				p->p_mon = c;
//				pair_amount--;
//			}
//		}
//		pair--;
//	}
//}
//
//void deleteList(HardMode** board) {
//	for (int i = 0; i < HARD_HEIGHT; i++) {
//		HardMode* p_temp;
//		while (board[i] != NULL) {
//			p_temp = board[i];
//			board[i] = board[i]->p_next;
//			p_temp->deleteCell();
//			//Insert Bg
//			Sleep(500);
//			delete p_temp;
//		}
//	}
//	delete[] board;
//}
//
//void printList(HardMode** board) {
//	for (int i = 0; i < HARD_HEIGHT; i++) {
//		HardMode* p_temp = board[i];
//		while (p_temp != NULL)
//		{
//			p_temp->drawCell(112);
//			p_temp = p_temp->p_next;
//		}
//	}
//}
//
//void move(HardMode** board, Position& pos, int& status, Player& p, Position selected_pos[], int& couple) {
//    int temp, key;
//    temp = _getch();
//    if (temp && temp != 224) {//If not arrow key
//        if (temp == ESC_KEY) {
//            status = 2; //Finish Game
//        }
//        else if (temp == ENTER_KEY) {
//            if (pos.x == selected_pos[0].x && pos.y == selected_pos[0].y) {
//                //Reset the Cell 
//                HardMode* temp = findPokeBall(board, pos.y, pos.x);
//                temp->drawCell(70);
//                Sleep(500);
//
//                temp->is_selected = 0;
//                couple = 2;
//                selected_pos[0] = { -1, -1 };
//                p.life--;
//                gotoXY(70, 0);
//                cout << "Life: " << p.life;
//            }
//            else {
//                selected_pos[2 - couple].x = pos.x;
//                selected_pos[2 - couple].y = pos.y;
//                findPokeBall(board, pos.y, pos.x)->is_selected = 1;
//                couple--;
//
//                //If 1 pair is selected
//                if (couple == 0) {
//                    HardMode* cell1, * cell2;
//                    cell1 = findPokeBall(board, selected_pos[0].y, selected_pos[0].x);
//                    cell2 = findPokeBall(board, selected_pos[1].y, selected_pos[1].x);
//                    if (cell1->p_mon == cell2->p_mon) {
//                        if (allCheck(board, selected_pos[0].y, selected_pos[0].x, selected_pos[1].y, selected_pos[1].x)) {
//                            p.point += 20;
//                            gotoXY(40, 0);
//                            cout << "Point: " << p.point;
//
//                            cell1->drawCell(40);
//                            cell2->drawCell(40);
//                            Sleep(500);
//
//
//                            cell1->exist = 0;
//                            cell2->exist = 0;
//                            //Insert BG
//                            deletePair(board, selected_pos[0].y, selected_pos[0].x, selected_pos[1].y, selected_pos[1].x);
//                        }
//                        else {
//                            cell1->drawCell(70);
//                            cell2->drawCell(70);
//                            Sleep(500);
//
//                            p.life--;
//                            gotoXY(70, 0);
//                            cout << "Life: " << p.life;
//                        }
//                    }
//                    else {
//                        cell1->drawCell(70);
//                        cell2->drawCell(70);
//                        Sleep(500);
//
//                        p.life--;
//                        gotoXY(70, 0);
//                        cout << "Life: " << p.life;
//                    }
//                    
//                    //Reset
//                    cell1->is_selected = 0;
//                    cell2->is_selected = 0;
//                    couple = 2;
//                    selected_pos[0] = { -1, -1 };
//                    selected_pos[1] = { -1, -1 };
//
//                    for (int i = pos.y; i < HARD_HEIGHT; i++) {
//                        for (int j = pos.x; j < HARD_WIDTH; j++) {
//                            if (findPokeBall(board, i, j) != NULL) {
//                                pos.x = j;
//                                pos.y = i;
//                                return;
//                            }
//                        }
//                    }
//
//                    //Move To First Cell
//                    for (int i = 0; i <= pos.y; i++) {
//                        for (int j = 0; j <= pos.x; j++) {
//                            if (findPokeBall(board, i, j) != NULL) {
//                                pos.x = j;
//                                pos.y = i;
//                                return;
//                            }
//                        }
//                    }
//                }
//            }
//        }
//    }
//    //If Arrow Key
//    else
//    {
//        if ((pos.y != selected_pos[0].y || pos.x != selected_pos[0].x) && (pos.y != selected_pos[1].y || pos.x != selected_pos[1].x)) // ktra xem o nay co dang duoc chon hay khong
//            findPokeBall(board, pos.y, pos.x)->is_selected = 0;
//        switch (key = _getch())
//        {
//        case UP_KEY:
//            for (int i = pos.x; i < HARD_WIDTH; i++) {
//                for (int j = pos.y - 1; j >= 0; j--) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.x - 1; i >= 0; i--) {
//                for (int j = pos.y - 1; j >= 0; j--) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.x; i < HARD_WIDTH; i++) {
//                for (int j = HARD_HEIGHT - 1; j > pos.y; j--) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.x; i >= 0; i--) {
//                for (int j = HARD_HEIGHT - 1; j > pos.y; j--) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//            break;
//
//        case DOWN_KEY:
//            for (int i = pos.x; i < HARD_WIDTH; i++) {
//                for (int j = pos.y + 1; j < HARD_HEIGHT; j++) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.x - 1; i >= 0; i--) {
//                for (int j = pos.y + 1; j < HARD_HEIGHT; j++) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.x; i < HARD_WIDTH; i++) {
//                for (int j = 0; j < pos.y; j++) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.x - 1; i >= 0; i--) {
//                for (int j = 0; j < pos.y; j++) {
//                    if (findPokeBall(board, j, i) != NULL) {
//                        pos.x = i;
//                        pos.y = j;
//                        return;
//                    }
//                }
//            }
//            break;
//
//        case LEFT_KEY:
//            for (int i = pos.y; i >= 0; i--) {
//                for (int j = pos.x - 1; j >= 0; j--) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) {
//                for (int j = pos.x - 1; j >= 0; j--) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.y; i >= 0; i--) {
//                for (int j = HARD_WIDTH - 1; j > pos.x; j--) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) {
//                for (int j = HARD_WIDTH - 1; j > pos.x; j--) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//            break;
//
//        case RIGHT_KEY:
//            for (int i = pos.y; i >= 0; i--) {
//                for (int j = pos.x + 1; j < HARD_WIDTH; j++) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) {
//                for (int j = pos.x + 1; j < HARD_WIDTH; j++) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.y; i >= 0; i--) {
//                for (int j = 0; j < pos.x; j++) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//
//            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) {
//                for (int j = 0; j < pos.x; j++) {
//                    if (findPokeBall(board, i, j) != NULL) {
//                        pos.x = j;
//                        pos.y = i;
//                        return;
//                    }
//                }
//            }
//            break;
//
//        default:
//            break;
//        }
//    }
//}
//
//void hardMode(Player& p) {
//    srand(time(0));
//    //getBackground(BG);
//
//    HardMode** board = new HardMode * [HARD_HEIGHT];
//    //Init HARD_HEIGHT linkedlists which has HARD_WIDTH elements
//    for (int i = 0; i < HARD_HEIGHT; i++) {
//        board[i] = NULL;
//        for (int j = 0; j < HARD_WIDTH; j++) {
//            HardMode* p = new HardMode;
//            p->i = i;
//            p->j = j;
//            p->p_next = NULL;
//            push(board[i], p);
//        }
//    }
//    initList(board);
//
//    gotoXY(10, 0);
//    cout << "Name: " << p.name;
//    gotoXY(40, 0);
//    cout << "Point: " << p.point;
//    gotoXY(70, 0);
//    cout << "Life: " << p.life;
//
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
//    gotoXY(100, 12);
//    cout << "Press arrow key to move";
//    gotoXY(100, 13);
//    cout << "Press Enter to delete";
//    gotoXY(100, 14);
//    cout << "Press ESC to quit";
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//
//    Position selected_pos[] = { {-1, -1}, {-1, -1} };
//    int couple = 2;
//    Position curPosition{ 0, 0 };
//    int status = 0; //0. dang choi game
//    //1. het game
//    //2. nguoi choi chon thoat
//
//    while (!status && p.life) {
//        findPokeBall(board, curPosition.y, curPosition.x)->is_selected = 1;
//
//        printList(board);
//
//        move(board, curPosition, status, p, selected_pos, couple);
//
//        if ((!checkValidPairs(board))) status = 1;
//    }
//
//    printList(board);
//    deleteList(board);
//    Sleep(500);
//    system("cls");
//
//    if (p.life && status == 1) {
//        //displayStatus(1);
//        gotoXY(50, 17);
//        char c;
//        cout << "Do you want to continue next game? (Y/N): ";
//        cin >> c;
//        cin.ignore();
//        system("cls");
//        if (c == 'y' || c == 'Y') hardMode(p);
//        else writeLeaderBoard(p);
//    }
//    else if (p.life == 0) {
//        //displayStatus(0);
//        writeLeaderBoard(p);
//        Sleep(500);
//    }
//    system("cls");
//}