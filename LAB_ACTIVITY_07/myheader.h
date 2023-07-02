#ifndef MY_HEADER_H
#define MY_HEADER_H
#include <stdbool.h>

#define EMPTY 0
#define DELETED -1

typedef struct {
    int elem;
    int link;
} Data;

typedef struct {
    Data *data;
    int avail;
    int count;
    int max;
} VSpace;

VSpace newVSpace(int max);
int allocSpace(VSpace *vs);
void freeSpace(VSpace *vs, int loc);
int hash(int val, int size);
bool addElement(VSpace *vs, int elem);
bool removeElement(VSpace *vs, int elem);
void visualize(VSpace vs);
#endif