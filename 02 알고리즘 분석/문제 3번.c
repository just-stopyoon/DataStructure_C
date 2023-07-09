#pragma warning (disable : 4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int* prefixAverages1(int* x, int n);
int* prefixAverages2(int* x, int n);

int main() {
	int n;
	scanf("%d", &n);

	int* X = (int*)malloc(n * sizeof(int));
	if (X == NULL) {
		printf("X ERROR");
		exit(1);
	}
	int* A = (int*)malloc(n * sizeof(int));
	if (A == NULL) {
		printf("A ERROR");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &X[i]);
	}
	A = prefixAverages1(X, n);

	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");

	A = prefixAverages2(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}
	free(X);
	free(A);
}
int* prefixAverages1(int* x, int n) {
	double sum = 0;
	int* A = (int*)malloc(n * sizeof(int));
	if (A == NULL) {
		printf("A ERROR");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j <= i; j++) {
			sum = sum + x[j];
		}
		A[i] = (int)((sum / (i + 1)) + 0.5);
	}
	return A;
}
int* prefixAverages2(int* x, int n) {
	double sum = 0;
	int* A = (int*)malloc(n * sizeof(int));
	if (A == NULL) {
		printf("A ERROR");
		exit(1);
	}
	for (int i = 0; i < n; i++) {
		sum = sum + x[i];
		A[i] = (int)((sum / (i + 1)) + 0.5);
	}
	return A;
}