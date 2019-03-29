#include <math.h>
#include <stdio.h>

typedef struct{
    float x;
    float y;
    float z;
}wektor;

wektor vecPlus(wektor one, wektor two){
    wektor sum;
    sum.x=one.x+two.x;
    sum.y=one.y+two.y;
    sum.z=one.z+two.z;
    return sum;
};

wektor vecMult(wektor vec, float x){
    wektor odp={x*vec.x, x*vec.y, x*vec.z};
    return odp;
}

wektor vecSkalarny(wektor one, wektor two){
    wektor skal = {
            one.x*two.x,
            one.y*two.y,
            one.z*two.z
    };
    return skal;
}

wektor vecWektorowy(wektor one, wektor two){
    wektor wek={
            one.y*two.z - one.z*two.y,
            one.z*two.x - one.x*two.z,
            one.x*two.y - one.y*two.x
    };
    return wek;
}
/*
wektor vecNormalizacja(wektor vec){
    float x = vec.x*vec.x + vec.y*vec.y + vec.z*vec.z;
    float modul = sqrtf (x);
    wektor wynik = {
            vec.x/modul,
            vec.y/modul,
            vec.z/modul
    };
    return wynik;
}

void vecPorownanie(wektor one, wektor two){
    float x = sqrtf(one.x*one.x + one.y*one.y + one.z*one.z);
    float y = sqrtf(two.x*two.x + two.y*two.y + two.z*two.z);
    if(x>y) printf("Pierwszy ma wieksza wartosc");
    else if(x<y) printf("Drugi ma wieksza wartosc");
    else printf("Sa rowne");
}
*/
void wypisz(){
    wektor first={10, 3, 11};
    wektor second={11, 2, 3};
    wektor suma = vecPlus(first, second);
    wektor mnozenie = vecMult(first, 3);
    wektor skalarne = vecSkalarny(first, second);
    wektor wektorowo = vecWektorowy(first, second);
    //wektor normal = vecNormalizacja(first);
    printf("suma: %.2f %.2f %.2f\n", suma.x, suma.y, suma.z);
    printf("mnozenie: %.2f %.2f %.2f\n", mnozenie.x, mnozenie.y, mnozenie.z);
    printf("skalarne: %.2f %.2f %.2f\n", skalarne.x, skalarne.y, skalarne.z);
    printf("wektorowe: %.2f %.2f %.2f\n", wektorowo.x, wektorowo.y, wektorowo.z);
    //printf("normalizacja: %.2f %.2f %.2f\n", normal.x, normal.y, normal.z);
    //vecPorownanie(first, second);
};