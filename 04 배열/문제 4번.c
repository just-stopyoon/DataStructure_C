#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N, M;
	int x[101][101];

	scanf("%d %d", &N, &M);
	int remN = N;
	int remM = M;

	int a = 0, b = -1;
	int num = 1;

	while (1) {
		if (num > remN * remM) {
			break;
		}
		for (int i = 0; i < M; i++) {
			b++;
			x[a][b] = num;
			num++;
		}
		M--;

		for (int i = 0; i < N - 1; i++) {
			a++;
			x[a][b] = num;
			num++;
		}
		N--;
		if (num > remN * remM) {
			break;
		}
		for (int i = 0; i < M; i++) {
			b--;
			x[a][b] = num;
			num++;
		}
		M--;
		for (int i = 0; i < N - 1; i++) {
			a--;
			x[a][b] = num;
			num++;
		}
		N--;
	}

	for (int i = 0; i < remN; i++) {
		for (int j = 0; j < remM; j++) {
			printf(" %d", x[i][j]);
		}
		printf("\n");
	}
}