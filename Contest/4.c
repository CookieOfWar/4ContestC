#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include  <stdlib.h>


typedef struct list {
	int val;
	int shoulddel;
	struct list* np;
}list;

list* newlist(int value);
list* add(int value, list* prevp);
void printlist(list* temp);
void deleteitem(list* prev, list* delv);
void marktodel(list* tmp, int len);
list* deletemarked(list* first);

int main() {
	int chislo, a, numoflist = 0;
	char temp;
	list* first = NULL;
	list* tmp;
	a = scanf("%d%c", &chislo, &temp);
	if (a != 0) {
		first = newlist(chislo);
		tmp = first;
		if (temp != '.') {
			while (1) {
				a = scanf("%d%c", &chislo, &temp);
				if (a == 0) {
					break;
				}
				if (temp != '.') {
					tmp = add(chislo, tmp);
					numoflist++;
				}
				else {
					tmp = add(chislo, tmp);
					numoflist++;
					break;
				}
			}
		}
	}
	else {
		printf("NULL");
		exit(0);
	}
	
	if (first) {
		marktodel(first, numoflist + 1);
		first = deletemarked(first);
		printlist(first);
	}
	
}

list* newlist(int value) {
	list* tmp = (list*)malloc(sizeof(list));
	if (tmp) {
		tmp->np = NULL;
		tmp->val = value;
		tmp->shoulddel = 0;
		return tmp;
	}
	else
		exit(0);
}

list* add(int value, list* prevp) {
	list* tmp = (list*)malloc(sizeof(list));
	if (tmp) {
		prevp->np = tmp;
		tmp->val = value;
		tmp->np = NULL;
		tmp->shoulddel = 0;
		return tmp;
	}
	else
		exit(0);
}

void printlist(list* temp) {
	int wp = 0;
	list* tmp = NULL;
	if (temp == NULL) {
		printf("NULL");
		return;
	}
	while (1) {
		printf("%d", temp->val);
		wp = 1;
		if (temp->np == NULL) {
			break;
		}
		else {
			printf(" ");
			temp = temp->np;
		}
	}
	if (!wp)
		printf("NULL");
}

void deleteitem(list* prev, list* delv) {
	prev->np = delv->np;
	free(delv);
}

void marktodel(list* tmp, int len) {
	list* curr = tmp;
	for (int i = 1; i <= len; i++) {
		if (i % 2 != 0 && (curr->val) % 2 == 0) {
			curr->shoulddel = 1;
		}
		curr = curr->np;
	}
}

list* deletemarked(list* first) {
	list* head = first;
	list* prev = NULL;
	while (first) {
		if (first->shoulddel) {
			if (prev == NULL) {
				head = head->np;
				free(first);
				first = head;
			}
			else {
				first = first->np;
				deleteitem(prev, prev->np);
			}
		}
		else {
			prev = first;
			first = first->np;
		}
	}
	return head;
}