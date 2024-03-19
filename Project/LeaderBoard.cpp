#include "LeaderBoard.h"

void readLeaderBoard() {
	//Leader Board UI
	gotoXY(58, 3);
	setColor(LIGHT_BLUE);
	cout << "LEADER BOARD";
	gotoXY(27, 6);
	setColor(BRIGHT_WHITE);
	cout << "NAME";
	gotoXY(97, 6);
	setColor(BRIGHT_WHITE);
	cout << "POINT";
	setColor(WHITE);
	gotoXY(27, 7);
	for (int i = 0; i < 75; i++) cout << "-";

	//Read file
	ifstream ifs;
	ifs.open("LeaderBoard.txt");
	if (!ifs.is_open()) {
		cout << "Cannot open file!";
		return;
	}
	Player temp_player;
	PlayerList p_list;
	string point = " ";
	while (!ifs.eof()) {
		getline(ifs, temp_player.name, ',');
		getline(ifs, point, '\n');

		temp_player.point = stoi(point);

		p_list.push_back(temp_player);
		sortPlayer(p_list);
	}
	ifs.close();

	//Display players
	int rank = 2;
	for (int i = 0; i < p_list.size(); i++) {
		displayPlayer(p_list[i], rank);
		rank += 2;
	}

	_getch();
	system("cls");
}
void writeLeaderBoard(Player p) {
	ofstream ofs;
	ofs.open("LeaderBoard.txt", ofstream::app);
	if (!ofs.is_open()) {
		cout << "Cannot open file!";
		return;
	}
	ofs << "\n" << p.name << "," << p.point << "\n";
	ofs.close();
}