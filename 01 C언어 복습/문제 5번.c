#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

struct time {
	int hour;
	int min;
	int sec;
};

int main() {
	struct time t[2];
	for (struct time* p = t; p < t + 2; p++) {
		scanf("%d %d %d", &(*p).hour, &(*p).min, &(*p).sec);
	}
	if (t[0].sec > t[1].sec) {
		t[1].min -= 1;
		t[1].sec += 60;
	}
	if (t[0].min > t[1].min) {
		t[1].hour -= 1;
		t[1].min += 60;
	}
	int hour = 0;
	int min = 0;
	int sec = 0;
	hour = t[1].hour - t[0].hour;
	min = t[1].min - t[0].min;
	sec = t[1].sec - t[0].sec;

	printf("%d %d %d", hour, min, sec);
}