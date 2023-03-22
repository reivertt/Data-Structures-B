/*
 * Implementasi ADT Deque (Double-ended Queue) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct dnode_t {
    char data[100];
    struct dnode_t *next, *prev;
} DListNode;

typedef struct deque_t {
    DListNode *_head, *_tail;
    unsigned _size;
} Deque;

DListNode* __dlist_createNode(char value[]);
void deq_init(Deque *deque);
bool deq_isEmpty(Deque *deque);
void deq_pushFront(Deque *deque, char value[]);
void deq_pushBack(Deque *deque, char value[]);
char*  deq_front(Deque *deque);
char*  deq_back(Deque *deque);
void deq_popFront(Deque *deque);
void deq_popBack(Deque *deque);

DListNode* __dlist_createNode(char value[]) {
    DListNode *newNode = (DListNode*) malloc (sizeof(DListNode));
    
    if (!newNode) return NULL;
    strcpy(newNode->data, value);
    newNode->next = NULL;
    newNode->prev = NULL;

    return (DListNode*) newNode;
}

void deq_init(Deque *deque) {
    deque->_head = deque->_tail = NULL;
    deque->_size = (unsigned) 0;
}

bool deq_isEmpty(Deque *deque) {
    return (deque->_head == NULL && deque->_tail == NULL);
}

void deq_pushFront(Deque *deque, char value[]) {
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        newNode->next = deque->_head;
        deque->_head->prev = newNode;
        deque->_head = newNode;
    }
}

void deq_pushBack(Deque *deque, char value[]) {
    DListNode *newNode = __dlist_createNode(value);
    if (newNode) {
        deque->_size++;
        if (deq_isEmpty(deque)) {
            deque->_head = newNode;
            deque->_tail = newNode;
            return;
        }

        deque->_tail->next = newNode;
        newNode->prev = deque->_tail;
        deque->_tail = newNode;
    }
}

char* deq_front(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_head->data);
    }
    return 0;
}

char* deq_back(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        return (deque->_tail->data);
    }
    return 0;
}

void deq_popFront(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        DListNode *temp = deque->_head;
        printf("Pop Front: %c%s%c\n", 34, deque->_head->data, 34);
        if (deque->_head == deque->_tail) {
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            deque->_head = deque->_head->next;
            deque->_head->prev = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

void deq_popBack(Deque *deque) {
    if (!deq_isEmpty(deque)) {
        printf("Pop Back: %c%s%c\n", 34, deque->_tail->data, 34);
        DListNode *temp;
        if (deque->_head == deque->_tail) {
            temp = deque->_head;
            deque->_head = NULL;
            deque->_tail = NULL;
            free(temp);
        }
        else {
            temp = deque->_tail;
            deque->_tail = deque->_tail->prev;
            deque->_tail->next = NULL;
            free(temp);
        }
        deque->_size--;
    }
}

int main(int argc, char const *argv[]) {
    Deque mydeq;
    deq_init(&mydeq);

    deq_pushBack(&mydeq, "One");
    deq_pushBack(&mydeq, "Twelve");
    deq_pushBack(&mydeq, "Six");
    deq_pushBack(&mydeq, "Seven");
    deq_pushBack(&mydeq, "Two");

    deq_pushFront(&mydeq, "Eleven");
    deq_pushFront(&mydeq, "Eight");
    deq_pushFront(&mydeq, "Zero");

    deq_popBack(&mydeq);
    deq_popFront(&mydeq);

    while (!deq_isEmpty(&mydeq)) {
        deq_popFront(&mydeq);
    }
    return 0;
}