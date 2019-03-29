#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float x;
    float y;
    float z;
}wektor;

typedef struct Node{
    void* data;
    struct Node *next;
}element;

typedef element *stack;

void push(stack *n,void* data){
    stack new;
    new=(stack)malloc(sizeof(element));
    new->data=data;
    new->next=*n;
    *n=new;
}

void* pop(stack *n){
    void* help;
    stack top;
    void* blad=NULL;
    if(*n==0) return blad;
    else{
        top=*n;
        help=(*n)->data;
        *n=(*n)->next;
        free(top);
        return help;
    }
}

void show(stack n){ //funkcja działa ale jest jakis błąd pamięciowy nie rozumiem o co chodzi
    if(n==NULL) printf("Stos jest pusty");
    else{
        do{
            void* c=n->data;
            int* d = (int*) c; //Nie wiem jak wyswietlac dowolne dane więc rzutuje
            printf("%d\n", *d);
            n=n->next;
        }while(n!=NULL);
    }
}

int main(void){
    //printf("Hello, World!\n");
    //printf("%u\n", Iloscjedynek(8));
    //trojkat(10);
    //printf("%d\n", fib(19));
    //wypisz();
    //max();
    //printf("%ld", itfib(50));
    int x=25;
    int y=54;
    int z=23;
    stack s;
    push(&s, &x);
    push(&s, &y);
    push(&s, &z);
    pop(&s);
    //show(s);


    return 0;
}