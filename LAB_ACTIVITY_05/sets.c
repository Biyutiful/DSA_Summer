#include <stdio.h>
#include "sets.h"

Set newSet(){
    Set s;
    int i;
    
    s.count = 0;
    
    for(i = 0; i < MAX; i++) {
        s.elems[i] = 0;
    }
    
    return s;
}
bool addElement(Set *s, int item) {
    bool check = false;
    
    if(s->elems[item] == 0){
        s->elems[item] = 1;
        s->count++;
        check = true;
    }
    
    return check;
}
bool removeElement(Set *s, int item) {
    bool check = false;
    
    if(s->elems[item] == 1){
        s->elems[item] = 0;
        s->count--;
        check = true;
    }
    
    return check;
}
void displaySet(Set s) {
    int i, ctr = 1;
    printf("\n| SET DISPLAY |\n\n");
    if(s.count != 0) {
        printf("{ ");
        for(i = 0; i < MAX; i++) {
            if(s.elems[i] != 0 != 0) {
                printf("%d ", i);
            }
            if(s.elems[i] != 0 && ctr != s.count) {
                printf(", ");
                ctr++;
            }
        }
        printf("}\n");
    }
}
void visualizeSet(Set s) {
    int i;
    printf("\n| SET VISUALIZE |\n");
    printf("\n-----------------------------------------------------------------------\n");
    printf("%7s |", "DATA");
    for(i = 0; i < MAX; i++) {
        printf("%3d", s.elems[i]);
    }
    printf("\n-----------------------------------------------------------------------\n");
    printf("%7s |", "INDEX");
    for(i = 0; i < MAX; i++) {
        printf("%3d", i);
    }
    printf("\n-----------------------------------------------------------------------\n");
    printf("\n");
}

Set unionSet(Set a, Set b) {
    Set c = newSet();
    int i;
    
    for(i = 0; i < MAX; i++) {
        if(a.elems[i] || b.elems[i]) {
            addElement(&c, i);
        }
    }
    
    return c;
}

Set intersectionSet(Set a, Set b) {
    Set c = newSet();
    int i;
    
    for(i = 0; i < MAX; i++) {
        if(a.elems[i] && b.elems[i]) {
            addElement(&c, i);
        }
    }
    
    return c;
}
Set differenceSet(Set a, Set b) {
    Set c = newSet();
    int i;
    
    for(i = 0; i < MAX; i++) {
        if(a.elems[i] != b.elems[i] && a.elems[i]) {
            addElement(&c, i);
        }
    }
    
    return c;
}
Set symmetricDiffSet(Set a, Set b) {
    Set c = newSet();
    int i;
    
    for(i = 0; i < MAX; i++) {
        if(a.elems[i] != b.elems[i] && a.elems[i]) {
            addElement(&c, i);
        }
    }
    
    return c;
}
int cardinality(Set s) {
    return s.count;
}