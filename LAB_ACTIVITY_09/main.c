/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include "myHeader.c"
int main()
{
    Dictionary d;

    initDict(&d);

    addVertex(&d, "Manila");
    addVertex(&d, "Cebu");
    addVertex(&d, "Davao");
    addVertex(&d, "Iloilo");
    addVertex(&d, "Zamboanga");

    addEdge(&d, "Manila", "Cebu");
    addEdge(&d, "Manila", "Zamboanga");

    addEdge(&d, "Cebu", "Davao");
    addEdge(&d, "Cebu", "Iloilo");

    addEdge(&d, "Davao", "Manila");
    addEdge(&d, "Davao", "Cebu");
    
    addEdge(&d, "Iloilo", "Manila");
    addEdge(&d, "Iloilo", "Zamboanga");

    addEdge(&d, "Zamboanga", "Cebu");
    addEdge(&d, "Zamboanga", "Davao");

    removeVertex(&d, "Manila");
    removeEdge(&d, "Zamboanga", "Davao");

    display(d);

    printf("%d", searchEdge(d, "Manila", "Cebu"));

    return 0;
}
