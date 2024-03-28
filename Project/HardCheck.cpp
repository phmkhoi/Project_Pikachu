#include "HardCheck.h"

HardMode* findPokeBall(HardMode** board, int r, int c) {
	if (r < 0 || r > 6 || c < 0 || c > 6) return NULL;

	HardMode* p_cur = board[r];
	while (p_cur != NULL) {
		if (p_cur->column == c) return p_cur;
		p_cur = p_cur->p_next;
	}
	return NULL;
}

bool IHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	int start, end, index = 0;
	HardMode* p_cur, * p_head;
	if (c1 == c2) {
		start = min(r1, r2);
		end = max(r1, r2);
		p_head = findPokeBall(board, start, c1);
		p_cur = p_head;
		while (p_cur == NULL) {
			++start;
			p_cur = findPokeBall(board, start, c1);
			p_head = p_cur;
			if (start == end) return true;
			if (p_cur != NULL) return false;
		}
		while (p_cur != NULL) {
			++index;
			p_cur = findPokeBall(board, start + index, c1);
			while (p_cur == NULL) {
				++index;
				p_cur = findPokeBall(board, start + index, c1);
				if (start + index > end) return true;
			}
			if (start + index > end) return true;
			if (start + index == end) {
				if (p_cur == NULL) return true;
				if (p_cur->p_mon == p_head->p_mon) return true;
				return false;
			}
			if (p_cur != NULL) return false;
		}
	}
	if (r1 == r2) {
		index = 0;
		start = min(c1, c2);
		end = max(c1, c2);
		p_head = findPokeBall(board, r1, start);
		p_cur = p_head;
		while (p_cur == NULL) {
			++start;
			p_cur = findPokeBall(board, start, c1);
			p_head = p_cur;
			if (start > end) return true;
		}
		while (p_cur != NULL) {
			++index;
			p_cur = p_cur->p_next;
			if (start + index > end) return true;
			if (start + index == end) {
				if (p_cur == NULL) return true;
				if (p_cur->p_mon == p_head->p_mon) return true;
				return false;
			}
			if (p_cur != NULL) return false;
		}
	}
	return false;
}

bool LHardcheck(HardMode** board, int r1, int c1, int r2, int c2) {
	HardMode* p_cur;
	p_cur = findPokeBall(board, r1, c2);
	if (p_cur == NULL) {
		int c = c2, r = r1;
		while (p_cur == NULL) {
			if (c2 > c1) --c;
			else ++c;
			p_cur = findPokeBall(board, r1, c);
		}
		p_cur = NULL;
		while (p_cur == NULL) {
			if (r2 > r1) ++r;
			else --r;
			p_cur = findPokeBall(board, r, c2);
		}
		if (IHardCheck(board, r1, c1, r1, c) && IHardCheck(board, r2, c2, r, c2))
			return true;
		else if (IHardCheck(board, r1, c1, r, c1) && IHardCheck(board, r2, c2, r2, c))
			return true;
	}
	p_cur = findPokeBall(board, r2, c1);
	if (p_cur == NULL) {
		int c = c1, r = r2;
		while (p_cur == NULL) {
			if (c2 > c1) ++c;
			else --c;
			p_cur = findPokeBall(board, r2, c);
		}
		p_cur = NULL;
		while (p_cur == NULL) {
			if (r2 > r1) --r;
			else ++r;
			p_cur = findPokeBall(board, r, c1);
		}
		if (Icheck(board, r1, c1, r1, c) && Icheck(board, r2, c2, r, c2)) 
			return true;
		else if (Icheck(board, r1, c1, r, c1) && Icheck(board, r2, c2, r, c2)) 
			return true;
	}
	return false;
}

