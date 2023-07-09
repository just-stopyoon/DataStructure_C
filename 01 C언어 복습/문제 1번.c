#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

 int sum(int n);

int main() {
	int n;
	int total = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		total = total + sum(i);
	}
	printf("%d", total);
}
 
int sum(int n) {
	int total = 0;
	for (int i = 1; i <= n; i++) {
		total = total + i;
	}
	return total;
}