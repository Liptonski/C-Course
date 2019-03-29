#include <stdio.h>

void trojkat(int n){
    int gwiazdki=0;
    int spacje=0;
    int rzad=0;
    int rozmiar=2*n-1;
    while(rozmiar>0){
        if(gwiazdki==rozmiar) {
            printf(" ");
            spacje++;
            if(spacje==rzad){
                rozmiar-=2;
                gwiazdki=0;
                spacje=0;
            }
        }
        else{
            printf("*");
            gwiazdki++;
            if(gwiazdki==rozmiar){
                printf("\n");
                rzad+=1;
            }
        }
    }
}