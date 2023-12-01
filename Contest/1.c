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

int main() {
	int chislo, numoflist = 0, a;
	char temp;
	list* curr;
	curr = newlist(0);
	while(1) {
		a = scanf("%d%c", &chislo, &temp);
		if (a == 0) {
			break;
		}
		if (temp != '.') {
			curr = add(chislo, curr);
			numoflist++;
		}
		else {
			curr = add(chislo, curr);
			numoflist++;
			break;
		}
	}
	if (numoflist == 0) {
		printf("NULL");
		return 0;
	}
	else {
		printlist(curr);
	}
}

list* newlist(int value) {
	list* tmp = (list*)malloc(sizeof(list));
	if (tmp) {
		tmp->np = NULL;
		tmp->val = value;
		return tmp;
	}
	else
		exit(-1);
}

list* add(int value, list* prevp) {
	list* tmp = (list*)malloc(sizeof(list));
	if (tmp) {
		tmp->np = prevp;
		tmp->val = value;
		return tmp;
	}
	else
		exit(-1);
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
