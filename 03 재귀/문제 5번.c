#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hanoi(int n, char from, char aux, char to);
//n : 이동해야 할 원반 수
//from : 출발
//aux : 보조
//to : 목표


int main() {
	int n;
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
}

void hanoi(int n, char from, char aux, char to) {
	if (n == 1) {
		printf("%c %c\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, aux);
		printf("%c %c\n", from, to);
		hanoi(n - 1, aux, from, to);
	}
}