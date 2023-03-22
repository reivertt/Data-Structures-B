/*
 * Implementasi ADT Stack (Stack menggunakan Linked List) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct stackNode_t {
    char data[100];
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value[]);
void stack_pop(Stack *stack);
char* stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack) {
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value[]) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        strcpy(newNode->data, value);
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) {
    if (!stack_isEmpty(stack)) {
        printf("Pop: %c%s%c\n", 34, stack->_top->data, 34);
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

char* stack_top(Stack *stack) {
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[]) {
    Stack myStack;
    stack_init(&myStack);

    stack_push(&myStack, "Alpha");
    stack_push(&myStack, "Bravo");
    stack_push(&myStack, "Charlie");
    stack_push(&myStack, "Delta");

    while (!stack_isEmpty(&myStack)) {
        stack_pop(&myStack);
    }
    return 0;
}