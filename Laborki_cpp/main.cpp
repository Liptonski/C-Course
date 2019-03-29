#include "Wektory.h"
#include "Macierz.h"
//#include "funkcje stringow.h"

char s1[] = "witam";
char s2[] = "czesc";
char s3[2];

int main() {
    srand(time(NULL));
    //wypisz();
    /*int i;
    int x = compare(s1, s2);
    cout << x << endl;
    copy(s2, s3);
    for(i=0; i<5; i++)
        cout << s2[i];
    cout << endl << len(s3) << endl;
    lacz(s1, s2);
    for(i=0; i<10; i++)
        cout << s1[i];
    memcopy(s2, s3, 3);
    cout << endl << s3[2] << endl;*/
    {
        Macierz pierwsza(3, 3);
        Macierz druga(2, 3);
        Macierz trzecia;
        trzecia.random();
        druga.random();
        pierwsza.random();
        pierwsza.pokaz();
        druga.pokaz();
        try{
            trzecia=pierwsza+druga;
        }
        catch(WyjatekSumRoz& e) {
            cerr << "Zly rozmiar " << pierwsza.r << " x " << pierwsza.c
                 << " != " << e.row << " x " << e.col << endl;
        }
        trzecia.pokaz();
        Macierz czwarta;
        try{
            czwarta=pierwsza/0;
        }
        catch(WyjatekDziel& e){
            cerr << "Nie dziel przez 0 (M/" << e.val << ")" << endl;
        }
        try{
            czwarta=pierwsza*druga;
        }
        catch (WyjatekIloczyn& e){
            cerr << "Zly Rozmiar (kolumny pierwszej != wiersze drugiej " << pierwsza.r << " x ";
            cerr << pierwsza.c << " * " << e.row;
            cerr << " x " << e.col << endl;
        }
        cout << druga.odczyt(4,2) << endl;
        druga.wstaw(4,2,23);
        druga.pokaz();
    }
    cout << "Koniec" << endl;

    return 0;
}