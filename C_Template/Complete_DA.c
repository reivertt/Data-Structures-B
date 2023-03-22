/*
 * Implementasi ADT Dynamic Array oleh Bayu Laksana
 * Diambil dari Repository Algoritma dan Program ITS
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dynamicarr_t {
    int *_arr;
    unsigned _size, _capacity;
} DynamicArray;

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, int value);
void dArray_popBack(DynamicArray *darray);
int  dArray_back(DynamicArray *darray);
int  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, int value);
int  dArray_getAt(DynamicArray *darray, unsigned index);
void dArray_insertAt(DynamicArray *darray, unsigned index, int value);
void dArray_removeAt(DynamicArray *darray, unsigned index);
void dArray_print(DynamicArray *darray);

void dArray_init(DynamicArray *darray) {
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (int*) malloc(sizeof(int) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, int value) {
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    darray->_arr[darray->_size++] = value;
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

int dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

int dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, int value) {
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

int dArray_getAt(DynamicArray *darray, unsigned index) {
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

void dArray_insertAt(DynamicArray *darray, unsigned index, int value) {
    if (darray->_size == darray->_capacity) {
        darray->_size++;
        unsigned it;
        darray->_capacity *= 2;
        int *newArr = (int*) malloc(sizeof(int) * darray->_capacity);

        for (it = 0; it < darray->_size - 1; ++it){
            if (it == index) {
                newArr[it] = value;
                it += 1;
            }
            else if (it > index) newArr[it] = darray->_arr[it-1];
            else newArr[it] = darray->_arr[it];
        }
        
        int *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    else {
        darray->_size++;
        unsigned it;
        for (it = darray->_size; it > index; --it)
            darray->_arr[it] = darray->_arr[it - 1];
        darray->_arr[index] = value;
    }
}

void dArray_removeAt(DynamicArray *darray, unsigned index){
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size) dArray_popBack(darray);
        else {
            unsigned it;
            for (it = index; it < darray->_size - 1; ++it)
                darray->_arr[it] = darray->_arr[it + 1];
            dArray_popBack(darray);
        }
    }
}


void dArray_print(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) {
        unsigned it;
        printf("Isi Array: ");
        for (it = 0; it < darray->_size; ++it)
            printf("%d ", darray->_arr[it]);
        printf("\n");
    }
}

int main(int argc, char const *argv[]){
    DynamicArray myArray;
    dArray_init(&myArray);

    dArray_pushBack(&myArray, 11);
    dArray_pushBack(&myArray, 14);
    dArray_pushBack(&myArray, 17);
    dArray_pushBack(&myArray, 23);
    dArray_pushBack(&myArray, 28);
    dArray_pushBack(&myArray, 33);
    dArray_print(&myArray);
    // isi myArray => [11, 14, 17, 23, 28, 33]

    dArray_insertAt(&myArray, 2, 20);
    dArray_print(&myArray);
    // isi myArray => [11, 14, 20, 17, 23, 28]

    dArray_removeAt(&myArray, 3);
    dArray_print(&myArray);
    
    return 0;
}