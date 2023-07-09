#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N, M;
	int arr[101][101];

	scanf("%d %d", &N, &M);
	int remN = N;
	int remM = M;

	int num = 2;
	int x = 0, y = 0;
	arr[0][0] = 1;

	for (int i = 1; i < M; i++) {
		x = 0;
		y = i;
		while(y > -1 && x < N) {
			arr[x][y] = num;
			x++;
			y--;
			num++;
		}
	}

	for (int i = 1; i < N; i++) {
		x = i;
		y = M - 1;
		while (x < N && y > -1) {
			arr[x][y] = num;
			x++;
			y--;
			num++;
		}
	}

	for (int i = 0; i < remN; i++) {
		for (int j = 0; j < remM; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}
}