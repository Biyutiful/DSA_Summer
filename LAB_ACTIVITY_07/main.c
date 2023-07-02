/******************************************************************************

    VSpace = Dictionary

*******************************************************************************/
#include <stdio.h>
// #include "myheader.h"
#include "myheader.c"
int main()
{
    VSpace space = newVSpace(10);
    
    addElement(&space, 10)? printf("ADDED\n") : printf("NOT ADDED\n");
    addElement(&space, 11)? printf("ADDED\n") : printf("NOT ADDED\n");
    // addElement(&space, 12)? printf("ADDED\n") : printf("NOT ADDED\n");
    // addElement(&space, 13)? printf("ADDED\n") : printf("NOT ADDED\n");
    // addElement(&space, 14)? printf("ADDED\n") : printf("NOT ADDED\n");
    addElement(&space, 20)? printf("ADDED\n") : printf("NOT ADDED\n");
    addElement(&space, 30)? printf("ADDED\n") : printf("NOT ADDED\n");
    visualize(space);

    removeElement(&space,20)? printf("REMOVED\n") : printf("NOT REMOVED\n");
    visualize(space);
    removeElement(&space,10)? printf("REMOVED\n") : printf("NOT REMOVED\n");
    visualize(space);
    removeElement(&space,11)? printf("REMOVED\n") : printf("NOT REMOVED\n");
    visualize(space);
    removeElement(&space,30)? printf("REMOVED\n") : printf("NOT REMOVED\n");
    visualize(space);
    return 0;
}
