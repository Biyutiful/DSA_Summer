/******************************************************************************

SETS

*******************************************************************************/
#include <stdio.h>
// #include "sets.h"
#include "sets.c"

int main()
{
    int count;
    Set setA = newSet();
    addElement(&setA, 1)? printf(" 1 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setA, 2)? printf(" 2 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setA, 3)? printf(" 3 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setA, 5)? printf(" 5 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setA, 7)? printf(" 7 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setA, 8)? printf(" 8 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setA, 9)? printf(" 9 is ADDED\n"): printf(" NOT ADDED\n");

    // visualizeSet(setA);
    displaySet(setA);

    
    removeElement(&setA, 2)? printf(" 2 is REMOVED\n"): printf(" NOT REMOVED\n");
    removeElement(&setA, 8)? printf(" 8 is REMOVED\n"): printf(" NOT REMOVED\n");

    // visualizeSet(setA);
    displaySet(setA);
    
    count = cardinality(setA);
    count ? printf("\nCARDINALITY: %d \n", count): printf("\nCARDINALITY: NOT FOUND\n");

    Set setB = newSet();
    addElement(&setB, 1)? printf(" 1 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setB, 2)? printf(" 2 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setB, 4)? printf(" 4 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setB, 6)? printf(" 6 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setB, 8)? printf(" 8 is ADDED\n"): printf(" NOT ADDED\n");
    addElement(&setB, 9)? printf(" 9 is ADDED\n"): printf(" NOT ADDED\n");
    // visualizeSet(setB);
    displaySet(setB);;
    
    // removeElement(&setB, 1)? printf(" 1 is REMOVED\n"): printf(" NOT REMOVED\n");
    // removeElement(&setB, 9)? printf(" 9 is REMOVED\n"): printf(" NOT REMOVED\n");

    // visualizeSet(setB);
    displaySet(setB);

    count = cardinality(setB);
    count ? printf("\nCARDINALITY: %d \n", count): printf("\nCARDINALITY: NOT FOUND\n");

    displaySet(unionSet(setA, setB));
    displaySet(intersectionSet(setA, setB));
    displaySet(differenceSet(setA, setB));
    displaySet(differenceSet(setB, setA));
    displaySet(symmetricDiffSet(setA, setB));
}
