#include "LeaderBoard.h"

void drawLeaderBoard() {
	//Draw LEADER
	////https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Small&t=POINT, font: Doom
	setColor(LIGHT_GREEN);
	gotoXY(27, 1);
	cout << " _      _____   ___  ______  _____ ______";
	gotoXY(27, 2);
	cout << "| |    |  ___| / _ \\ |  _  \\|  ___|| ___ \\";
	setColor(LIGHT_AQUA);
	gotoXY(27, 3);
	cout << "| |    | |__  / /_\\ \\| | | || |__  | |_/ /";
	gotoXY(27, 4);
	cout << "| |    |  __| |  _  || | | ||  __| |    /";
	setColor(LIGHT_YELLOW);
	gotoXY(27, 5);
	cout << "| |____| |___ | | | || |/ / | |___ | |\\ \\";
	gotoXY(27, 6);
	cout << "\\_____/\\____/ \\_| |_/|___/  \\____/ \\_| \\_|";

	//Draw BOARD
	////https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Small&t=POINT, font: Doom
	setColor(LIGHT_GREEN);
	gotoXY(69, 1);
	cout << "______  _____   ___  ______ ______";
	gotoXY(69, 2);
	cout << "| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
	setColor(LIGHT_AQUA);
	gotoXY(69, 3);
	cout << "| |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
	gotoXY(69, 4);
	cout << "| ___ \\| | | ||  _  ||    / | | | |";
	setColor(LIGHT_YELLOW);
	gotoXY(69, 5);
	cout << "| |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
	gotoXY(69, 6);
	cout << "\\____/  \\___/ \\_| |_/\\_| \\_||___/";

	setColor(BRIGHT_WHITE);
	//Draw NAME
	//https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Small&t=POINT, font: Small
	gotoXY(27, 9);
	cout << " _  _    _    __  __  ___";
	gotoXY(27, 10);
	cout << "| \\| |  /_\\  |  \\/  || __|";
	gotoXY(27, 11);
	cout << "| .` | / _ \\ | |\\/| || _|";
	gotoXY(27, 12);
	cout << "|_|\\_|/_/ \\_\\|_|  |_||___|";

	//Draw POINT
	//https://patorjk.com/software/taag/#p=display&h=0&v=0&f=Small&t=POINT, font: Small
	gotoXY(76, 9);
	cout << " ___   ___   ___  _  _  _____";
	gotoXY(76, 10);
	cout << "| _ \\ / _ \\ |_ _|| \\| ||_   _|";
	gotoXY(76, 11);
	cout << "|  _/| (_) | | | | .` |  | |";
	gotoXY(76, 12);
	cout << "|_|   \\___/ |___||_|\\_|  |_|";

	setColor(WHITE);
	gotoXY(27, 13);
	for (int i = 0; i < 79; i++) cout << "-";

}
void readLeaderBoard() {
	//Draw leaderBoard
	drawLeaderBoard();

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
	int rank = 0;

	for (int i = 0; i < p_list.size(); i++) {
		if (i < 7) displayPlayer(p_list[i], rank);
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