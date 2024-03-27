#include "HardCheck.h"

HardMode* findPokeBall(HardMode** board, int r, int c) {
	if (r < 0 || r > 4 || c < 0 || c > 7) return NULL;

	HardMode* temp = board[r];
	while (temp != NULL) {
		if (temp->j == c) {
			return temp;
		}
		temp = temp->p_next;
	}
	return NULL;
}

bool IHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	HardMode* p_curr = nullptr, *temp_head = nullptr;
	int start, end, cnt = 0;

	if (r1 == r2) {
		start = c1 < c2 ? c1 : c2;
		end = c1 < c2 ? c2 : c1;
		temp_head = findPokeBall(board, r1, start);
		p_curr = temp_head;
		while (p_curr == NULL) {
			start++;
			p_curr = findPokeBall(board, start, c1);
			temp_head = p_curr;
			if (start > end) {
				return true;
			}
		}

		while (p_curr != NULL) {
			++cnt;
			p_curr = p_curr->p_next;
			if (start + cnt > end) {
				return true;
			}
			if (start + cnt == end) {
				if (p_curr == NULL) {
					return true;
				}
				if (p_curr->p_mon == temp_head->p_mon) {
					return true;
				}
				return false;
			}
			if (p_curr != NULL) {
				return false;
			}
		}
	}
	if (c1 == c2) {
		start = r1 < r2 ? r1 : r2;
		end = r1 < r2 ? r2 : r1;
		temp_head = findPokeBall(board, start, c1);
		p_curr = temp_head;
		while (p_curr == NULL) {
			start++;
			p_curr = findPokeBall(board, start, c1);
			temp_head = p_curr;
			if (start == end) {
				return true;
			}
			if (p_curr != NULL) {
				return false;
			}
		}
		while (p_curr != NULL) {
			cnt++;
			p_curr = findPokeBall(board, start + cnt, c1);
			while (p_curr == NULL) {
				cnt++;
				p_curr = findPokeBall(board, start + cnt, c1);
				if (start + cnt > end) {
					return true;
				}
			}
			if (start + cnt > end) {
				return true;
			}
			if (start + cnt == end) {
				if (p_curr == NULL) {
					return true;
				}
				if (p_curr->p_mon == temp_head->p_mon) {
					return true;
				}
				return false;
			}
			if (p_curr != NULL) {
				return false;
			}
		}
	}
	return false;
}

bool LHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	HardMode* temp;
	temp = findPokeBall(board, r1, c2);
	if (temp == NULL) {
		int x = c2, y = r1;
		while (temp == NULL) {
			if (c2 > c1) {
				x--;
			}
			else {
				x++;
			}
			temp = findPokeBall(board, r1, x);
		}
		temp = NULL;
		while (temp == NULL) {
			if (r2 > r1) {
				y++;
			}
			else {
				y--;
			}
			temp = findPokeBall(board, y, c2);
		}
		if (IHardCheck(board, r1, c1, r1, x)) {
			if (IHardCheck(board, r2, c2, y, c2)) {
				return true;
			}
		}
		else if (IHardCheck(board, r1, c1, r1, x)) {
			if (IHardCheck(board, r2, c2, y, c2)) {
				return true;
			}
		}
	}

	temp = findPokeBall(board, r2, c1);
	if (temp == NULL) {
		int x = c1, y = r2;
		while (temp == NULL) {
			if (c2 > c1) {
				x++;
			}
			else {
				x--;
			}
			temp = findPokeBall(board, r2, x);
		}
		temp = NULL;
		while (temp == NULL) {
			if (r2 > r1) {
				y--;
			}
			else {
				y++;
			}
			temp = findPokeBall(board, y, c1);
		}
		if (IHardCheck(board, r1, c1, r1, x)) {
			if (IHardCheck(board, r2, c2, y, c2)) {
				return true;
			}
		}
		else if (IHardCheck(board, r2, c2, r2, x)) {
			if (IHardCheck(board, r1, c1, y, c1)) {
				return true;
			}
		}
	}
	return false;
}


