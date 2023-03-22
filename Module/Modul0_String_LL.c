/*
 * Implementasi ADT SInglyList (Singly Linked List) oleh Bayu Laksana (22 Januari 2019)
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct snode_t {
    char data[101];
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, char value[]);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, char value[]);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, unsigned index, char value[]);
void slist_removeAt(SinglyList *list, unsigned index);
void slist_remove(SinglyList *list, char value[]);
char* slist_front(SinglyList *list);
char* slist_back(SinglyList *list);
char* slist_getAt(SinglyList *list, unsigned index);

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, char value[]) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_popFront(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_pushBack(SinglyList *list, char value[]){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        strcpy(newNode->data, value);
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

void slist_popBack(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *nextNode = list->_head->next;
        SListNode *currNode = list->_head;

        if (currNode->next == NULL) {
            free(currNode);
            list->_head = NULL;
            return;
        }

        while (nextNode->next != NULL) {
            currNode = nextNode;
            nextNode = nextNode->next;
        }
        currNode->next = NULL;
        free(nextNode);
        list->_size--;
    }
}

void slist_insertAt(SinglyList *list, unsigned index, char value[]){
    if (slist_isEmpty(list) || index >= list->_size) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0 || index < 0) {
        slist_pushFront(list, value);
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1) {
            temp = temp->next;
            _i++;
        }
        strcpy(newNode->data, value);
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, unsigned index){
    if (!slist_isEmpty(list)) {
        if (index >= list->_size) {
            slist_popBack(list);
            return;    
        }
        else if (index == 0 || index < 0) {
            slist_popFront(list);
            return;
        }
        
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, char value[]){
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (!strcmp(temp->data, value)) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && strcmp(temp->data, value) != 0) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

char* slist_front(SinglyList *list){
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

char* slist_back(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

char* slist_getAt(SinglyList *list, unsigned index){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index) {
            temp = temp->next;
            _i++;
        }
        return temp->data;
    }
    return 0;
}

void printElements(SinglyList *list){
    SListNode *temp = list->_head;
    printf("Isi list: ");
    for (int _i = 0; _i < list->_size; _i++) {
        printf("%c%s%c ", 34, temp->data, 34);
        temp = temp->next;
    }
    printf("\n");
}

void forEachElement(SinglyList *list, void (*f)(SinglyList*)){
    if (!slist_isEmpty(list)) {
        (*f)(list);
    }
}

int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init(&myList);

    slist_pushBack(&myList, "Alpha");
    slist_pushBack(&myList, "Beta");
    slist_pushBack(&myList, "Gamma");
    slist_pushBack(&myList, "Delta");
    slist_pushBack(&myList, "Epsilon");
    // Isi list sekarang: Alpha Beta Gamma Delta Epsilon

    slist_pushFront(&myList, "First Data");

    slist_insertAt(&myList, 2, "Insert at 2");

    //isi list sekarang: First Data Alpha Insert at 2 Beta Gamma Delta Epsilon

    slist_popFront(&myList);

    slist_remove(&myList, "Gamma");

    forEachElement(&myList, printElements);

    puts("");
    return 0;
}