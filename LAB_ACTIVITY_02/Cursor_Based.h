#ifndef CURSOR_BASED_H
#define CURSOR_BASED_H

#define MAX 10

typedef char String[20];
typedef int Loc;
typedef int List;

typedef struct {
    int studID;
    String studName;
    char sex;
    String program;
} Student;

typedef struct {
    Student elem;
    Loc next;
} SType;

typedef struct{
    SType elems[MAX];
    Loc avail;
} VirtualHeap;

Student newStudent(int studID, String studName, char sex, String program);

VirtualHeap newVirtualHeap();
int allocSpace(VirtualHeap *VH);
void insertFront(VirtualHeap *VH, List *list, Student s);

void displayList(VirtualHeap VH, List list);
void visualizeSpace(VirtualHeap VH);

void deallocSpace(VirtualHeap *VH, Loc index);
Student removeStudent(VirtualHeap*VH, List *list, String keyword);
void displayStud(Student s);


#endif