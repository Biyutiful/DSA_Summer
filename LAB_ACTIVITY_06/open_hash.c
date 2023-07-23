#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "open_hash.h"

Student newStudent(String studID, Name studName, char sex, MyDate birthday, String program, int year) {
    Student student = {"-",'-', sex, '-', "-", year};

    strcpy(student.studID, studID);
    strcpy(student.program, program);

    student.studName = studName;
    student.birthday = birthday;

    return student;
}
//Create an open hash array for student and max size = 26
Dictionary newDictionary(int max) {
    Dictionary dict = {NULL, 0, max};

    dict.studList = (SType *) malloc(sizeof(SType) * max);

    int ctr;
    for (ctr=0 ; ctr<max ; ctr++) {
        dict.studList[ctr] = NULL;
    }

    return dict;
}
void initDict(Dictionary *d, int size) {
    if (d->studList != NULL) free(d->studList);

    d->studList = (SType *) malloc(sizeof(SType) * size);
    d->count = 0;
    d->max = size;

    int ctr;
    for (ctr=0 ; ctr<size ; ctr++) {
        d->studList[ctr] = NULL;
    }
}
//Insert sorted by the last name > first name > middle name > id number and if everything the same then don't add
void insertSorted(Dictionary *d, Student s) {
    int hashVal = hash(d, s);
    SType *trav, newNode;

    for (trav=&d->studList[hashVal] ; *trav!=NULL ;) {
        if (strcmp((*trav)->s.studName.LName, s.studName.LName) < 0
            ||
            strcmp((*trav)->s.studName.FName, s.studName.FName) < 0
            ||
            strcmp((*trav)->s.studName.MName, s.studName.MName) < 0
            ||
            strcmp((*trav)->s.studID, s.studID) < 0) {
            trav=&(*trav)->link;
        } else break;
    }

    newNode = (SType) malloc(sizeof(struct node));
    
    if (newNode != NULL && (*trav)->s.studID!=s.studID) {
        newNode->s = newStudent(s.studID, s.studName, s.sex, s.birthday, s.program, s.year);
        newNode->link = *trav;

        *trav = newNode;

        d->count++;
    }
    
}

Student deleteStud(Dictionary *d, String id) {
    Student stud;
    int ctr;
    SType deleted = NULL, *trav, temp;

    for (ctr = 0; ctr < d->max && deleted == NULL; ctr++) {
        for (trav = &d->studList[ctr]; *trav != NULL && strcmp((*trav)->s.studID, id) != 0; trav = &(*trav)->link) {}

        if (*trav != NULL && strcmp((*trav)->s.studID, id) == 0) {
            deleted = *trav;
        }
    }

    if (deleted != NULL) {
        temp = deleted;
        stud = deleted->s;

        *trav = deleted->link;
        free(temp);

        d->count--;
        return stud;
    }

    Student emptyStudent = { .studID = "-" };
    return emptyStudent;
}

Student accessStud(Dictionary *d, String id) {
    int ctr;
    SType found = NULL;

    for (ctr = 0; ctr < d->max && found == NULL; ctr++) {
        for (SType *trav = &d->studList[ctr]; *trav != NULL; trav = &(*trav)->link) {
            if (strcmp((*trav)->s.studID, id) == 0) {
                found = *trav;
                break;
            }
        }
    }

    if (found != NULL) {
        return found->s;
    }

    Student emptyStudent = { .studID = "-" };
    return emptyStudent;
}

// Display the lastname, then initial of firstname and middlename
void visualizeDict(Dictionary d) {
    int i;
    SType trav;
    for(i=0; i<d.max; i++){
        printf(" %c | ", 'A'+i); 
        for (trav=d.studList[i] ; trav!=NULL ; trav=trav->link) {
            printf("%8s, %1c. %1c. %1s", 
                    trav->s.studName.LName,
                    trav->s.studName.FName[0],
                    trav->s.studName.MName[0],
                    " ");
        }
        printf("\n"); 
    } 
}

void displayStudlist(Dictionary d) {
    printf("STUDENT LIST\n");
    printf("%10s | %10s | %10s \n", "LASTNAME","FIRSTNAME","MIDDLENAME");
    printf("-------------------------------------\n");
    int ctr;
    SType trav;
    for (ctr=0 ; ctr<d.max ; ctr++) {
        for (trav=d.studList[ctr] ; trav!=NULL ; trav=trav->link) {
            printf("%10s,   %7s,   %6c.\n", 
                    trav->s.studName.LName,
                    trav->s.studName.FName,
                    trav->s.studName.MName[0]);
        }
    }
    printf("-------------------------------------\n");
}

int hash(Dictionary *d, Student s) {
    return (s.studName.LName[0] - 'A') % d->max;
}