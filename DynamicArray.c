#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"
 
void initList(List *list) {
    list->count = 0;
}

List newList(int max) {
    List list = {NULL,0,max};
    list.elems = (DATA*) malloc(sizeof(DATA)*max) ;
    return list;
}

void displayList(List list) {
    int ctr = 0;
    for(; ctr<list.count; ctr++) {
        printf("%d ", list.elems[ctr]);
    }
    printf("\n");
}

bool insertFront(List *list, DATA item) {
    bool check = 0;
    if(list->count<list->max) {
        int ctr = 0;
        // memcpy(&list->elems[1],&list->elems[0],sizeof(DATA)*list->count++); ahhh no string.h stupid me
        for( ctr=list->count-1 ; ctr>0 ; ctr-- ) {
            list->elems[ctr+1] = list->elems[ctr];
        }
        list->elems[0] = item;
        list->count++;
        check = 1;
    }
    return check;
}

bool insertRear(List *list, DATA item) {
    bool check = 0;
    if(list->count<list->max){
        list->elems[list->count++] = item;
        check = 1;
    }
    return check;
}

bool insertSorted(List *list, DATA item) {
    bool check = 0;
    int tra, ctr = 0;
    if(list->count<list->max) {
        for(; ctr<list->count-1 && list->elems[ctr] < item ; ctr++) { }
        for( tra=list->count ; tra>ctr ; tra--) {
            list->elems[tra] = list->elems[tra-1];
        }
        list->elems[tra] = item;
        list->count++;
        check = 1;
    }
    return check;
}

bool insertAt(List *list, DATA item, int loc) {
    bool check = 0;
    if(list->count<list->max) {
        int ctr;
        for(ctr = list->count; ctr>loc-1 ; ctr--) {
            list->elems[ctr] = list->elems[ctr-1];
        }
        list->count++;
        list->elems[loc-1] = item;
        check = 1;
    }
    return check;
}

bool searchItem(List list, DATA key) {
    int ctr;
    for( ctr=0 ; ctr<list.count && list.elems[ctr]!=key ; ctr++) { }
    return list.elems[ctr]==key;
}

int getItem(List list, DATA key) {
    int ctr;
    for( ctr=0 ; ctr<list.count&&list.elems[ctr]!=key ;ctr++ ) { }
    return list.elems[ctr]==key? key : 0;
}

bool deleteFront(List *list) { 
    bool check=0;
    if(list->count == 1) {
        list->count--;
        check=1;
    }else if(list->count>0) {
        int ctr=0;
        for( ; ctr<list->count ;ctr++ ) {
            list->elems[ctr] = list->elems[ctr+1];
        }
        list->count--;
        check=1;
    }
    return check;
}

bool deleteRear(List *list) {
    bool check=0;
    if(list->count>0) {
        list->count--;
        check=1;
    }
    return check;
}

int deleteAt(List *list, int loc) {
    int check=0;
    if(list->count>0) {
        int ctr;
        for( ctr=loc-1; ctr<list->count ; ctr++){
            list->elems[ctr] = list->elems[ctr+1];
        }
        list->count--;
        check=1;
    }
    return check;
}

bool deleteItem(List *list, DATA key) {
    bool check=0;
    if(list->count>0){
        int trav,ctr;
        for( ctr=0 ; ctr<list->count && list->elems[ctr]!=key ; ctr++) { }
        for( trav=ctr; trav<list->count ; trav++){
            list->elems[trav] = list->elems[trav+1];
        }
        list->count--;
        check=1;
    }
    return check;
}

int deleteAllItem(List *list, DATA key) {
    if(list->count>0){
        list->count = 0;
        key=1;
    }
    return key;
}
