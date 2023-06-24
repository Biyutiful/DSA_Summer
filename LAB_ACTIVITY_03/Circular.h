#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <stdbool.h>
#define MAX 10
#define EMPTY 9999

typedef char String[100];

typedef struct {
    int elems[MAX];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void display(Queue q); //can use element traversal
void visualize(Queue q);

//use only Queue Fuctions, no element traversal
bool removeItem(Queue *q, int item); //first occurance
Queue removeEven(Queue *q); //removes all even and returns all deleted item stored in Q
int doubleTheValue(Queue *q, int value);// doubles the value in Q that is a multiple  of the given value and return how many values have changed

#endif