bool UandZcheck(HardMode** board, int r1, int c1, int r2, int c2) {
	if ((findPokeBall(board, r1 - 1, c1) == NULL && findPokeBall(board, r2 - 1, c2) == NULL 
		|| findPokeBall(board, r1 + 1, c1) == NULL && findPokeBall(board, r2 + 1, c2) == NULL) && (r1 == r2)) {
		return true;
	}

	if ((c1 == 0 && c2 == 0) || (findPokeBall(board, r1, c1)->p_next == NULL 
		&& findPokeBall(board, r2, c2)->p_next == NULL)) {
		return true;
	}

	HardMode* tempTail, * tempHead;
	if ((IHardCheck(board, r1, c1, 0, c1) || IHardCheck(board, r1, c1, HARD_HEIGHT - 1, c1)) && (r1 != r2)) {
		tempTail = findPokeBall(board, r1, c2);
		if (tempTail == NULL) {
			int y = r1;
			if ((IHardCheck(board, r1, c1, 0, c1))) {
				while (tempTail == NULL) {
					y++;
					tempTail = findPokeBall(board, y, c2);
				}
			}
			if (IHardCheck(board, y, c2, r2, c2)) {
				return true;
			}
			y = r1;
			if (IHardCheck(board, r1, c1, HARD_HEIGHT - 1, c1)) {
				tempTail = NULL;
				while (tempTail == NULL) {
					y--;
					tempTail = findPokeBall(board, y, c2);
				}
			}
			if (IHardCheck(board, y, tempTail->j, r2, c2)) {
				return true;
			}
		}
		if (IHardCheck(board, tempTail->i, tempTail->j, r2, c2)) {
			return true;
		}
	}
	if ((IHardCheck(board, r2, c2, 0, c2) || IHardCheck(board, r2, c2, 4, c2)) && (r1 != r2)) {
		tempTail = findPokeBall(board, r2, c1);
		if (tempTail == NULL) {
			int y = r2;
			if (IHardCheck(board, r2, c2, 0, c2)) {
				while (tempTail == NULL) {
					y++;
					tempTail = findPokeBall(board, y, c1);
				}
			}
			if (IHardCheck(board, y, c1, r1, c1)) {
				return true;
			}
			y = r2;
			if (IHardCheck(board, r2, c2, HARD_HEIGHT - 1, c2)) {
				while (tempTail == NULL) {
					y--;
					tempTail = findPokeBall(board, y, c1);
				}
			}
			if (IHardCheck(board, y, c1, r1, c1)) {
				return true;
			}
		}
		else {
			if (IHardCheck(board, tempTail->i, tempTail->j, r1, c1)) {
				return true;
			}
		}
	}

	int ma, mi;
	ma = max(r1, r2);
	mi = min(r1, r2);
	if (c1 != c2) {
		for (int i = 0; (i < HARD_HEIGHT); i++) {
			tempHead = findPokeBall(board, i, c1);
			int x = c1;
			tempTail = findPokeBall(board, i, c2);
			x = c2;
			if (IHardCheck(board, i, c1, i, c2)) {
				if (IHardCheck(board, i, c1, r1, c1) && IHardCheck(board, i, c2, r2, c2)) {
					return true;
				}
			}
		}
	}

	ma = max(c1, c2);
	mi = min(c1, c2);
	if (r1 != r2) {
		for (int i = 0; i < HARD_HEIGHT; i++) {
			tempHead = findPokeBall(board, r1, i);
			int y = r1;
			tempTail = findPokeBall(board, r2, i);
			y = r2;
			if (IHardCheck(board, r1, i, r2, i)) {
				if (IHardCheck(board, r1, i, r1, c1) && IHardCheck(board, r2, i, r2, c2)) {
					return true;
				}
			}
		}
	}
	return false;
}

bool allCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	if (IHardCheck(board, r1, c1, r2, c2) == true) return true;
	if (LHardCheck(board, r1, c1, r2, c2) == true) return true;
	if (UandZcheck(board, r1, c1, r2, c2) == true) return true;
	return false;
}

void deleteCell(HardMode** board, int y, int x) {
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
			while (p->p_next->p_next != NULL)
			{
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
		while (p->p_next->p_next != NULL)
		{
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

void deletePair(HardMode** board, int r1, int c1, int r2, int c2) {
	if (c1 > c2)
	{
		deleteCell(board, r1, c1);
		deleteCell(board, r2, c2);
	}
	else {
		deleteCell(board, r2, c2);
		deleteCell(board, r1, c1);
	}
}

bool checkValidPairs(HardMode** board) {
	HardMode* head, * temp;
	for (int i = 0; i < 5; i++) {
		head = board[i];
		while (head != NULL) {
			int j = i;
			temp = head->p_next;
			while (temp == NULL && j < 4) {
				j++;
				temp = board[j];
			}
			while (temp != NULL) {
				if (head->p_mon == temp->p_mon) {
					if (allCheck(board, head->i, head->j, temp->i, temp->j)) {
						return true;
					}
				}
				temp = temp->p_next;
				if ((temp == NULL) && (j < 4)) {
					j++;
					temp = findPokeBall(board, j, 0);
				}
			}
			head = head->p_next;
		}
	}
	return false;
}