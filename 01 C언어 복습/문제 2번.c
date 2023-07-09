#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

void ABC(int arr[], int k);

int main() {
	int arr[11];
	for (int* p = arr; p < arr + 10; p++) {
		scanf("%d", p);
	}
	for (int i = 0; i < 10; i++) {
		ABC(arr, i);
	}
	for (int* p = arr; p < arr + 10; p++) {
		printf(" %d", *p);
	}
}

void ABC(int arr[], int k) {
	int max = arr[k];
	int max_i = k;
	for (int i = k; i < 10; i++) {
		if (max < arr[i]) {
			max = arr[i];
			max_i = i;
		}
	}
	int tmp = arr[k];
	arr[k] = arr[max_i];
	arr[max_i] = tmp;
}
