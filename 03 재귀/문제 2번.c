#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void highernum(int n);

int main() {
	int num;
	scanf("%d", &num);
	highernum(num);
}

void highernum(int n) {
	if (n < 10) {
		printf("%d\n", n);
	}
	else {
		highernum(n / 10);
		printf("%d\n", n % 10);
	}
}