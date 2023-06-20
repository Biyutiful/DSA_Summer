#include <stdio.h>
#include <stdlib.h>
#include "StackLIST.h"
#include "StackLIST.c"

int main()
{
    List pancakes;
    initStack(&pancakes);
    isEmpty(&pancakes)? printf("is EMPTY\n"):printf("NOT EMPTY\n");

    push(&pancakes, 10);
    push(&pancakes, 9);
    push(&pancakes, 8);
    push(&pancakes, 11);
    push(&pancakes, 12);

    display(pancakes);
    visualize(pancakes);

    top(pancakes)? printf("TOP is %d\n", top(pancakes)):printf("TOP NOT FOUND\n");
    
    pop(&pancakes);
    pop(&pancakes);
    
    isEmpty(&pancakes)? printf("is EMPTY\n"):printf("NOT EMPTY\n");

    display(pancakes);
    visualize(pancakes);

    top(pancakes)? printf("TOP is %d\n", top(pancakes)):printf("TOP NOT FOUND\n");

    isEmpty(&pancakes)? printf("is EMPTY\n"):printf("NOT EMPTY\n");

    pop(&pancakes);
    pop(&pancakes);
    pop(&pancakes);
    
    display(pancakes);
    visualize(pancakes);

    top(pancakes)? printf("TOP is %d\n", top(pancakes)):printf("TOP NOT FOUND\n");

    return 0;
}