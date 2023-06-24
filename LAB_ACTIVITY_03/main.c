#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Circular.h"
#include "Circular.c"

int main()
{
    Queue myQueue;
    int choice, i, value;
    initQueue(&myQueue);
    String menuOption[10] = {"Enqueue","Dequeue",
                            "isEmpty","isFull",
                            "Display","Viszualize",
                            "Front", "Double The Value",
                            "Remove Item", "Remove Even"};
    do {
        system("cls");
        printf("MENU\n");
        for(i = 0; i < 10; ++i){
            printf("[%d] %s\n", i+1, menuOption[i]);
        }
        printf("Enter your choice <0 to EXIT>: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("| ENQUEUE |\n");
                printf("Enter a number: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                visualize(myQueue);
                break;
            case 2:
                printf("| DEQUEUE |\n");
                dequeue(&myQueue);
                visualize(myQueue);
                break;
            case 3:
                printf("| ISEMPTY |\n");
                isEmpty(myQueue)? printf("   > is EMPTY\n") : printf("   > is NOT EMPTY\n");
                break;
            case 4:
                printf("| ISFULL |\n");
                isFull(myQueue)? printf("   > is FULL\n") : printf("   > is NOT FULL\n");
                break;
            case 5:
                printf("| DISPLAY |\n");
                display(myQueue);
                break;
            case 6:
                printf("| VISUALIZE |\n");
                visualize(myQueue);
                break;
            case 7:
                printf("| FRONT |\n");
                front(myQueue)!=EMPTY? printf("   > %d is FOUND\n", front(myQueue)) : printf("   > is NOT FOUND\n");
                break;
            case 8:
                printf("| DOUBLE THE VALUE |\n");
                printf("Enter the root number: ");
                scanf("%d", &value);
                int count = doubleTheValue(&myQueue, value);
                count!=EMPTY? printf("   > %d HAVE CHANGED\n", count) : printf("   > NO CHANGE\n");
                break;
            case 9:
                printf("| REMOVE ITEM |\n");
                printf("Enter the number to remove: ");
                scanf("%d", &value);
                bool check = removeItem(&myQueue, value);
                check? printf("   > %d is REMOVED\n", value) : printf("   > %d is NOT REMOVED\n", value);
                break;
            case 10:
                printf("| REMOVE EVEN |\n");
                Queue evenQ;
                initQueue(&evenQ);
                evenQ = removeEven(&myQueue);
                display(evenQ);
                break;
            case 0:
                printf("Thank you\n");
                break;
            default:
                printf("Invalid Choice...\n");
                break;
        }
        system("pause");
    } while (choice != 0);
    printf("\nBye\n");

    return 0;
}
