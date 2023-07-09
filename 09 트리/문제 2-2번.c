#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(int id, int data, Node* left, Node* right);
Node* findNode(Node* p, int id);
int preorder(Node* p);

int main() {
    Node* F8 = makeNode(8, 80, NULL, NULL);
    Node* F7 = makeNode(7, 130, NULL, NULL);
    Node* F6 = makeNode(6, 120, F7, F8);
    Node* F5 = makeNode(5, 90, NULL, NULL);
    Node* F4 = makeNode(4, 70, NULL, NULL);
    Node* F3 = makeNode(3, 50, NULL, F6);
    Node* F2 = makeNode(2, 30, F4, F5);
    Node* F1 = makeNode(1, 20, F2, F3);
    Node* tree = F1;
    int nodeID;
    scanf("%d", &nodeID);
    Node* tmp = findNode(tree, nodeID);
    if (tmp == NULL)
        printf("-1");
    int result = preorder(tmp);
    if (result == 0) {
        exit(1);
    }
    printf("%d", result);
}

Node* makeNode(int id, int data, Node* left, Node* right) {
    Node* N = (Node*)malloc(sizeof(Node));
    N->id = id;
    N->data = data;
    N->left = left;
    N->right = right;
    return N;
}

Node* findNode(Node* p, int id) {
    if (p == NULL) {
        return NULL;
    }
    if (p->id == id) {
        return p;
    }
    Node* leftResult = findNode(p->left, id);
    if (leftResult != NULL) {
        return leftResult;
    }
    Node* rightResult = findNode(p->right, id);
    if (rightResult != NULL) {
        return rightResult;
    }
    return NULL;
}

int preorder(Node* p) {
    int total = 0;
    if (p != NULL) {
        total = total + p->data;
        total = total + preorder(p->left);
        total = total + preorder(p->right);
    }
    return total;
}