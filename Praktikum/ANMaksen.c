/**
 * Implementasi ADT Queue (Queue menggunakan Linked List)
 * 
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
int queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

void queue_init(Queue *queue) {
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value) {
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

int queue_pop(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        int TempData = temp->data;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
        return TempData;
    }
    return 0;
}

int queue_front(Queue *queue) {
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[])
{
    Queue myWatchlist;
    queue_init(&myWatchlist);

    int x, y, n;
    scanf("%d %d %d", &x, &y, &n);
    for (int i = 0; i < x; i++){
        int ID;
        scanf("%d", &ID);
        queue_push(&myWatchlist, ID);
    }

    if (x < n) {
        printf("Kasian Ersya\n");
        return 0;
    }

    for (int i = 0; i < n; i++){
        queue_pop(&myWatchlist);
        for (int j = 0; j < y; j++){
            queue_push(&myWatchlist, queue_pop(&myWatchlist));
        }
    }

    printf("%d", queue_front(&myWatchlist));

    return 0;
}