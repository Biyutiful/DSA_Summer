#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Circular.h"

void initQueue(Queue *q) {
    int i;
    q->front = 7;
    q->rear = 6;
    for(i = 0; i < MAX; ++i){
            q->elems[i] = EMPTY;
    }
}
void enqueue(Queue *q, int item) {
    if(!isFull(*q)){
        q->rear = (q->rear+1) % MAX;
        q->elems[q->rear] = item;
    }
}
void dequeue(Queue *q) {
    if(!isEmpty(*q)){
        q->front = (q->front+1) % MAX;
    }
}
int front(Queue q) {
    // if(!isEmpty(q)){
    //     return q.elems[q.front];
    // }
    // return EMPTY;
    
    return !isEmpty(q)? q.elems[q.front] : EMPTY;
}
bool isEmpty(Queue q) {
    return (q.rear + 1) % MAX == q.front;
}
bool isFull(Queue q) {
    return (q.rear + 2) % MAX == q.front;
}
void display(Queue q) {
    int i;
    printf("myQueue\n");
    printf("------------------------\n");
    printf("{ ");
    for(i = q.front; i != (q.rear + 1) % MAX; i = (++i) % MAX) {
        if(q.elems[i]!=EMPTY) {
            printf("%d", q.elems[i]);
            if(i!=q.rear){
                printf(", ");
            }
        }
    }
    printf(" }\n");
    
    printf("------------------------\n");
}
void visualize(Queue q) {
    int i;
    printf("%5s | %5s | %s\n", "INDEX", "VALUE", "POSITION");
    printf("------------------------\n");
    for(i = 0; i < MAX; ++i) {
        printf("%5d | ", i);
        if(q.elems[i]!=EMPTY) {
            printf("%5d | ", q.elems[i]);
        } else {
            printf("%5s | ", " ");
        }
        if(i == q.front) {
            printf("FRONT");
        }
        if(i == q.rear) {
            printf("REAR");
        }
        printf("\n");
    }
    printf("------------------------\n");
}

//use only Queue Fuctions, no element traversal
bool removeItem(Queue *q, int item) {
    //first occurance
    Queue p;
    initQueue(&p);
    bool check = 0;
    
    /* FOR LOOP IMPLEMENTATION */
    // int i;
    // for(i = q->front; i != (q->rear+1) % MAX; i = (++i) % MAX) {
    //     if(front(*q) == item && check<1){
    //         dequeue(q);
    //         check = 1;
    //         continue;
    //     }
    //     enqueue(&p, front(*q));
    //     dequeue(q);
    // }
    // for(i = p.front; i != (p.rear + 1) % MAX; i = (++i) % MAX) {
    //     enqueue(q, front(p));
    //     dequeue(&p);
    // }
    
    /* WHILE LOOP IMPLEMENTATION */
    while(q->front != (q->rear+1) % MAX){
        if(front(*q) == item && check<1){
            dequeue(q);
            check = 1;
            continue;
        }
        enqueue(&p, front(*q));
        dequeue(q);
    }
    while(p.front != (p.rear + 1) % MAX){
        enqueue(q, front(p));
        dequeue(&p);
    }
    return check;
}
Queue removeEven(Queue *q){
    //removes all even and returns all deleted item stored in Q
    Queue p, even;
    initQueue(&p);
    initQueue(&even);
    /* FOR LOOP IMPLEMENTATION */
    // int i;
    // for(i = q->front; i != (q->rear+1) % MAX; i = (++i) % MAX) {
    //     if(front(*q) % 2 == 0){
    //         enqueue(&even, front(*q));
    //         dequeue(q);
    //         continue;
    //     }
    //     enqueue(&p, front(*q));
    //     dequeue(q);
    // }
    
    // for(i = p.front; i != (p.rear + 1) % MAX; i = (++i) % MAX) {
    //     enqueue(q, front(p));
    //     dequeue(&p);
    // }

    /* WHILE LOOP IMPLEMENTATION */
    while(q->front != (q->rear+1) % MAX){
        if(front(*q) % 2 == 0){
            enqueue(&even, front(*q));
            dequeue(q);
        }
        enqueue(&p, front(*q));
        dequeue(q);
    }
    while(p.front != (p.rear + 1) % MAX){
        enqueue(q, front(p));
        dequeue(&p);
    }
    return even;
} 
int doubleTheValue(Queue *q, int value){
    // doubles the value in Q that is a multiple of the given value and return how many values have changed
    Queue p;
    initQueue(&p);
    int doub, count=0;

    /* FOR LOOP IMPLEMENTATION */
    // int i;
    // for(i = q->front; i != (q->rear+1) % MAX; i = (i+1) % MAX) {
    //     if(front(*q) % value == 0){
    //         doub = front(*q)*2;
    //         enqueue(&p, doub);
    //         ++count;
    //     } else{
    //         enqueue(&p, front(*q));
    //     }
    //     dequeue(q);
    // }
    
    // for(i = p.front; i != (p.rear+1) % MAX; i = (i+1) % MAX) {
    //     enqueue(q, front(p));
    //     dequeue(&p);
    // }

    /* WHILE LOOP IMPLEMENTATION */
    while(q->front!=(q->rear+1) % MAX) {
        if(front(*q) % value == 0){
            doub = front(*q)*2;
            enqueue(&p, doub);
            ++count;
        } else{
            enqueue(&p, front(*q));
        }
        dequeue(q);
    }

    while(p.front!=(p.rear+1) % MAX) {
        enqueue(q, front(p));
        dequeue(&p);
    }
    
    return count;

}