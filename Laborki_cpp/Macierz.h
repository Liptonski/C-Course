//
// Created by michal on 21.03.18.
//

#ifndef LABORKI_CPP_MACIERZ_H
#define LABORKI_CPP_MACIERZ_H

#include <ctime>
#include <string.h>
using namespace std;

int i;
int j;

class WyjatekSumRoz{
public:
    int row;
    int col;
    WyjatekSumRoz(int r, int c):row(r), col(c){}
};

class WyjatekIloczyn{
public:
    int row;
    int col;
    WyjatekIloczyn(int r, int c):row(r), col(c){}
};

class WyjatekDziel{
public:
    int val;
    WyjatekDziel(int x):val(x){}
};

class Macierz {
public:
    double *p;
    unsigned int r, c;

    Macierz(unsigned int rr = 0, unsigned int cc = 0):r(rr), c(cc) {
        p = new double[r * c];
    }
    ~Macierz(){
        cout << "Adres: " << (unsigned int*) p << endl;
        delete[]p;
    }

    void pokaz() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << *(p + (c * i + j)) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void random() {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                *(p + (c * i + j)) = rand() % 10;
            }
        }
    }

    void uzupelnij() {
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                cout << i+1 << " rzad " << j+1 << " kolumna: ";
                cin >> *(p + (c * i + j));
            }
        }
    }

    double odczyt (int row, int col){
        return *(p + (c*(row-1) + col-1));
    }

    void wstaw (int row, int col, double val){
        *(p + (c*(row-1) + col-1))=val;
    }

    Macierz &operator = (const Macierz m){
        r=m.r;
        c=m.c;
        delete [] p;
        p=new double [r*c];
        memcpy(p,m.p, r*c*sizeof(double));
    }

    int operator == (const Macierz& nowa){
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if ((*(p + (c * i + j))) != (*(nowa.p + (c * i + j)))) return 0;
            }
        }
        return 1;
    }

    int operator != (const Macierz &nowa){
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (*(p + (c * i + j)) == *(nowa.p + (c * i + j))) return 0;
            }
        }
        return 1;
    }

    Macierz operator ! (){
        Macierz pomoc(r,c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                *(pomoc.p + (c * i + j)) = (*(p + (c * i + j)))*(-1);
            }
        }
        return pomoc;
    }

    Macierz operator + (const Macierz& nowa) {
        Macierz pomoc(r,c);
        if (nowa.r != r || nowa.c != c)
            throw WyjatekSumRoz(nowa.r, nowa.c);
        else {
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    *(pomoc.p + (c * i + j)) = *(p + (c * i + j)) + *(nowa.p + (c * i + j));
                }
            }
        }
        return pomoc;
    }
    Macierz operator - (const Macierz& nowa) {
        Macierz pomoc(r,c);
        if (nowa.r != r || nowa.c != c)
            throw WyjatekSumRoz(nowa.r, nowa.c);
        else {
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    *(pomoc.p + (c * i + j)) = *(p + (c * i + j)) - *(nowa.p + (c * i + j));
                }
            }
        }
        return pomoc;
    }

    Macierz operator * (double skal){
        Macierz pomoc(r,c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                *(pomoc.p + (c * i + j)) = (*(p + (c * i + j)))*skal;
            }
        }
        return pomoc;
    }

    Macierz operator / (double skal){
        if(skal==0) throw WyjatekDziel(skal);
        Macierz pomoc(r,c);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                *(pomoc.p + (c * i + j)) = (*(p + (c * i + j)))/skal;
            }
        }
        return pomoc;
    }
    Macierz operator * (const Macierz &nowa) {
        if(c!=nowa.r) throw WyjatekIloczyn(nowa.r, nowa.c);
        Macierz pomoc(r,nowa.c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < nowa.c; j++) {
                double result = 0.0;
                for (int k = 0; k < nowa.r; k++) {
                    result += *(p+ c * i + k) * (*(nowa.p +(nowa.c*k) + j));
                }
                *(pomoc.p+nowa.c* i + j) = result;
            }
        }    return pomoc;
    }

    void wyznacznik (Macierz& nowa){

    }
};

/*srand(time(NULL));
    Macierz pierwsza;
    Macierz druga;
    Macierz sum = pierwsza.dodaj(druga);
    Macierz rozn = pierwsza.odejmij(druga);
    Macierz skal = pierwsza.skalar(5);
    Macierz ilocz = pierwsza.iloczyn(druga);
    double wyzn = pierwsza.wyznacznik();
    pierwsza.pokaz();
    druga.pokaz();*/

#endif //LABORKI_CPP_MACIERZ_H
