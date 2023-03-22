/*
 * Implementasi ADT SInglyList (Singly Linked List) oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Pemrograman ITS
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct snode_t {
    int data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head, *_tail;
} SinglyList;

void slist_init(SinglyList *list);
bool slist_isEmpty(SinglyList *list);
void slist_popFront(SinglyList *list);
void slist_push(SinglyList *list, int value);
void slist_popBack(SinglyList *list);
void slist_removeAt(SinglyList *list, int index);
void slist_remove(SinglyList *list, int value);
int slist_front(SinglyList *list);
int slist_back(SinglyList *list);
int slist_getAt(SinglyList *list, int index);

void slist_init(SinglyList *list) {
    list->_head = NULL;
    list->_tail = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) { return (list->_head == NULL); }

void slist_popFront(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        list->_head = list->_head->next;
        free(temp);
        list->_size--;
    }
}

void slist_push(SinglyList *list, int value) {
    SListNode *newNode = (SListNode *)malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        int count = list->_size - 1;
        newNode->data = value;
        newNode->next = list->_head;

        if (slist_isEmpty(list)) list->_head = list->_tail = newNode;
        else {
            SListNode *temp = list->_tail;
            temp->next = newNode;
            list->_tail = temp->next;
        }

    }
}

void slist_popBack(SinglyList *list) {
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

void slist_removeAt(SinglyList *list, int index) {
    if (!slist_isEmpty(list)) {
        if (index >= list->_size) {
        slist_popBack(list);
        return;
        } else if (index == 0 || index < 0) {
        slist_popFront(list);
        return;
        }

        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index - 1) {
        temp = temp->next;
        _i++;
        }
        SListNode *nextTo = temp->next->next;
        free(temp->next);
        temp->next = nextTo;
        list->_size--;
    }
}

void slist_remove(SinglyList *list, int value) {
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

        if (temp == NULL)
        return;
        prev->next = temp->next;
        free(temp);
        list->_size--;
    }
}

int slist_front(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        return list->_head->data;
    }
    return 0;
}

int slist_back(SinglyList *list) {
    if (!slist_isEmpty(list)) {
        return list->_tail->data;
    }
    return 0;
}

int slist_getAt(SinglyList *list, int index) {
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

void slist_print(SinglyList *list){
    if (!slist_isEmpty(list)) {
        SListNode *temp = list->_head;
        printf("Children left: ");
        for(int _i = 0; _i < list->_size; _i++){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void slist_josephus(SinglyList *list) {
    SListNode *templist = list->_head, *prev = templist;
    int round = list->_size - 1;
    while (round--) {
        char temp[200];
        printf("Input Sentence: ");
        scanf("\n%[^\n]s", temp);
        for (int j = 0; temp[j] != '\0'; j++) {
            if (temp[j] == ' ' && temp[j+1] != ' '){
                prev = templist;
                templist = templist->next;
                }
        }
        
        if (templist == list->_head) {
            prev = list->_tail;
            list->_tail->next = list->_head->next;
            list->_head = list->_head->next;
        }
        else prev->next = templist->next;

        printf("%d is out!\n", templist->data);
        free(templist);
        list->_size--;
        
        templist = prev->next;
        slist_print(list);
    }
    printf("Winner is %d", templist->data);
}

int main(int argc, char const *argv[]) {
    SinglyList myList;
    slist_init(&myList);

    int n;
    printf("Number of Children: ");
    scanf("%d", &n);

      for (int i = 1; i < n + 1; i++) {
        slist_push(&myList, i);
      }
    slist_print(&myList);

    slist_josephus(&myList);

    // while (myList._head != NULL) {
    //     printf("%d ", slist_back(&myList));
    //     slist_popBack(&myList);
    // }
  return 0;
}