#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedList.c"

int main(int argc, char *argv[]) {

	List evenList;
	initList(&evenList);
	// List evenList = newList();

	insertFront(&evenList, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertRear(&evenList, 8)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertAt(&evenList, 4, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&evenList, 6)? printf("ADDED\n"):printf("NOT ADDED\n");
	searchItem(evenList, 5)? printf("FOUND\n"):printf("NOT FOUND\n");
	getItem(evenList, 4)? printf("%d is FOUND\n", getItem(evenList, 4)):printf("IS NOT FOUND\n");
	displayList(evenList);

	insertRear(&evenList, 9)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&evenList, 5)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertAt(&evenList, 3, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertFront(&evenList, 1)? printf("ADDED\n"):printf("NOT ADDED\n");
	displayList(evenList);

	deleteFront(&evenList)? printf("DELETED\n"):printf("NOT DELETED\n");
	displayList(evenList);
	deleteRear(&evenList)? printf("DELETED\n"):printf("NOT DELETED\n");
	displayList(evenList);
	deleteAt(&evenList, 2)? printf("DELETED\n"):printf("NOT DELETED\n");
	displayList(evenList);
	deleteItem(&evenList, 5)? printf("5 is DELETED\n"):printf("NOT DELETED\n");
	displayList(evenList);
	deleteAllItem(&evenList, 0)? printf("LIST DELETED\n"):printf("NOT DELETED\n");
	return 0;
}
