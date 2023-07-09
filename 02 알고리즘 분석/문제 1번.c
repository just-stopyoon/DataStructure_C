#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int modulo(int a, int b);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", modulo(a, b));
}

int modulo(int a, int b) {
	int result = a;
	while (result >= b) {
		result -= b;
	}
	return result;
}