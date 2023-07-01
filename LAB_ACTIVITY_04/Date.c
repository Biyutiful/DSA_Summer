/******************************************************************************

 > Create a menu
 > Implement necessary functions such as display and visualization
 > Implement the stack and queue operations

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Date.h"

/*VirtualHeap*/

// Product 
    Product newProduct(int prodID, String prodName, int prodQty, double prodPrice, Date prodExp) {
        Product p;

        p.prodID = prodID; 
        strcpy(p.prodName, prodName);
        p.prodQty = prodQty; 
        p.prodPrice = prodPrice;
        p.prodExp = prodExp;

        return p;
    }
// "Initialize" - Create virtual space
    VirtualSpace newVirtualSpace() {
        VirtualSpace vh;
        int i;
        Date defaultDate = {0};
        for(i = 0; i < MAX; i++) {
            vh.data[i].items = newProduct(0, "", 0, 00.00, defaultDate);
            vh.data[i].link = i-1;
        }

        vh.avail = MAX-1;
        printf("%d", vh.avail);
        return vh;
    }
// "isFull" - Checks if virtual space is full
    bool isFull(VirtualSpace vh){
        return vh.avail==MAX-1;
    }
// "Alloc" -  Changes the avail to the next avail space
    int allocSpace(VirtualSpace *vh) {
        int retVal = vh->avail;

        if(retVal != -1) {
            vh->avail = vh->data[vh->avail].link;
        }

        return retVal;
    }
// "Dealloc" - Changes the avail to the prev avail space
    void deallocSpace(VirtualSpace *vh, int index) {
        if(index > -1 && index < MAX) {
            Date defaultDate = {0};
            vh->data[index].link = vh->avail;
            vh->data[index].items = newProduct(0, "", 0, 00.00, defaultDate);
            vh->avail = index;
        }
        
    }
// "Viszualize" - Shows how it is being stored
    void visualizeSpace(VirtualSpace vh) {
        int i;
        printf("\n%5s | %30s | %s\n", "INDEX", "ITEMS", "NEXT");
        printf("---------------------------------------------\n");
        for(i = 0; i < MAX; ++i){
            
            printf("%5d | ", i);
            
            if(vh.data[i].items.prodID==0){
                
                printf("%30s  | ", "EMPTY");
                
            } else{
                
                printf("%4d  - %23s | ", vh.data[i].items.prodID, vh.data[i].items.prodName);
                
            }
            
            printf("%d\n", vh.data[i].link);
        }
        
        printf("---------------------------------------------\n");
        printf("AVAILABLE: %d\n", vh.avail);
    }  
//  "Display Product"
    void displayProduct(Product p) {
        String month[12] = {"Jan", "Feb", "Mar",
                            "Apr", "May", "Jun", 
                            "Jul", "Aug", "Sept", 
                            "Oct", "Nov", "Dec"};
                            
        printf("%5d | ", p.prodID);
        printf("%20s | ", p.prodName);
        printf("%5d | ", p.prodQty);
        printf("%7.2lf | ", p.prodPrice);
        printf("%d/ ", p.prodExp.date);
        printf("%s/ %d\n",month[p.prodExp.month-1], p.prodExp.year);
    }
// "Remove" - Removes and returns the data in the front of the cursorbase(Virtual Space)
    int removeData(VirtualSpace *vh, int index){
        int temp = index;
        
        if(index > -1) {

            index = vh->data[index].link;
            deallocSpace(vh, temp);
            
        } else {
            printf("\nNo Data\n");
        }
        return index;
    }

