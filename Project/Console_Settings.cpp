#include <iostream>
#include <Windows.h>

using namespace std;

//Move Cursor to Position (x, y)
void gotoXY(int x, int y) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor_pos = { x, y };
	cursor_pos.X = x;
	cursor_pos.Y = y;
	SetConsoleCursorPosition(console, cursor_pos);
}

//Set cursor visile/invisible
void setCursor(bool visible) {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ipCursor;
	ipCursor.bVisible = visible;
	ipCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &ipCursor);
}


//resize Screen
void resizeWindow(int x, int y) {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, x, y, TRUE);
}

//hide Scrollbar
void hideScrollBar() {
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
	GetConsoleScreenBufferInfo(console, &screenBufferInfo);

	COORD new_screen_buffer_size;

	new_screen_buffer_size.X = screenBufferInfo.srWindow.Right - screenBufferInfo.srWindow.Left + 1;
	new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom - screenBufferInfo.srWindow.Top + 1;

	SetConsoleScreenBufferSize(console, new_screen_buffer_size);
}

//Initialize Window Screen
void initWindow(int width, int length) {
	resizeWindow(width, length);
	hideScrollBar();
	setCursor(0);
}