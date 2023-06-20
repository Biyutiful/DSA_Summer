#include <stdio.h>
#include <stdlib.h>
#include "StackLIST.h"


void initStack(List *list) {
    *list=NULL;
}
bool isEmpty(List *list){
    return *list==NULL;
}

void push(List *list,int item) {
   List newNode = (List) malloc (sizeof(struct node));
    if ( newNode!=NULL ) {
        newNode->data = item;
        newNode->next = (*list);
        *list = newNode;
    }
}
void pop(List *list) {
    List temp; 
    if(!isEmpty(list)){
       temp = *list;
       *list = (*list)->next;
       free(temp);
       temp=NULL;
    }
}
int top(List list) {
    if(!isEmpty(&list)){
        return list->data;
    }
}
void display(List list) {
    for( ;list!=NULL;list=list->next ) {
        printf("%d ", list->data);
    }
    printf("\n");
}
void visualize(List list) {
    List headR;
    initStack(&headR);
    
    while(list!=NULL){
        push(&headR, top(list));
        pop(&list);
    }
    while(headR!=NULL){
        printf("%d ", headR->data);
        push(&list, top(headR));
        pop(&headR);
    }
    printf("\n");
}