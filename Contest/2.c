#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include  <stdlib.h>


typedef struct list {
	int val;
	struct list* np;
}list;

list* newlist(int value);
list* add(int value, list * prevp);
void printlist(list *temp);
void delsum(list* tmp, int k);

int main() {
	int chislo, numoflist = 0, a;
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
		exit(0);
	}
	a = scanf("%d%*c", &chislo);
	if (numoflist == 0) {
		printf("NULL");
		return 0;
	}
	else {
		delsum(first, chislo);
	}
	return 0;
}

list* newlist(int value) {
	list* tmp = (list*)malloc(sizeof(list));
	if (tmp) {
		tmp->np = NULL;
		tmp->val = value;
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
		return tmp;
	}
	else
		exit(0);
}

void printlist(list* temp) {
	while (1) {
		printf("%d", temp->val);
		if ((temp->np)->np == NULL) {
			break;
		}
		else {
			printf(" ");
			temp = temp->np;
		}
	}
}

void delsum(list* tmp, int k) {
	int numofdel = 0, sumofdel = 0;
	while (1) {
		if (tmp->val % k == 0) {
			numofdel++;
			sumofdel += tmp->val;
		}
		if (tmp->np == NULL)
			break;
		tmp = tmp->np;
	}
	if (numofdel == 0) {
		printf("NULL");
		exit(0);
	}
	else {
		float f = (float)sumofdel / (float)numofdel;
		printf("%.2f", f);
	}
}