#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char* arr;
    int top;
} stack;

void initStack(stack* s);
void push(stack* s, char element);
char pop(stack* s);
char peek(stack* s);
int isEmpty(stack* s);
int isOperand(char element);
int findRank(char c);
void print(char c);
void convert(char* arr);

int main() {
    int N;
    scanf("%d", &N);
    char arr[101];
    for (int i = 0; i < N; i++) {
        scanf("%s", arr);
        convert(arr);
    }
    return (0);
}

//스택 초기화
void initStack(stack* s) {
    s->arr = (char*)malloc(sizeof(char) * 100);
    s->top = -1;
}
//스택에 하나씩 추가
void push(stack* s, char element) {
    s->top++;
    s->arr[s->top] = element;
}
//하나 출력 후 삭제
char pop(stack* s) {
    s->top--;
    return (s->arr[s->top + 1]);
}
//top 위치 반환
char peek(stack* s) {
    return (s->arr[s->top]);
}
//오류 확인
int isEmpty(stack* s) {
    return (s->top == -1);
}
//문자 반환
int isOperand(char element) {
    return (element >= 'A' && element <= 'Z');
}
//수식의 우선순위 찾기
int findRank(char c) {
    if (c == '*')
        return 5;
    else if (c == '/')
        return 5;
    else if (c == '+')
        return 4;
    else if (c == '-')
        return 4;
    else if (c == '>')
        return 3;
    else if (c == '<')
        return 3;
    else if (c == '&')
        return 2;
    else if (c == '|')
        return 1;
    else if (c == '(' || c == ')')
        return 0;
}
//출력 함수
void print(char c) {
    if (c == '|' || c == '&')
        printf("%c%c", c, c);
    else if (c == 'p')
        printf("+");
    else if (c == 'm')
        printf("-");
    else
        printf("%c", c);
}
//후위수식으로 변환
void convert(char* arr) {
    stack* s = (stack*)malloc(sizeof(stack));
    initStack(s);
    for (int i = 0; arr[i]; i++) {
        char c = arr[i];
        if (isOperand(c))
            print(c);
        else if (c == '(')
            push(s, c);
        else if (c == ')') {
            while (s->arr[s->top] != '(')
                print(pop(s));
            pop(s);
        }
        else if ((c == '+' || c == '-') && (i == 0 || (!isOperand(arr[i - 1]) && arr[i - 1] != ')'))) {
            while (!isEmpty(s) && 6 <= findRank(peek(s)))
                print(pop(s));
            if (c == '+')
                push(s, 'p');
            else
                push(s, 'm');
        }
        else {
            while (!isEmpty(s) && findRank(c) <= findRank(peek(s)))
                print(pop(s));
            push(s, c);
            if (c == '|' || c == '&')
                i++;
        }
    }
    while (!isEmpty(s))
        print(pop(s));
    printf("\n");
}