/*
 * Implementasi ADT Dynamic Array oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define string_length 100

typedef struct dynamicarr_t {
    char **_arr;
    unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray);
void dArray_stringify(char **arr, int capacity);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, char value[]);
void dArray_popBack(DynamicArray *darray);
char*  dArray_back(DynamicArray *darray);
char*  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, char value[]);
char*  dArray_getAt(DynamicArray *darray, unsigned index);
void dArray_insertAt(DynamicArray *darray, unsigned index, char value[]);
void dArray_removeAt(DynamicArray *darray, unsigned index);
void dArray_print(DynamicArray *darray);

void dArray_init(DynamicArray *darray) {
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (char**) malloc(sizeof(char*) * 2);
    dArray_stringify(darray->_arr, darray->_capacity);
}

void dArray_stringify(char **arr, int capacity) {
    for (int i = 0; i < capacity;i++)
        arr[i] = (char*) malloc(sizeof(char) * string_length);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, char value[]) {
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(char*) * darray->_capacity);
        dArray_stringify(newArr, darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            strcpy(newArr[it], darray->_arr[it]);
        
        char **oldArray = darray->_arr;
        darray->_arr = newArr;
        free(*oldArray);
    }
    strcpy(darray->_arr[darray->_size++], value);
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

char* dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

char* dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, char value[]) {
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            strcpy(darray->_arr[darray->_size-1], value);
        else
            strcpy(darray->_arr[index], value);
    }
}

char* dArray_getAt(DynamicArray *darray, unsigned index) {
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

void dArray_insertAt(DynamicArray *darray, unsigned index, char value[]) {
    if (darray->_size == darray->_capacity) {
        darray->_size++;
        unsigned it;
        darray->_capacity *= 2;
        char **newArr = (char**) malloc(sizeof(char*) * darray->_capacity);
        dArray_stringify(newArr, darray->_capacity);

        for (it = 0; it < darray->_size - 1; ++it){
            if (it == index) {
                strcpy(newArr[it], value);
                it += 1;
            }
            else if (it > index) strcpy(newArr[it], darray->_arr[it-1]);
            else strcpy(newArr[it], darray->_arr[it]);
        }
        
        char **oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    else {
        darray->_size++;
        unsigned it;
        for (it = darray->_size; it > index; --it)
            strcpy(darray->_arr[it], darray->_arr[it - 1]);
        strcpy(darray->_arr[index], value);
    }
}

void dArray_removeAt(DynamicArray *darray, unsigned index){
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size) dArray_popBack(darray);
        else {
            unsigned it;
            for (it = index; it < darray->_size - 1; ++it)
                strcpy(darray->_arr[it], darray->_arr[it + 1]);
            dArray_popBack(darray);
        }
    }
}


void dArray_print(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) {
        unsigned it;
        printf("Isi Array: ");
        for (it = 0; it < darray->_size; ++it)
            printf("%c%s%c ", 34, darray->_arr[it], 34);
        printf("\n");
    }
}

int main(int argc, char const *argv[]){
    DynamicArray myArray;
    dArray_init(&myArray);

    dArray_pushBack(&myArray, "Alpha");
    dArray_pushBack(&myArray, "Bravo");
    dArray_pushBack(&myArray, "Charlie");
    dArray_pushBack(&myArray, "Delta");
    dArray_pushBack(&myArray, "Echo");
    dArray_pushBack(&myArray, "Foxtrot");
    dArray_print(&myArray);
    // isi myArray => ["Alpha", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot"]

    dArray_insertAt(&myArray, 2, "cece cici");
    dArray_print(&myArray);
    // isi myArray => ["Alpha", "Bravo", "cece cici", "Charlie", "Delta", "Echo", "Foxtrot"]

    dArray_removeAt(&myArray, 3);
    dArray_print(&myArray);
    // isi myArray => ["Alpha", "Bravo", "cece cici", "Delta", "Echo", "Foxtrot"]
    
    return 0;
}