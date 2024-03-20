#include "NormalCheck.h"

//r stands for row, c stands for column
bool nextCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if ((c1 == c2 - 1 || c1 == c2 + 1) && (r1 == r2))
		if (p_ball[r1][c1].p_mon == p_ball[r2][c2].p_mon)
			return true;
	if ((r1 == r2 - 1 || r1 == r2 + 1) && (c1 == c2))
		if (p_ball[r1][c1].p_mon == p_ball[r2][c2].p_mon)
			return true;
	return false;
}

bool lineCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	int start, end, cnt = 0;
	if (r1 == r2) {
		start = c1 < c2 ? c1 : c2;
		end = c1 < c2 ? c2 : c1;
		for (int i = start; i <= end; i++) {
			if (p_ball[r1][i].exist == true) {
				++cnt;
				if (cnt > 1) return false;
			}
		}
		if (cnt == 0) return true;
		if (cnt == 1)
			if (p_ball[r1][c1].exist == true && p_ball[r2][c2].exist != true)
				return true;
			else if (p_ball[r1][c1].exist != true && p_ball[r2][c2].exist == true)
				return true;	
	}
	if (c1 == c2) {
		start = r1 < r2 ? r1 : r2;
		end = r1 < r2 ? r2 : r1;
		for (int i = start; i <= end; i++) {
			if (p_ball[i][c1].exist == true) {
				++cnt;
				if (cnt > 1) return false;
			}
		}
		if (cnt == 0) return true;
		if (cnt == 1)
			if (p_ball[r1][c1].exist == true && p_ball[r2][c2].exist != true)
				return true;
			else if (p_ball[r1][c1].exist != true && p_ball[r2][c2].exist == true)
				return true;
	}
	return false;
}

bool INormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	int start, end;
	if (r1 == r2) {
		start = c1 < c2 ? c1 : c2;
		end = c1 < c2 ? c2 : c1;
		for (int i = start + 1; i < end; i++)
			if (p_ball[r1][i].exist == true)
				return false;
		return true;
	}
	if (c1 == c2) {
		start = r1 < r2 ? r1 : r2;
		end = r1 < r2 ? r2 : r1;
		for (int i = start + 1; i < end; i++)
			if (p_ball[i][c1].exist == true) 
				return false;
		return true;
	}
	return false;
}

bool LNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (r1 == r2 || c1 == c2) return false;
	bool check1, check2;
	if (p_ball[r1][c2].exist != true) {
		check1 = lineCheck(p_ball, r1, c1, r1, c2);
		check2 = lineCheck(p_ball, r1, c2, r2, c2);
		if (check1 == true && check2 == true) return true;
	}
	if (p_ball[r2][c1].exist != true) {
		check1 = lineCheck(p_ball, r1, c1, r2, c1);
		check2 = lineCheck(p_ball, r2, c1, r2, c2);
		if (check1 == true && check2 == true) return true;
	}
	return false;
}

bool ZNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (r1 == r2 || c1 == c2) return false;
	int start, end;
	bool check1, check2, check3;
	start = c1 < c2 ? c1 : c2;
	end = c1 < c2 ? c2 : c1;
	for (int i = start + 1; i < end; i++) {
		check1 = lineCheck(p_ball, r1, i, r2, i);
		if (check1 == true) {
			check2 = lineCheck(p_ball, r1, c1, r1, i);
			check3 = lineCheck(p_ball, r2, c2, r2, i);
			if (check2 == true && check3 == true) return true;
		}
	}
	start = r1 < r2 ? r1 : r2;
	end = r1 < r2 ? r2 : r1;
	for (int i = start + 1; i < end; i++) {
		check1 = lineCheck(p_ball, i, c1, i, c2);
		if (check1 == true) {
			check2 = lineCheck(p_ball, r1, c1, i, c1);
			check3 = lineCheck(p_ball, r2, c2, i, c2);
			if (check2 == true && check3 == true) return true;
		}
	}
	return false;
}

bool UNormalCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (((r1 == r2) && (r1 == 0 || r1 == NORMAL_HEIGHT - 1)) ||
		((c1 == c2) && (c1 == 0 || c1 == NORMAL_WIDTH - 1)))
			return true;
	int start, end;
	bool check1, check2, check3;
	start = c1 < c2 ? c1 : c2;
	end = c1 < c2 ? c2 : c1;
	for (int i = 0; i < NORMAL_WIDTH; i++) {
		if (i <= start || i >= end) {
			check1 = lineCheck(p_ball, r1, i, r2, i);
			if (check1 == true) {
				check2 = lineCheck(p_ball, r1, c1, r1, i);
				check3 = lineCheck(p_ball, r2, c2, r2, i);
				if (check2 == true && check3 == true) return true;
			}
		}
		else if (i == 0 || i == NORMAL_WIDTH - 1) {
			check2 = lineCheck(p_ball, r1, c1, r1, i);
			check3 = lineCheck(p_ball, r2, c2, r2, i);
			if ((check2 == true && check3 == true) ||
				(check2 == true && c2 == i) ||
				(c1 == i && check3 == true))
				return true;
		}
	}
	start = r1 < r2 ? r1 : r2;
	end = r1 < r2 ? r2 : r1;
	for (int i = 0; i < NORMAL_HEIGHT; i++) {
		if (i <= start || i >= end) {
			check1 = lineCheck(p_ball, i, c1, i, c2);
			if (check1 == true) {
				check2 = lineCheck(p_ball, r1, c1, i, c1);
				check3 = lineCheck(p_ball, r2, c2, i, c1);
				if (check2 == true && check3 == true) return true;
			}
		}
		else if (i == 0 || i == NORMAL_HEIGHT - 1) {
			check2 = lineCheck(p_ball, r1, c1, i, c1);
			check3 = lineCheck(p_ball, r2, c2, i, c1);
			if ((check2 == true && check3 == true) ||
				(check2 == true && r2 == i) ||
				(r1 == i && check3 == true))
				return true;
		}
	}
	return false;
}

bool allCheck(NormalMode** p_ball, int r1, int c1, int r2, int c2) {
	if (nextCheck(p_ball, r1, c1, r2, c2) == true) return true;
	if (INormalCheck(p_ball, r1, c1, r2, c2) == true) return true;
	if (LNormalCheck(p_ball, r1, c1, r2, c2) == true) return true;
	if (ZNormalCheck(p_ball, r1, c1, r2, c2) == true) return true;
	if (UNormalCheck(p_ball, r1, c1, r2, c2) == true) return true;
	return false;
}

bool isPLaying(NormalMode** p_ball) {
	char check = 'A';
	while (check >= 'A' && check <= 'C') {
		int cnt = 0;
		int* pos = new int[NORMAL_HEIGHT * NORMAL_WIDTH];
		for (int i = 0; i < NORMAL_HEIGHT; i++)
			for (int j = 0; j < NORMAL_WIDTH; j++)
				if (p_ball[i][j].p_mon == check && p_ball[i][j].exist == true) {
					pos[cnt++] = i;
					pos[cnt++] = j;
				}
		for (int i = 0; i < cnt - 2; i++)
			for (int j = i + 2; j < cnt; j++)
				if (allCheck(p_ball, pos[i], pos[i + 1], pos[j], pos[j + 1]) == true) {
					delete[] pos;
					return true;
				}
		++check;
		delete[] pos;
	}
	return false;
}