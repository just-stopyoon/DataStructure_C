#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N;
	scanf("%d", &N);

	int x[101][101];

	int num = 1;

	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < N; j++) {
				x[i][j] = num;
				num++;
			}
		}
		else {
			for (int j = N - 1; j >= 0; j--) {
				x[i][j] = num;
				num++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}
}