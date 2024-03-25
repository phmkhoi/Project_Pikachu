#include "HardCheck.h"

//HardMode* findPokeBall(HardMode** p_ball, int r, int c) {
//	if (r < HARD_HEIGHT || r > HARD_HEIGHT || c < HARD_WIDTH || c > HARD_WIDTH) return NULL;
//	HardMode* p_curr = p_ball[r];
//
//	if (c == 0) return p_ball[r];
//	while (c-- > 0) {
//		p_curr = p_curr->p_next;
//	}
//	return p_curr;
//}
//
//bool lineCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
//	HardMode* p_curr = nullptr;
//	HardMode* p_start = nullptr;
//	HardMode* p_end = nullptr;
//	int start;
//	int end;
//	int cnt = 0;
//
//	if (r1 == r2) {
//		start = c1 < c2 ? c1 : c2;
//		end = c1 < c2 ? c2 : c1;
//		p_start = c1 < c2 ? findPokeBall(p_ball, r1, c1) : findPokeBall(p_ball, r2, c2);
//		p_end = c1 < c2 ? findPokeBall(p_ball, r2, c2) : findPokeBall(p_ball, r1, c1);
//		p_curr = p_start;
//		for (int i = start; i <= end; i++) {
//			if (p_curr->exist == true) ++cnt;
//			if (cnt > 1) return false;
//			p_curr = p_curr->p_next;
//		}
//		if (cnt == 0) return true;
//		if (cnt == 1)
//			if ((p_start->exist == true && p_end->exist == false) ||
//				(p_start->exist == false && p_end->exist == true))
//				return true;
//	}
//	if (c1 == c2) {
//		start = r1 < r2 ? r1 : r2;
//		end = r1 < r2 ? r2 : r1;
//		p_start = r1 < r2 ? findPokeBall(p_ball, r1, c1) : findPokeBall(p_ball, r2, c2);
//		p_end = r1 < r2 ? findPokeBall(p_ball, r2, c2) : findPokeBall(p_ball, r1, c1);
//		for (int i = start; i <= end; i++) {
//			p_curr = findPokeBall(p_ball, i, c1);
//			if (p_curr->exist == true) ++cnt;
//			if (cnt > 1) return false;
//		}
//		if (cnt == 0) return true;
//		if (cnt == 1)
//			if ((p_start->exist == true && p_end->exist == false) ||
//				(p_start->exist == false && p_end->exist == true))
//				return true;
//	}
//	return false;
//}
//bool IHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
//	HardMode* p_curr = nullptr;
//	int start;
//	int end;
//
//	if (r1 == r2) {
//		start = c1 < c2 ? c1 : c2;
//		end = c1 < c2 ? c2 : c1;
//		p_curr = c1 < c2 ? findPokeBall(p_ball, r1, c1) : findPokeBall(p_ball, r2, c2);
//		for (int i = start + 1; i < end; i++) {
//			p_curr = p_curr->p_next;
//			if (p_curr->exist == true) return false;
//		}
//		return true;
//	}
//	if (c1 == c2) {
//		start = r1 < r2 ? r1 : r2;
//		end = r1 < r2 ? r2 : r1;
//		p_curr = r1 < r2 ? findPokeBall(p_ball, r1, c1) : findPokeBall(p_ball, r2, c2);
//		for (int i = start + 1; i < end; i++) {
//			p_curr = findPokeBall(p_ball, i, c1);
//			if (p_curr->exist == true) return false;
//		}
//		return true;
//	}
//	return false;
//}
//
//bool LHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
//	if (r1 == r2 || c1 == c2) return false;
//
//	HardMode* p_curr = nullptr;
//	bool check1;
//	bool check2;
//
//	p_curr = findPokeBall(p_ball, r1, c2);
//	if (p_curr->exist == false) {
//		check1 = lineCheck(p_ball, r1, c1, r1, c2);
//		check2 = lineCheck(p_ball, r1, c2, r2, c2);
//		if (check1 == true && check2 == true) return true;
//	}
//	p_curr = findPokeBall(p_ball, r2, c1);
//	if (p_curr->exist == false) {
//		check1 = lineCheck(p_ball, r1, c1, r2, c1);
//		check2 = lineCheck(p_ball, r2, c1, r2, c2);
//		if (check1 == true && check2 == true) return true;
//	}
//	return false;
//}
//
//bool ZHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
//	if (r1 == r2 || c1 == c2) return false;
//	
//	bool check1;
//	bool check2;
//	bool check3;
//	int start;
//	int end;
//
//	start = c1 < c2 ? c1 : c2;
//	end = c1 < c2 ? c2 : c1;
//	for (int i = start + 1; i < end; i++) {
//		check1 = lineCheck(p_ball, r1, i, r2, i);
//		if (check1 == true) {
//			check2 = lineCheck(p_ball, r1, c1, r1, i);
//			check3 = lineCheck(p_ball, r2, c2, r2, i);
//			if (check2 == true && check3 == true) return true;
//		}
//	}
//	start = r1 < r2 ? r1 : r2;
//	end = r1 < r2 ? r2 : r1;
//	for (int i = start + 1; i < end; i++) {
//		check1 = lineCheck(p_ball, i, c1, i, c2);
//		if (check1 == true) {
//			check2 = lineCheck(p_ball, r1, c1, i, c1);
//			check3 = lineCheck(p_ball, r2, c2, i, c2);
//			if (check2 == true && check3 == true) return true;
//		}
//	}
//	return false;
//}
//
//bool UHardCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
//	if (((r1 == r2) && (r1 == 0 || r1 == HARD_HEIGHT - 1)) ||
//		((c1 == c2) && (c1 == 0 || c1 == HARD_WIDTH - 1)))
//		return true;
//
//	bool check1;
//	bool check2;
//	bool check3;
//	int start;
//	int end;
//
//	start = c1 < c2 ? c1 : c2;
//	end = c1 < c2 ? c2 : c1;
//	for (int i = 0; i < HARD_WIDTH; i++) {
//		if (i <= start || i >= end) {
//			check1 = lineCheck(p_ball, r1, i, r2, i);
//			if (check1 == true) {
//				check2 = lineCheck(p_ball, r1, c1, r1, i);
//				check3 = lineCheck(p_ball, r2, c2, r2, i);
//				if (check2 == true && check3 == true) return true;
//			}
//		}
//		else if (i == 0 || i == HARD_WIDTH - 1) {
//			check2 = lineCheck(p_ball, r1, c1, r1, i);
//			check3 = lineCheck(p_ball, r2, c2, r2, i);
//			if ((check2 == true && check3 == true) ||
//				(check2 == true && c2 == i) ||
//				(c1 == i && check3 == true))
//				return true;
//		}
//	}
//	start = r1 < r2 ? r1 : r2;
//	end = r1 < r2 ? r2 : r1;
//	for (int i = 0; i < HARD_HEIGHT; i++) {
//		if (i <= start || i >= end) {
//			check1 = lineCheck(p_ball, i, c1, i, c2);
//			if (check1 == true) {
//				check2 = lineCheck(p_ball, r1, c1, i, c1);
//				check3 = lineCheck(p_ball, r2, c2, i, c1);
//				if (check2 == true && check3 == true) return true;
//			}
//		}
//		else if (i == 0 || i == HARD_HEIGHT - 1) {
//			check2 = lineCheck(p_ball, r1, c1, i, c1);
//			check3 = lineCheck(p_ball, r2, c2, i, c1);
//			if ((check2 == true && check3 == true) ||
//				(check2 == true && r2 == i) ||
//				(r1 == i && check3 == true))
//				return true;
//		}
//	}
//	return false;
//}
//
//bool allCheck(HardMode** p_ball, int r1, int c1, int r2, int c2) {
//	if (IHardCheck(p_ball, r1, c1, r2, c2) == true) return true;
//	if (LHardCheck(p_ball, r1, c1, r2, c2) == true) return true;
//	if (ZHardCheck(p_ball, r1, c1, r2, c2) == true) return true;
//	if (UHardCheck(p_ball, r1, c1, r2, c2) == true) return true;
//	return false;
//}
//
//void deleteCell(HardMode** board, int y, int x) {
//	HardMode* p = findPokeBall(board, y, x);
//	if (x == 0) {
//		if (board[y]->p_next == NULL) {
//			board[y]->deleteCell();
//			//if (board[y]->j < 4) displayBackground(bg, board[y]->j, y);
//			board[y] = NULL;
//			return;
//		}
//		board[y]->p_mon = p->p_next->p_mon;
//
//		p = board[y]->p_next;
//		if (p->p_next == NULL) {
//			p->deleteCell();
//			//if (p->j < 4) displayBackground(bg, p->j, y);
//			delete p;
//			board[y]->p_next = NULL;
//		}
//		else {
//			while (p->p_next->p_next != NULL)
//			{
//				p->p_mon = p->p_next->p_mon;
//				p = p->p_next;
//			}
//			p->p_mon = p->p_next->p_mon;
//			p->p_next->deleteCell();
//			//if (p->p_next->j < 4) displayBackground(bg, p->p_next->j, p->p_next->i);
//			delete p->p_next;
//			p->p_next = NULL;
//		}
//	}
//	else if (p->p_next != NULL) {
//		while (p->p_next->p_next != NULL)
//		{
//			p->p_mon = p->p_next->p_mon;
//			p = p->p_next;
//		}
//		p->p_mon = p->p_next->p_mon;
//		p->p_next->deleteCell();
//		//if (p->p_next->j < 4) displayBackground(bg, p->p_next->j, p->p_next->i);
//		delete p->p_next;
//		p->p_next = NULL;
//	}
//	else {
//		p->deleteCell();
//		//if (p->j < 4) displayBackground(bg, p->j, p->i);
//		delete p;
//		p = findPokeBall(board, y, x - 1);
//		p->p_next = NULL;
//	}
//}
//
//void deletePair(HardMode** board, int y1, int x1, int y2, int x2) {
//	if (x1 > x2)
//	{
//		deleteCell(board, y1, x1);
//		deleteCell(board, y2, x2);
//	}
//	else {
//		deleteCell(board, y2, x2);
//		deleteCell(board, y1, x1);
//	}
//}
//
//bool checkValidPairs(HardMode** board) {
//	HardMode* head, * temp;
//	for (int i = 0; i < 5; i++) {
//		head = board[i];
//		while (head != NULL) {
//			int j = i;
//			temp = head->p_next;
//			while (temp == NULL && j < 4) {
//				j++;
//				temp = board[j];
//			}
//			while (temp != NULL) {
//				if (head->p_mon == temp->p_mon) {
//					if (allCheck(board, head->i, head->j, temp->i, temp->j)) {
//						return true;
//					}
//				}
//				temp = temp->p_next;
//				if ((temp == NULL) && (j < 4)) {
//					j++;
//					temp = findPokeBall(board, j, 0);
//				}
//			}
//			head = head->p_next;
//		}
//	}
//	return false;
//}
//
//bool haveFinished(HardMode** p_ball) {
//	for (int i = 0; i < HARD_HEIGHT; i++)
//		for (int j = 0; j < HARD_WIDTH; j++) {
//			if (p_ball[i]->exist == true) return false;
//			p_ball[i] = p_ball[i]->p_next;
//		}
//	return true;
//}