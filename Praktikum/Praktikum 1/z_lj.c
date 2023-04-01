#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
typedef struct node{
    int data;
    struct node *next;
}node;
 
typedef struct stack{
    unsigned size;
    node *top;
}stack;
 
void init(stack *s){
    s->top = NULL;
    s->size = 0;
}
 
bool isEmpty(stack *s){
    return (s->top == NULL);
}
 
void stack_push(stack *s,int data){
    node *temp = (node*)malloc(sizeof(node));
    if(temp){
        s->size++;
        temp->data = data;
        if(isEmpty(s)) temp->next = NULL;
        else temp->next = s->top;
        s->top = temp;
    }
}
 
void stack_pop(stack *s){
    if(!isEmpty(s)){
        node *temp = s->top;
        s->top = s->top->next;
        free(temp);
        s->size--;
    }
}
 
int stack_top(stack *s){
    if(!isEmpty(s)) return s->top->data;
    return 0;
}
 
void printStack(stack *s,int op){
    node *temp = s->top;
    int arr[s->size];
    int i = 0;
    while(temp != NULL){
        arr[i] = temp->data;
        temp = temp->next;
        i++;
    }
    printf("tumpukan %d: ",op);
    for(int j = s->size-1 ; j>=0 ; j--){
        printf("%d%c",arr[j],j==0 ? '\n' : ' ');
    }
}
 
int main(){
    stack s[3];
    int temp = 0;
    for(int i = 0 ; i<3 ; i++){
        init(&s[i]);
    }
    int n;
    scanf("%d",&n);
    while(n--){
        char cmd[8];
        scanf("%s",cmd);
        if(cmd[0] == 'K'){
            int x;
            scanf("%d",&x);
            for(int i = temp+1 ; i<= temp+x ; i++){
                stack_push(&s[0],i);
            }
            temp += stack_top(&s[0]);
            // printStack(&s[0],1);
        }
        else if(cmd[0] == 'C'){
            int x;
            scanf("%d",&x);
            for(int i = 1 ; i<= x ; i++){
                stack_push(&s[1],stack_top(&s[0]));
                stack_pop(&s[0]); 
            }
            // printStack(&s[1],2);
        }
        else if(cmd[0] == 'S'){
            int x;
            scanf("%d",&x);
            for(int i = 1 ; i<= x ; i++){
                stack_push(&s[2],stack_top(&s[1]));
                stack_pop(&s[1]);   
            }
            // printStack(&s[2],3);
        }
    }
    printStack(&s[0],1);
    printStack(&s[1],2);
    printStack(&s[2],3);
}