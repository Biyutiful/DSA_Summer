#include "myheader.h"
#include <stdio.h>
#include <stdlib.h>

VSpace newVSpace(int max){
    VSpace vs;
    
    vs.max = max%2 == 0? max: max + 1;
    vs.count = 0;
    vs.data = malloc(sizeof(Data) * vs.max);
    vs.avail = vs.max/2;
    int i;
    
    for(i = 0; i < vs.avail; ++i){
        vs.data[i].elem = EMPTY;
        vs.data[i].link = -1;
    }
    for(; i < vs.max; ++i){
        vs.data[i].elem = EMPTY;
        vs.data[i].link = i+1;
    }
    vs.data[max-1].elem = EMPTY;
    vs.data[max-1].link = -1;
        
    return vs;
}
int allocSpace(VSpace *vs) {
    int retVal = vs->avail;
    
    if(retVal != -1){
        vs->avail = vs->data[vs->avail].link;
    }
    
    return retVal;
}
void freeSpace(VSpace *vs, int loc) {
    if(loc >= (vs->max/2) && loc < vs->max){
        vs->data[loc].link = vs->avail;
        vs->data[loc].elem = EMPTY;
        vs->avail = loc;
    }
}
int hash(int val, int size) {
    int hashed = val%(size/2);
    return hashed;
}

bool addElement(VSpace *vs, int elem) {
    bool check = 0;
    int i, temp, hashed = hash(elem, vs->max);
    
    if(vs->data[hashed].elem == EMPTY) {
        vs->data[hashed].elem = elem;
        check = 1;
    } else {
        for(i = vs->max/2; vs->data[i].elem == EMPTY; i = vs->data[i].link){}
        
        int alloced = allocSpace(vs);
        
        if(alloced != -1) { 
            vs->data[i].link = alloced;
            vs->data[alloced].elem = elem;
            vs->data[alloced].link = -1;
            if(vs->data[hashed].link == -1){
                vs->data[hashed].link = alloced; 
            }
            
            check = 1;
        }
    }
    
    return check;
}
bool removeElement(VSpace *vs, int elem) {
    bool check = 0; 
    int *i, temp, loc = hash(elem, vs->max);

    for(i = &loc; vs->data[*i].link != -1 && vs->data[*i].elem != elem; i = &vs->data[*i].link){}

    if(*i != -1){
        if(*i >= (vs->max/2)){

            temp = *i;
            *i = vs->data[*i].link;
            freeSpace(vs, temp);
            if(vs->data[loc].link == -1){
                vs->data[loc].elem = EMPTY; 
            }
            
        } else {
            
            if(vs->data[*i].link == -1){
                vs->data[loc].elem = EMPTY; 
                vs->data[loc].link = -1;
            } else {
                vs->data[loc].elem = DELETED;   
            }
        }
        check = 1;
    }
    
    return check;
}
void visualize(VSpace vs) {
    int i, half = vs.max/2;
    printf("%5s | %5s | %5s %10s %5s | %5s | %5s\n", "INDEX", "DATA", "LINK", "" , "INDEX", "DATA", "LINK");
    printf("----------------------          ----------------------\n");    
    for(i = 0; i < half; ++i) {
        printf("%5d | %5d | %5d %10s %5d | %5d | %5d\n",
                i, vs.data[i].elem, vs.data[i].link, "",
                i+half, vs.data[i+half].elem, vs.data[i+half].link);
        
    }
    printf("----------------------          ----------------------\n"); 
    printf("AVAILABLE: %d\n", vs.avail);
}

