#include <stdio.h>
#include <stdlib.h>
#include "Cursor_Based.c"

int main()
{
    VirtualHeap myHeap = newVirtualHeap();
    List myList = -1;
    
    // visualizeSpace(myHeap);

    insertFront(&myHeap,&myList,newStudent(101,"Jonathan",'m',"BS IT"));
    insertFront(&myHeap,&myList,newStudent(105,"Sebastian",'m',"BS CS"));
    
    visualizeSpace(myHeap);
    printf("\n");
    displayList(myHeap, myList);
    printf("\n");
    
    insertFront(&myHeap,&myList,newStudent(107,"Abby",'f',"BS CS"));
    insertFront(&myHeap,&myList,newStudent(109,"Katherine",'f',"BS IS"));
    insertFront(&myHeap,&myList,newStudent(111,"Ralph",'f',"BS IT"));
    
    displayList(myHeap, myList);
    printf("\n");
    
    displayStud(removeStudent(&myHeap, &myList, "Ralph"));
    printf("\n");
    
    displayList(myHeap, myList);
    printf("\n");
    visualizeSpace(myHeap);
    return 0;
}