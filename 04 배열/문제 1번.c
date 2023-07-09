#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N; //수열의 길이
	scanf("%d", &N);

	int x[101]; //수열 x
	for (int *p = x ; p < x + N ;p++) {
		scanf("%d", p);
	}

	int M; //뒤집기 정보의 개수
	scanf("%d", &M);

	int a[101], b[101];
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a[i], &b[i]); //뒤집기 구간 정보
	}

	for (int i = 0; i < M; i++) {
		int gap = b[i] - a[i] + 1; //구간 넓이
		int cnt = 0; //몇 개
		if ((gap) % 2 == 1) { //구간이 홀수일 때
			gap = (gap / 2) + 1; //홀수로 구간
			for (int j = 0; j < gap; j++) {
				int tmp = x[a[i] + cnt];
				x[a[i] + cnt] = x[b[i] - cnt];
				x[b[i] - cnt] = tmp;
				cnt++;
			}
		}
		else {
			gap = gap / 2;
			for (int j = 0; j < gap; j++) {
				int tmp = x[a[i] + cnt];
				x[a[i] + cnt] = x[b[i] - cnt];
				x[b[i] - cnt] = tmp;
				cnt++;
			}
		}
	}
	for (int* p = x; p < x + N; p++) {
		printf(" %d", *p);
	}
}