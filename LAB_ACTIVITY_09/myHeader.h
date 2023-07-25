#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>

#define DICTMAX 5

typedef char String[20];

typedef struct{
    String *nearby;
    int count;
} arrList;

typedef struct{
    arrList list;
    String key;
} arrNode;

typedef struct{
    arrNode map[DICTMAX];
    int dcount;
} Dictionary;

void initDict(Dictionary *d);
bool searchVertex(Dictionary d, String data);
bool searchEdge(Dictionary d, String main, String nearby);
void addVertex(Dictionary *d, String data); //node
void addEdge(Dictionary *d, String main, String nearby); //connection
void removeVertex(Dictionary *d, String data);
void removeEdge(Dictionary *d, String main, String nearby);
int hash(char initial);
void display(Dictionary d);
#endif