#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arrayStack {
	char stack[1001];
	int topsize;
}arrstack;

arrstack* createStack();
int isEmpty(arrstack* s);
int isFull(arrstack* s);
void push(arrstack* s, char elem);
char pop(arrstack* s);

int main() {
	char str[1000], pop_element;
	int length, chk = 0, count = 0;
	arrstack* s;
	s = createStack();
	gets(str);
	length = strlen(str);
	for (int i = 0; i < length; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			push(s, str[i]);
			count++;
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			pop_element = pop(s);
			if (str[i] == ')') {
				if (pop_element != '(') {
					chk++;
				}
			}
			else if (str[i] == '}') {
				if (pop_element != '{') {
					chk++;
				}
			}
			else if (str[i] == ']') {
				if (pop_element != '[') {
					chk++;
				}
			}
			count++;
		}
	}
	if (chk == 0 && isEmpty(s)) {
		printf("OK_%d", count);
	}
	else {
		printf("Wrong_%d", count);
	}
	return 0;
}

arrstack* createStack(){
	arrstack* newStack;
	newStack = (arrstack*)malloc(sizeof(arrstack));
	newStack->topsize = -1;
	return newStack;
}

int isEmpty(arrstack* s){
	if (s->topsize == -1)
		return 1;
	return 0;
}

int isFull(arrstack* s){
	if (s->topsize + 1 == 1000)
		return 1;
	return 0;
}

void push(arrstack* s, char elem){
	if (isFull(s))	{
		printf("Stack Full\n");
		return;
	}
	s->stack[++s->topsize] = elem;
}

char pop(arrstack* s){
	return s->stack[s->topsize--];
}