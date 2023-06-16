#include <stdio.h>
#include <stdlib.h>
// include the library you want to test
// #include "StaticArray.c"
#include "DynamicArray.c"

int main(int argc, char *argv[]) {
	
	// List evenList = newList();
	// List evenList;
	// initList(&evenList);

	// insertFront(&evenList, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	// insertRear(&evenList, 8)? printf("ADDED\n"):printf("NOT ADDED\n");
	// insertSorted(&evenList, 6)? printf("ADDED\n"):printf("NOT ADDED\n");
	// insertAt(&evenList, 4, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	// searchItem(evenList, 5)? printf("FOUND\n"):printf("NOT FOUND\n");
	// getItem(evenList, 3)? printf("%d is FOUND\n", getItem(evenList, 3)):printf("IS NOT FOUND\n");

	// insertRear(&evenList, 9)? printf("ADDED\n"):printf("NOT ADDED\n");
	// insertSorted(&evenList, 5)? printf("ADDED\n"):printf("NOT ADDED\n");
	// insertSorted(&evenList, 3)? printf("ADDED\n"):printf("NOT ADDED\n");
	// insertSorted(&evenList, 1)? printf("ADDED\n"):printf("NOT ADDED\n");
	// displayList(evenList);

	// deleteFront(&evenList)? printf("DELETED\n"):printf("NOT DELETED\n");
	// displayList(evenList);
	// deleteRear(&evenList)? printf("DELETED\n"):printf("NOT DELETED\n");
	// displayList(evenList);
	// deleteAt(&evenList, 2)? printf("DELETED\n"):printf("NOT DELETED\n");
	// displayList(evenList);
	// deleteItem(&evenList, 5)? printf("5 is DELETED\n"):printf("NOT DELETED\n");
	// displayList(evenList);
	// deleteAllItem(&evenList, 0)? printf("LIST DELETED\n"):printf("NOT DELETED\n");


	// List oddList;
	// initList(&oddList);
	List oddList = newList(10);
	
	insertFront(&oddList, 3)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertRear(&oddList, 9)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&oddList, 7)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertAt(&oddList, 5, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	searchItem(oddList, 5)? printf("FOUND\n"):printf("NOT FOUND\n");
	getItem(oddList, 7)? printf("%d is FOUND\n", getItem(oddList, 7)):printf("is NOT FOUND\n");
	displayList(oddList);

	insertRear(&oddList, 10)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&oddList, 6)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&oddList, 4)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&oddList, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	displayList(oddList);

	deleteFront(&oddList)? printf("DELETED\n"):printf("NOT DELETED\n");
	displayList(oddList);
	deleteRear(&oddList)? printf("DELETED\n"):printf("NOT DELETED\n");
	displayList(oddList);
	deleteAt(&oddList, 2)? printf("DELETED\n"):printf("NOT DELETED\n");
	displayList(oddList);
	deleteItem(&oddList, 5)? printf("5 is DELETED\n"):printf("NOT DELETED\n");
	displayList(oddList);
	deleteAllItem(&oddList, 0)? printf("LIST DELETED\n"):printf("NOT DELETED\n");
	free(oddList.elems);

	return 0;
}
