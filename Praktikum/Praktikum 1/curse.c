/**
 * Implementasi ADT PriorityQueue menggunakan Linked List
 * [default: minimum priority]
 *
 * Dibuat dan ditulis oleh Bayu Laksana
 * -- tanggal 22 Januari 2019
 * Struktur Data 2020
 * Implementasi untuk bahasa C
 *
 * !!NOTE!!
 * cara menggunakan lihat pada fungsi main()
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Struktur Node */

typedef struct pqueueNode_t {
  int data;
  struct pqueueNode_t *next;
} PQueueNode;

/* Struktur ADT PriorityQueue menggunakan Linked List */

// Prioritas default: nilai maximum
typedef struct pqueue_t {
  PQueueNode *_top;
  unsigned _size;
} PriorityQueue;

/* Function prototype */

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int value);
int pqueue_pop(PriorityQueue *pqueue);
int pqueue_top(PriorityQueue *pqueue);

/* Function definition below */

void pqueue_init(PriorityQueue *pqueue) {
  pqueue->_top = NULL;
  pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) { return (pqueue->_top == NULL); }

void pqueue_push(PriorityQueue *pqueue, int value) {
  PQueueNode *temp = pqueue->_top;
  PQueueNode *newNode = (PQueueNode *)malloc(sizeof(PQueueNode));
  newNode->data = value;
  newNode->next = NULL;

  if (pqueue_isEmpty(pqueue)) {
    pqueue->_top = newNode;
    return;
  }

  if (value > pqueue->_top->data) {
    newNode->next = pqueue->_top;
    pqueue->_top = newNode;

  } else {
    while (temp->next != NULL && temp->next->data > value)
      temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
  }
}

int pqueue_pop(PriorityQueue *pqueue) {
  if (!pqueue_isEmpty(pqueue)) {
    PQueueNode *temp = pqueue->_top;
    int data = pqueue->_top->data;
    pqueue->_top = pqueue->_top->next;
    free(temp);
    return data;
  }
  return 0;
}

int pqueue_top(PriorityQueue *pqueue) {
  if (!pqueue_isEmpty(pqueue))
    return pqueue->_top->data;
  else
    return 0;
}

int main(int argc, char const *argv[]) {
  PriorityQueue myPque;
  pqueue_init(&myPque);

  int n, m;
  scanf("%d", &n);
  m = n;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    pqueue_push(&myPque, x);
    if (x == m) {
        while (!pqueue_isEmpty(&myPque) && pqueue_top(&myPque) == m) {
            printf("%d ", pqueue_pop(&myPque));
            m--;
        }
    }
    printf("\n");
  }
  return 0;
}