bool ZHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {

}
bool UHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	if (((!findPokeBall(board, r1 - 1, c1) && !findPokeBall(board, r2 - 1, c2)) ||
		(!findPokeBall(board, r1 + 1, c1) && !findPokeBall(board, r2 + 1, c2))) && (r1 == r2))
		return true;

	if ((!findPokeBall(board, r1, c1)->p_next && !findPokeBall(board, r2, c2)->p_next) ||
		(c1 == 0 && c2 == 0))
		return true;

	HardMode* p_tail, * p_head;
	if ((IHardCheck(board, r1, c1, 0, c1) || IHardCheck(board, r1, c1, 5, c1)) && (r1 != r2)) {
		p_tail = findPokeBall(board, r1, c2);
		if (p_tail == NULL) {
			int r = r1;
			if ((IHardCheck(board, r1, c1, 0, c1)))
				while (p_tail == NULL) {
					++r;
					p_tail = findPokeBall(board, r, c2);
				}
			if (Icheck(board, r, c2, r2, c2)) return true;
			
			r = r1;
			if (IHardCheck(board, r1, c1, 5, c1)) {
				p_tail = NULL;
				while (p_tail == NULL) {
					--r;
					p_tail = findPokeBall(board, r, c2);
				}
			}
			if (Icheck(board, r, p_tail->column, r2, c2)) return true;
		}
		if (Icheck(board, p_tail->row, p_tail->column, r2, c2)) return true;
	}
	if ((Icheck(board, r2, c2, 0, c2) || Icheck(board, r2, c2, 5, c2)) && (r1 != r2)) {
		p_tail = findPokeBall(board, r2, c1);
		if (p_tail == NULL) {
			int y = r2;
			if (Icheck(board, r2, c2, 0, c2))
				while (p_tail == NULL) {
					y++;
					p_tail = findPokeBall(board, y, c1);
				}
			if (Icheck(board, y, c1, r1, c1)) return true;
			
			y = r2;
			if (Icheck(board, r2, c2, 5, c2))
				while (p_tail == NULL) {
					y--;
					p_tail = findPokeBall(board, y, c1);
				}
			if (Icheck(board, y, c1, r1, c1)) return true;
		}
		else 
			if (Icheck(board, p_tail->row, p_tail->column, r1, c1)) 
				return true;
	}
	if (c1 != c2) {
		for (int i = 0; i < HARD_HEIGHT; i++) {
			p_head = findPokeBall(board, i, c1);
			int c = c1;
			p_tail = findPokeBall(board, i, c2);
			c = c2;
			if (Icheck(board, i, c1, i, c2)) 
				if (Icheck(board, i, c1, r1, c1) && Icheck(board, i, c2, r2, c2))
					return true;
		}
	}
	if (r1 != r2) {
		for (int i = 0; i < HARD_HEIGHT; i++) {
			p_head = findPokeBall(board, r1, i);
			int y = r1;
			p_tail = findPokeBall(board, r2, i);
			y = r2;
			if (Icheck(board, r1, i, r2, i)) 
				if (Icheck(board, r1, i, r1, c1) && Icheck(board, r2, i, r2, c2))
					return true;
		}
	}
	return false;
}

bool allCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	if (Icheck(board, r1, c1, r2, c2)) return true;
	else if (Lcheck(board, r1, c1, r2, c2)) return true;
	else if (UandZcheck(board, r1, c1, r2, c2)) return true;
	return false;
}

void deleteNode(HardMode** board, int y, int x) {
	HardMode* p = findPokeBall(board, y, x);
	if (x == 0) {
		if (board[y]->p_next == NULL) {
			board[y]->deleteCell();
			//if (board[y]->j < 4) displayBackground(bg, board[y]->j, y);
			board[y] = NULL;
			return;
		}
		board[y]->p_mon = p->p_next->p_mon;

		p = board[y]->p_next;
		if (p->p_next == NULL) {
			p->deleteCell();
			//if (p->j < 4) displayBackground(bg, p->j, y);
			delete p;
			board[y]->p_next = NULL;
		}
		else {
			while (p->p_next->p_next != NULL) {
				p->p_mon = p->p_next->p_mon;
				p = p->p_next;
			}
			p->p_mon = p->p_next->p_mon;
			p->p_next->deleteCell();
			//if (p->p_next->j < 4) displayBackground(bg, p->p_next->j, p->p_next->i);
			delete p->p_next;
			p->p_next = NULL;
		}
	}
	else if (p->p_next != NULL) {
		while (p->p_next->p_next != NULL) {
			p->p_mon = p->p_next->p_mon;
			p = p->p_next;
		}
		p->p_mon = p->p_next->p_mon;
		p->p_next->deleteCell();
		//if (p->p_next->j < 4) displayBackground(bg, p->p_next->j, p->p_next->i);
		delete p->p_next;
		p->p_next = NULL;
	}
	else {
		p->deleteCell();
		//if (p->j < 4) displayBackground(bg, p->j, p->i);
		delete p;
		p = findPokeBall(board, y, x - 1);
		p->p_next = NULL;
	}
}

void DifMode(HardMode** board, int r1, int c1, int r2, int c2) {
	if (c1 > c2) {
		deleteNode(board, r1, c1);
		deleteNode(board, r2, c2);
	}
	else {
		deleteNode(board, r2, c2);
		deleteNode(board, r1, c1);
	}
}

bool checkValidPairs(HardMode** board) {
	HardMode* head, * temp;
	for (int i = 0; i < 5; i++) {
		head = board[i];
		while (head != NULL) {
			int j = i;
			temp = head->p_next;
			while (temp == NULL && j < 6) {
				j++;
				temp = board[j];
			}
			while (temp != NULL) {
				if (head->p_mon == temp->p_mon) 
					if (allCheck(board, head->row, head->column, temp->row, temp->column))
						return true;
				temp = temp->p_next;
				if ((temp == NULL) && (j < 6)) {
					j++;
					temp = findPokeBall(board, j, 0);
				}
			}
			head = head->p_next;
		}
	}
	return false;
}