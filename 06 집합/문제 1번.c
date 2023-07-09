#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int num; //오른차순 양의 정수 수열
	struct Node* next; //다음 노드를 가리키는 링크
}node;

typedef struct List {
	node* header;
}list;

void init(list* L);
void addset(list* L, int element);
int subset(list* A, list* B);


int main() {
	list L1, L2;
	init(&L1);
	init(&L2);
	int N1; //A 집합 크기
	scanf("%d", &N1);
	int *arr1 = (int *)malloc(sizeof(int)*N1);
	for (int i = 0; i < N1; i++) {
		scanf("%d", &arr1[i]);
		addset(&L1, arr1[i]);
	}

	int N2; //B 집합 크기
	scanf("%d", &N2);
	int* arr2 = (int*)malloc(sizeof(int) * N2);
	for (int i = 0; i < N2; i++) {
		scanf("%d", &arr2[i]);
		addset(&L2, arr2[i]);
	}
	int result;
	result = subset(&L1, &L2);
	printf("%d", result);
}

void init(list* L) {
	L->header = NULL;
}

void addset(list* L, int element) {
	node* tmp = L->header; //임의의 노드 포인터 생성 (위치 이동용)
	node* N = (node*)malloc(sizeof(node)); //넣을 노드 생성
	if (tmp == NULL) {
		N->num = element;
		N->next = NULL;
		L->header = N;
	}
	else {
		while (tmp->next) { //tmp->next 값이 NULL일 때까지
			tmp = tmp->next; //노드 이동
		}
		N->num = element;
		N->next = NULL;
		tmp->next = N;
	}
}

int subset(list* A, list* B) {
	int set = 0;

	node* tmpA = A->header;
	node* tmpB = B->header;

	while (1) {
		if (tmpA == NULL) {
			break;
		}
		if (tmpB == NULL || tmpA->num < tmpB->num) {
			set = tmpA->num;
			return set;
		}
		else if (tmpA->num > tmpB->num) {
			tmpB = tmpB->next;
		}
		else if (tmpA->num == tmpB->num) {
			tmpA = tmpA->next;
			tmpB = tmpB->next;
		}
		else if (tmpA == NULL) {
			return 0;
		}
	}
	return 0;
}
