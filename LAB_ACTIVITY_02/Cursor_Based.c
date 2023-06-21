#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cursor_Based.h"

Student newStudent(int studID, String studName, char sex, String program) {
    Student s;
    
    s.studID = studID;
    strcpy(s.studName, studName);
    s.sex = sex;
    strcpy(s.program, program);
    
    return s;
}

VirtualHeap newVirtualHeap() {
    VirtualHeap vh;

    int i;
    for(i = 0; i < MAX; ++i){
        vh.elems[i].elem = newStudent(0,"",' ',"");
        vh.elems[i].next = i-1;
    }
    vh.avail = MAX-1;

    return vh;
}
int allocSpace(VirtualHeap *VH) {
    int retVal = VH->avail;
    
    if(retVal != -1) {
        VH->avail = VH->elems[VH->avail].next;
    }
    
    return retVal;
}
void insertFront(VirtualHeap *VH, List *list, Student s) {
    List temp = allocSpace(VH);
    
    if(temp != -1){
        VH->elems[temp].next = *list;
        VH->elems[temp].elem = s;
        *list = temp;
    }
}

void displayList(VirtualHeap VH, List list) {
    int i;
    printf("%5s | %20s | %5s | %5s\n", "ID", "NAME", "SEX", "PROGRAM");
    printf("-------------------------------------------------\n");
    
    for(i = list; i>-1; i = VH.elems[i].next) {
        printf("%5d | ", VH.elems[i].elem.studID);
        printf("%20s | ", VH.elems[i].elem.studName);
        printf("%5c | ", VH.elems[i].elem.sex);
        printf("%5s\n", VH.elems[i].elem.program);
    }
    
    printf("-------------------------------------------------\n");
    printf("AVAILABLE: %d\n", VH.avail);
}
void visualizeSpace(VirtualHeap VH) {
    int i;
    
    printf("%5s | %30s | %s\n", "INDEX", "ELEMENTS", "NEXT");
    printf("---------------------------------------------\n");
    for(i = 0;i < MAX; ++i){
        printf("%5d | ", i);
        if(VH.elems[i].elem.studID==0){
            printf("%30s  | ", "EMPTY");
        } else{
            printf("%4d  - %23s | ", VH.elems[i].elem.studID, VH.elems[i].elem.studName);
        }
        printf("%d\n", VH.elems[i].next);
    }
    printf("---------------------------------------------\n");
    printf("AVAILABLE: %d\n", VH.avail);
}

void deallocSpace(VirtualHeap *VH, Loc index){
    if(index != -1 && index<MAX){
        VH->elems[index].next = VH->avail;
        VH->elems[index].elem = newStudent(0,"",' ',"");
        VH->avail = index;
    }
}

Student removeStudent(VirtualHeap*VH, List *list, String keyword){
    int *i;
    Student remStud;
    for(i = list; i > -1 && strcmp(keyword,VH->elems[*i].elem.studName)>0; *i = VH->elems[*i].next){}
    
    if(*i!=-1) {
        remStud = VH->elems[*i].elem;
        List temp = *i;
        *i = VH->elems[*i].next;
        deallocSpace(VH, temp);
        
    }
    
    return remStud;
}

void displayStud(Student s){
    printf("DELETED STUDENT\n");
    printf("-------------------------------------------------\n");
        printf("%5d | ", s.studID);
        printf("%20s | ", s.studName);
        printf("%5c | ", s.sex);
        printf("%5s\n", s.program);
    
    printf("-------------------------------------------------\n");
}