#ifndef STACKARR_H
#define STACKARR_H

#include <stdbool.h>

typedef int DATA;

typedef struct node{
	DATA data;
	struct node *next;
} *List;

void initStack(List *list);
bool isEmpty(List *list);
void push(List *list,int item);
void pop(List *list);
int top(List list);
void display(List list);
void visualize(List list);

#endif
