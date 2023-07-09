#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int num;
	struct Node* next;
}node;

typedef struct List {
	node* header;
}list;

void init(list* L);
void addset(list* L, int element);
list* findunion(list* A, list* B);
list* intersect(list* A, list* B);
void print(list* L);


int main() {
	list A, B;
	init(&A);
	init(&B);
	int a;
	int element;
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &element);
		addset(&A, element);
	}
	int b;
	scanf("%d", &b);
	for (int i = 0; i < b; i++) {
		scanf("%d", &element);
		addset(&B, element);
	}
	int *unionresult = findunion(&A, &B);
	int *intersectresult = intersect(&A, &B);
	if (a == 0 && b == 0) {
		printf(" 0\n 0");
	}
	else if (a == 0) {
		print(unionresult);
		printf("\n");
		printf(" 0");
	}
	else {
		print(unionresult);
		printf("\n");
		print(intersectresult);
	}
	
}

void init(list* L) {
	L->header = (node*)malloc(sizeof(node));
	L->header->next = NULL;
}

void addset(list* L, int element) {
	node* tmp = L->header;
	while (tmp->next) {
		tmp = tmp->next;
	}
	node* N = (node*)malloc(sizeof(node));
	N->num = element;
	N->next = NULL;
	tmp->next = N;

}

list* findunion(list* A, list* B) {
	list* result = (list*)malloc(sizeof(list));
	init(result);
	node* tmpA = A->header->next;
	node* tmpB = B->header->next;
	while (1) {
		if ((tmpA == NULL) && (tmpB == NULL)) {
			return (result);
		}
		else if (tmpA == NULL) {
			addset(result, tmpB->num);
			tmpB = tmpB->next;
		}
		else if (tmpB == NULL) {
			addset(result, tmpA->num);
			tmpA = tmpA->next;
		}
		else if (tmpA->num == tmpB->num) {
			addset(result, tmpA->num);
			tmpA = tmpA->next;
			tmpB = tmpB->next;
		}
		else if (tmpA->num < tmpB->num) {
			addset(result, tmpA->num);
			tmpA = tmpA->next;
		}
		else if (tmpA->num > tmpB->num) {
			addset(result, tmpB->num);
			tmpB = tmpB->next;
		}
	}
	return(result);
}
list* intersect(list* A, list* B) {
	list* result = (list*)malloc(sizeof(list));
	init(result);

	node* tmpA = A->header->next;
	node* tmpB = B->header->next;

	while (1) {
		if ((tmpA == NULL) || (tmpB == NULL)) {
			return (result);
		}
		if (tmpA->num < tmpB->num) {
			tmpA = tmpA->next;
		}
		else if (tmpA->num > tmpB->num) {
			tmpB = tmpB->next;
		}
		else if (tmpA->num == tmpB->num) {
			addset(result, tmpA->num);
			tmpA = tmpA->next;
			tmpB = tmpB->next;
		}
	}
	return result;
}

void print(list* L) {
	node* result = L->header->next;
	for (;;) {
		if (result == NULL) {
			break;
		}
		printf(" %d", result->num);
		result = result->next;
	}
}