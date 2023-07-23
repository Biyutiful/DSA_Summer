/******************************************************************************

Create an open hash array for student
 >  sorted by the last name > first name > middle name > id number
    > if everything the same then don't add
 >  max size = 26
 
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "open_hash.c"

int main()
{
    Student stud;
    Dictionary dict = newDictionary(26);

    Name n1 = {"Bianca", "Atengsu", "Asabel"};
    Name n2 = {"Aianca", "Btengsu", "Bsabel"};
    Name n3 = {"Aianca", "Btengsu", "Bsabel"};
    Name n4 = {"Bianca", "Atengsu", "Dsabel"};
    Name n5 = {"Cianca", "Atengsu", "Esabel"};

    MyDate d1 = {8, 1, 2002};
    MyDate d2 = {1, 2, 2001};
    MyDate d3 = {4, 1, 2003};
    MyDate d4 = {2, 5, 2003};
    MyDate d5 = {12, 11, 2004};
    
    Student s1 = newStudent("2", n1, 'f', d1, "BSCS", 2);
    Student s2 = newStudent("4", n2, 'm', d2, "BSCS", 2);
    Student s3 = newStudent("1", n3, 'f', d3, "BSCS", 2);
    Student s4 = newStudent("3", n4, 'f', d4, "BSCS", 2);
    Student s5 = newStudent("5", n5, 'm', d5, "BSCS", 2);

    insertSorted(&dict, s1);
    insertSorted(&dict, s2);
    insertSorted(&dict, s3);
    insertSorted(&dict, s4);
    insertSorted(&dict, s5);

    displayStudlist(dict);
    
    stud = deleteStud(&dict, "1"); 
    
    if(strcmp(stud.studID, "-")){
        printf("%s, %c. %c.\n", stud.studName.LName, stud.studName.FName[0],stud.studName.MName[0]);
    } else {
        printf("STUDENT NOT FOUND\n");
    }

    stud = accessStud(&dict, "2");

    if(strcmp(stud.studID, "-")){
        printf("%s, %c. %c.\n", stud.studName.LName, stud.studName.FName[0],stud.studName.MName[0]);
    } else {
        printf("STUDENT NOT FOUND\n");
    }

    visualizeDict(dict);
    return 0;
}
