/* 
Auth: Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem: A stack, S1, contains some numbers in arbitrary order. Using another stack, S2, for temporary \
storage, show how to sort the numbers in S1 such that the smallest is at the top of S1 and the largest \
is at the bottom.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define t printf("test\n");

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack) {
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
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

void stack_print(Stack *stack) {
    StackNode *i;
    for (i = stack->_top; i != NULL; i = i->next) {
        printf("%d ", i->data);
    }
    printf("\n");
}

void stack_sort(Stack *s1, Stack *s2) {
    // t
    int temp;
    while (!stack_isEmpty(s1)) {
        temp = stack_top(s1);
        stack_pop(s1);

        while (!stack_isEmpty(s2) && temp < stack_top(s2)) {
            stack_push(s1, stack_top(s2));
            stack_pop(s2);
        }
        stack_push(s2, temp);
    }
    while (!stack_isEmpty(s2)) {
        stack_push(s1, stack_top(s2));
        stack_pop(s2);
    }
}

int main(int argc, char const *argv[]) {
    Stack stack, temp;
    stack_init(&temp);
    stack_init(&stack);

    stack_push(&stack, 72);
    stack_push(&stack, 4);
    stack_push(&stack, 57);
    stack_push(&stack, -2);
    stack_push(&stack, 35);
    stack_push(&stack, 23);
    stack_push(&stack, 5);
    stack_push(&stack, 73);
    stack_push(&stack, -55);
    stack_push(&stack, 54);
    stack_push(&stack, 78);
    stack_push(&stack, 28);

    printf("Unsorted :\n");
    stack_print(&stack);

    stack_sort(&stack, &temp);
    printf("Sorted: \n");
    stack_print(&stack);

    return 0;
}