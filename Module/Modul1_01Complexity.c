/*
 * Implementasi ADT Stack (Stack menggunakan Linked List) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
    int smallest;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);
int stack_smallest(Stack *stack);

void stack_init(Stack *stack) {
    stack->_size = 0;
    stack->_top = NULL;
    stack->smallest = __INT_MAX__;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        if (value < stack->smallest) stack->smallest = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) {
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack) {
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int stack_smallest(Stack *stack) {
    return stack->smallest;
}

int main(int argc, char const *argv[]) {
    Stack myStack;
    stack_init(&myStack);

    stack_push(&myStack, 1423);
    stack_push(&myStack, -133);
    stack_push(&myStack, 0);
    printf("Smallest: %d\n", stack_smallest(&myStack));

    while (!stack_isEmpty(&myStack)) {
        printf("%d ", stack_top(&myStack));
        stack_pop(&myStack);
    }
    return 0;
}