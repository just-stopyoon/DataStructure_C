#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack{
    int top;
    int* arr;
} stack;

void initStack(stack* s);
void push(stack* s, int element);
int pop(stack* s);
int defineNum(char ch);
int evaluatePostfix(stack* s, char arr[]);

int main() {
    int n;
    scanf("%d", &n);
    stack s;
    initStack(&s);
    for (int i = 0; i < n; i++) {
        char arr[100];
        scanf("%s", arr);
        int result = evaluatePostfix(&s, arr);
        printf("%d\n", result);
    }
    return 0;
}

void initStack(stack* s) {
    s->arr = (int*)malloc(sizeof(int) * 100);
    s->top = -1;
}

void push(stack* s, int element) {
    s->top++;
    s->arr[s->top] = element;
}

int pop(stack* s) {
    s->top--;
    return s->arr[s->top + 1];
}

int defineNum(char c) {
    return c >= '0' && c <= '9';
}

int evaluatePostfix(stack* s, char arr[]) {
    for (int i = 0; arr[i] != '\0'; i++) {
        if (defineNum(arr[i])) {
            push(s, arr[i] - '0');
        }
        else {
            int num2 = pop(s);
            int num1 = pop(s);
            int result;

            if (arr[i] == '+') {
                result = num1 + num2;
            }
            else if (arr[i] == '-') {
                result = num1 - num2;
            }
            else if (arr[i] == '*') {
                result = num1 * num2;
            }
            else if (arr[i] == '/') {
                result = num1 / num2;
            }
            push(s, result);
        }
    }
    return pop(s);
}
