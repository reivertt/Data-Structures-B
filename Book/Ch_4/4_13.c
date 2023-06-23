/* 
Auth: Muhammad Nabil Akhtar Raya Amoriza | 5025221021
Problem: The digits of an integer are held on a linked list in reverse order, one digit per node.   \
Write a function that, given pointers to two integers, performs a digit-by-digit addition and       \
returns a pointer to the digits of the sum stored in reverse order. Note: This idea can be used to  \
add arbitrarily large integers.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define t printf("test\n");

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);
int stack_sum(int *first, int *second, int *result, int surplus);

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

int stack_sum(int *first, int *second, int *result, int surplus) {
    *result = *first + *second + surplus;
    int carry = *result / 10;
    *result %= 10;
    return carry;
}

int main(int argc, char const *argv[]) {
    Stack s_first, s_second, s_result;
    stack_init(&s_first);
    stack_init(&s_second);
    stack_init(&s_result);

    //first stack -> 975312
    stack_push(&s_first, 9);
    stack_push(&s_first, 7);
    stack_push(&s_first, 5);
    stack_push(&s_first, 3);
    stack_push(&s_first, 1);
    stack_push(&s_first, 2);

    //second stack -> 060253
    stack_push(&s_second, 0);
    stack_push(&s_second, 6);
    stack_push(&s_second, 0);
    stack_push(&s_second, 2);
    stack_push(&s_second, 5);
    stack_push(&s_second, 3);

    int size = stack_size(&s_first), carry = 0;
    for(int i = 0; i < size; i++){
        int* result = malloc(sizeof(int));
        carry = stack_sum(&s_first._top->data, &s_second._top->data, result, carry);
        stack_pop(&s_first);
        stack_pop(&s_second);
        stack_push(&s_result, *result);
    }
    if (carry) {
        stack_push(&s_result, carry);
        size++;
    }

    //print result stack
    for(int i = 0; i < size; i++){
        printf("%d", stack_top(&s_result));
        stack_pop(&s_result);
    }

    return 0;
}