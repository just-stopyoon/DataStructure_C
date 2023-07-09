#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ArrayStack { //스택의 기본 요소
	char* arr; //배열의 크기를 모르니깐, 포인터로 선언
	int top; 
	int N; //배열 크기
}stack;

void initStack(stack* s, int n); //스택 초기화, n은 배열의 크기
void push(stack* s, char element); //스택에 추가
char pop(stack* s); //하나 출력 후 삭제
char peek(stack* s); //top이라고도 씀
void duplicate(stack* s); //top에 있는 데이터를 pop해서 두번 push;
void upRotate(stack* s, int n); //top부터 n개의 데이터를 회전
void downRotate(stack* s, int n); //
void print(stack* s);

int main() {
	stack s;
	int N, cnt = 0;
	char arr[10];

	scanf("%d", &N);
	initStack(&s, N);
	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%s", arr);
		if (strcmp(arr, "POP") == 0) {
			pop(&s);
		}
		else if (strcmp(arr, "PUSH") == 0) {
			char e;
			getchar();
			scanf("%c", &e);
			push(&s, e);
		}
		else if (strcmp(arr, "PEEK") == 0) {
			char element = peek(&s);
			if (element != -1) {
				printf("%c", element);
			}
		}
		else if (strcmp(arr, "DUP") == 0) {
			duplicate(&s);
		}
		else if (strcmp(arr, "UpR") == 0) {
			int n;
			scanf("%d", &n);
			upRotate(&s, n);
		}
		else if (strcmp(arr, "DownR") == 0) {
			int n;
			scanf("%d", &n);
			downRotate(&s, n);
		}
		else if (strcmp(arr, "PRINT") == 0) {
			print(&s);
		}
	}
	return 0;
}

void initStack(stack* s, int n) {
	s->arr = (char*)malloc(sizeof(char) * n); //배열 동적할당
	s->top = -1; //top은 항상 -1로 초기화
	s->N = n; //배열 크기로 할당
}

void push(stack* s, char element) {
	if (s->top == s->N - 1) { //top이 배열의 크기와 같을 때
		printf("Stack FULL\n"); //더 넣을 수 없으므로 오류
		return -1;
	}
	
	s->top++; //top을 한 칸 옮겨줌
	s->arr[s->top] = element; //원소 삽입
}

char pop(stack* s) {
	if (s->top == -1) { //더 이상 삭제할 게 없을 때
		printf("Stack Empty\n"); //아무것도 없을 때
		return -1;
	}
	s->top--;//top을 한 칸 왼쪽으로 가면서 삭제할 필요가 없음
	return (s->arr[s->top + 1]); //옮겨줬으므로 top 다음 것을 출력함
}

char peek(stack* s) {
	if (s->top == -1) { //더 이상 삭제할 게 없을 때
		printf("Stack Empty\n"); //아무것도 없을 때
		return -1;
	}
	return (s->arr[s->top]); //top꺼를 출력
}

void duplicate(stack* s) {
	if (s->top == s->N - 1) { //top이 배열의 크기와 같을 때
		printf("Stack FULL\n"); //더 넣을 수 없으므로 오류
		return -1;
	}
	char element = pop(s);
	push(s, element);
	push(s, element);
}

void upRotate(stack* s, int n) {
	int t = s->top;
	if (n <= s->top + 1) {
		char tmp = s->arr[s->top];
		for (int i = 0; i < n-1; i++) { //n-1번 반복해줘야하므로
			s->arr[t] = s->arr[t - 1]; //밑에꺼를 위로
			t--;
		}
		s->arr[t] = tmp; //저장해둔 top 값을 넣어줌
	}
}

void downRotate(stack* s, int n) {
	if (n <= s->top + 1) {
		char tmp = s->arr[s->top - n + 1];
		for (int i = s->top - n + 1; i < s->top; i++) {
			s->arr[i] = s->arr[i + 1];
		}
		s->arr[s->top] = tmp;
	}
}

void print(stack* s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%c", s->arr[i]);
	}
	printf("\n");
}