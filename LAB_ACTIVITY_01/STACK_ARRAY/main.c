#include <stdio.h>
#include <stdlib.h>
#include "StackARR.h"
#include "StackARR.c"

int main()
{
    Stack pancakes;
    initStack(&pancakes);
    isEmpty(pancakes)? printf("is EMPTY\n"):printf("NOT EMPTY\n");
    isFull(pancakes)? printf("is FULL\n"):printf("NOT FULL\n");

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
    
    isEmpty(pancakes)? printf("is EMPTY\n"):printf("NOT EMPTY\n");
    isFull(pancakes)? printf("is FULL\n"):printf("NOT FULL\n");

    display(pancakes);
    visualize(pancakes);

    top(pancakes)? printf("TOP is %d\n", top(pancakes)):printf("TOP NOT FOUND\n");

    push(&pancakes, 7);
    push(&pancakes, 6);
    push(&pancakes, 5);
    push(&pancakes, 4);
    push(&pancakes, 3);
    push(&pancakes, 2);
    push(&pancakes, 1);

    isEmpty(pancakes)? printf("is EMPTY\n"):printf("NOT EMPTY\n");
    isFull(pancakes)? printf("is FULL\n"):printf("NOT FULL\n");
    
    display(pancakes);
    visualize(pancakes);

    top(pancakes)? printf("TOP is %d\n", top(pancakes)):printf("TOP NOT FOUND\n");

    return 0;
}