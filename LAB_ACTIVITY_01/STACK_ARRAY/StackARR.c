#include <stdio.h>
#include <stdlib.h>
#include "StackARR.h"

void initStack(Stack *list) {
    list->count = 0;
}
bool isEmpty(Stack list){
    return list.count==0;
}
bool isFull(Stack list) {
    return list.count>=MAX;
}
void push(Stack *list,int item) {
    if(!isFull(*list)){
        list->data[list->count++] = item;
    }
}
void pop(Stack *list) {
    if(!isEmpty(*list)){
        list->count--;
    }
}
int top(Stack list) {
        DATA data;
        data = list.data[list.count-1];
        return data;
}
void display(Stack list) {
    int ctr;
    printf("DISPLAY STACK\n");
    for(ctr=0; ctr<list.count; ctr++) {
        printf("%d ", list.data[ctr]);
    }
    printf("\n");
}
void visualize(Stack list) {
    Stack temp;
    initStack(&temp);
    int i, j;
    printf("VISUALIZE STACK\n");
    while(list.count>0) {
        push(&temp, top(list));
        printf("%d ", list.data[list.count-1]);
        pop(&list);
    }
    while(temp.count>0) {
        push(&list, top(temp));
        pop(&temp);
    }
    printf("\n");
}