insertRear(&oddList, 7)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertSorted(&oddList, 5)? printf("ADDED\n"):printf("NOT ADDED\n");
	insertAt(&oddList, 3, 2)? printf("ADDED\n"):printf("NOT ADDED\n");
	searchItem(oddList, 3)? printf("FOUND\n"):printf("NOT FOUND\n");
	getItem(oddList, 5)? printf("%d is FOUND\n", getItem(oddList, 5)):printf("IS NOT FOUND\n");