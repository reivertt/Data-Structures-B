/*
 * Implementasi ADT PriorityQueue menggunakan Linked List oleh Bayu Laksana
 * [default: minimum priority]
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct pqueueNode_t {
    int data, priority;
    struct pqueueNode_t *next;
} PQueueNode;

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, int data, int priority);
int pqueue_pop(PriorityQueue *pqueue);
int  pqueue_top(PriorityQueue *pqueue);

void pqueue_init(PriorityQueue *pqueue) {
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, int data, int priority) {
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode*) malloc (sizeof(PQueueNode));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }

    if (priority > pqueue->_top->priority) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && temp->next->priority > priority)
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
    else return 0;
}

int pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

int main(int argc, char const *argv[]) {
    PriorityQueue myPque;
    pqueue_init(&myPque);

    char action[10];
    int id, x, Q;
    scanf("%d", &Q);
    while (Q--){
        scanf("%s", action);

        if (!strcmp(action, "MASUK")){
            scanf("%d %d", &id, &x);
            pqueue_push(&myPque, id, x);
        }
        else if (!strcmp(action, "LAYANI")){
            printf("%d\n", pqueue_pop(&myPque));
        }
    }
    if (pqueue_isEmpty(&myPque)) printf("HORE");
    
    return 0;
}