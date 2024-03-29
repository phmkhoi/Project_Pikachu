#include "HardMode.h"
#include "HardCheck.h"
#include "Struct.h"
#include "LeaderBoard.h"
#include "Utility.h"

#define HARD_HEIGHT 6
#define HARD_WIDTH 6

void push(HardMode*& head, HardMode* p) {
    if (head == NULL) head = p;
    else {
        HardMode* temp = head;
        while (temp->p_next != NULL) {
            temp = temp->p_next;
        }
        temp->p_next = p;
    }
}

void initList(HardMode** board) {
    for (int i = 0; i < HARD_HEIGHT; i++) {
        board[i] = NULL;
        for (int j = 0; j < HARD_WIDTH; j++) {
            HardMode* p = new HardMode;
            p->row = i;
            p->column = j;
            p->p_next = NULL;
            push(board[i], p);
        }
    }

    int flagNum = (HARD_WIDTH * HARD_HEIGHT) / 2;
    while (flagNum) {
        int i, time = 2;
        char c = 65 + rand() % 5;
        while (time) {
            i = rand() % HARD_HEIGHT;
            int j = rand() % HARD_WIDTH;
            HardMode* p = findPokeBall(board, i, j);
            if (p->p_mon == ' ') {
                p->p_mon = c;
                time--;
            }
        }
        flagNum--;
    }
}

void deleteList(HardMode** board) {
    for (int i = 0; i < HARD_HEIGHT; i++) {
        HardMode* temp;
        while (board[i] != NULL) {
            temp = board[i];
            board[i] = board[i]->p_next;
            temp->deleteCell();
            //if (temp->j < 4) displayBackground(BG, temp->j, i);
            Sleep(500);
            delete temp;
        }
    }
    delete[] board;
}

void renderList(HardMode** board) {
    for (int i = 0; i < HARD_HEIGHT; i++) {
        HardMode* temp = board[i];
        while (temp != NULL) {
            temp->drawCell(112);
            temp = temp->p_next;
        }
    }
}

