/*
 * Implementasi ADT Stack (Stack menggunakan Linked List) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 * Submisi Muhammad Nabil Akhtar Raya Amoriza
 * 5025221021
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct stackNode_t {
    int id;
    char item[100];
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char value[], int id);
void stack_pop(Stack *stack);
void stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack) {
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, char value[], int id) {
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        strcpy(newNode->item, value);
        newNode->id = id;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack) {
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        stack->_size--;
        free(temp);
    }
}

char* stack_find(Stack *stack1, Stack *stack2, int id){
    if (!stack_isEmpty(stack1)) {
        StackNode *temp = stack1->_top;
        while(stack1->_top->id != id){
            stack_push(stack2, temp->item, temp->id);
            temp = temp->next;
            stack_pop(stack1);
        }
        
        stack_top(stack1);
        stack_pop(stack1);

        while(!stack_isEmpty(stack2)){
            stack_push(stack1, stack2->_top->item, stack2->_top->id);
            stack_pop(stack2);
        }
        return temp->item;
    }
    return NULL;
}

void stack_print(Stack *stack1, Stack *stack2) {
    if (!stack_isEmpty(stack1)) {
        StackNode *n_temp1 = stack1->_top, *n_temp2 = stack2->_top;
        while(n_temp1 != NULL){
            stack_push(stack2, n_temp1->item, n_temp1->id);
            n_temp1 = n_temp1->next;
        }

        while(!stack_isEmpty(stack2)){
            stack_top(stack2);
            stack_pop(stack2);
        }
    }
}

void stack_top(Stack *stack) {
    if (!stack_isEmpty(stack)) printf("#%d %c%s%c\n", stack->_top->id, 34,  stack->_top->item, 34);
    return;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(int argc, char const *argv[]) {
    Stack myStack;
    stack_init(&myStack);

    while(1){
        int n;
        scanf("%d", &n);
        if (n == 9) break;
        else if (n == 1) {
            char item[100];
            int id;
            scanf("\n%d\n%[^\n]c", &id, item);
            stack_push(&myStack, item, id);
        }
        else if (n == 2) {
            // printf("Finding: \n");
            int id;
            Stack stackTemp;
            scanf("%d", &id);
            stack_init(&stackTemp);
            stack_find(&myStack, &stackTemp, id);
            // printf("Found!\n");
        }
        else if (n == 3) {
            Stack stackTemp;
            stack_init(&stackTemp);
            printf("Isi Stack: \n");
            stack_print(&myStack, &stackTemp);
        }
    }

    while (!stack_isEmpty(&myStack)) {
        stack_pop(&myStack);
    }
    printf("Semua barang titipan telah dibuang, terima kasih telah menggunakan jasa titipan kami!\n");
    return 0;
}