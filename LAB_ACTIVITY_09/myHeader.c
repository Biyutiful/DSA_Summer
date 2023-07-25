#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myHeader.h"

void initDict (Dictionary * d) {
  d->dcount = 0;

  int ctr;
  for (ctr = 0; ctr < DICTMAX; ctr++) {
      strcpy (d->map[ctr].key, "EMPTY");
      d->map[ctr].list.count = 0;
      d->map[ctr].list.nearby = (String *) malloc(sizeof(String) * (DICTMAX-1));
    }
}

bool searchVertex(Dictionary d, String data) {
    int hashVal = hash(data[0]), i, count = 0;
        
    for(i = hashVal; ++count < DICTMAX 
                     && strcmp(d.map[i].key, data) != 0 
                     && strcmp(d.map[i].key, "EMPTY") != 0
                   ; i = (i+1) % DICTMAX) {}
                   
    return strcmp(d.map[i].key, data) == 0;
}

bool searchEdge(Dictionary d, String main, String nearby) {
    int hashVal = hash(main[0]), i, count = 0;
        
    for(i = hashVal; ++count < DICTMAX 
                     && strcmp(d.map[i].key, main) != 0 
                     && strcmp(d.map[i].key, "EMPTY") != 0
                   ; i = (i+1) % DICTMAX) {}
                   
    if (strcmp(d.map[i].key, main) == 0) {
      int ctr;
      for (ctr=0 ; ctr<d.map[i].list.count && strcmp(d.map[i].list.nearby[ctr], nearby) != 0 ; ctr++) {}

      return ctr<d.map[i].list.count;
    }

    return 0;
}

//node
void addVertex (Dictionary * d, String data) {
  if(!searchVertex(*d, data)){
      int hashVal = hash(data[0]), i, count = 0;
        
      for(i = hashVal; ++count < DICTMAX && strcmp(d->map[i].key, "EMPTY") != 0; i = (i+1) % DICTMAX) {}

      if(count-1 < DICTMAX && strcmp(d->map[i].key, "EMPTY") == 0) {
          strcpy(d->map[i].key, data);

          d->dcount++;
      }
  }
}

//connection
void addEdge (Dictionary *d, String main, String nearby) {
    if (searchVertex(*d, main) && searchVertex(*d, nearby) && !searchEdge(*d, main, nearby)) {
      int hashVal = hash(main[0]), i;
        
      for(i = hashVal; strcmp(d->map[i].key, main) != 0 ; i = (i+1) % DICTMAX) {}

      strcpy(d->map[i].list.nearby[d->map[i].list.count++], nearby);
    }
}

void removeVertex(Dictionary *d, String data) {
    if (searchVertex(*d, data)) {
      int hashVal = hash(data[0]), i, ctr;
        
      for (i = hashVal; strcmp(d->map[i].key, data) != 0 ; i = (i+1) % DICTMAX) {}

      strcpy(d->map[i].key, "EMPTY");
      d->map[i].list.count = 0;

      d->dcount--;

      for (ctr=0 ; ctr<DICTMAX ; ctr++) {
        if (strcmp(d->map[ctr].key, "EMPTY") == 0) continue;

        for (i=0 ; i<d->map[ctr].list.count && strcmp(d->map[ctr].list.nearby[i], data) != 0 ; i = (i+1) % DICTMAX) {}

        if (i<d->map[ctr].list.count) {
          memcpy(d->map[ctr].list.nearby[i], d->map[ctr].list.nearby[i+1], sizeof(String) * (d->map[ctr].list.count-i-1));
          d->map[ctr].list.count--;
          continue;
        }
      }
    }
}

void removeEdge(Dictionary *d, String main, String nearby) {
  if (searchVertex(*d, main) && searchEdge(*d, main, nearby)) {
    int hashVal = hash(main[0]), i, ctr;
        
    for (i = hashVal; strcmp(d->map[i].key, main) != 0 ; i = (i+1) % DICTMAX) {}
    for (ctr = 0 ; strcmp(d->map[i].list.nearby[ctr],nearby) != 0 ; ctr++) {}

    memcpy(d->map[i].list.nearby[ctr], d->map[i].list.nearby[ctr+1], sizeof(String) * (d->map[i].list.count-ctr-1));
    d->map[i].list.count--;
  }
}

int hash (char initial) {
  return initial % DICTMAX;
}

void display(Dictionary d) {
  int nodeCount = 0;
  printf("Total Vertices: %d\n", d.dcount);

  int ctr;
  for (ctr=0 ; ctr<DICTMAX ; ctr++) {
    if (strcmp(d.map[ctr].key, "EMPTY")) {
      printf("Vertex %d - %s: ", ++nodeCount, d.map[ctr].key);

      printf("[ ");

      int temp;
      for (temp=0 ; temp<d.map[ctr].list.count ; temp++) {
        printf("%s ", d.map[ctr].list.nearby[temp]);
      }

      printf("]");

      printf("\n");
    }
  }
}