#ifndef DATE_H
#define DATE_H

#include <string.h>
#include <stdbool.h>

#define MAX 20

typedef char String[20];

typedef struct {
    int date, month, year;
} Date;

typedef struct {
    int prodID;
    String prodName;
    int prodQty;
    double prodPrice;
    Date prodExp;
} Product;

typedef struct {
    Product items;
    int link;
} SType;

typedef struct{
    SType data[MAX];
    int avail;
} VirtualSpace;

typedef int StackList;

typedef struct{
    int front;
    int rear;
} Queue;

/*VirtualHeap*/

// Product 
    Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp);
// "Initialize" - Create virtual space
    VirtualSpace newVirtualSpace(); 
// "isFull" - Checks if virtual space is full
    bool isFull(VirtualSpace vh);
// "Alloc" -  Changes the avail to the next avail space
    int allocSpace(VirtualSpace *vh); 
// "Dealloc" - Changes the avail to the prev avail space
    void deallocSpace(VirtualSpace *vh, int index);
// "Viszualize" - Shows how it is being stored
    void visualizeSpace(VirtualSpace vh);
// "Insert" - Inserts the data in the cursorbase(Virtual Space)
    void insertFront(VirtualSpace *vh, Product p);
    void insertRear(VirtualSpace *vh, Product p);
    
/*StackList*/
    // "Initialize" - initializes the count
    StackList initStackR();
    void initStack(StackList *stack);
    // "Push" - Removes the top of the stack
    void push(VirtualSpace *vh, StackList *s, Product p);
    // "Pop" - Adds+ to the top
    void pop(VirtualSpace *vh, StackList *s);
    Product popR(VirtualSpace *vh, StackList *s);
    // "isEmpty" -Check if it's equal to -1
    bool isEmptyStack(StackList s);
    // "Peak/Top" - Returns what's at the top of the stack
    Product top(VirtualSpace vh, StackList s);
    // "Display" - Displays the Stack
    void displayStack(VirtualSpace vh, StackList s);
    // "Viszualize" - Visualizes the stack
    void visualStack(VirtualSpace vh, StackList s);


/*Queue*/
    // "Initialize" - Initializes the front and the rear
    Queue initQueueR();
    void initQueue(Queue *q);
    // "Enqueue" - Adds data to the rear
    void enqueue(VirtualSpace *vh, Queue *q, Product p);
    // "Dequeue" - Removes from the front
    void dequeue(VirtualSpace *vh, Queue *q);
    Product dequeueR(VirtualSpace *vh, Queue *q);
    // "isEmpty" - Checks if queue is -1
    bool isEmptyQueue(Queue q);
    // "Front" - Returns the first in line
    Product front(VirtualSpace vh, Queue q);
    // "Display" - Displays the Queue
    void displayQueue(VirtualSpace vh, Queue q);
    // "Viszualize" - Visualizes the Queue
    void visualQueue(VirtualSpace vh, Queue q);

#endif