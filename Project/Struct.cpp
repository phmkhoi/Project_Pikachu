#include "Utility.h"
#include "Struct.h"

//Player
void swapPlayer(Player& p1, Player& p2) {
	swap(p1.name, p2.name);
	swap(p1.life, p2.life);
	swap(p1.point, p2.point);
}

void sortPlayer(PlayerList& p_list) {
	for (int i = 0; i < p_list.size() - 1; i++)
		for (int j = i + 1; j < p_list.size(); j++)
			if (p_list[i].point < p_list[j].point)
				swapPlayer(p_list[i], p_list[j]);
}

//Print LeaderBoard
void displayPlayer(Player p, int rank) {
	switch (rank) {
	case 0:
		gotoXY(27, 14 + rank);
		setColor(LIGHT_RED);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(LIGHT_RED);
		cout << p.point;
		break;
	case 2:
		gotoXY(27, 14 + rank);
		setColor(GREEN);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(GREEN);
		cout << p.point;
		break;
	case 4:
		gotoXY(27, 14 + rank);
		setColor(LIGHT_AQUA);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(LIGHT_AQUA);
		cout << p.point;
		break;
	default:
		gotoXY(27, 14 + rank);
		setColor(LIGHT_YELLOW);
		cout << p.name;
		gotoXY(89, 14 + rank);
		setColor(LIGHT_YELLOW);
		cout << p.point;
		break;
	}
	setColor(WHITE);
	gotoXY(27, 15 + rank);
	for (int i = 0; i < 79; i++) cout << "-";
}

void getPlayerInfo(Player& p) {
	//Draw WELCOME
	//Source: https://patorjk.com/software/taag/#p=display&h=1&v=1&f=Chiseled&t=WELCOME
	setColor(LIGHT_GREEN);
	gotoXY(20, 7);
	cout << "         ,-.-.      ,----.              _,.----.      _,.---._            ___       ,----.";
	gotoXY(20, 8);
	cout << ",-..-.-./  \\==\\  ,-.--` , \\   _.-.    .' .' -   \\   ,-.' , -  `.   .-._ .'=.'\\   ,-.--` , \\";
	gotoXY(20, 9);
	cout << "|, \\=/\\=|- |==| |==|-  _.-` .-,.'|   /==/  ,  ,-'  /==/_,  ,  - \\ /==/ \\|==|  | |==|-  _.-`";
	setColor(LIGHT_AQUA);
	gotoXY(20, 10);
	cout << "|- |/ |/ , /==/ |==|   `.-.|==|, |   |==|-   |  . |==|   .=.     ||==|,|  / - | |==|   `.-.";
	gotoXY(20, 11);
	cout << " \\, ,     _|==|/==/_ ,    /|==|- |   |==|_   `-' \\|==|_ : ;=:  - ||==|  \\/  , |/==/_ ,    /";
	gotoXY(20, 12);
	cout << " | -  -  , |==||==|    .-' |==|, |   |==|   _  , ||==| , '='     ||==|- ,   _ ||==|    .-'";
	setColor(LIGHT_YELLOW);
	gotoXY(20, 13);
	cout << "  \\  ,  - /==/ |==|_  ,`-._|==|- `-._\\==\\.       / \\==\\ -    ,_ / |==| _ /\\   ||==|_  ,`-._";
	gotoXY(20, 14);
	cout << "  |-  /\\ /==/  /==/ ,     //==/ - , ,/`-.`.___.-'   '.='. -   .'  /==/  / / , //==/ ,     /";
	gotoXY(20, 15);
	cout << "  `--`  `--`   `--`-----`` `--`-----'                 `--`--''    `--`./  `--` `--`-----``";
	setColor(WHITE);
	gotoXY(50, 17);
	cout << "Enter Player name: ";
	cin >> p.name;
	cin.ignore();
	p.life = 3;
	p.point = 0;
	system("cls");
}

char cell[5][12] = {
	{"+---------+"},
	{"|         |"},
	{"|         |"},
	{"|         |"},
	{"+---------+"},
};

//draw cell in gameboard
void NormalMode::drawCell(int color) {
	if (!exist) return;

	int x = column + 1, y = row + 1; //coordinate of cell

	for (int i = 0; i < 5; i++) {
		gotoXY(x * 10 + 6, y * 4 + i + 2);
		cout << cell[i];
	}

	setColor(WHITE);
	if (is_selected) {
		setColor(color);
		for (int i = 1; i < 4; i++) {
			gotoXY(x * 10 + 6 + 1, y * 4 + i + 2);
			cout << "         ";
		}

		//print letter in cell
		setColor(color);
		gotoXY(x * 10 + 5 + 6, y * 4 + 4);
		cout << p_mon;
		setColor(WHITE); //reset color
	}
	else {

		//print letter in cell
		setColor(WHITE);
		gotoXY(x * 10 + 5 + 6, y * 4 + 4);
		cout << p_mon;
		setColor(WHITE); //Reset Color
	}
}

void NormalMode::deleteCell() {
	int x = column + 1, y = row + 1; //coordinate of cell

	//delete cell
	for (int i = 0; i < 5; i++) {
		gotoXY(x * 10 + 6, y * 4 + i + 2);
		cout << "           ";
	}
}

void HardMode::drawCell(int color) {
	int x = column + 1, y = row + 1;

	for (int i = 0; i < 5; i++) {
		gotoXY(x * 10, y * 4 + i - 2);
		cout << cell[i];
	}

	setColor(WHITE);
	if (is_selected) {
		setColor(color);
		for (int i = 1; i < 4; i++) {
			gotoXY(x * 10 + 1, y * 4 + i - 2);
			cout << "         ";
		}

		//print letter in cell
		setColor(color);
		gotoXY(x * 10 + 5, y * 4 + 2 - 2);
		cout << p_mon;
		setColor(WHITE); //reset color
	}
	else {
		//print letter in cell
		setColor(WHITE);
		gotoXY(x * 10 + 5, y * 4 + 2 - 2);
		cout << p_mon;
		setColor(WHITE); //Reset Color
	}
}

void HardMode::deleteCell() {
	int x = column + 1, y = row + 1; //coordinate of cell

	//delete cell
	for (int i = 0; i < 5; i++) {
		gotoXY(x * 10, y * 4 + i - 2);
		cout << "           ";
	}
}