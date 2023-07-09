#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// (rear + 1) / N
typedef struct ArrayQueue { //큐의 기본 요소
	int* arr; //입력 받을 배열
	int front; 
	int rear; //stack 의 top과 동일
	int size; //배열 크기
}Queue;

void initQueue(Queue* q); //Queue 초기화 
void enQueue(Queue* q, int element); //Queue 추가
void deQueue(Queue* q); //Queue 삭제
void print(Queue* q); //Queue 프린트

int main() {
	int n;
	Queue Q;
	initQueue(&Q);
	scanf("%d", &n); //연산의 개수
	getchar();
	for (int i = 0; i < n; i++) {
		char commend;
		int num;
		scanf("%c", &commend);
		getchar();
		if (commend == 'I') {
			scanf("%d", &num);
			getchar();
			enQueue(&Q, num);
		}
		else if (commend == 'D') {
			deQueue(&Q);
		}
		else if (commend == 'P') {
			print(&Q);
		}
	}
}

void initQueue(Queue* q) {
	scanf("%d", &q->size); //q->size == n 원형 큐의 크기
	getchar();
	q->arr = (int*)calloc(q->size, sizeof(int));
	q->front = 0;
	q->rear = 0;
}

void enQueue(Queue* q, int element) {
	if ((q->rear + 1) % (q->size) == q->front) { //양수를 이용하기 위해
		printf("overflow");
		print(q);
	}
	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = element;
}

void deQueue(Queue* q) {
	if (q->rear == q->front) {
		printf("underflow");
		exit(1);
	}
	q->front++;
	q->arr[q->front] = 0;
}

void print(Queue* q) {
	for (int i = 0; i < q->size; i++) {
		printf(" %d", q->arr[i]);
	}
	printf("\n");
}
