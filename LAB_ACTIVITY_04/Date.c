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

        vh.avail = i;
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
// "Insert" - Inserts the data in the cursorbase(Virtual Space)
    void insertRear(VirtualSpace *vh, Product p) {
        
        // List *trav;
        
        // for(trav = list; *trav != -1; trav = vh->data[*trav].link){}
        // List newDex = allocSpace(vh);
        
        // if (newDex != -1) {
        //     vh->data[newDex].items = p;
        //     vh->data[newDex].link = -1;
            
        //     *trav = newDex;
        // }
        
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
        if(!isFull(*vh)){
            
            int temp = allocSpace(vh);
        
            if(temp != -1){

                vh->data[temp].items = p;
                vh->data[temp].link = *s;
                *s = temp;

            }   
        }
    }
    // "Pop" - Adds+ to the top
    void pop(VirtualSpace *vh, StackList *s) {
        if(!isEmpty(*s)){
            *s = removeData(vh, *s);
        }
    }
    
    Product popR(VirtualSpace *vh, StackList *s) {
        Product data;

        if(!isEmpty(*s)){
            
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

        if(!isEmpty(s)) {
            data = vh.data[s].items;
        }

        return data;
    }
    // "Display" - Displays the Stack
    void displayStack(VirtualSpace vh, StackList s) {
        int i;
        printf("\n | DISPLAY | \n");
        printf("---------------------------------------------\n");
        for(i = s; i > -1; i = vh.data[i].link){
                
            printf("%5s | %d\n", "ID", vh.data[i].items.prodID);
            printf("%5s | %s\n", "NAME", vh.data[i].items.prodName);
            printf("%5s | %d\n", "QTY", vh.data[i].items.prodQty);
            printf("%5s | %.2f\n", "PRICE", vh.data[i].items.prodPrice);
            printf("%5s | %d\n", "EXP", vh.data[i].items.prodExp);
            
            printf("\n");
        }
        
        printf("---------------------------------------------\n");
        printf("AVAILABLE: %d\n", vh.avail);
    }
    // "Viszualize" - Visualizes the stack
    void visualStack(VirtualSpace vh, StackList s) {
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