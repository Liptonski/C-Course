#include <stdio.h>
#include <stdlib.h>

#define MAX 19

struct Node{
    void* Tab[MAX+1];
    int size;
};

typedef struct Node element;
element stack;

void push(void* new){
    if (stack.size==MAX){
        printf("Stos jest pelny\n");
    }
    else{
        stack.Tab[stack.size]=new;
        stack.size++;
    }
}

void* pop(){
    if (stack.size==0){
        return NULL;
    }
    else {
        void* poped = stack.Tab[stack.size];
        stack.size--;
        return poped;
    }
}


int main() {
    stack.size=0;
    *stack.Tab=NULL;
    int first=12;
    int second=17;
    push(&first);
    push(&second);

    return 0;
}
