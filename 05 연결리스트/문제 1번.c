#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	char element;
	struct Node* prev, * next;
}node;

typedef struct List {
	node* header;
	node* trailer;
}list;

void init(list* L);
void add(list* L, int r, int e);
void delete(list* L, int r);
char get(list* L, int r);
void print(list* L);

int main() {
	list L;
	init(&L);
	int n;
	scanf("%d", &n);
	getchar();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int r;
		char commend, element;
		scanf("%c", &commend);
		getchar();
		if (commend == 'A'){
			scanf("%d %c", &r, &element);
			getchar();
			if (r > cnt + 1) {
				printf("invalid position");
				continue;
			}
			add(&L, r, element);
			cnt++;
		}
		if (commend == 'D') {
			scanf("%d", &r);
			getchar();
			if (r > cnt) {
				printf("invalid position");
				continue;
			}
			delete(&L, r);
			cnt--;
		}
		if (commend == 'G') {
			scanf("%d", &r);
			getchar();
			if (r > cnt) {
				printf("invalid position");
				continue;
			}
			printf("%c", get(&L, r));
		}
		if (commend == 'P') {
			print(&L);
		}
	}
}

void init(list* L) {
	L->header = (node*)malloc(sizeof(node));
	L->trailer = (node*)malloc(sizeof(node));
	L->header->next = L->trailer;
	L->trailer->prev = L->header;
}

void add(list* L, int r, int e) {
	node* N = (node*)malloc(sizeof(node));
	N->element = e;
	N->prev = NULL;
	N->next = NULL;
	node* tmp = L->header;
	for (int i = 1; i < r; i++) {
		tmp = tmp->next;
	}
	N->prev = tmp;
	N->next = tmp->next;
	tmp->next = N;
	N->next->prev = N;
}

void delete(list* L, int r) {
	node* N = L->header;
	for (int i = 0; i < r; i++) {
		N = N->next;
	}
	N->next->prev = N->prev;
	N->prev->next = N->next;
}

char get(list* L, int r) {
	node* N = L->header;
	for (int i = 0; i < r; i++) {
		N = N->next;
	}
	return(N->element);
}

void print(list* L) {
	node *N = L->header;
	while (1) {
		N = N->next;
		if (N == L->trailer) {
			break;
		}
		printf("%c", N->element);
	}
}
