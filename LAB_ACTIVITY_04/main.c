/******************************************************************************

Create a program implemnted using header files and c files.
Using of Virtual Heap Concept of the Cursor-based implementation as a shared 
space for both the 2 data structures and algorithms introduced (Stack & Queues)

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Date.h"
#include "Date.c"

/******************************************************************************

 > Create a menu
 > Implement necessary functions such as display and visualization
 > Implement the stack and queue operations

*******************************************************************************/

int main()
{
    
    int choice, i, value;
    String menuChoice[4] = {"Stack","Queue",
                            "isFull","Viszualize"};
                            
    String menuStack[7]  = {"Initialize",
                            "Push","Pop",
                            "isEmpty","Peak/Top",
                            "Display","Viszualize"};
                            
    String menuQueue[7]  = {"Initialize",
                            "Enqueue","Dequeue",
                            "isEmpty","Front",
                            "Display","Viszualize"};
    
    VirtualSpace vh = newVirtualSpace();
    Product p;
    Date d;
    do {
        system("cls");
        printf("MENU\n");
        for(i = 0; i < 4; ++i){
            printf("[%d] %s\n", i+1, menuChoice[i]);
        }
        printf("Enter your choice <0 to EXIT>: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                do {
                    system("cls");
                    printf("STACK MENU\n");
                    for(i = 0; i < 7; ++i){
                        printf("[%d] %s\n", i+1, menuStack[i]);
                    }
                    printf("Enter your choice <0 to RETURN>: ");
                    scanf("%d", &choice);
                    
                    switch(choice) {
                        case 1:
                            printf("| INITIALIZE |\n");
                            StackList s =  initStackR();
                            printf("STACK INITIALIZED \n");
                            break;
                        case 2:
                            printf("| PUSH |\n");
                            printf("Enter a product(enter after every prompt): ");
                            printf("Product ID: ");
                            scanf("%d", &p.prodID);
                            printf("Product Name: ");
                            scanf("%s", &p.prodName);
                            printf("Product Qty: ");
                            scanf("%d", &p.prodQty);
                            printf("Product Price: ");
                            scanf("%lf", &p.prodPrice);
                            printf("Product Exp(DD MM YY): ");
                            scanf("%d %d %d", &p.prodExp.date, &p.prodExp.month, &p.prodExp.year);

                            push(&vh, &s, newProduct(p.prodID, p.prodName, p.prodQty, p.prodPrice, p.prodExp));
                            visualStack(vh,s);
                            break;
                        case 3:
                            printf("| POP |\n");
                            // pop(&vh, &s);
                            displayProduct(popR(&vh, &s));
                            break;
                        case 4:
                            printf("| ISEMPTY |\n");
                            isEmptyStack(s)? printf("   > is EMPTY\n") : printf("   > is NOT EMPTY\n");
                            visualStack(vh,s);
                            break;
                        case 5:
                            printf("| PEAK / TOP |\n");
                            displayProduct(top(vh, s));
                            break;
                        case 6:
                            printf("| DISPLAY |\n");
                            displayStack(vh, s);
                            break;
                        case 7:
                            printf("| VISUALIZE |\n");
                            visualStack(vh, s);
                            break;
                        case 0:
                            printf("Returning\n");
                            continue;
                        default:
                            printf("Invalid Choice...\n");
                            break;
                    }
                    system("pause");
                } while (choice != 0);
                break;
            case 2:
                do {
                    system("cls");
                    printf("QUEUE MENU\n");
                    for(i = 0; i < 7; ++i){
                        printf("[%d] %s\n", i+1, menuQueue[i]);
                    }
                    printf("Enter your choice <0 to RETURN>: ");
                    scanf("%d", &choice);
                    switch(choice) {
                        case 1:
                            printf("| INITIALIZE |\n");
                            Queue q = initQueueR();
                            printf("QUEUE INITIALIZED \n");
                            break;
                        case 2:
                            printf("| ENQUEUE |\n");
                            printf("Enter a product(enter after every prompt): ");
                            printf("Product ID: ");
                            scanf("%d", &p.prodID);
                            printf("Product Name: ");
                            scanf("%s", &p.prodName);
                            printf("Product Qty: ");
                            scanf("%d", &p.prodQty);
                            printf("Product Price: ");
                            scanf("%lf", &p.prodPrice);
                            printf("Product Exp(DD MM YY): ");
                            scanf("%d %d %d", &p.prodExp.date, &p.prodExp.month, &p.prodExp.year);

                            enqueue(&vh, &q, p);
                            visualQueue(vh, q);
                            break;
                        case 3:
                            printf("| DEQUEUE |\n");
                            displayProduct(dequeueR(&vh, &q));
                            break;
                        case 4:
                            printf("| ISEMPTY |\n");
                            isEmptyQueue(q)? printf("   > is EMPTY\n") : printf("   > is NOT EMPTY\n");
                            break;
                        case 5:
                            printf("| FRONT |\n");
                            displayProduct(front(vh, q));
                            break;
                        case 6:
                            printf("| DISPLAY |\n");
                            displayQueue(vh, q);
                            break;
                        case 7:
                            printf("| VISUALIZE |\n");
                            visualQueue(vh, q);
                            break;
                        case 0:
                            printf("Returning\n");
                            continue;
                        default:
                            printf("Invalid Choice...\n");
                            break;
                    }
                    system("pause");
                } while (choice != 0);
                break;
            case 3:
                printf("| ISFULL |\n");
                isFull(vh)? printf("   > is FULL\n") : printf("   > is NOT FULL\n");
                break;
            case 4:
                printf("| VISUALIZE |\n");
                visualizeSpace(vh);
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