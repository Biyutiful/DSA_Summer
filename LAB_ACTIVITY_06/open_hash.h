#ifndef OPEN_HASH_H
#define OPEN_HASH_H

typedef char String[30];

typedef struct {
    String FName, LName, MName;
} Name;

typedef struct {
    int day, month, year;
} MyDate;

typedef struct {
    String studID;
    Name studName;
    char sex;
    MyDate birthday;
    String program;
    int year;
} Student;

typedef struct node{
    Student s;
    struct node *link;
} *SType;

typedef struct{
    SType *studList;
    int count;
    int max;
} Dictionary;

Student newStudent(String studID, Name studName, char sex, MyDate birthday, String program, int year);
Dictionary newDictionary();
void initDict(Dictionary *d, int size);
void insertSorted(Dictionary *d, Student s);
Student deleteStud(Dictionary *d, String id);
Student accessStud(Dictionary *d, String id);
void visualizeDict(Dictionary d);
void displayStudlist(Dictionary d);

#endif
