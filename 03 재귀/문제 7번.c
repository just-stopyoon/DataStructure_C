#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findchar(char x[], char c, int cnt, int len);

int main() {
	char x[101]; //영어 문자열
	char c; //특정 문자
	scanf("%s", x);
	getchar();
	int len = strlen(x); //문자열 길이
	scanf("%c", &c);
	int cnt = 0; //특정 문자 개수
	cnt = findchar(x, c, cnt, len);
	printf("%d", cnt);
}

int findchar(char x[], char c, int cnt, int len) {
	if (len == 1) {
		if (x[0] == c) {
			cnt++;
		}
		return cnt;
	}
	else {
		if (x[len - 1] == c) {
			return 1 + findchar(x, c, cnt, len-1);
		}
		else {
			return 0 + findchar(x, c, cnt, len-1);
		}
	}
}