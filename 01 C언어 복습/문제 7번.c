int main() {
	int N;
	scanf("%d", &N);
	int *num1 = (int*)malloc(N * sizeof(int));
	int *num2 = (int*)malloc(N * sizeof(int));
	int *sumnum = (int*)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++) {
		scanf("%d",&num1[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &num2[i]);
	}
	for (int i = 0; i < N; i++) {
		sumnum[i] = num1[i] + num2[N - 1 - i];
		printf(" %d", sumnum[i]);
	}

	free(num1);
	free(num2);
	free(sumnum);

	return 0;
}