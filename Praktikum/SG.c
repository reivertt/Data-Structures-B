/*
 * Implementasi ADT SInglyList (Singly Linked List) oleh Bayu Laksana (22 Januari 2019)
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct snode_t {
    char data[6][11];
    int size;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushBack(SinglyList *list);
char* slist_popString(SinglyList *list, unsigned index, int s_index);
void slist_pushString(SinglyList *list, int index, int K);

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushBack(SinglyList *list){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->size = 0;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) 
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

char* slist_popString(SinglyList *list, unsigned index, int s_index){
    if (!slist_isEmpty(list) && index <= list->_size){
        SListNode *temp = list->_head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        
        s_index = s_index - 1;
        char *tempData = (char*) malloc(sizeof(char) * 11);
        strcpy(tempData, temp->data[s_index]);
        if (s_index + 1 > temp->size) return "Kambing Tidak Ada";
        for (int i = s_index; i < temp->size - 1; i++) {
            strcpy(temp->data[i], temp->data[i+1]);
        }
        temp->data[temp->size - 1][0] = '\0';
        temp->size--;
        return tempData;
    }
    return NULL;
    
}

void slist_pushString(SinglyList *list, int index, int K){
    SListNode *temp = list->_head;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
    }
    temp->size = K;
    for (int i = 0; i < K; i++) {
        scanf("%s", temp->data[i]);
    }
}

int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init(&myList);

    int global = 1, N;
    scanf("%d", &N);
    while(N--){
        int choice, K;
        scanf("%d %d", &choice, &K);
        if (choice == 1){
            slist_pushBack(&myList);
            slist_pushString(&myList, global, K);
            global++;
        }
        else if (choice == 2){
            int s_index;
            scanf("%d", &s_index);
            if (K > global) printf("Kambing Tidak Ada\n");
            else printf("%s\n", slist_popString(&myList, K, s_index));
        }
        else continue;
    }


    return 0;
}