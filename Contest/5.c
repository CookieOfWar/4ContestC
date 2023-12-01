#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include  <stdlib.h>


typedef struct list {
	int val;
	int shoulddel; //не используется
	struct list* np;
}list;

list* newlist(int value); //создание заглавного элемента списка
list* add(int value, list* prevp); //добавление в список
void printlist(list* temp); //вывод списка
void deleteitem(list* prev, list* delv); //удаление элемента списка (передается предыдущий элемент и тот, который надо удалить)
list* reverserows(list* tmp); //Переворот списка

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
		printlist(reverserows(first));
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

list* reverserows(list* tmp) {
	int first = 1;
	list* prev = tmp;
	list* nextp;
	while (tmp) {
		if (first) {
			nextp = tmp->np;
			tmp->np = NULL;
			first = 0;
		}
		else {
			nextp = tmp->np;
			tmp->np = prev;
		}
		prev = tmp;
		tmp = nextp;
	}
	return prev;
}