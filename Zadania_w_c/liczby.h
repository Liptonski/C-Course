#include <stdlib.h>
#include <stdio.h>

void max(){
    float x;
    float *tab=NULL;
    int i=0;
    int j;
    float max=0;
    while(1) {
        printf("Podaj kolejna liczbe (wpisanie 'nieliczby' zatwierdzi wpisywanie): ");
        if((scanf("%f", &x))==0) break;
        tab=realloc(tab, (i+1)*sizeof(*tab));
        *(tab+i)=x;
        i++;
    }
    for(j=0; j<=i; j++){
        if(*(tab+j)>max) max=*(tab+j);
    }
    printf("%.2f", max);
}
