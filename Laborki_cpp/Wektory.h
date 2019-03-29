
#ifndef LABORKI_CPP_WEKTORY_H
#define LABORKI_CPP_WEKTORY_H

#include <iostream>
#include <cmath>
using namespace std;

struct RangeException{
    double val;
    RangeException(double x):val(x){}
};


class Wektor{
public:
    double vx;
    double vy;
    double vz;
    double norma;
    Wektor(double x=1, double y=1, double z=1):vx(x), vy(y), vz(z){
        norma = sqrt(vx*vx+vy*vy+vz*vz);
    }
    ~Wektor(){}

    void pokaz(){
        cout << vx << " " << vy << " " << vz << endl;
    }

    void parametr(char i){
        if(i=='x') cout << vx << endl;
        else if (i=='y') cout << vy << endl;
        else if (i=='z') cout << vz << endl;
        else cout << "Nie ma takiego parametru:" << endl;
    }

    Wektor &operator = (const Wektor nowy){
        vx=nowy.vx;
        vy=nowy.vy;
        vz=nowy.vz;
        norma=nowy.norma;
    }

    Wektor operator + (const Wektor& nowy){
        return Wektor(vx+nowy.vx, vy+nowy.vy, vz+nowy.vz);
    }

    Wektor operator * (double skalar){
        return Wektor(vx*skalar, vy*skalar, vz*skalar);
    }

    /*Wektor operator * (double skalar){
        return Wektor(vx*skalar, vy*skalar, vz*skalar);
    }*/

    Wektor operator / (double skalar) {
        if (skalar == 0)throw RangeException(skalar);
        else return Wektor(vx / skalar, vy / skalar, vz / skalar);
    }

    double operator * (const Wektor& nowy){
        return vx*nowy.vx + vy*nowy.vy + vz*nowy.vz;
    }

    Wektor operator ^ (const Wektor& nowy){
        return Wektor(vy*nowy.vz-vz*nowy.vy, vz*nowy.vx-vx*nowy.vz, vx*nowy.vy-vy*nowy.vx);
    }

    Wektor operator ! (){
        return Wektor(-this->vx, -this->vy, -this->vz);
    }

    Wektor operator ~ (){
        if(norma==0) return 0;
        else return Wektor(vx/norma, vy/norma, vz/norma);
    }

    int operator == (const Wektor& nowy){
        if (nowy.norma > norma) return 0;
        else if (nowy.norma < norma) return 0;
        else return 1;
    }

    int operator != (const Wektor& nowy){
        if (nowy.norma == norma) return 0;
        else return 1;
    }

};

void wypisz(){
    Wektor pierwszy(2, 3, 11);
    Wektor drugi(6, 22, 11);
    Wektor sum = pierwszy+drugi;
    Wektor il = pierwszy*5;
    Wektor dziel;
    try{
        dziel = pierwszy/0;
    }
    catch(RangeException& e){
        cerr << "Nie mozna dzielic przez 0 (v/" << e.val << ")" << endl;
    }
    cout << "dziel: ";
    dziel.pokaz();
    Wektor rowna = sum;
    rowna.pokaz();
    rowna.parametr('p');
    double skal = pierwszy*drugi;
    Wektor krzyz = pierwszy^drugi;
    Wektor przeciwny = !pierwszy;
    Wektor norm = ~pierwszy;
    int ktory = pierwszy==drugi;
    cout << "suma: " << sum.vx << " " << sum.vy << " " << sum.vz << endl;
    cout << "il: " << il.vx << " " << il.vy << " " << il.vz << endl;
    //cout << "dziel: " << dziel.vx << " " << dziel.vy << " " << dziel.vz << endl;

    cout << "kolko: " << skal << endl;
    cout << "krzyz: " << krzyz.vx << " " << krzyz.vy << " " << krzyz.vz << endl;
    cout << "norm: " << norm.vx << " " << norm.vy << " " << norm.vz << endl;
    cout << "rowne?: " << ktory << endl;
    cout << "przeciwny: " << przeciwny.vx << " " << przeciwny.vy << " " << przeciwny.vz << endl;
}
#endif //LABORKI_CPP_WEKTORY_H
