#include "HardCheck.h"

HardMode* findPokeBall(HardMode** p_ball, int r, int c) {
	HardMode* p_curr = p_ball[r];
	if (c == 0) return p_ball[r];
	while (c-- > 0) {
		p_curr = p_curr->p_next;
	}
	return p_curr;
}

bool IHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
	HardMode* p_curr = nullptr;
	int start, end;
	if (r1 == r2) {
		start = c1 < c2 ? c1 : c2;
		end = c1 < c2 ? c2 : c1;
		p_curr = c1 < c2 ? findPokeBall(p_ball, r1, c1) : findPokeBall(p_ball, r2, c2);
		for (int i = start + 1; i < end; i++) {
			p_curr = p_curr->p_next;
			if (p_curr->exist == true) return false;
		}
		return true;
	}
	if (c1 == c2) {
		start = r1 < r2 ? r1 : r2;
		end = r1 < r2 ? r2 : r1;
		p_curr = r1 < r2 ? findPokeBall(p_ball, r1, c1) : findPokeBall(p_ball, r2, c2);
		for (int i = start + 1; i < end; i++) {
			p_curr = findPokeBall(p_ball, i, c1);
			if (p_curr->exist == true) return false;
		}
		return true;
	}
	return false;
}

bool LHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {}
bool ZHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {}
bool UHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {}
bool allCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {}
bool isPlaying(HardMode** p_ball, int r1, int c1, int r2, int c2) {}