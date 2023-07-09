#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

void swap(int* p, int* q);

int main() {
	int N;
	int arr[51];
	int a, b;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &a, &b);
	swap(arr + a, arr + b);
	
	for (int i = 0; i < N; i++) {
		printf(" %d", arr[i]);
	}
}

void swap(int* p, int* q) {
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
