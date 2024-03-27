#include "HardCheck.h"

HardMode* findPokeBall(HardMode** board, int y, int x) {
	if (y < 0 || y > 6 || x < 0 || x > 6) return NULL;

	HardMode* temp = board[y];
	while (temp != NULL) {
		if (temp->j == x) return temp;
		temp = temp->p_next;
	}
	return NULL;
}

bool Icheck(HardMode** board, int y1, int x1, int y2, int x2) {
	int ma, mi, i = 0;
	HardMode* temp, * tempHead;
	if (x1 == x2) {
		ma = max(y1, y2);
		mi = min(y1, y2);
		tempHead = findPokeBall(board, mi, x1);
		temp = tempHead;
		while (temp == NULL) {
			mi++;
			temp = findPokeBall(board, mi, x1);
			tempHead = temp;
			if (mi == ma) return true;
			if (temp != NULL) return false;
		}
		while (temp != NULL) {
			i++;
			temp = findPokeBall(board, mi + i, x1);
			while (temp == NULL) {
				i++;
				temp = findPokeBall(board, mi + i, x1);
				if (mi + i > ma) return true;
			}
			if (mi + i > ma) return true;
			if (mi + i == ma) {
				if (temp == NULL) return true;
				if (temp->p_mon == tempHead->p_mon) return true;
				return false;
			}
			if (temp != NULL) return false;
		}
	}
	if (y1 == y2) {
		i = 0;
		ma = max(x1, x2);
		mi = min(x1, x2);
		tempHead = findPokeBall(board, y1, mi);
		temp = tempHead;
		while (temp == NULL) {
			mi++;
			temp = findPokeBall(board, mi, x1);
			tempHead = temp;
			if (mi > ma) return true;
		}
		while (temp != NULL) {
			i++;
			temp = temp->p_next;
			if (mi + i > ma) return true;
			if (mi + i == ma) {
				if (temp == NULL) return true;
				if (temp->p_mon == tempHead->p_mon) return true;
				return false;
			}
			if (temp != NULL) return false;
		}
	}
	return false;
}

bool Lcheck(HardMode** board, int y1, int x1, int y2, int x2) {
	HardMode* temp;
	temp = findPokeBall(board, y1, x2);
	if (temp == NULL) {
		int x = x2, y = y1;
		while (temp == NULL) {
			if (x2 > x1) x--;
			else x++;
			temp = findPokeBall(board, y1, x);
		}
		temp = NULL;
		while (temp == NULL) {
			if (y2 > y1) y++;
			else y--;
			temp = findPokeBall(board, y, x2);
		}
		if (Icheck(board, y1, x1, y1, x)) 
			if (Icheck(board, y2, x2, y, x2)) 
				return true;
		else if (Icheck(board, y1, x1, y1, x)) 
			if (Icheck(board, y2, x2, y, x2)) 
				return true;
	}
	temp = findPokeBall(board, y2, x1);
	if (temp == NULL) {
		int x = x1, y = y2;
		while (temp == NULL) {
			if (x2 > x1) x++;
			else x--;
			temp = findPokeBall(board, y2, x);
		}
		temp = NULL;
		while (temp == NULL) {
			if (y2 > y1) y--;
			else y++;
			temp = findPokeBall(board, y, x1);
		}
		if (Icheck(board, y1, x1, y1, x)) 
			if (Icheck(board, y2, x2, y, x2)) 
				return true;
		else if (Icheck(board, y2, x2, y2, x))
			if (Icheck(board, y1, x1, y, x1)) 
				return true;
	}
	return false;
}

bool UandZcheck(HardMode** board, int y1, int x1, int y2, int x2) {
	if ((findPokeBall(board, y1 - 1, x1) == NULL && findPokeBall(board, y2 - 1, x2) == NULL ||
		findPokeBall(board, y1 + 1, x1) == NULL && findPokeBall(board, y2 + 1, x2) == NULL) && (y1 == y2)) {
		return true;
	}

	if ((x1 == 0 && x2 == 0) || (findPokeBall(board, y1, x1)->p_next == NULL && findPokeBall(board, y2, x2)->p_next == NULL)) {
		return true;
	}

	HardMode* tempTail, * tempHead;
	if ((Icheck(board, y1, x1, 0, x1) || Icheck(board, y1, x1, 5, x1)) && (y1 != y2)) {
		tempTail = findPokeBall(board, y1, x2);
		if (tempTail == NULL) {
			int y = y1;
			if ((Icheck(board, y1, x1, 0, x1)))
				while (tempTail == NULL) {
					y++;
					tempTail = findPokeBall(board, y, x2);
				}
			if (Icheck(board, y, x2, y2, x2)) return true;
			
			y = y1;
			if (Icheck(board, y1, x1, 5, x1)) {
				tempTail = NULL;
				while (tempTail == NULL) {
					y--;
					tempTail = findPokeBall(board, y, x2);
				}
			}
			if (Icheck(board, y, tempTail->j, y2, x2)) return true;
		}
		if (Icheck(board, tempTail->i, tempTail->j, y2, x2)) return true;
	}
	if ((Icheck(board, y2, x2, 0, x2) || Icheck(board, y2, x2, 5, x2)) && (y1 != y2)) {
		tempTail = findPokeBall(board, y2, x1);
		if (tempTail == NULL) {
			int y = y2;
			if (Icheck(board, y2, x2, 0, x2))
				while (tempTail == NULL) {
					y++;
					tempTail = findPokeBall(board, y, x1);
				}
			if (Icheck(board, y, x1, y1, x1)) return true;
			
			y = y2;
			if (Icheck(board, y2, x2, 5, x2))
				while (tempTail == NULL) {
					y--;
					tempTail = findPokeBall(board, y, x1);
				}
			if (Icheck(board, y, x1, y1, x1)) return true;
		}
		else 
			if (Icheck(board, tempTail->i, tempTail->j, y1, x1)) 
				return true;
	}

	int ma, mi;
	ma = max(y1, y2);
	mi = min(y1, y2);
	if (x1 != x2) {
		for (int i = 0; (i < HARD_HEIGHT); i++) {
			tempHead = findPokeBall(board, i, x1);
			int x = x1;
			tempTail = findPokeBall(board, i, x2);
			x = x2;
			if (Icheck(board, i, x1, i, x2)) 
				if (Icheck(board, i, x1, y1, x1) && Icheck(board, i, x2, y2, x2))
					return true;
		}
	}

	ma = max(x1, x2);
	mi = min(x1, x2);
	if (y1 != y2) {
		for (int i = 0; i < HARD_HEIGHT; i++) {
			tempHead = findPokeBall(board, y1, i);
			int y = y1;
			tempTail = findPokeBall(board, y2, i);
			y = y2;
			if (Icheck(board, y1, i, y2, i)) 
				if (Icheck(board, y1, i, y1, x1) && Icheck(board, y2, i, y2, x2))
					return true;
		}
	}
	return false;
}

bool allCheck(HardMode** board, int y1, int x1, int y2, int x2) {
	if (Icheck(board, y1, x1, y2, x2)) return true;
	else if (Lcheck(board, y1, x1, y2, x2)) return true;
	else if (UandZcheck(board, y1, x1, y2, x2)) return true;
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

void DifMode(HardMode** board, int y1, int x1, int y2, int x2) {
	if (x1 > x2) {
		deleteNode(board, y1, x1);
		deleteNode(board, y2, x2);
	}
	else {
		deleteNode(board, y2, x2);
		deleteNode(board, y1, x1);
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
					if (allCheck(board, head->i, head->j, temp->i, temp->j))
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