/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "bst.c"

int main()
{
    BSTPtr list;
    list = newBST();
    
    BSTPtr head;
    initBST(&head);
    
    list = addElement(list, createProduct(1003,"Cake", 1, 120.00));
    
    inorderBST(list);
    printf("\n");

    insertBST(&list, createProduct(1000,"Pie", 1, 100.00));
    
    preorderBST(list);
    printf("\n");
    list = addElement(list, createProduct(1004,"Brownie", 1, 70.00));

    postorderBST(list);
    printf("\n");

    insertBST(&list, createProduct(1001,"Cookie", 1, 100.00));
    insertBST(&list, createProduct(1002,"Tart", 1, 100.00));
    insertBST(&list, createProduct(1005,"Cupcake", 1, 100.00));

    preorderBST(list);
    printf("\n");
    
    removeElement(list, 1001);

    preorderBST(list);
    printf("\n");

    removeElement(list, 1005);

    preorderBST(list);
    printf("\n");

    removeElement(list, 1003);

    preorderBST(list);
    printf("\n");

    insertBST(&list, createProduct(1001,"Cookie", 1, 100.00));
    insertBST(&list, createProduct(1006,"Macroon", 1, 100.00));
    insertBST(&list, createProduct(1005,"Cupcake", 1, 100.00));

    preorderBST(list);
    printf("\n");

    list = deleteElement(list, 1006);

    preorderBST(list);
    printf("\n");

    list = deleteElement(list, 1001);

    preorderBST(list);
    printf("\n");


    list = deleteElement(list, 1002);

    preorderBST(list);
    printf("\n");

    return 0;
}
