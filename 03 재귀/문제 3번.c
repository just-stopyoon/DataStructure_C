#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void lowernum(int n);

int main() {
	int num;
	scanf("%d", &num);
	lowernum(num);
}

void lowernum(int n) {
	if (n < 10) {
		printf("%d", n);
	}
	else {
		printf("%d\n", n % 10);
		lowernum(n / 10);
	}
}