//#include <iostream>
//#include <Windows.h>
//#include <conio.h>
//
//using namespace std;
//
//void gotoXY(int x, int y) {
//	//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD cursor_pos = { x, y };
//	//cursor_pos.X = x;
//	//cursor_pos.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_pos);
//}
//
//void setCursor(bool visible) {
//	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO ipCursor;
//	ipCursor.bVisible = visible;
//	ipCursor.dwSize = 20;
//	SetConsoleCursorInfo(console, &ipCursor);
//}
//
//void resizeWindow(int x, int y) {
//	HWND console = GetConsoleWindow();
//	RECT r;
//	GetWindowRect(console, &r);
//	MoveWindow(console, r.left, r.top, x, y, TRUE);
//}
//
//void hideScrollBar() {
//	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
//	GetConsoleScreenBufferInfo(console, &screenBufferInfo);
//
//	COORD new_screen_buffer_size;
//
//	new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
//	new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;
//
//	SetConsoleScreenBufferSize(console, new_screen_buffer_size);
//}
//
//void initWindow(int width, int length) {
//	resizeWindow(width, length);
//	hideScrollBar();
//	setCursor(0);
//}
//
//void textColor(int color) {
//	HANDLE hcolor;
//	hcolor = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(hcolor, color);
//}
//
//void box(int x, int y, int width, int height, int t_color, int b_color, string content) {
//	for (int ix = x; ix <= x + width; ix++) {
//		gotoXY(ix, y);
//		cout << char(196);
//		gotoXY(ix, y + height);
//		cout << char(196);
//	}
//
//	for (int iy = y; iy <= y + height; iy++) {
//		gotoXY(x, iy);
//		cout << char(179);
//		gotoXY(x + width, iy);
//		cout << char(179);
//	}
//
//	gotoXY(x, y); cout << char(218);
//	gotoXY(x + width, y); cout << char(191);
//	gotoXY(x, y + height); cout << char(192);
//	gotoXY(x + width, y + height); cout << char(217);
//
//	gotoXY(x + 14, y + 2);
//	cout << content;
//	textColor(7 + 0 * 16);
//}
//
//void boxColor(int x, int y, int width, int height, int b_color, string content) {
//	textColor(7 + b_color * 16);
//	for (int ix = x + 1; ix <= x + width - 1; ix++) {
//		for (int iy = y + 1; iy <= y + height - 1; iy++) {
//			gotoXY(ix, iy);
//			cout << " ";
//		}
//	}
//	gotoXY(x + 14, y + 2);
//	cout << content;
//	textColor(7);
//}
//
//void cellColor(int x, int y, int width, int height, int b_color, string content) {
//	textColor(7 + b_color * 16);
//	for (int ix = x + 1; ix <= x + width - 1; ix++) {
//		for (int iy = y + 1; iy <= y + height - 1; iy++) {
//			gotoXY(ix, iy);
//			cout << " ";
//		}
//	}
//	gotoXY(x + width / 2, y + height / 2);
//	cout << content;
//	textColor(7);
//}
//
//char cell[5][12] = {
//	{"+---------+"},
//	{"|         |"},
//	{"|         |"},
//	{"|         |"},
//	{"+---------+"}
//};
//
//void drawbox(int x, int y, char c) {
//	for (int i = 0; i < 5; i++) {
//		gotoXY(x, y + i);
//		cout << cell[i];
//	}
//	gotoXY(x + (11 - 2 + 1) / 2, y + (5 - 2 + 1) / 2);
//	cout << c;
//}
//
//int main() {
//	system("cls");
//	/*int x = 45, y = 5;
//	int width = 31, height = 4;
//	int t_color = 7, b_color = 5;
//	string content = "Hello";
//	for (int i = 0; i < 4; i++) {
//		box(x, y * (i + 1), width, height, t_color, b_color, content);
//	}
//	setCursor(0);
//
//	int x_colorbox = x, y_colorbox = y;
//	int old_x_color = x_colorbox, old_y_color = y_colorbox;
//	bool kbhit = true;
//	while (1) {
//		if (kbhit == true) {
//			gotoXY(old_x_color, old_y_color);
//			boxColor(old_x_color, old_y_color, width, height, 0, content);
//			old_x_color = x_colorbox; old_y_color = y_colorbox;
//			boxColor(x_colorbox, y_colorbox, width, height, b_color, content);
//			kbhit = false;
//		}
//		if (_kbhit()) {
//			char c = _getch();
//			kbhit = true;
//			if (c == 72) {
//				if (y_colorbox != y) {
//					y_colorbox -= 5;
//				}
//				else {
//					y_colorbox = y + (height + 1) * (4 - 1);
//				}
//			}
//			else if (c == 80) {
//				if (y_colorbox != (y + (height + 1) * (4 - 1))) {
//					y_colorbox += 5;
//				}
//				else {
//					y_colorbox = y;
//				}
//			}
//
//		}
//	}
//	_getch();*/
//	setCursor(0);
//	int x = 20, y = 5;
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 4; j++) {
//			drawbox(x + i * 10, y + j * 4, 'A');
//			//cellColor(x + i * 10, y + j * 4, 10, 4, 5, "A");
//		}
//	}
//	bool kbhit = true;
//	int x_cell = x, y_cell = y;
//	int old_x = x_cell, old_y = y_cell;
//	int width_cell = 11, height_cell = 5;
//	int x_choice, y_choice;
//	string content = "A";
//	int cnt_kb = 0;
//	while (1) {
//		if (kbhit == true) {
//			gotoXY(old_x, old_y);
//			cellColor(old_x, old_y, width_cell - 1, height_cell - 1, 0, content);
//			old_x = x_cell; old_y = y_cell;
//			cellColor(x_cell, y_cell, width_cell - 1, height_cell - 1, 5, content);
//			kbhit = false;
//		}
//
//		if (_kbhit()) {
//			char c = _getch();
//			kbhit = true;
//			if (c == 72) {
//				if (y_cell != y) {
//					y_cell -= 4;
//				}
//				else {
//					y_cell = y + (height_cell - 1) * (4 - 1);
//				}
//			}
//			else if (c == 80) {
//				if (y_cell != y + (height_cell - 1) * (4 - 1)) {
//					y_cell += 4;
//				}
//				else {
//					y_cell = y;
//				}
//			}
//			else if (c == 75) {
//				if (x_cell != x) {
//					x_cell -= 10;
//				}
//				else {
//					x_cell = x + (width_cell - 1) * (4 - 1);
//				}
//			}
//			else if (c == 77) {
//				if (x_cell != x + (width_cell - 1) * (4 - 1)) {
//					x_cell += 10;
//				}
//				else {
//					x_cell = x;
//				}
//			}
//			else if (c == 13) {
//				x_choice = x_cell; y_choice = y_cell;
//				cellColor(x_choice, y_choice, width_cell - 1, height_cell - 1, 2, content);
//			}
//		}
//	}
//	_getch();
//	return 0;
//}