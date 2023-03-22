/**
 * Implementasi ADT Stack (Stack menggunakan Linked List)
 * 
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
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack) 
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value) 
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;
        
        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

int stack_pop(Stack *stack) {
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        int tempData = temp->data;
        free(temp);
        stack->_size--;
        return tempData;
    }
}

int stack_top(Stack *stack) 
{
    if (!stack_isEmpty(stack)) 
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

void printElements(Stack *stack){
    StackNode *temp = stack->_top;
    int TempArr[stack->_size], size = stack->_size;
    for (int _i = 0; _i < stack->_size; _i++) {
        TempArr[_i] = temp->data;
        temp = temp->next;
    }
    while(size--){
        printf("%d ", TempArr[size]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    Stack Tumpukan1, Tumpukan2, Tumpukan3;
    stack_init(&Tumpukan1);
    stack_init(&Tumpukan2);
    stack_init(&Tumpukan3);

    int N, id = 1;
    scanf("%d", &N);
    while(N--){
        int x;
        char chore[10];
        scanf("%s %d",chore, &x);
        for (int i = 0; i < x; i++){
            if(chore[0] == 'K'){
                stack_push(&Tumpukan1, id);
                id++;
            }
            else if(chore[0] == 'C'){
                stack_push(&Tumpukan2, stack_pop(&Tumpukan1));
            }
            else if (chore[0] == 'S'){
                stack_push(&Tumpukan3, stack_pop(&Tumpukan2));
            }
        }
    }

    printf("tumpukan 1: ");
    printElements(&Tumpukan1);
    printf("tumpukan 2: ");
    printElements(&Tumpukan2);
    printf("tumpukan 3: ");
    printElements(&Tumpukan3);
    return 0;
}