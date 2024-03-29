#include "NormalCheck.h"


//r stands for row, c stands for column
bool lineCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	int start;
	int end;
	int cnt = 0;

	if (r1 == r2) {
		start = min(c1, c2);
		end = max(c1, c2);
		for (int i = start; i <= end; i++) {
			if (p_ball[r1][i].exist) {
				++cnt;
				if (cnt > 1) return false;
			}
		}
		if (cnt == 0) return true;
		if (cnt == 1)
			if (p_ball[r1][c1].exist && !p_ball[r2][c2].exist)
				return true;
			else if (!p_ball[r1][c1].exist && p_ball[r2][c2].exist)
				return true;	
	}
	if (c1 == c2) {
		start = min(r1, r2);
		end = max(r1, r2);
		for (int i = start; i <= end; i++) {
			if (p_ball[i][c1].exist) {
				++cnt;
				if (cnt > 1) return false;
			}
		}
		if (cnt == 0) return true;
		if (cnt == 1)
			if (p_ball[r1][c1].exist && !p_ball[r2][c2].exist)
				return true;
			else if (!p_ball[r1][c1].exist && p_ball[r2][c2].exist)
				return true;
	}
	return false;
}

bool INormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	int start;
	int end;

	if (r1 == r2) {
		start = min(c1, c2);
		end = max(c1, c2);
		for (int i = start + 1; i < end; i++)
			if (p_ball[r1][i].exist)
				return false;
		return true;
	}
	if (c1 == c2) {
		start = min(r1, r2);
		end = max(r1, r2);
		for (int i = start + 1; i < end; i++)
			if (p_ball[i][c1].exist) 
				return false;
		return true;
	}
	return false;
}

bool LNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (r1 == r2 || c1 == c2) return false;

	bool check1;
	bool check2;

	if (p_ball[r1][c2].exist == false) {
		check1 = lineCheck(p_ball, r1, c1, r1, c2);
		check2 = lineCheck(p_ball, r1, c2, r2, c2);
		if (check1 && check2) return true;
	}
	if (p_ball[r2][c1].exist == false) {
		check1 = lineCheck(p_ball, r1, c1, r2, c1);
		check2 = lineCheck(p_ball, r2, c1, r2, c2);
		if (check1 && check2) return true;
	}
	return false;
}

bool ZNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (r1 == r2 || c1 == c2) return false;

	bool check1;
	bool check2;
	bool check3;
	int start;
	int end;

	start = min(c1, c2);
	end = max(c1, c2);
	for (int i = start + 1; i < end; i++) {
		check1 = lineCheck(p_ball, r1, i, r2, i);
		if (check1) {
			check2 = lineCheck(p_ball, r1, c1, r1, i);
			check3 = lineCheck(p_ball, r2, c2, r2, i);
			if (check2 && check3) return true;
		}
	}
	start = min(r1, r2);
	end = max(r1, r2);
	for (int i = start + 1; i < end; i++) {
		check1 = lineCheck(p_ball, i, c1, i, c2);
		if (check1) {
			check2 = lineCheck(p_ball, r1, c1, i, c1);
			check3 = lineCheck(p_ball, r2, c2, i, c2);
			if (check2 && check3) return true;
		}
	}
	return false;
}

bool UNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (((r1 == r2) && (r1 == 0 || r1 == NORMAL_HEIGHT - 1)) ||
		((c1 == c2) && (c1 == 0 || c1 == NORMAL_WIDTH - 1)))
			return true;

	bool check1;
	bool check2;
	bool check3;
	int start;
	int end;

	start = min(c1, c2);
	end = max(c1, c2);
	for (int i = 0; i < NORMAL_WIDTH; i++) {
		if (i == 0 || i == NORMAL_WIDTH - 1) {
			check2 = lineCheck(p_ball, r1, c1, r1, i);
			check3 = lineCheck(p_ball, r2, c2, r2, i);
			if ((check2 && check3) || (check2 && c2 == i) || (c1 == i && check3))
				return true;
		}
		if (i <= start || i >= end) {
			check1 = lineCheck(p_ball, r1, i, r2, i);
			if (check1) {
				check2 = lineCheck(p_ball, r1, c1, r1, i);
				check3 = lineCheck(p_ball, r2, c2, r2, i);
				if (check2 && check3) return true;
			}
		}
	}

	start = min(r1, r2);
	end = max(r1, r2);
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		if (i == 0 || i == NORMAL_HEIGHT - 1) {
			check2 = lineCheck(p_ball, r1, c1, i, c1);
			check3 = lineCheck(p_ball, r2, c2, i, c2);
			if ((check2 && check3) || (check2 && r2 == i) || (r1 == i && check3))
				return true;
		}
		if (i <= start || i >= end) {
			check1 = lineCheck(p_ball, i, c1, i, c2);
			if (check1) {
				check2 = lineCheck(p_ball, r1, c1, i, c1);
				check3 = lineCheck(p_ball, r2, c2, i, c2);
				if (check2 && check3) return true;
			}
		}
	}
	return false;
}

bool allCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (INormalCheck(p_ball, r1, c1, r2, c2)) return true;
	if (LNormalCheck(p_ball, r1, c1, r2, c2)) return true;
	if (ZNormalCheck(p_ball, r1, c1, r2, c2)) return true;
	if (UNormalCheck(p_ball, r1, c1, r2, c2)) return true;
	return false;
}

bool checkValidPairs(NormalMode** board) {
	char check = 'A';
	while (check >= 'A' && check <= 'Z') {
		int cnt = 0;
		int* pos = new int[NORMAL_HEIGHT * NORMAL_WIDTH];
		for (int i = 0; i < NORMAL_HEIGHT; i++)
			for (int j = 0; j < NORMAL_WIDTH; j++) 
				if (board[i][j].p_mon == check && board[i][j].exist) {
					pos[cnt++] = i;
					pos[cnt++] = j;
				}

		for (int i = 0; i < cnt - 2; i += 2)
			for (int j = i + 2; j < cnt; j += 2) 
				if (allCheck(board, pos[i], pos[i + 1], pos[j], pos[j + 1])) {
					delete[] pos;
					return true;
				}

		check++;
		delete[] pos;
	}
	return false;
}
