/**
 * Implementasi ADT PriorityQueue menggunakan Linked List oleh Bayu Laksana
 * [setting: lexicographical order]
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct pqueueNode_t {
    char data[100];
    struct pqueueNode_t *next;
} PQueueNode;

// Prioritas default: nilai minimum
typedef struct pqueue_t {
    PQueueNode *_top;
    unsigned _size;
} PriorityQueue;

void pqueue_init(PriorityQueue *pqueue);
bool pqueue_isEmpty(PriorityQueue *pqueue);
void pqueue_push(PriorityQueue *pqueue, char value[]);
void pqueue_pop(PriorityQueue *pqueue);
char*  pqueue_top(PriorityQueue *pqueue);

void pqueue_init(PriorityQueue *pqueue) {
    pqueue->_top = NULL;
    pqueue->_size = 0;
}

bool pqueue_isEmpty(PriorityQueue *pqueue) {
    return (pqueue->_top == NULL);
}

void pqueue_push(PriorityQueue *pqueue, char value[]) {
    PQueueNode *temp = pqueue->_top;
    PQueueNode *newNode = (PQueueNode*) malloc (sizeof(PQueueNode));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (pqueue_isEmpty(pqueue)) {
        pqueue->_top = newNode;
        return;
    }
    
    if (strcmp(value, pqueue->_top->data) < 0) {
        newNode->next = pqueue->_top;
        pqueue->_top = newNode;
    }
    else {
        while ( temp->next != NULL && strcmp(value, pqueue->_top->data) < 0)
            temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void pqueue_pop(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue)) {
        printf("Pop: %c%s%c\n", 34, pqueue->_top->data, 34);
        PQueueNode *temp = pqueue->_top;
        pqueue->_top = pqueue->_top->next;
        free(temp);
    }
}

char* pqueue_top(PriorityQueue *pqueue) {
    if (!pqueue_isEmpty(pqueue))
        return pqueue->_top->data;
    else return 0;
}

int main(int argc, char const *argv[]) {
    PriorityQueue myPque;
    pqueue_init(&myPque);

    pqueue_push(&myPque, "aaa");
    pqueue_push(&myPque, "bbb");
    pqueue_push(&myPque, "AAA");
    pqueue_push(&myPque, "BBB");

    while (!pqueue_isEmpty(&myPque)) {
        pqueue_pop(&myPque);
    }
    return 0;
}