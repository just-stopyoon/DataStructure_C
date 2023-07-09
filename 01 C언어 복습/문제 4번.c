#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>

int main() {
	char test[101];
	int len = 0;
	scanf("%s", test);
	len = strlen(test);

	printf("%s\n", test);
	for (int j = 0; j < len-1; j++){
		char tmp = test[0];
		for (int i = 0; i < len - 1; i++) {
			test[i] = test[i + 1];
		}
		test[len - 1] = tmp;
		printf("%s\n", test);
	}
}