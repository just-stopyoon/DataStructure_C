#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int sum(int n);

int main() {
	int N, result = 0;
	scanf("%d", &N);
	result = sum(N);
	printf("%d", result);
}

int sum(int n) {
	if (n == 1) {
		return n;
	}
	else {
		return n + sum(n - 1);
	}
}