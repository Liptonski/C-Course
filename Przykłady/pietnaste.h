//
// Created by michal on 19.04.18.
//

#ifndef ROBOCZY_PIETNASTE_H
#define ROBOCZY_PIETNASTE_H

class fifth {
public:
    static void foo() {};
    static int bar(int i) {return 1;};
};

class der : public fifth {
public:
    static int bar(int i) {return 2;}
};

class Base2 {
    int i;
public:
    Base2() {};
    Base2(int ii):i(ii){};
    void foo() { cout << "cos";}
};

class der1 : private Base2 {};
class der2 : protected Base2 {};

void fun (Base2& b){
    b.foo();
}

#endif //ROBOCZY_PIETNASTE_H
