#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gcd(int a, int b);

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int n = gcd(a, b);
	printf("%d", n);
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return (gcd(b, a % b));
	}
}