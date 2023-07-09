#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N;
	scanf("%d", &N);

	int x[101];
	for (int* p = x; p < x + N; p++) {
		scanf("%d", p);
	}

	int M;
	scanf("%d", &M);

	int a[101];
	for (int* p = a; p < a + M; p++) {
		scanf("%d", p);
	}

	int cnt = 0;
	int prev = x[a[0]];
	int next = x[a[1]];

	for (int i = 0; i < M - 1; i++) {
		next = x[a[cnt + 1]];
		x[a[cnt + 1]] = prev;
		prev = next;
		cnt++;
	}

	for (int* p = x; p < x + N; p++) { 
		printf(" %d", *p);
	}
}