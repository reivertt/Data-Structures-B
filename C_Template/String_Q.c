/*
 * Implementasi ADT Queue (Queue menggunakan Linked List) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct queueNode_t {
    char data[100];
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, char value[]);
void queue_pop(Queue *queue);
char* queue_front(Queue *queue);
int queue_size(Queue *queue);

void queue_init(Queue *queue) {
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, char value[]) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        strcpy(newNode->data, value);
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        printf("Pop: %c%s%c\n", 34, queue->_front->data, 34);
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

char* queue_front(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[]) {
    Queue myQueue;
    queue_init(&myQueue);

    queue_push(&myQueue, "Alpha");
    queue_push(&myQueue, "Bravo");
    queue_push(&myQueue, "Charlie");

    while (!queue_isEmpty(&myQueue)) {
        queue_pop(&myQueue);
    }
    return 0;
}