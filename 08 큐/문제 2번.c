#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int element;
    struct Node* prev;
    struct Node* next;
} node;

typedef struct Deque {
    node* front;
    node* rear;
} deque;

void initDeque(deque* d);
void add_front(deque* d, int X);
void add_rear(deque* d, int X);
void delete_front(deque* d);
void delete_rear(deque* d);
void print(deque* d);

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    deque d;
    initDeque(&d);
    for (int i = 0; i < n; i++) {
        char command[3];
        scanf("%s", command);
        getchar();
        if (strcmp(command, "AF") == 0) {
            int e;
            scanf("%d", &e);
            add_front(&d, e);
        }
        else if (strcmp(command, "AR") == 0) {
            int e;
            scanf("%d", &e);
            getchar();
            add_rear(&d, e);
        }
        else if (strcmp(command, "DF") == 0) {
            delete_front(&d);
        }
        else if (strcmp(command, "DR") == 0) {
            delete_rear(&d);
        }
        else if (strcmp(command, "P") == 0) {
            print(&d);
        }
    }
}

void initDeque(deque* d) {
    d->front = NULL;
    d->rear = NULL;
}

void add_front(deque* d, int X) {
    node* N = (node*)malloc(sizeof(node));
    N->element = X;
    N->next = d->front;
    N->prev = NULL;
    if (d->front == NULL) {
        d->front = N;
        d->rear = N;
    }
    else {
        d->front->prev = N;
        d->front = N;
    }
}

void add_rear(deque* d, int X) {
    node* N = (node*)malloc(sizeof(node));
    N->element = X;
    N->prev = d->rear;
    N->next = NULL;
    if (d->rear == NULL) {
        d->front = N;
        d->rear = N;
    }
    else {
        d->rear->next = N;
        d->rear = N;
    }
}

void delete_front(deque* d) {
    if (d->front == NULL) {
        printf("underflow");
        exit(1);
    }
    node* tmp = d->front;
    d->front = d->front->next;
    if (d->front != NULL)
        d->front->prev = NULL;
    else
        d->rear = NULL;
    free(tmp);
}

void delete_rear(deque* d) {
    if (d->rear == NULL) {
        printf("underflow");
        exit(1);
    }
    node* tmp = d->rear;
    d->rear = d->rear->prev;
    if (d->rear != NULL)
        d->rear->next = NULL;
    else
        d->front = NULL;
    free(tmp);
}

void print(deque* d) {
    node* N = d->front;
    while (N != NULL) {
        printf(" %d", N->element);
        N = N->next;
    }
    printf("\n");
}