#include "HardCheck.h"
#include "Utility.h"

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
            if (start + index > end) return true;
            p_cur = findPokeBall(board, start + index, c1);
            while (p_cur == NULL) {
                ++index;
                if (start + index > end) return true;
                p_cur = findPokeBall(board, start + index, c1);
            }
            if (start + index == end) {
                if (p_cur == NULL) return true;
                if (p_cur->p_mon == p_head->p_mon) return true;
                return false;
            }
            if (p_cur != NULL) return false;
        }
    }
    if (r1 == r2) {
        start = min(c1, c2);
        end = max(c1, c2);
        p_head = findPokeBall(board, r1, start);
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

bool LHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
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
        if (c == c1 && r == r2) return true;
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
        if (c == c2 && r == r1) return true;
    }
    return false;
}

bool ZHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
    int start = min(r1, r2);
    int end = max(r1, r2);
    for (int i = start + 1; i < end; i++) {
        if (IHardCheck(board, i, c1, i, c2))
            if (IHardCheck(board, r1, c1, i, c1) && IHardCheck(board, r2, c2, i, c2))
                return true;
    }
    return false;
}

bool UHardCheck(HardMode** board, int r1, int c1, int r2, int c2) {
    if (r1 == r2) {
        if (r1 == 0 || r1 == HARD_HEIGHT - 1) return true;
        if ((!findPokeBall(board, r1 - 1, c1) && !findPokeBall(board, r1 - 1, c2)) ||
            (!findPokeBall(board, r1 + 1, c1) && !findPokeBall(board, r1 + 1, c2)))
            return true;
    }

    if ((c1 == 0 && c2 == 0) ||
        (!findPokeBall(board, r1, c1)->p_next && !findPokeBall(board, r2, c2)->p_next)) {
        return true;
    }

    int start = min(r1, r2);
    int end = max(r1, r2);
    if (r1 != r2) {
        for (int i = 0; i < HARD_HEIGHT; i++) {
            if (i == 0 || i == HARD_HEIGHT - 1)
                if ((IHardCheck(board, r1, c1, i, c1) && IHardCheck(board, r2, c2, i, c2)) ||
                    (IHardCheck(board, r2, c2, i, c2) && r1 == i) ||
                    (IHardCheck(board, r1, c1, i, c1) && r2 == i))
                    return true;
            if (i <= start || i >= end)
                if (IHardCheck(board, i, c1, i, c2))
                    if (IHardCheck(board, r1, c1, i, c1) && IHardCheck(board, r2, c2, i, c2))
                        return true;
        }
    }
    return false;
}

bool allCheck(HardMode** board, int r1, int c1, int r2, int c2) {
	if (IHardCheck(board, r1, c1, r2, c2)) return true;
	if (LHardCheck(board, r1, c1, r2, c2)) return true;
    if (ZHardCheck(board, r1, c1, r2, c2)) return true;
	if (UHardCheck(board, r1, c1, r2, c2)) return true;
	return false;
}

void deleteNode(HardMode** board, int r, int c, char bg[][50]) {
	HardMode* p_cur = findPokeBall(board, r, c);
	if (c == 0) {
		if (board[r]->p_next == NULL) {
			board[r]->deleteCell();
			if (board[r]->column < 5) displayHardBackground(bg, board[r]->column, r);
			board[r] = NULL;
			return;
		}
		board[r]->p_mon = p_cur->p_next->p_mon;

		p_cur = board[r]->p_next;
		if (p_cur->p_next == NULL) {
			p_cur->deleteCell();
			if (p_cur->column < 5) displayHardBackground(bg, p_cur->column, r);
			delete p_cur;
			board[r]->p_next = NULL;
		}
		else {
			while (p_cur->p_next->p_next != NULL) {
				p_cur->p_mon = p_cur->p_next->p_mon;
				p_cur = p_cur->p_next;
			}
			p_cur->p_mon = p_cur->p_next->p_mon;
			p_cur->p_next->deleteCell();
			if (p_cur->column < 5) displayHardBackground(bg, p_cur->p_next->column, p_cur->p_next->row);
			delete p_cur->p_next;
			p_cur->p_next = NULL;
		}
	}
	else if (p_cur->p_next != NULL) {
		while (p_cur->p_next->p_next != NULL) {
			p_cur->p_mon = p_cur->p_next->p_mon;
			p_cur = p_cur->p_next;
		}
		p_cur->p_mon = p_cur->p_next->p_mon;
		p_cur->p_next->deleteCell();
		if (p_cur->p_next->column < 5) displayHardBackground(bg, p_cur->p_next->column, p_cur->p_next->row);
		delete p_cur->p_next;
		p_cur->p_next = NULL;
	}
	else {
		p_cur->deleteCell();
		if (p_cur->column < 5) displayHardBackground(bg, p_cur->column, p_cur->row);
		delete p_cur;
		p_cur = findPokeBall(board, r, c - 1);
		p_cur->p_next = NULL;
	}
}

void DifMode(HardMode** board, int r1, int c1, int r2, int c2, char bg[][50]) {
	if (c1 > c2) {
		deleteNode(board, r1, c1, bg);
		deleteNode(board, r2, c2, bg);
	}
	else {
		deleteNode(board, r2, c2, bg);
		deleteNode(board, r1, c1, bg);
	}
}

bool checkValidPairs(HardMode** board) {
	HardMode* head, * temp;
	for (int i = 0; i < 6; i++) {
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

bool haveFinished(HardMode** board) {
    for (int i = 0; i < HARD_HEIGHT; i++)
        if (board[i] != NULL) return false;
    return true;
}