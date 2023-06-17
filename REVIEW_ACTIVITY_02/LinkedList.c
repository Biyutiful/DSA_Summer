#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void initList(List *list) {
    *list = NULL;
}

List newList() {
    List list = NULL;
    return list;
}

NodeType createNode(DATA data) {
    NodeType newNode = {data,NULL};
    return newNode;
}

void displayList(List list){
    for( ; list!=NULL ; list = list->next ) {
        printf("%d ", list->data);
    }
    printf("\n");
}

bool insertFront(List *list, DATA item) {
        bool check=0;

        NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
        if(newNode!=NULL) {
            *newNode = createNode(item);
            newNode->next=*list; 
            *list=newNode;
            check=1;
        }
        return check;
}

bool insertRear(List *list, DATA item) {
    bool check=0;
    List *trav;
    for( trav=list ; *trav!=NULL ; trav=&(*trav)->next ) { }
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if(newNode!=NULL) {
        *newNode = createNode(item);
        *trav=newNode;
        check=1;
    }
    return check;
}

bool insertAt(List *list, DATA item, int loc) {
    bool check=0;
    List *trav;
    for( trav=list ; *trav!=NULL&&--loc!=0 ; trav=&(*trav)->next ) { }
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if(newNode!=NULL) {
        *newNode = createNode(item);
        newNode->next=*trav;
        *trav=newNode;
        check=1;
    }
    return check;
}

bool insertSorted(List *list, DATA data) {
    bool check=0;
    List *trav;
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    for( trav=list ; *trav!=NULL&&(*trav)->data<data ; trav=&(*trav)->next ) { }
    if(newNode!=NULL) {
        *newNode = createNode(data);
        newNode->next=*trav;
        *trav=newNode;
        check=1;
    }
    return check;
}

bool searchItem(List list, DATA key) {
    bool check=0;
    for( ; list->next!=NULL&&list->data!=key ; list=list->next ) { }
    if(list->data==key){
        printf("he ");
        check=1;
    }
    return check;
}

int getItem(List list, DATA key){
    int ctr=0;
    for( ; list!=NULL&&--key!=0 ; list=list->next ) { }
    if(key==0) {
        ctr=list->data;
    }
    return ctr;
}

bool deleteFront(List *list) {
    // bool check=0;
    List freed;
    freed=*list;
    *list=(*list)->next;
    free(freed);
    freed=NULL; 
    // if(freed==NULL)
    //     check=1;
    return freed==NULL;
}

bool deleteRear(List *list){
    List *trav, freed;
    for( trav=list; (*trav)->next!=NULL ; trav=&(*trav)->next ) { }
    freed=*trav;
    *trav=NULL;
    free(freed);
    freed=NULL;
    return freed==NULL;
}

int deleteAt(List *list, int loc) {
    List *trav, freed;
    for( trav=list; (*trav)!=NULL&&--loc!=0 ; trav=&(*trav)->next ) { }
    freed=*trav;
    *trav=(*trav)->next;
    free(freed);
    freed=NULL;
    return freed==NULL;
}

bool deleteItem(List *list, DATA key) {
    List *trav, freed;
    for( trav=list; (*trav)!=NULL&&(*trav)->data!=key ; trav=&(*trav)->next ) { }
    freed=*trav;
    *trav=(*trav)->next;
    free(freed);
    freed=NULL;
    return freed==NULL;
}

int deleteAllItem(List *list, DATA key) {
    List *trav, freed;
    trav=list;
    *list=NULL;
    while((*trav)!=NULL){
        deleteFront(trav);
    }
    if(*trav==NULL){
        key=1;
    }
    return key;
}
