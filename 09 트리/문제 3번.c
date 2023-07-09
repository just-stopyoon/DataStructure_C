#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* makeNode(int data);
Node* findNode(Node* p, int d);
void connectNode(Node *p, int d, int L, int R);

int main() {
    int n;
    scanf("%d", &n);
    int M, L, R;
    scanf("%d %d %d", &M, &L, &R);
    Node* root = makeNode(M);
    connectNode(root, M, L, R);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d %d %d", &M, &L, &R);
        connectNode(root, M, L, R);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        char arr[101] = { 0 };
        scanf("%s", arr);
        int len = strlen(arr);
        Node* tmp = root;
        printf(" %d", root->data);
        for (int i = 0; i < len; i++) {
            if (arr[i] == 'L') {
                tmp = tmp->left;
                printf(" %d", tmp->data);
            }
            else if (arr[i] == 'R') {
                tmp = tmp->right;
                printf(" %d", tmp->data);
            }
        }
    }
}

Node* makeNode(int data) {
    Node* N = (Node*)malloc(sizeof(Node));
    N->data = data;
    N->left = NULL;
    N->right = NULL;
    return N;
}

Node* findNode(Node* p, int d) {
    if (!p || p->data == d)
        return p;
    Node* tmp = findNode(p->left, d);
    if (tmp != NULL)
        return tmp;
    return findNode(p->right, d);
}

void connectNode(Node* root, int d, int L, int R) {
    Node* p = findNode(root, d);
    if (L != 0)
        p->left = makeNode(L);
    if (R != 0)
        p->right = makeNode(R);
}