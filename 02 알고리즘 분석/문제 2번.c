#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mostOnes(int arr[101][101], int n);

int main() {
	int n;
	scanf("%d", &n);
	int arr[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d", mostOnes(arr, n));
}

int mostOnes(int arr[101][101], int n) {
	int max = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[cnt][i] == 0) {
			cnt++;
			if (arr[cnt][i] == 1) {
				max = cnt;
			}
			else {
				i = i - 1;
			}
		}
		if (cnt == n - 1) {
			break;
		}
	}
	return max;
}