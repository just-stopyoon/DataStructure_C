#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int maxnum(int n, int x[]);

int main() {
	int N;
	int x[20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x[i]);
	}
	int max = 0;
	max = maxnum(N, x);
	printf("%d", max);
}

int maxnum(int n, int x[]) {
	if (n == 1) {
		return x[0];
	}
	else {
		if (x[n - 1] > maxnum(n-1, x)) {
			return x[n - 1];
		}
		else {
			return maxnum(n-1, x);
		}
	}
}