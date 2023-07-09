#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

struct student {
	char name[8];
	int kor;
	int eng;
	int math;
	double average;
};

int main() {
	int n;
	scanf("%d", &n);

	struct student *st = (struct student*)malloc(n * sizeof(struct student));
	if (st == NULL) {
		printf("STRUCT ERROR");
		exit(1);
	}
	for (struct student * p = st; p < st + n; p++) {
		scanf("%s %d %d %d", (*p).name, &(*p).kor, &(*p).eng, &(*p).math);
		(*p).average = (*p).kor + (*p).eng + (*p).math;
		(*p).average /= 3;
	}
	for (struct student* p = st; p < st + n; p++) {
		printf("%s %.1lf", (*p).name, (*p).average);
		if ((*p).kor >= 90 || (*p).eng >= 90 || (*p).math >= 90) {
			printf(" GREAT");
		}
		if ((*p).kor < 70 || (*p).eng < 70 || (*p).math < 70) {
			printf(" BAD");
		}
		printf("\n");
	}
	free(st);
}