/*
Это не рабочая программа, пишет, что превышен лимит памяти на 4м тесте, причем каждый раз испольщует рандомную память
*/
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
void delsum(list* tmp, int k);
list* deleteitem(list* curr, int a, int b, int len);

int main() {
	int chislo, ind, numoflist = 0, a;
	char temp;
	list* first;
	list* tmp;
	a = scanf("%d%c", &chislo, &temp);
	if (a != 0) {
		first = newlist(chislo);
		tmp = first;
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
	else {
		printf("NULL");
		return 0;
	}
	a = scanf("%d %d", &chislo, &ind);
	if (numoflist == 0) {
		printf("NULL");
		return 0;
	}
	else {
		printlist(deleteitem(first, chislo, ind, numoflist + 1));
	}
	return 0;
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
		return NULL;
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
		return NULL;
}

void printlist(list* temp) {
	int wp = 0;
	list* tmp = NULL;
	while (1) {
		if (!(temp->shoulddel)) {
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
		else {
			if (temp->np == NULL) {
				break;
			}
			else {
				tmp = temp->np;
				free(temp);
				temp = tmp;
			}
		}
	}
	if (!wp)
		printf("NULL");
}

list* deleteitem(list* curr, int a, int b, int len) {
	list* prev = NULL;
	list* head = curr;
	int i = 1;
	while (curr) {
		if (i == a || i == b) {
			curr->shoulddel = 1;
		}
		curr = curr->np;
		i++;
	}
	return head;
}