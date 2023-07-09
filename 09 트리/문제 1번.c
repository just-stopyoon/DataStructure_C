#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int data;
	struct Node* left, * right;
}node;

node* makeNode(int data, node* left, node* right);
void print(node* p);

int main() {
	node *F8 = makeNode(80, NULL , NULL);
	node* F7 = makeNode(130, NULL, NULL);
	node* F6 = makeNode(120, F7, F8);
	node* F5 = makeNode(90, NULL, NULL);
	node* F4 = makeNode(70, NULL, NULL);
	node* F3 = makeNode(50, NULL, F6);
	node* F2 = makeNode(30, F4, F5);
	node* F1 = makeNode(20, F2, F3);
	int n;
	scanf("%d", &n);
	if (n == 1)
		print(F1);
	else if (n == 2)
		print(F2);
	else if (n == 3)
		print(F3);
	else if (n == 4)
		print(F4);
	else if (n == 5)
		print(F5);
	else if (n == 6)
		print(F6);
	else if (n == 7)
		print(F7);
	else if (n == 8)
		print(F8);
	else
		printf("-1");
}

node* makeNode(int data, node* left, node* right) {
	node* N = (node*)malloc(sizeof(node));
	N->data = data;
	N->left = left;
	N->right = right;
	return (N);
}

void print(node* N) {
	printf("%d ", N->data);
	if (N->left != NULL) {
		printf("%d ", N->left->data);
	}
	if (N->right != NULL) {
		printf("%d ", N->right->data);
	}
}