/*StackList*/
    // "Initialize" - initializes the start
    StackList initStackR() {
        StackList s = -1;
        return s;
    }
    void initStack(StackList *stack) {
        *stack = -1;
    }
    // "Push" - Removes the top of the stack
    void push(VirtualSpace *vh, StackList *s, Product p) {
            
        int temp = allocSpace(vh);
    
        if(temp != -1){

            vh->data[temp].items = p;
            vh->data[temp].link = *s;
            *s = temp;

        }   
    }
    // "Pop" - Adds+ to the top
    void pop(VirtualSpace *vh, StackList *s) {
        if(!isEmptyStack(*s)){
            *s = removeData(vh, *s);
        }
    }
    
    Product popR(VirtualSpace *vh, StackList *s) {
        Product data;

        if(!isEmptyStack(*s)){
            
            data = vh->data[*s].items;
            *s = removeData(vh, *s);

        }
        return data;
    }
    // "isEmpty" -Check if it's equal to -1
    bool isEmptyStack(StackList s) {
        return s==-1;
    }
    // "Peak/Top" - Returns what's at the top of the stack
    Product top(VirtualSpace vh, StackList s) {
        Product data;

        if(!isEmptyStack(s)) {
            data = vh.data[s].items;
        }

        return data;
    }
    // "Display" - Displays the Stack
    void displayStack(VirtualSpace vh, StackList s) {
        int i;
        printf("\n%5s | %20s | %5s | %7s | %s\n", "ID", "NAME", "QTY", "PRICE", "EXP");
        printf("---------------------------------------------\n");
        
        for(i = s; i > -1; i = vh.data[i].link){
            displayProduct(vh.data[i].items);
        }
        
        printf("---------------------------------------------\n");
        printf("AVAILABLE: %d\n", vh.avail);
    }
    // "Viszualize" - Visualizes the stack
    void visualStack(VirtualSpace vh, StackList s) {
        int i;
        printf("\n%5s | %30s | %s\n", "INDEX", "ITEMS", "NEXT");
        printf("---------------------------------------------\n");
        for(i = s; i < MAX; ++i){
            
            printf("%5d | ", i);
            
            if(vh.data[i].items.prodID==0){
                
                printf("%30s  | ", "EMPTY");
                
            } else{
                
                printf("%4d  - %22s | ", vh.data[i].items.prodID, vh.data[i].items.prodName);
                
            }
            
            printf("%d\n", vh.data[i].link);
        }
        
        printf("---------------------------------------------\n");
        printf("AVAILABLE: %d\n", vh.avail);
    }


/*Queue*/
    // "Initialize" - Initializes the front and the rear
    Queue initQueueR() {
        Queue q;

        q.front = -1;
        q.rear = -1;

        return q;
    }
    void initQueue(Queue *q) {

    }
    // "Enqueue" - Adds data to the rear
    void enqueue(VirtualSpace *vh, Queue *q, Product p) {
        
        int newDex = allocSpace(vh);
    
        if (newDex != -1) {
            vh->data[newDex].items = p;
            vh->data[newDex].link = q->rear;
            
            q->rear = newDex;

            if(q->front == -1){
                q->front = newDex;
            }
        }
    }
    // "Dequeue" - Removes from the front
    void dequeue(VirtualSpace *vh, Queue *q) {

    }
    Product dequeueR(VirtualSpace *vh, Queue *q) {
        Product p;

        if(!isEmptyQueue(*q)){
            int temp = q->front;
            p = vh->data[temp].items;
            q->front = vh->data[temp].link;
            deallocSpace(vh, temp);
        }

        return p;
    }
    // "isEmpty" - Checks if queue is -1
    bool isEmptyQueue(Queue q) {
        return q.front != -1;
    }
    // "Front" - Returns the first in line
    Product front(VirtualSpace vh, Queue q) {
        Product p;

        if(!isEmptyQueue(q)){
            p = vh.data[q.front].items;
        }

        return p;
    }
    // "Display" - Displays the Queue
    void displayQueue(VirtualSpace vh, Queue q) {
        int i;
        printf("\n%5s | %20s | %5s | %7s | %s\n", "ID", "NAME", "QTY", "PRICE", "EXP");
        printf("---------------------------------------------\n");
        
        for(i = q.front; i > -1; i = vh.data[i].link){
            displayProduct(vh.data[i].items);
        }
        
        printf("---------------------------------------------\n");
        printf("AVAILABLE: %d\n", vh.avail);
    }
    // "Viszualize" - Visualizes the Queue
    void visualQueue(VirtualSpace vh, Queue q) {
        int i;
        printf("\n%5s | %30s | %s\n", "INDEX", "ITEMS", "NEXT");
        printf("---------------------------------------------\n");
        for(i = q.front; i < MAX; ++i){
            
            printf("%5d | ", i);
            
            if(vh.data[i].items.prodID==0){
                
                printf("%30s  | ", "EMPTY");
                
            } else{
                
                printf("%4d  - %22s | ", vh.data[i].items.prodID, vh.data[i].items.prodName);
                
            }
            
            printf("%d\n", vh.data[i].link);
        }
        
        printf("---------------------------------------------\n");
        printf("AVAILABLE: %d\n", vh.avail);
    }