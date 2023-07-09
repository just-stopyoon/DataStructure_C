#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

struct student {
	char name[10];
	int score;
};

int main() {
	struct student st[5];
	int average = 0;
	for (struct student* p = st; p < st + 5; p++) {
		scanf("%s %d", (*p).name, &(*p).score);
		average = average + (*p).score;
	}
	average = average / 5;

	for (struct student* p = st; p < st + 5; p++) {
		if ((*p).score <= average)
			printf("%s\n", (*p).name);
	}
}