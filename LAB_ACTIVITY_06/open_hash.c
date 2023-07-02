#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "open_hash.h"

Student newStudent(String studID, String FName, String MName, String LName, char sex, MyDate birthday, String program, int year){
    Student s;
    strcpy(s.studID, studID);
    strcpy(s.studName.LName, LName);
    strcpy(s.studName.FName, FName);
    strcpy(s.studName.MName, MName);
    s.sex = sex;
    s.birthday = birthday;
    strcpy(s.program, program);
    s.year = year;
}
//Create an open hash array for student and max size = 26
Dictionary newDictionary(int max) {
    
}
void initDict(Dictionary *d, int size) {
    int i;

    d->count = 0;
    d->max = size;
    
    d->studList = malloc(sizeof(Student) * d->max);
    MyDate defaultbday = {0};
    for(i=0; i<d->max; i++){
        d->studList[i].s = newStudent("0", "EMPTY", " ", " ", ' ', defaultbday, " ", 0);
    }
}
int hash(Dictionary *d) {

}
//Insert sorted by the last name > first name > middle name > id number and if everything the same then don't add
void insertSorted(Dictionary *d, Student s) {
    Dictionary *trav;
    // if( ){

    // }
}
Student deleteStud(Dictionary *d) {

}
Student accessStud(Dictionary *d) {

}
// Display the lastname, then initial of firstname and middlename
void visualizeDict(Dictionary d) {

}
void displayStudlist(Dictionary d) {

}
