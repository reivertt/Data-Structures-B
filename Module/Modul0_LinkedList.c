/*
 * Implementasi ADT SInglyList (Singly Linked List) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_pushFront(SinglyList *list, int value);
void slist_popFront(SinglyList *list);
void slist_pushBack(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_insertAt(SinglyList *list, int index, int value);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int  slist_front(SinglyList *list);
int  slist_back(SinglyList *list);
int  slist_getAt(SinglyList *list, int index);
void forEachElement(SinglyList *list, void (*f)(int, SListNode*, int*, int));
void printElements(int index, SListNode *temp, int *TempArr, int num_loops);
void reverseEach(int index, SListNode *temp, int *TempArr, int num_loops);
void sumDigit(int index, SListNode *temp, int *TempArr, int num_loops);
int SumOfDigits(int a);

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushFront(SinglyList *list, int value) {
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

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

void slist_pushBack(SinglyList *list, int value){
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
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

void slist_insertAt(SinglyList *list, int index, int value){
    /* Kasus apabila posisinya melebihi batas */
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
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_removeAt(SinglyList *list, int index){
    if (!slist_isEmpty(list)) {
        
        /* Kasus apabila posisinya melebihi batas */
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

void slist_remove(SinglyList *list, int value){
    if (!slist_isEmpty(list)) {
        SListNode *temp, *prev;
        temp = list->_head;

        if (temp->data == value) {
            slist_popFront(list);
            return;
        }
        while (temp != NULL && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list){
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        while (temp->next != NULL) 
            temp = temp->next;
        return temp->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index){
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

void forEachElement(SinglyList *list, void (*f)(int, SListNode*, int*, int)){
    if (!slist_isEmpty(list)) {
        int TempArr[list->_size], _j = list->_size - 1, num_loops = 1;
        if (f == reverseEach) num_loops = 2;
        while (num_loops--) {
            SListNode *temp = list->_head;
            for (int _i = 0; _i < list->_size; _i++){
                if (*f == reverseEach) {
                    if (num_loops == 0) {
                        (f)((_j - _i), temp, TempArr, num_loops);
                    }
                    else (f)(_i, temp, TempArr, num_loops);
                }
                else (*f)(_i, temp, NULL, num_loops);
                temp = temp->next;
            }
        }
        printf("\n");
    }
}

void reverseEach(int index, SListNode *temp, int *TempArr, int num_loops){
    if (num_loops == 1) {
        TempArr[index] = temp->data;
    }
    else if (num_loops == 0) {
        temp->data = TempArr[index];
    }
}

void printElements(int index, SListNode *temp, int *TempArr, int num_loops){
    printf("%d ", temp->data);
}

void sumDigit(int index, SListNode *temp, int *TempArr, int num_loops){
    temp->data = SumOfDigits(temp->data);
}

int SumOfDigits(int a){
    if (a < 10) return a % 10;
    else return SumOfDigits(a/10) + SumOfDigits(a%10);
}

int main(int argc, char const *argv[]){
    SinglyList myList;
    slist_init(&myList);

    slist_pushBack(&myList, 11);
    slist_pushBack(&myList, 22);
    slist_pushBack(&myList, 33);
    slist_pushBack(&myList, 44);
    // Isi List => [11, 22, 33, 44]

    slist_pushFront(&myList, 100);
    slist_pushFront(&myList, 99);
    slist_pushFront(&myList, 88);
    slist_pushFront(&myList, 77);
    // Isi List => [77, 88, 99, 100, 11, 22, 33, 44]

    slist_popBack(&myList);
    slist_popFront(&myList);
    // Isi List => [88, 99, 100, 11, 22, 33]

    slist_removeAt(&myList, 3);
    // Isi List => [88, 99, 100, 22, 33]

    slist_insertAt(&myList, 1, 13);
    slist_pushBack(&myList, 1);
    slist_remove(&myList, 1);
    // Isi List => [88, 13, 99, 100, 22, 33]

    printf("List: ");
    forEachElement(&myList, printElements);

    // forEachElement(&myList, sumDigit);
    // printf("Sum of digits: ");
    // forEachElement(&myList, printElements);
    
    forEachElement(&myList, reverseEach);
    printf("Reversed: ");
    forEachElement(&myList, printElements);

    return 0;
}