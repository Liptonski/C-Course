//
// Created by michal on 21.03.18.
//

#ifndef LABORKI_CPP_FUNKCJE_STRINGOW_H
#define LABORKI_CPP_FUNKCJE_STRINGOW_H

#include <iostream>
#include <cstring>

using namespace std;


int compare(char *s1, char *s2){
    int i=0;
    int j=0;
    while(true){
        if(*(s1+i)!=*(s2+j)) return *(s1+i)-*(s2+j);
        i++;
        j++;
        if(*(s1+i)==NULL && *(s2+j)==NULL) return 0;
    }
}

char* copy(char *from, char *to){
    int i=0;
    while(*from!=NULL){
        *(to+i)=*from;
        i++;
        from++;
    }
    return to;
}

int len(char *s){
    int lenght=0;
    int i=0;
    while(*(s+i)!=NULL){
        lenght++;
        i++;
    }
    return lenght;
}

char *lacz(char *s1, char *s2){
    int i=0;
    int j=0;
    while(*(s1+i)!=NULL){
        i++;
    }
    while(*(s2+j)!=NULL){
        *(s1+i)=*(s2+j);
        j++;
        i++;
    }
    return s1;
}

void *memcopy(void* from, void * to, unsigned int size){
    int i=0;
    int j=0;
    char *t = (char*) to;
    char *f = (char*) from;
    while(i!=size){
        *(t+j)=*f;
        i++;
        j++;
        f++;
    }
    return (void*)t;
}

#endif //LABORKI_CPP_FUNKCJE_STRINGOW_H
