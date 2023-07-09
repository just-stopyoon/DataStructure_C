#pragma warning(disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
   int coef; //항의 계수
   int exp; //항의 차수
   struct Node* next; //다음 노드를 가리키는 링크
}node;

typedef struct List {
   node* header;
}list;

void init(list* L);
void add(list* L, int coef, int exp);
list* addpoly(list* L1, list* L2);
void print(list* L);

int main() {
   list L1, L2;
   init(&L1);
   init(&L2);
   int n1;
   scanf("%d", &n1); //첫 번째 다항식의 항의 개수
   for (int i = 0; i < n1; i++) { //리스트 만들기
      int coef, exp;
      scanf("%d %d", &coef, &exp);
      add(&L1, coef, exp);
   }
   int n2;
   scanf("%d", &n2); //두 번째 다항식의 항의 개수
   for (int i = 0; i < n2; i++) { //리스트 만들기
      int coef, exp;
      scanf("%d %d", &coef, &exp);
      add(&L2, coef, exp);
   }
   list *result = addpoly(&L1, &L2);
   print(result);
}

void init(list* L) {
   L->header = (node*)malloc(sizeof(node));
   L->header->next = NULL;
}

void add(list* L, int coef, int exp) {
   node* tmp = L->header; //임의의 노드 포인터 생성 (위치 이동용)
   while(tmp->next) { //tmp->next 값이 NULL일 때까지
      tmp = tmp->next; //노드 이동
   }
   node* N = (node*)malloc(sizeof(node)); //넣을 노드 생성
   N->coef = coef; //원소 넣어주기
   N->exp = exp; //원소 넣어주기
   N->next = NULL; //맨 마지막에 넣는 것이므로
   tmp->next = N; //기존 연결리스트의 마지막 노드에 생성한 노드 연결
}

list* addpoly(list* L1, list* L2) {
   list* result = (node*)malloc(sizeof(node));
   init(result);
   node* tmp1 = L1->header->next;
   node* tmp2 = L2->header->next;
   while (1) {
      if ((tmp1 == NULL) && (tmp2 == NULL)) {
         return (result);
      }
      else if (tmp1 == NULL) {
         add(result, tmp2->coef, tmp2->exp);
         tmp2 = tmp2->next;
      }
      else if (tmp2 == NULL) {
         add(result, tmp1->coef, tmp1->exp);
         tmp1 = tmp1->next;
      }
      else if (tmp1->exp > tmp2->exp) {
         add(result, tmp1->coef, tmp1->exp);
         tmp1= tmp1->next;
      }
      else if (tmp1->exp < tmp2->exp) {
         add(result, tmp2->coef, tmp2->exp);
         tmp2 = tmp2->next;
      }

      else if ((tmp1->exp) == (tmp2->exp)) {
         if ((tmp1->coef + tmp2->coef) == 0) {
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
            continue;
         }
         add(result, tmp1->coef+tmp2->coef, tmp1->exp);
         tmp1 = tmp1->next;
         tmp2 = tmp2->next;
      }
   }
   return(result);
}

void print(list* L) {
   node* N = L->header->next;
   for (;;) {
      if (N == NULL) {
         break;
      }
      printf(" %d %d", N->coef, N->exp);
      N = N->next;
   }
}