void move(HardMode** board, Position& pos, int& status, Player& p, Position selectedPos[], int& couple) {
    int temp, key;
    temp = _getch();

    //If Not Arrow Key
    if (temp && temp != 224) {
        if (temp == ESC_KEY) status = 2;
        else if (temp == ENTER_KEY) {
            if (pos.x == selectedPos[0].x && pos.y == selectedPos[0].y) {
                HardMode* temp = findPokeBall(board, pos.y, pos.x);
                temp->drawCell(70);
                Sleep(500);

                temp->is_selected = 0;
                couple = 2;
                selectedPos[0] = { -1, -1 };
                p.life--;

                //Update Life
                gotoXY(95, 8);
                cout << "Life: ";
                setColor(LIGHT_AQUA);
                cout << p.life;
                setColor(WHITE);
            }
            else {
                selectedPos[2 - couple].x = pos.x;
                selectedPos[2 - couple].y = pos.y;
                findPokeBall(board, pos.y, pos.x)->is_selected = 1;
                couple--;

                //If 1 Pair Is Selected
                if (couple == 0) {
                    HardMode* p1, * p2;
                    p1 = findPokeBall(board, selectedPos[0].y, selectedPos[0].x);
                    p2 = findPokeBall(board, selectedPos[1].y, selectedPos[1].x);
                    if (p1->p_mon == p2->p_mon) {
                        if (allCheck(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x)) {
                            rightPairSound();
                            Sleep(150);

                            p.point += 20;

                            //Update Score
                            gotoXY(95, 9);
                            cout << "Point: ";
                            setColor(LIGHT_AQUA);
                            cout << p.point;
                            setColor(WHITE);

                            p1->drawCell(40);
                            p2->drawCell(40);
                            Sleep(500);

                            DifMode(board, selectedPos[0].y, selectedPos[0].x, selectedPos[1].y, selectedPos[1].x);
                        }
                        else {
                            wrongPairSound();
                            Sleep(150);

                            p1->drawCell(70);
                            p2->drawCell(70);
                            Sleep(500);

                            p.life--;

                            //Update Life
                            gotoXY(95, 8);
                            cout << "Life: ";
                            setColor(LIGHT_AQUA);
                            cout << p.life;
                            setColor(WHITE);
                        }
                    }
                    else {
                        wrongPairSound();
                        Sleep(150);

                        p1->drawCell(70);
                        p2->drawCell(70);
                        Sleep(500);

                        p.life--;

                        //Update Life
                        gotoXY(95, 8);
                        cout << "Life: ";
                        setColor(LIGHT_AQUA);
                        cout << p.life;
                        setColor(WHITE);
                    }
                    
                    //Reset
                    p1->is_selected = 0;
                    p2->is_selected = 0;
                    couple = 2;
                    selectedPos[0] = { -1, -1 };
                    selectedPos[1] = { -1, -1 };

                    for (int i = pos.y; i < HARD_HEIGHT; i++)
                        for (int j = pos.x; j < HARD_WIDTH; j++) 
                            if (findPokeBall(board, i, j) != NULL) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }

                    ////Move To Cell
                    for (int i = 0; i <= pos.y; i++)
                        for (int j = 0; j <= pos.x; j++) 
                            if (findPokeBall(board, i, j) != NULL) {
                                pos.x = j;
                                pos.y = i;
                                return;
                            }
                }
            }
        }
    }
    //If arrow key
    else {
        if ((pos.y != selectedPos[0].y || pos.x != selectedPos[0].x) && 
            (pos.y != selectedPos[1].y || pos.x != selectedPos[1].x)) // ktra xem o nay co dang duoc chon hay khong
            findPokeBall(board, pos.y, pos.x)->is_selected = 0;
        switch (key = _getch()) {
        case UP_KEY:
            for (int i = pos.x; i < HARD_WIDTH; i++)
                for (int j = pos.y - 1; j >= 0; j--) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            for (int i = pos.x - 1; i >= 0; i--)
                for (int j = pos.y - 1; j >= 0; j--) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            for (int i = pos.x; i < HARD_WIDTH; i++)
                for (int j = HARD_HEIGHT - 1; j > pos.y; j--) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            for (int i = pos.x; i >= 0; i--)
                for (int j = HARD_HEIGHT - 1; j > pos.y; j--) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            break;
        case DOWN_KEY:
            for (int i = pos.x; i < HARD_WIDTH; i++) 
                for (int j = pos.y + 1; j < HARD_HEIGHT; j++) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            for (int i = pos.x - 1; i >= 0; i--)
                for (int j = pos.y + 1; j < HARD_HEIGHT; j++) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            for (int i = pos.x; i < HARD_WIDTH; i++) 
                for (int j = 0; j < pos.y; j++) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            for (int i = pos.x - 1; i >= 0; i--)
                for (int j = 0; j < pos.y; j++) 
                    if (findPokeBall(board, j, i) != NULL) {
                        pos.x = i;
                        pos.y = j;
                        return;
                    }

            break;
        case LEFT_KEY:
            for (int i = pos.y; i >= 0; i--)
                for (int j = pos.x - 1; j >= 0; j--) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) 
                for (int j = pos.x - 1; j >= 0; j--) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            for (int i = pos.y; i >= 0; i--) 
                for (int j = HARD_WIDTH - 1; j > pos.x; j--) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) 
                for (int j = HARD_WIDTH - 1; j > pos.x; j--) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            break;
        case RIGHT_KEY:
            for (int i = pos.y; i >= 0; i--) 
                for (int j = pos.x + 1; j < HARD_WIDTH; j++) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) 
                for (int j = pos.x + 1; j < HARD_WIDTH; j++) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            for (int i = pos.y; i >= 0; i--) 
                for (int j = 0; j < pos.x; j++) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            for (int i = pos.y + 1; i < HARD_HEIGHT; i++) 
                for (int j = 0; j < pos.x; j++) 
                    if (findPokeBall(board, i, j) != NULL) {
                        pos.x = j;
                        pos.y = i;
                        return;
                    }

            break;
        default:
            break;
        }
    }
}

void difficultMode(Player& p) {
    gameStartSound();
    srand(time(0));
    drawHardBorder(p);
    //getBackground(BG);

    HardMode** board = new HardMode * [HARD_HEIGHT];
    initList(board);

    Position selectedPos[] = { {-1, -1}, {-1, -1} };
    int couple = 2;
    Position curPosition{ 0, 0 };
    int status = 0; 
    /*0. Playing
    1. Finish
    2. Game over
    3. Exit*/

    while (!status && p.life) {
        findPokeBall(board, curPosition.y, curPosition.x)->is_selected = 1;

        renderList(board);

        move(board, curPosition, status, p, selectedPos, couple);

        if ((!checkValidPairs(board))) status = 1;
    }

    renderList(board);
    deleteList(board);
    Sleep(500);
    system("cls");

    if (p.life && status == 1) {
        displayStatus(1);
        gotoXY(50, 17);
        char c;
        cout << "Do you want to continue next game? (Y/N): ";
        cin >> c;
        cin.ignore();
        system("cls");
        if (c == 'y' || c == 'Y') difficultMode(p);
        else writeLeaderBoard(p);
    }
    else if (p.life == 0) {
        displayStatus(2);
        writeLeaderBoard(p);
        Sleep(500);
    }
    system("cls");
}